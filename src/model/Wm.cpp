#include "WaveformModel.h"
#include <algorithm>
#include <cstdlib>
WaveformModel::WaveformModel(int width, int height, QObject *parent)
    : QObject(parent), 
      m_image(width, height, QImage::Format_RGB32),
      m_pawGradient()
{
    
    m_image.fill(QColor("#0a0a0a"));
    
    m_ecgBuf.resize(BUFFER_SIZE);
    m_pawBuf.resize(BUFFER_SIZE);
    m_flowBuf.resize(BUFFER_SIZE);
    m_etco2Buf.resize(BUFFER_SIZE);
}

void WaveformModel::renderFrame(double dt) {
    m_time += dt;
    m_frameCount++;
    
    generateECG(m_time);
    generatePaw(m_time);
    generateFlow(m_time);
    generateEtCO2(m_time);
    
    
    int w = m_image.width();
    int h = m_image.height();
    
    m_painter.begin(&m_image);
    m_painter.fillRect(m_image.rect(), QColor("#0a0a0a"));
    m_painter.setRenderHint(QPainter::Antialiasing, true);
    
    const qreal panelH = h / 4.0;
    const qreal drawW = w; 
    const qreal xOffset = 0; 
    
    
    qreal ecgBase = panelH * 0.5;
    drawTrace(m_painter, m_ecgBuf, QColor("#00FF00"), 2.0, false, m_pawGradient, 
              ecgBase, 50.0, xOffset, drawW);
    
    
    qreal pawBase = panelH * 1.8;
    m_pawGradient = QLinearGradient(0, pawBase - 70, 0, pawBase);
    m_pawGradient.setColorAt(0.0, QColor(0, 191, 255, 120));
    m_pawGradient.setColorAt(1.0, QColor(0, 191, 255, 0));
    drawTrace(m_painter, m_pawBuf, QColor("#00bfff"), 2.5, true, m_pawGradient, 
              pawBase, 3.0, xOffset, drawW);
    
    
    qreal flowBase = panelH * 2.5;
    drawTrace(m_painter, m_flowBuf, QColor("#ffd700"), 1.5, false, m_pawGradient, 
              flowBase, 50.0, xOffset, drawW);
    
    
    qreal etco2Base = panelH * 3.8;
    QLinearGradient etco2Grad(0, etco2Base - 60, 0, etco2Base);
    etco2Grad.setColorAt(0.0, QColor(255, 215, 0, 100));
    etco2Grad.setColorAt(1.0, QColor(255, 215, 0, 0));
    drawTrace(m_painter, m_etco2Buf, QColor("#ffd700"), 2.0, true, etco2Grad, 
              etco2Base, 1.5, xOffset, drawW);
    
    m_painter.end();
    
    if (m_frameCount % 1 == 0) emit imageReady();
    
    static double lastScalarUpdate = 0.0;
    constexpr double SCALAR_UPDATE_INTERVAL = 0.5;
    
    if (m_time - lastScalarUpdate >= SCALAR_UPDATE_INTERVAL) {
        lastScalarUpdate = m_time;
        
        
        double newBpm = 70.0 + 5.0 * qSin(m_time * 0.1);
        if (!qFuzzyCompare(m_bpm, newBpm)) {
            m_bpm = newBpm;
            emit bpmChanged();
        }
        
        double newPeak = 24.0 + 2.0 * qSin(m_time * 0.05);
        if (!qFuzzyCompare(m_peakPressure, newPeak)) {
            m_peakPressure = newPeak;
            emit peakPressureChanged();
        }
        
        double newEtco2 = 37.0 + 2.0 * qSin(m_time * 0.08);
        if (!qFuzzyCompare(m_etco2Value, newEtco2)) {
            m_etco2Value = newEtco2;
            emit etco2ValueChanged();
        }
        
        double simBattery = m_batteryLevel - 0.5 + (qSin(m_time * 0.01) > 0.8 ? 2.0 : 0.0);
        int newBattery = static_cast<int>(qBound(0.0, simBattery, 100.0));
        if (m_batteryLevel != newBattery) {
            m_batteryLevel = newBattery;
            emit batteryLevelChanged();
        }

        
        int newWifi = static_cast<int>(qBound(1.0, 3.0 + qSin(m_time * 0.05) * 1.5, 4.0));
        if (m_wifiStrength != newWifi) {
            m_wifiStrength = newWifi;
            emit wifiStrengthChanged();
        }
    }
}


