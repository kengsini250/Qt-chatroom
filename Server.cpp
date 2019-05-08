#include "Server.h"

MyServer::MyServer(QMainWindow* parent):QTcpServer(parent)
{
    listen(QHostAddress::Any, 55555);
}

int MyServer::getConnectingClient() noexcept
{
    return AllClient.count();
}

void MyServer::incomingConnection(qintptr socketDescriptor)
{
    QTcpSocket* currentClient = new QTcpSocket(this);
    currentClient->setSocketDescriptor(socketDescriptor);

    connect(currentClient,&QTcpSocket::readyRead,[=](){
        msg = currentClient->readAll();
        if(msg=="PC_CLIENT")
            emit ClientType(msg);
        else if(msg=="ANDROID_CLIENT")
            emit ClientType(msg);
        else{
            for(int i =0; i<AllClient.count();i++)
            {
                AllClient[i]->write(msg.toUtf8());
            }
        }
    });
    AllClient.append(currentClient);
    emit newClient();
}
