#include "mytcpclient.h"
namespace FanSocket
{
MyTcpClient::MyTcpClient(QObject *parent) : FSocket(parent)
{
    connect(&m_socket, &QTcpSocket::connected, this, &MyTcpClient::Connected);
    connect(&m_socket, &QTcpSocket::disconnected, this, &MyTcpClient::DisConnected);
    connect(&m_socket, &QTcpSocket::readyRead, this, &MyTcpClient::ReadData);
//    connect(&m_socket,QTcpSocket::error(QAbstractSocket::SocketError),this,MyTcpClient::YesError);
    connect(&m_socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(Error()));
}

void MyTcpClient::Connected()
{

}

void MyTcpClient::DisConnected()
{

}

void MyTcpClient::ReadData()
{
    emit NotifyDisposeData(rec_data);

}

void MyTcpClient::Error()
{

}

void MyTcpClient::ConnectToServer()
{
    m_socket.connectToHost(m_addrRemote, m_portRemote);
}

void MyTcpClient::InitRemotePc(QString addr, int port)
{
    m_addrRemote = addr;
    m_portRemote = port;
}
}
