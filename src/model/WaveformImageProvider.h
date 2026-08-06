#ifndef WAVEFORMIMAGEPROVIDER_H
#define WAVEFORMIMAGEPROVIDER_H

#include <QQuickImageProvider>
#include "WaveformModel.h"

class WaveformImageProvider : public QQuickImageProvider {
public:
    explicit WaveformImageProvider(WaveformModel *model);
    
    
    QImage requestImage(const QString &id, QSize *size, const QSize &requestedSize) override;

private:
    WaveformModel *m_model;
};

#endif