#include "CircularBuffer.h"
#include<QDebug>


void initBuffer(CBufs * Buf){
    Buf->_count = 0;
    Buf->_writePtr = &Buf->buffer;
    Buf->_readPtr = &Buf->buffer;
    Buf->_endPtr = &Buf->buffer[CIRBUFSIZE*CIRBUFMAX];
    std::memset(Buf->buffer, '\0',CIRBUFSIZE*CIRBUFMAX);
    qDebug()<<"BUFFEr SIZE: " << sizeof(Buf->buffer);
}

void write_buffer(CBufs * Buf, const void * data){

    qDebug()<<"write buf : " << (char*)data;
    if(Buf->_count == CIRBUFMAX ){
        qDebug() << "SIZE FULL";
        return;
    }
    if(Buf->_writePtr == Buf->_endPtr){
        qDebug() << "#######BUF END~!~~!~";
    }

    std::memcpy(Buf->_writePtr, (char*)data, CIRBUFSIZE);
    qDebug()<<"WHAT IS wrteptr?" << (char*)(Buf->_writePtr);
    Buf->_writePtr+=CIRBUFSIZE;
    if(Buf->_writePtr == Buf->_endPtr){
        qDebug() << "******END POINT";
        Buf->_writePtr = &Buf->buffer;
    }
    Buf->_count++;
}

void read_buffer(CBufs * Buf, void * data){
    //qDebug()<<"READ buf " << Buf->_count;
    if(Buf->_count == 0)
        return ;
    std::memcpy(data, Buf->_readPtr, CIRBUFSIZE);
    std::memset(Buf->_readPtr, '\0',CIRBUFSIZE);
    Buf->_readPtr+=CIRBUFSIZE;
    if(Buf->_readPtr == Buf->_endPtr)
        Buf->_readPtr = &Buf->buffer;
    Buf->_count--;
    //qDebug()<<"read buf : " << (char*)data << " left "<< Buf->_count;
}

void clean_buffer(CBufs * Buf){
    std::memset(Buf->buffer, '\0', sizeof(Buf->buffer));
    Buf->_writePtr = Buf->buffer;
    Buf->_readPtr = Buf->buffer;
}
