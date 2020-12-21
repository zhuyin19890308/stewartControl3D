#include "mytcpserver.h"
namespace FanSocket
{
MyTcpServer::MyTcpServer(QObject *parent) : FSocket(parent)
{
    connect(&m_server, &QTcpServer::newConnection, this, &MyTcpServer::OnNewConnect);

}

void MyTcpServer::ReadData()
{

    emit NotifyDisposeData(rec_data);
}

QString MyTcpServer::GetLocalIp()
{
    QString hostName = QHostInfo::localHostName();
    QHostInfo hostInfo = QHostInfo::fromName(hostName);
    QString localIp = "";
    QList<QHostAddress> addList = hostInfo.addresses();

    if(!addList.isEmpty())
        for(int i = 0; i < addList.count(); i++)
        {
            QHostAddress aHost = addList.at(i);

            if(QAbstractSocket::IPv4Protocol == aHost.protocol())
            {
                localIp = aHost.toString();
                break;
            }
        }

    return localIp;
}

void MyTcpServer::OnNewConnect()
{
    m_pSocket = m_server.nextPendingConnection();
    connect(m_pSocket, &QTcpSocket::connected, this, &MyTcpServer::OnClientConnected);
    connect(m_pSocket, &QTcpSocket::disconnected, this, &MyTcpServer::OnClientDisConnected);
    connect(m_pSocket, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(OnSocketStateChange(QAbstractSocket::SocketState)));
    connect(m_pSocket, &QTcpSocket::readyRead, this, &MyTcpServer::ReadData);
}

void MyTcpServer::OnClientConnected()
{

}

void MyTcpServer::OnClientDisConnected()
{

}

void MyTcpServer::OnSocketStateChange(QAbstractSocket::SocketState state)
{

}

void MyTcpServer::InitListenInfo(int port)
{
    m_portlocal = port;

}

void MyTcpServer::Listen()
{
    QHostAddress addr(GetLocalIp());
    m_server.listen(addr, m_portlocal);
}
}
