#include "ClientSocket.h"

ClientSocket::ClientSocket(QObject *parent) : QTcpSocket(parent) {
  connect(this, &QIODevice::readyRead, this, &ClientSocket::recvData);
  connect(this, &QAbstractSocket::disconnected, this, &ClientSocket::disconnect);
}

void ClientSocket::recvData() {
  while (bytesAvailable() > 0) {
    QByteArray msgBytes = readAll();
    emit dataReceived(msgBytes);
  }
}

void ClientSocket::disconnect() {
  emit clientDisconnected(socketDescriptor());
}