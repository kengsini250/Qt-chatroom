#include "Server.h"

MyServer::MyServer(QMainWindow* parent):QTcpServer(parent)
{
    qDebug()<<"listen";
    listen(QHostAddress::Any, 55555);
}

int MyServer::getConnectingClient() noexcept
{
    return AllClient.count();
}

void MyServer::incomingConnection(qintptr socketDescriptor)
{
    qDebug()<<"incomming";
    QTcpSocket* currentClient = new QTcpSocket(this);
    currentClient->setSocketDescriptor(socketDescriptor);
    connect(currentClient,&QTcpSocket::readyRead,[=](){
        msg = currentClient->readAll();
        for(int i =0; i<AllClient.count();i++)
        {
            AllClient[i]->write(msg);
        }
    });
    AllClient.append(currentClient);
    emit newClient();
}
