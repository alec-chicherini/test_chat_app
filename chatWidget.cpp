#include "chatWidget.h"
chatWidget::chatWidget(QObject* parent) :QWidget(qobject_cast<QWidget*>(parent))
{
	QGridLayout* layout = new QGridLayout(this);
	
	layout->setAlignment(Qt::AlignLeft);
	layout->setColumnStretch(0, 0);
	layout->setColumnStretch(1, 1);
	layout->setColumnStretch(2, 0);

	QLabel* labelLocalPort = new QLabel(this);
	QLineEdit* editLocalPort = new QLineEdit(this);
	labelLocalPort->setBuddy(editLocalPort);
	labelLocalPort->setText(tr("Локальный порт"));

	QLabel* labelRemotePort = new QLabel(this);
	QLineEdit* editRemotePort = new QLineEdit(this);
	labelRemotePort->setBuddy(editRemotePort);
	labelRemotePort->setText(tr("Удалённый порт"));

	QPushButton* btnConnect = new QPushButton(this);
	btnConnect->setText(tr("Подключиться"));

	QPushButton* btnDisconnect = new QPushButton(this);
	btnDisconnect->setText(tr("Отключиться"));

	QTextEdit* chatWindow = new QTextEdit(this);
	QLineEdit* editMessage = new QLineEdit(this);
	QPushButton* btnSend = new QPushButton(this);
	btnSend->setText(tr("Отправить"));

	layout->addWidget(labelLocalPort,  0, 0, Qt::AlignLeft);
	layout->addWidget(editLocalPort,   0, 1);
	layout->addWidget(btnConnect,      0, 2);

	layout->addWidget(labelRemotePort, 1, 0, Qt::AlignLeft);
	layout->addWidget(editRemotePort,  1, 1);
	layout->addWidget(btnDisconnect,   1, 2);

	layout->addWidget(chatWindow,      2, 0, 1, 3);

	layout->addWidget(editMessage,     3, 0,1,2);
	layout->addWidget(btnSend,         3, 2);

	setLayout(layout);
}