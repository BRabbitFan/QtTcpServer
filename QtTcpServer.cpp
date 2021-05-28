#include "QtTcpServer.h"

#include <QtNetwork/QHostInfo>

namespace MSG_TYPE {
  const int TYPE_LEN = 1;
  const QString TEXT = "1";
  const QString AUDIO = "2";
}

QtTcpServer::QtTcpServer(QWidget *parent) : QDialog(parent) {
  //ui.setupUi(this);
  
  addr = QHostInfo::fromName(QHostInfo::localHostName()).addresses().at(1).toString();
  port = 8010;
  
  initGui();

  connect(createRoomBtn, &QPushButton::clicked, this, &QtTcpServer::createServer);
}

void QtTcpServer::createServer() {
  server = new ServerHandler(this, port);
  connect(server, &ServerHandler::messageReceived, this, &QtTcpServer::showMessage);
  createRoomBtn->setEnabled(false);
  portLineEdit->setEnabled(false);
}

void QtTcpServer::showMessage(QString msgStr) {

  QString msgType = msgStr.left(MSG_TYPE::TYPE_LEN);
  QString msgVal = msgStr.right(msgStr.length() - MSG_TYPE::TYPE_LEN);

  if (msgType == MSG_TYPE::TEXT) {
    msgListWidget->addItem(msgVal);
  } else if (msgType == MSG_TYPE::AUDIO) {
    msgListWidget->addItem("[Audio]");
  } else {
    // TODO
  }
}

void QtTcpServer::initGui() {
  setWindowTitle(tr("Qt TCP Server"));

  mainLayout = new QGridLayout(this);

  msgListWidget = new QListWidget();
  mainLayout->addWidget(msgListWidget, 0, 0, 1, 4);

  addrLabel = new QLabel();
  QString tipText = "ip : ";
  addrLabel->setText(tipText.append(addr));
  mainLayout->addWidget(addrLabel, 1, 0, 1, 2);

  portLabel = new QLabel();
  portLabel->setText(tr(" | port : "));
  mainLayout->addWidget(portLabel, 1, 2, 1, 1);

  portLineEdit = new QLineEdit();
  portLineEdit->setFixedWidth(65);
  portLineEdit->setText(QString::number(port));
  mainLayout->addWidget(portLineEdit, 1, 3, 1, 1);

  createRoomBtn = new QPushButton();
  createRoomBtn->setText(tr("create room"));
  mainLayout->addWidget(createRoomBtn, 2, 1, 1, 2);
}