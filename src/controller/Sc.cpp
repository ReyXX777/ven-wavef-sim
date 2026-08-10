#include "Sc.h"

SimController::SimController(WaveformModel *model, QObject *parent)
    : QObject{parent},
      m_model{model},
      m_timer{},
      m_elapsed{}
{
    connect(&m_timer, &QTimer::timeout, this, &SimController::onTick);
    m_timer.setInterval(16);
}

void SimController::start()
{
    m_elapsed.start();
    m_timer.start();
}

void SimController::onTick()
{
    if (!m_model) {
        return;
    }

    double dt{static_cast<double>(m_elapsed.restart()) / 1000.0};
    m_model->renderFrame(dt);
}
