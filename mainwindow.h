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
#include <QTimer>

namespace Ui {
class MainWindow;
}

class VlcInstance;
class VlcMedia;
class VlcMediaPlayer;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QString getUrl();

private:
    VlcInstance *_instance;
    VlcMedia *_media;
    VlcMediaPlayer *_player;

public slots:
    void startWeb();

private slots:
    void on_pushButton_p0_to_p1_clicked();
    void on_pushButton_p1_go_back_clicked();
    void on_pushButton_p1_play_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
