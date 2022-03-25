#include <QObject>
#include "chatWidget.h"
class chatCore : public QObject
{
private:
	chatCore(QObject* parent = nullptr);
	chatWidget* chatWidget_;
public:
	static void init();
};