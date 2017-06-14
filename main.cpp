#include "mainwindow.h"
#include <QApplication>
#include <VLCQtCore/Common.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    VlcCommon::setPluginPath(a.applicationDirPath() + "/plugins");

    MainWindow w;
    //w.showFullScreen();
    w.show();


    return a.exec();
}
