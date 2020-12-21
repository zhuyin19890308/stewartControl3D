#ifndef FSOCKET_H
#define FSOCKET_H

#include <QObject>
#include <QWidget>
#include <QUdpSocket>
#include <QTcpServer>
#include <QTcpSocket>
#include <QHostInfo>
//#include <global.h>
namespace FanSocket
{


class FSocket : public QObject
{
    Q_OBJECT
public:
    explicit FSocket(QObject *parent = nullptr);

signals:
    void NotifyDisposeData(QByteArray &data);
public slots:

protected:

    int m_portlocal;

    int m_portRemoteObjectCreate;

    //目标ip地址
    QString          m_addrRemote;
    QVector<QString> m_addrRemoteList;  //目标IP地址容器
    //目标端口
    int              m_portRemote;
    QVector<int>     m_portRemoteList;      //目标端口容器

    int m_portLocal;                //本地端口
    QString m_addrLocal;            //本地IP

    QByteArray rec_data;

private:
    virtual void ReadData(void) = 0;
    virtual void OnNewConnect(void);
    virtual void OnClientConnected(void);
    virtual void OnClientDisConnected(void);
    virtual void OnSocketStateChange(QAbstractSocket::SocketState state);
//    virtual void OnSocketReadyRead(void);

public:
    virtual bool InitLocalReceive(int port);
    virtual void InitLocalSend(QString addr, int port, int portAnother = 0);
    virtual void InitLocalSend(QVector<QString> addr, QVector<int> port);

    virtual void InitRemotePc(QString addr, int port);
    virtual void ConnectToServer(void);

    virtual void InitListenInfo(int port);
    virtual void Listen(void);

    virtual qint64 WriteData(const char *pdata, int len, bool defRemote = true);
};

}
#endif // FSOCKET_H
