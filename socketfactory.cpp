#include "socketfactory.h"
namespace FanSocket {
SocketFactory::SocketFactory(QObject *parent) : QObject(parent)
{

}

FSocket *SocketFactory::CreateSocket(QString name)
{
        if(0 == name.compare("client")){
            return new MyTcpClient;
        }

        if(0 == name.compare("server")){
            return new MyTcpServer;
        }

        if(0 == name.compare("udp")){
            return new MyUdp;
        }

        return 0;
    }
}
