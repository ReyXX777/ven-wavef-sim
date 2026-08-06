#ifndef SIMCONTROLLER_H
#define SIMCONTROLLER_H

#include <QObject>
#include <QTimer>
#include <QElapsedTimer>
#include "WaveformModel.h"

class SimController : public QObject {
    Q_OBJECT
public:
    explicit SimController(WaveformModel *model, QObject *parent = nullptr);
    void start();

private slots:
    void onTick();

private:
    WaveformModel *m_model;
    QTimer m_timer;
    QElapsedTimer m_elapsed;
};

#endif