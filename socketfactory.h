#ifndef SOCKETFACTORY_H
#define SOCKETFACTORY_H

#include <QObject>
#include "mytcpclient.h"
#include "mytcpserver.h"
#include "myudp.h"
#include "fsocket.h"

namespace FanSocket
{
class SocketFactory : public QObject
{
    Q_OBJECT
public:
    explicit SocketFactory(QObject *parent = nullptr);

signals:

public slots:
private:
    MyTcpClient *m_pTcpClient = 0;
    MyTcpServer *m_pTcpServer = 0;
    MyUdp *m_udp = 0;
    FSocket *m_pSocket = 0;
public:
    FSocket *CreateSocket(QString);


};
}
#endif // SOCKETFACTORY_H
