#include <QApplication>
#include "chatCore.h"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	chatCore::init();
	return app.exec();
}