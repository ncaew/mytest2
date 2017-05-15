#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    //view->load(QUrl("http://www.baidu.com"));
    view->load(QUrl(getUrl()));
    view->show();
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
