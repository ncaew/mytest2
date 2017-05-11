#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QWebView *view = new QWebView(parent);
    ui->verticalLayout_p0->addWidget(view);
    view->load(QUrl("http://qt.nokia.com/"));
    view->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}
