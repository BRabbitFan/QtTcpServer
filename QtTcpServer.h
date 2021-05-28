#pragma once

#include <QtWidgets/QDialog>
//#include "ui_QtTcpServer.h"

#include <QGridLayout>
#include <QListWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

#include "ServerHandler.h"

class QtTcpServer : public QDialog {
  Q_OBJECT

public:
  QtTcpServer(QWidget *parent = Q_NULLPTR);

public Q_SLOTS:
  void createServer();
  void showMessage(QString);

private:
  //Ui::QtTcpServerClass ui;

  QGridLayout *mainLayout;

  QListWidget *msgListWidget;

  QLabel *addrLabel;
  QLabel *portLabel;
  QLineEdit *portLineEdit;

  QPushButton *createRoomBtn;

  void initGui();

  
  QString addr;
  int port;
  
  ServerHandler *server;

};
