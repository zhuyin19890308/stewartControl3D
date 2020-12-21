#ifndef MYUDP_H
#define MYUDP_H

#include <QObject>
#include <structDefine.h>
#include "fsocket.h"


namespace FanSocket
{
class MyUdp : public FSocket
{
    Q_OBJECT
public:
    explicit MyUdp(QObject *parent = 0);
    int serPort() const;
    void setSerPort(int serPort);

    QString serAddr() const;
    void setSerAddr(const QString &serAddr);

    qint64 WriteData(QString data);
    qint64 WriteData(QByteArray data);
    qint64 WriteData(const char *pdata, int len, bool defRemote = true);
    bool InitLocalReceive(int port);
    void InitLocalSend(QString addr, int port, int portAnother = 0);
    void InitLocalSend(QVector<QString> addr, QVector<int> port);

private:
    QUdpSocket m_socket;

signals:
    void Log(QString);
    void Log(int, int);
    void Log(int);
    void Log(QString, int);

//    void NotifyDisposeData(QByteArray &data);
private:
    void ReadData(void);
};
}
#endif // MYUDP_H
