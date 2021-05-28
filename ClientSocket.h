#pragma once

#include <QtNetwork/QTcpSocket>

class ClientSocket : public QTcpSocket {
  Q_OBJECT

public:
  ClientSocket(QObject *parent = Q_NULLPTR);

Q_SIGNALS:
  void clientDisconnected(int);
  void dataReceived(QByteArray);

public Q_SLOTS:
  void recvData();
  void disconnect();

private:


};