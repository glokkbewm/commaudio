#ifndef CLIENTUDP_H
#define CLIENTUDP_H

#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include "udprecvthread.h"
#include "circularbuffer.h"
#include "recording.h"


#define WORD unsigned short
#define MAXADDRSTR  16
#define TIMECAST_ADDR "234.5.6.7"


class ClientUDP :public QObject{
    Q_OBJECT
public:

    boolean Start(SOCKET * sock, int port);
    boolean multiSetup(SOCKET * sock);
    boolean initData();
void sendVoice(char *ip);

    int UDPClose();

    SOCKET voiceTo;
    LPSOCKET_INFORMATION SIVoice;
    SOCKADDR_IN InetAddr;
    SOCKET hSocket;
    char hostAddr[MAXADDRSTR] = TIMECAST_ADDR;
    u_long lhostAddr;
    u_short nPort = TIMECAST_PORT;
    FILE *fstream;


    struct ip_mreq stMreq;         /* Multicast interface structure */

    int _type;
signals:
    void voiceGo(char*);
    void VoiceDataSent(Recording *recording);
    void connected();
public slots:

    void sendVoice();
    void udpConn();

};


#endif // CLIENTUDP_H
