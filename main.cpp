#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "basetheme.h"
#include "processcsv.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(u"main.qml"_qs);
//    BaseTheme baseTheme;
    ProcessCsv processCsv;

    qmlRegisterSingletonType<BaseTheme>("BaseTheme", 1, 0, "BaseTheme", BaseTheme::baseThemeSingletonProvider);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}


