#include "WaveformImageProvider.h"

WaveformImageProvider::WaveformImageProvider(WaveformModel *model)
    : QQuickImageProvider(QQuickImageProvider::Image), m_model(model) {}

QImage WaveformImageProvider::requestImage(const QString &id, QSize *size, const QSize &requestedSize) {
    Q_UNUSED(id)
    Q_UNUSED(requestedSize)
    
    if (size) *size = m_model->waveformImage().size();
    
    
    return m_model->waveformImage();
}