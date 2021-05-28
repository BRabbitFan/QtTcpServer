#include "ServerHandler.h"

ServerHandler::ServerHandler(QObject *parent, int port) : QTcpServer(parent) {
  QTcpServer::listen(QHostAddress::Any, port);
}

void ServerHandler::incomingConnection(int socketDescriptor) {
  ClientSocket *newClient = new ClientSocket(this);

  connect(newClient, &ClientSocket::dataReceived, this, &ServerHandler::recvMessage);
  connect(newClient, &ClientSocket::clientDisconnected, this, &ServerHandler::removeClient);
  
  newClient->setSocketDescriptor(socketDescriptor);
  socketList.append(newClient);
}

void ServerHandler::recvMessage(QByteArray msgBytes) {
  emit messageReceived(msgBytes.data());

  for (ClientSocket *client : socketList) {
    if (client->write(msgBytes, msgBytes.size()) != msgBytes.size()) {
      // TODO
      continue;
    }
  }
}

void ServerHandler::removeClient(int socketDescriptor) {
  for (ClientSocket *client : socketList) {
    if ((int)client->socketDescriptor() == socketDescriptor) {
      socketList.removeOne(client);
    }
  }
}