#ifndef GLOBAL_H
#define GLOBAL_H
#include <winsock2.h>
#include <iostream>
#include "recording.h"
#include "socket/circularbuffer.h"

#define BUFMAX  128
#define BUFSIZE 8192
#define DATA_BUFSIZE 8192
#define MAXADDRSTR  16

#define TCP_DEFAULT_HOST "127.0.0.1"
#define TCP_DEFAULT_PORT 7000

#define TIMECAST_ADDR "234.5.6.7"
#define TIMECAST_PORT 8910

#define UDP_DEFAULT_PORT 8000

//client side type flag
#define MUSIC_DOWNLOAD 10001
#define MUSIC_REQUEST  10002
#define VOICE_ENABLE   10003

//server side type flag
#define MUSIC_LIST  20001
#define CLIENT_LIST 20002


#define UDP_CLIENT 1001
#define MULTI_CLIENT 1002

typedef struct _SOCKET_INFORMATION {
   OVERLAPPED Overlapped;
   SOCKET Socket;
   CHAR Buffer[DATA_BUFSIZE];
   WSABUF DataBuf;
   DWORD BytesSEND;
   DWORD BytesRECV;
} SOCKET_INFORMATION, * LPSOCKET_INFORMATION;

typedef struct TCP_MESSSAGE{
    int type;
    char name[BUFSIZE];
    char data[DATA_BUFSIZE];
    boolean _end;

}TCP_MESG;

//extern Recording *gRecording;

extern boolean _TCPconnectOn;
extern boolean _UDPconnectOn;
extern boolean _MULTIconnectOn;
extern boolean _VoiceChat;

extern SOCKET multiSock;
extern SOCKET udpSock;
extern SOCKET tcpSock;

extern int sockPort;
//static SOCKET hSocket;
extern struct CBuffer CBuf;
extern struct CBuffer CBufOut;
extern struct CBuffer UDPbuf;

extern SOCKADDR_IN stLclAddr,  InternetAddr;

#endif // GLOBAL_H
