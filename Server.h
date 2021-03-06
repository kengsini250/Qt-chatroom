#ifndef SERVER_H
#define SERVER_H

#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <QMainWindow>
#include <QString>
#include <QByteArray>

class MyServer : public QTcpServer
{
    Q_OBJECT
public:
	explicit MyServer(QMainWindow* parent = nullptr);

    int getConnectingClient() noexcept;
protected:
    void incomingConnection(qintptr socketDescriptor);
private:
	QVector<QTcpSocket*> AllClient;
    QString msg;
signals:
    void newClient();
    void ClientType(const QString& str);
};

#endif
