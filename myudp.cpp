#include "myudp.h"
namespace FanSocket
{
MyUdp::MyUdp(QObject *parent) : FSocket(parent)
{

}

qint64 MyUdp::WriteData(QString data)
{
    return m_socket.writeDatagram(data.toLatin1(), data.length(), QHostAddress(m_addrRemote), m_portRemote);
}

qint64 MyUdp::WriteData(QByteArray data)
{
    return m_socket.writeDatagram(data, QHostAddress(m_addrRemote), m_portRemote);
}


/*若发送方未绑定端口号，则将数据发送给接收数据时的随机端口
 *m_portRemoteObjectCreate记录每次收到数据时发送方的端口
*/
qint64 MyUdp::WriteData(const char *pdata, int len, bool defRemote)
{
    if(defRemote)
    {
        return m_socket.writeDatagram(pdata, len, QHostAddress(m_addrRemote), m_portRemote);
    }
    else
    {
        return m_socket.writeDatagram(pdata, len, QHostAddress(m_addrRemote), m_portRemoteObjectCreate);

    }
}

bool MyUdp::InitLocalReceive(int port)//
{
    m_portLocal = port;

    if(m_socket.bind(m_portLocal, QAbstractSocket::ShareAddress))
    {
        connect(&m_socket, &QUdpSocket::readyRead, this, &MyUdp::ReadData);
        return true;
    }

    return false;
}

void MyUdp::InitLocalSend(QString addr, int port, int portAnother)
{
//    m_addrRemote = addr;
//    m_portRemote = port;
    //    m_portRemoteObjectCreate = portAnother;
}

void MyUdp::InitLocalSend(QVector<QString> addr, QVector<int> port)
{
    m_addrRemoteList = addr;
    m_portRemoteList = port;
    return;
}

void MyUdp::ReadData(void)
{
    rec_data.clear();
    int size = 0;

    do
    {
        size = m_socket.pendingDatagramSize();
        rec_data.resize(size);
        m_socket.readDatagram(rec_data.data(), size);
        emit NotifyDisposeData(rec_data);
        emit Log(QString(rec_data));
    }
    while(m_socket.hasPendingDatagrams());

    //解析接收到的数据
    do
    {
        Header packHead;
        memcpy(&packHead, rec_data, sizeof(packHead));

        if(packHead.PackID == 0xFCFE)
        {
            //TODO: process valid data


        }
        else
        {
            //TODO: porcess invalid data
            rec_data.clear();
        }

        //note: 注意跳出循环条件，需要避免死循环的出现
    }
    while(rec_data.length() > 0) ;
}

}
