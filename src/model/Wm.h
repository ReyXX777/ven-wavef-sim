#ifndef WM_H
#define WM_H

#include <QObject>
#include <QImage>
#include <QPainter>
#include <QLinearGradient>
#include <QPolygonF>
#include <QVector>
#include <QtMath>

class WaveformModel : public QObject {
    Q_OBJECT
    Q_PROPERTY(QImage waveformImage READ waveformImage NOTIFY imageReady)
    Q_PROPERTY(double bpm READ bpm NOTIFY bpmChanged)
    Q_PROPERTY(double peakPressure READ peakPressure NOTIFY peakPressureChanged)
    Q_PROPERTY(double etco2Value READ etco2Value NOTIFY etco2ValueChanged)
    Q_PROPERTY(double spo2 READ spo2 NOTIFY spo2Changed)
    Q_PROPERTY(double respiratoryRate READ respiratoryRate NOTIFY respiratoryRateChanged)
    Q_PROPERTY(double tidalVolume READ tidalVolume NOTIFY tidalVolumeChanged)
    Q_PROPERTY(double peepValue READ peepValue NOTIFY peepValueChanged)
    Q_PROPERTY(double fio2Value READ fio2Value NOTIFY fio2ValueChanged)
    Q_PROPERTY(int batteryLevel READ batteryLevel NOTIFY batteryLevelChanged)
    Q_PROPERTY(int wifiStrength READ wifiStrength NOTIFY wifiStrengthChanged)
    
public:
    explicit WaveformModel(int width, int height, QObject *parent = nullptr);
    
    const QImage& waveformImage() const { return m_image; }
    double bpm() const { return m_bpm; }
    double peakPressure() const { return m_peakPressure; }
    double etco2Value() const { return m_etco2Value; }
    double spo2() const { return m_spo2; }
    double respiratoryRate() const { return m_respiratoryRate; }
    double tidalVolume() const { return m_tidalVolume; }
    double peepValue() const { return m_peepValue; }
    double fio2Value() const { return m_fio2Value; }
    int batteryLevel() const { return m_batteryLevel; }
    int wifiStrength() const { return m_wifiStrength; }
    

public slots:
    void renderFrame(double dt);

signals:
    void imageReady();
    void bpmChanged();
    void peakPressureChanged();
    void etco2ValueChanged();
    void spo2Changed();
    void respiratoryRateChanged();
    void tidalVolumeChanged();
    void peepValueChanged();
    void fio2ValueChanged();
    void batteryLevelChanged();
    void wifiStrengthChanged();

private:
    void generateECG(double t);
    void generatePaw(double t);
    void generateFlow(double t);
    void generateEtCO2(double t);
    
    // Updated signature: Removed unnecessary safeTop/safeBottom constraints
    void drawTrace(QPainter &p, const QVector<QPointF> &samples, 
                   const QColor &color, qreal lineWidth, bool fill, 
                   const QLinearGradient &fillGrad, qreal baselineY, qreal scaleY,
                   qreal xOffset, qreal drawWidth);

    QImage m_image;
    QPainter m_painter;
    QLinearGradient m_pawGradient;
    
    QVector<QPointF> m_ecgBuf, m_pawBuf, m_flowBuf, m_etco2Buf;
    static constexpr int BUFFER_SIZE = 120; // 2s @ 60Hz
    
    double m_time = 0.0;
    double m_bpm = 72.0;
    double m_peakPressure = 25.0;
    double m_etco2Value = 38.0;
    int m_frameCount = 0;
    double m_spo2 = 98.0;
    double m_respiratoryRate = 12.0;
    double m_tidalVolume = 500.0;
    double m_peepValue = 8.0;
    double m_fio2Value = 40.0;
    int m_batteryLevel = 100;
    int m_wifiStrength = 4;
};

#endif