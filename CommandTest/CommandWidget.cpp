/********************************************************************************
> FileName:	CommandWidget.cpp
> Author:	Mingping Zhang
> Email:	mingpingzhang@163.com
> Create Time:	Fri Apr  9 11:41:36 2021
********************************************************************************/

#include "CommandWidget.h"
#include "CommandButton.h"
#include "CommandItem.h"
#include "Logger.h"
#include <QHBoxLayout>
#include <QDebug>
#include <cassert>

CommandWidget::CommandWidget(QWidget* parent)
	: QWidget(parent)
	  , buttonContainer_(0)
	  , current_(0)
{
	initialize();
}

CommandWidget::~CommandWidget()
{
}

void CommandWidget::initialize()
{
	items_ = {
		CommandItem::Setting,
		CommandItem::Music,
		CommandItem::Message,
		CommandItem::Navigation,
		CommandItem::Warning
	};
	makeWidgets();
	assert(buttonContainer_);
	addButtons();
	hideButtons();
}

void CommandWidget::hideButtons()
{
	auto index = 0;
	for(auto i : buttons_)
	{
		if (index >= 3)
			i->hide();
		++index;
	}
}

CommandItem getItem(const std::list<CommandItem>& items, int index)
{
	int i = 0;
	for(auto w : items)
	{
		if (i == index)
			return w;
		++i;
	}
	assert(false);
	return CommandItem::None;
}

void CommandWidget::addButtons()
{
	for(int i = 0; i != 3; ++i)
	{
		CommandItem item = getItem(items_, i); 
		auto w = new CommandButton(item);
		buttons_.push_back(w);
		buttonContainer_->addWidget(w);
	}
}

void CommandWidget::makeWidgets()
{
	auto layout = new QHBoxLayout(this);
	layout->addStretch();
	layout->addLayout(makeButtonContainer());
	layout->addStretch();
}

QLayout* CommandWidget::makeButtonContainer()
{
	buttonContainer_ = new QHBoxLayout;
	return buttonContainer_;
}



int getIndex(const std::vector<CommandButton*>& buttons, CommandButton* button)
{
	for(auto i = 0; i != buttons.size(); ++i)
		if (button == buttons[i])
			return i;
	assert(false);
	return -1;
}

QString toString(CommandItem item)
{
	std::map<CommandItem, QString> m{
		{CommandItem::Music, "Music"},
			{CommandItem::Setting, "Setting"},
			{CommandItem::Message, "Message"},
			{CommandItem::Navigation, "Navigation"},
			{CommandItem::Warning, "Warning"}};
	return m[item];
}

void showOrders(const std::list<CommandButton*>& buttons)
{
	for(auto button : buttons)
		qDebug() << toString(button->item()) << " " << button->isHidden();
	qDebug() << " ";
}

void decreaseItems(std::list<CommandItem>& list)
{
	auto item = list.front();
	list.pop_front();
	list.push_back(item);
}


void CommandWidget::leftShift()
{
	removeButtons();
	decreaseItems(items_);
	addButtons();
}

void CommandWidget::showButtons()
{
	for(auto w : buttons_)
	{
		w->show();
	}
}



//void CommandWidget::showFirstOne()
//{
//
//}

void showHidden(const QObjectList& list)
{
	for(auto child : list)
	{
		auto w = dynamic_cast<QWidget*>(child);
		if (w == NULL)
			continue;
		qDebug() << w->isHidden();
	}
}	


void increaseItems(std::list<CommandItem>& items)
{
	auto i = items.back();
	items.pop_back();
	items.push_front(i);
}

void CommandWidget::rightShift()
{
	removeButtons();
	increaseItems(items_);
	addButtons();
}

void CommandWidget::removeButtons()
{
	for(auto button : buttons_)
		button->deleteLater();
	buttons_.clear();
}
