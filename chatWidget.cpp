#include "chatWidget.h"

chatWidget::chatWidget(QObject* parent) :QWidget(qobject_cast<QWidget*>(parent))
{
	QMessageBox messageBox;
	messageBox.setText("This is message");
	messageBox.exec();
}