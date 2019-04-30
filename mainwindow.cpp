#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	connect(ui->cclear, &QAbstractButton::clicked, [=]() {ui->textBrowser->clear(); });

    myServer=new MyServer(this);
    connect(myServer,&MyServer::newClient,[=]() {
        ui->textBrowser->append("connecting : " + QString::number(myServer->getConnectingClient()));
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

