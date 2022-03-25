#include "chatCore.h"

chatCore::chatCore(QObject* parent) : QObject(parent)
{
	chatWidget_ = new chatWidget(this);
	chatWidget_->show();
}

void chatCore::init()
{
	static chatCore chatCore_;
}
