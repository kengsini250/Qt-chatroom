#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->cclean, &QAbstractButton::clicked, [=]() {ui->textBrowser->clear(); });

    myServer=new MyServer(this);

    connect(myServer,&MyServer::newClient,[=]() {
        ui->textBrowser->append("connecting : " + QString::number(myServer->getConnectingClient()));
        ui->textBrowser->append("--new  client---\n\n");
        //ui->listWidget->addItem("PC Client");
    });
    connect(myServer,&MyServer::ClientType,[=](const QString& msg){
        if(msg=="PC_CLIENT")
            ui->listWidget->addItem("PC Client");
        if(msg=="ANDROID_CLIENT")
            ui->listWidget->addItem("Android Client");
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

