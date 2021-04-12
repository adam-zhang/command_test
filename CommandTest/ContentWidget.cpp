/********************************************************************************
> FileName:	ContentWidget.cpp
> Author:	Mingping Zhang
> Email:	mingpingzhang@163.com
> Create Time:	Fri Apr  9 13:24:57 2021
********************************************************************************/

#include "ContentWidget.h"
#include <cassert>
#include <QVBoxLayout>
#include <QLabel>

ContentWidget::ContentWidget(QWidget* parent)
	: QWidget(parent)
{
	initialize();
}

ContentWidget::~ContentWidget()
{
}

void ContentWidget::initialize()
{
	auto layout = new QVBoxLayout(this);
	layout->addStretch();
	auto l = new QLabel;
	layout->addWidget(l);
	layout->addStretch();
	label_ = l;
	assert(label_);
}

QString getItemString(CommandItem item)
{
	switch(item)
	{
		case CommandItem::Music:
			return "Music";
		case CommandItem::Setting:
			return "Setting";
		case CommandItem::Navigation:
			return "Navigation";
		case CommandItem::Message:
			return "Message";
		case CommandItem::Warning:
			return "Warning";
	}
	assert(false);
	return "";
}

void ContentWidget::setItem(CommandItem item)
{
	assert(label_);
	auto s = getItemString(item);
	label_->setText(s);
}