void WaveformModel::generateECG(double t) {
    std::rotate(m_ecgBuf.begin(), m_ecgBuf.begin() + 1, m_ecgBuf.end());
    
    
    static double smoothBpm = m_bpm;
    smoothBpm += (m_bpm - smoothBpm) * 0.1; 
    
    double phase = fmod(t * (smoothBpm / 60.0), 1.0);
    double val = 0.0;
    if (phase < 0.1) val += 0.15 * exp(-pow((phase - 0.05)/0.02, 2));
    if (phase > 0.1 && phase < 0.15) val -= 0.2 * exp(-pow((phase - 0.12)/0.01, 2));
    if (phase > 0.12 && phase < 0.2) val += 1.0 * exp(-pow((phase - 0.16)/0.015, 2));
    if (phase > 0.18 && phase < 0.25) val -= 0.25 * exp(-pow((phase - 0.21)/0.02, 2));
    if (phase > 0.3 && phase < 0.5) val += 0.2 * exp(-pow((phase - 0.4)/0.08, 2));
    m_ecgBuf.last() = QPointF(0, val);
}

void WaveformModel::generatePaw(double t) {
    std::rotate(m_pawBuf.begin(), m_pawBuf.begin() + 1, m_pawBuf.end());
    
    double respCycle = fmod(t * (m_respiratoryRate / 60.0), 1.0);
    double val = m_peepValue; 
    if (respCycle < 0.33) { 
        val += (m_peakPressure - m_peepValue) * sin(respCycle / 0.33 * M_PI); 
    } else { 
        val += (m_peakPressure - m_peepValue) * exp(-(respCycle - 0.33) * 3.0); 
    }
    m_pawBuf.last() = QPointF(0, val);
}

void WaveformModel::generateFlow(double t) {
    std::rotate(m_flowBuf.begin(), m_flowBuf.begin() + 1, m_flowBuf.end());
    double respCycle = fmod(t * (m_respiratoryRate / 60.0), 1.0);
    double val = 0.0;
    if (respCycle < 0.33) { 
        val = 1.0 * sin(respCycle / 0.33 * M_PI); 
    } else { 
        
        val = -0.95 * sin((respCycle - 0.33) / 0.67 * M_PI); 
    }
    m_flowBuf.last() = QPointF(0, val);
}

void WaveformModel::generateEtCO2(double t) {
    std::rotate(m_etco2Buf.begin(), m_etco2Buf.begin() + 1, m_etco2Buf.end());
    double respCycle = fmod(t * (m_respiratoryRate / 60.0), 1.0);
    double val = 0.0;
    
    
    
    if (respCycle < 0.33) {
        
        val = 0.0;
    } else if (respCycle < 0.40) {
        
        double expPhase = (respCycle - 0.33) / 0.07;
        val = m_etco2Value * expPhase;
    } else if (respCycle < 0.85) {
        
        val = m_etco2Value;
    } else {
        
        double washout = (respCycle - 0.85) / 0.15;
        val = m_etco2Value * (1.0 - washout);
    }
    m_etco2Buf.last() = QPointF(0, val);
}

void WaveformModel::drawTrace(QPainter &p, const QVector<QPointF> &samples,
                              const QColor &color, qreal lineWidth, bool fill,
                              const QLinearGradient &fillGrad, qreal baselineY, 
                              qreal scaleY, qreal xOffset, qreal drawWidth) {
    if (samples.isEmpty()) return;
    
    const qreal spacing = drawWidth / (BUFFER_SIZE - 1);
    QPolygonF poly;
    
    for (int i = 0; i < samples.size(); ++i) {
        qreal x = xOffset + i * spacing;
        qreal y = baselineY - samples[i].y() * scaleY;
        poly << QPointF(x, y);
    }
    
    if (fill) {
        QPolygonF fillPoly = poly;
        fillPoly << QPointF(xOffset + drawWidth, baselineY) 
                 << QPointF(xOffset, baselineY);
        p.setBrush(fillGrad);
        p.setPen(Qt::NoPen);
        p.drawPolygon(fillPoly);
    }
    
    p.setPen(QPen(color, lineWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    p.setBrush(Qt::NoBrush);
    p.drawPolyline(poly);
}