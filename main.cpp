#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "src/model/WaveformModel.h"
#include "src/controller/SimController.h"
#include "src/model/WaveformImageProvider.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);
    
    
    WaveformModel model(870, 600);
    SimController controller(&model);
    
    QQmlApplicationEngine engine;
    
    engine.addImageProvider("waveform", new WaveformImageProvider(&model));
    engine.rootContext()->setContextProperty("waveformModel", &model);
    
    const QUrl url(QStringLiteral("qrc:/qml/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl) QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);
    
    controller.start();
    
    return app.exec();
}