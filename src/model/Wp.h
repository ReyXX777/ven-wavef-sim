#ifndef Wp_H
#define Wp_H

#include <QQuickImageProvider>
#include "Wm.h"

class WaveformImageProvider : public QQuickImageProvider {
public:
    explicit WaveformImageProvider(WaveformModel *model);
    
    
    QImage requestImage(const QString &id, QSize *size, const QSize &requestedSize) override;

private:
    WaveformModel *m_model;
};

#endif