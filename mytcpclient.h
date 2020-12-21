#ifndef MYTCPCLIENT_H
#define MYTCPCLIENT_H

#include <QObject>

#include "fsocket.h"
namespace FanSocket {
class MyTcpClient : public FSocket
{
    Q_OBJECT
public:
    explicit MyTcpClient(QObject *parent = nullptr);

signals:

public slots:
private:
    QTcpSocket m_socket;
private:
    void Connected(void);
    void DisConnected(void);
    void ReadData(void);
    void Error();

public:
    void ConnectToServer(void);
    void InitRemotePc(QString addr,int port);


};
}
#endif // MYTCPCLIENT_H
