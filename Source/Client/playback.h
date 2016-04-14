#ifndef PLAYBACK_H
#define PLAYBACK_H

#include <QObject>
#include <QIODevice>
#include <QAudioDeviceInfo>
#include <QAudioOutput>
#include <QByteArray>
#include <QFile>
#include <QDebug>
#include <QtEndian>
#include <QByteArray>
#include <QBuffer>
#include <QtConcurrent/QtConcurrent>
#include <QDataStream>
#include "../Server/socket/UDPSendWorker.h"
#include "socket/circularbuffer.h"
#include "global.h"

#include<string>
#include<iostream>

class Playback : public QObject
{
    Q_OBJECT

public:
    Playback(struct CBuffer * buffer);
    ~Playback();
FILE *fstream;

public slots:
    void runthis();
    //void read_data(qint64 pos);
    void read_data();
    void updateVolume(float vol);

signals:
    void CanSendNextData(qint64 pos, QByteArray qba);

private:
    QAudioFormat m_format;
    QAudioDeviceInfo m_device;
    QAudioOutput *m_audioOutput;

    QByteArray qByteArray;
    QBuffer qBuf;
    struct CBuffer *playBuf;
    UDPSendWorker *udpSendWorker;
};

#endif // PLAYBACK_H
