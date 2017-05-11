#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebView>
#include <QMessageBox>
#include <QFile>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonObject>
#include <QByteArray>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QString getUrl();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
