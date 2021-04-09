/********************************************************************************
> FileName:	CommandButton.cpp
> Author:	Mingping Zhang
> Email:	mingpingzhang@163.com
> Create Time:	Fri Apr  9 13:31:41 2021
********************************************************************************/

#include "CommandButton.h"
#include "ImagesFactory.h"
#include "Logger.h"
#include <QPixmap>
#include <cassert>

CommandButton::CommandButton(CommandItem item, QWidget* parent)
	: QLabel(parent)
	  , item_(item)
{
	initialize();
}

CommandButton::~CommandButton()
{
}

QString getImage(CommandItem& item)
{
	switch(item)
	{
		case CommandItem::Music:
			return getImagesFactory()->music();
		case CommandItem::Setting:
			return getImagesFactory()->setting();
		case CommandItem::Navigation:
			return getImagesFactory()->navigation();
		case CommandItem::Message:
			return getImagesFactory()->message();
		case CommandItem::Warning:
			return getImagesFactory()->warning();
	}
	assert(false);
	return QString();
}

void CommandButton::initialize()
{
	QPixmap pixmap(getImage(item_));
	Logger::write("item", int(item_));
	Logger::write("width", pixmap.width());
	Logger::write("height", pixmap.height());
	setPixmap(QPixmap(getImage(item_)));	
}


