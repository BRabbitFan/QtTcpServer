#pragma once

#include <QtNetwork/QTcpServer>

#include "ClientSocket.h"

class ServerHandler : public QTcpServer {
  Q_OBJECT

public:
  ServerHandler(QObject *parent = Q_NULLPTR, int port = 0);
  QList<ClientSocket *> socketList;

signals:
  void messageReceived(QString);

public Q_SLOTS:
  void recvMessage(QByteArray);
  void removeClient(int);

protected:
  void incomingConnection(int socketDescriptor);
};