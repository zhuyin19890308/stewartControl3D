#include "fsocket.h"
namespace FanSocket
{
FSocket::FSocket(QObject *parent) : QObject(parent)
{

}

bool FSocket::InitLocalReceive(int port)
{

}

void FSocket::InitLocalSend(QString addr, int port, int portAnother)
{
//    m_addrRemote = addr;
//    m_portRemote = port;
    //    m_portRemoteObjectCreate = portAnother;
}

void FSocket::InitLocalSend(QVector<QString> addr, QVector<int> port)
{

}

void FSocket::InitRemotePc(QString addr, int port)
{

}

void FSocket::ConnectToServer()
{

}

void FSocket::InitListenInfo(int port)
{

}

void FSocket::Listen()
{

}

qint64 FSocket::WriteData(const char *pdata, int len, bool defRemote)
{

}

void FSocket::OnNewConnect()
{

}

void FSocket::OnClientConnected()
{

}

void FSocket::OnClientDisConnected()
{

}

void FSocket::OnSocketStateChange(QAbstractSocket::SocketState state)
{

}

}
