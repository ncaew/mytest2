#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWebFrame>
#include <VLCQtCore/Common.h>
#include <VLCQtCore/Instance.h>
#include <VLCQtCore/Media.h>
#include <VLCQtCore/MediaPlayer.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTimer * timer = new QTimer(this);
    connect( timer, SIGNAL(timeout()), this, SLOT(startWeb()) );
    timer->setSingleShot(true);
    timer->start(300);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startWeb()
{
    QWebView *view = new QWebView(this);
    ui->verticalLayout_p0->addWidget(view);
    //view->load(QUrl("http://192.168.234.1/"));
    view->load(QUrl(getUrl()));
    ui->stackedWidget->setCurrentIndex(0);
    view->show();

    view->page()->mainFrame()->setScrollBarPolicy( Qt::Vertical, Qt::ScrollBarAlwaysOff );
    view->page()->mainFrame()->setScrollBarPolicy( Qt::Horizontal, Qt::ScrollBarAlwaysOff );
}

QString MainWindow::getUrl()
{
    QString fileName = "settings.json";
    QString str;
    QFile file(fileName);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this,"Warnning","can't open settings.json",QMessageBox::Cancel);
        QApplication::quit();
        QApplication::exit(0);
        return 0;
    }
    QTextStream in(&file);
    str=in.readAll();
    file.close();

    QJsonParseError json_error;
    QJsonDocument parse_doucment = QJsonDocument::fromJson(str.toUtf8(), &json_error);
    if(json_error.error == QJsonParseError::NoError)
    {
        if(parse_doucment.isObject())
        {
            QJsonObject obj = parse_doucment.object();
            if(obj.contains("url"))
            {
                QJsonValue url_value = obj.take("url");
                if(url_value.isString())
                {
                    QString strUrl = url_value.toString();
                    return strUrl;
                }
            }
        }
    }
    return ( "file://" + QApplication::applicationDirPath() + "/" + fileName);
}

void MainWindow::on_pushButton_p0_to_p1_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

    _instance = new VlcInstance(VlcCommon::args(), this);
    _player = new VlcMediaPlayer(_instance);
    _player->setVideoWidget(ui->vlcvvideo_p1);
    ui->vlcvvideo_p1->setMediaPlayer(_player);
}

void MainWindow::on_pushButton_p1_go_back_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_p1_play_clicked()
{
    qDebug()<<"Play... TODO reuse media player instance";
    _media = new VlcMedia("/usr/local/share/sample/1494636104019.mp4", true, _instance);
    //_media = new VlcMedia("rtsp://127.0.0.1:8554/", _instance);
    _player->open(_media);
}
