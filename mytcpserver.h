#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QObject>

#include "fsocket.h"

namespace FanSocket {
class MyTcpServer : public FSocket
{
    Q_OBJECT
public:
    explicit MyTcpServer(QObject *parent = nullptr);

signals:

public slots:
private:
    QTcpServer m_server;
    QTcpSocket *m_pSocket = 0;
private:
    void ReadData(void);
    QString GetLocalIp(void);
    void OnNewConnect(void);
    void OnClientConnected(void);
    void OnClientDisConnected(void);
    void OnSocketStateChange(QAbstractSocket::SocketState state);
public:
    void InitListenInfo(int port);
    void Listen(void);

};
}
#endif // MYTCPSERVER_H
