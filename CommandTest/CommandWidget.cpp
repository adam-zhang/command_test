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
#include "WidgetAssistant.h"
#include "Shifter.h"
#include <QHBoxLayout>
#include <QDebug>
#include <cassert>

CommandWidget::CommandWidget(QWidget* parent)
	: QWidget(parent)
{
	initialize();
}

CommandWidget::~CommandWidget()
{
}

void CommandWidget::initialize()
{
	WidgetAssistant::setBackgroundColor(this, Qt::green);
	items_ = {
		CommandItem::Setting,
		CommandItem::Music,
		CommandItem::Message,
		CommandItem::Navigation,
		CommandItem::Warning
	};
	setFixedWidth(40 * items_.size());
	setFixedHeight(40);
	makeWidgets();
	addButtons();
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
	for(int i = 0; i != items_.size(); ++i)
	{
		CommandItem item = getItem(items_, i); 
		auto w = new CommandButton(item, this);
		w->setGeometry(i * 40, 0, 40, 40);
		buttons_.push_back(w);
	}
}

void CommandWidget::makeWidgets()
{
	auto layout = new QHBoxLayout(this);
	layout->addStretch();
	layout->addStretch();
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


void CommandWidget::shiftToLeft()
{
	cloneLeft();
	shiftLeft();
}

void CommandWidget::cloneLeft()
{
	auto p = buttons_[0]->clone();
	int x = buttons_[0]->geometry().width() * buttons_.size();
	int y = buttons_[0]->geometry().y();
	int w = buttons_[0]->geometry().width();
	int h = buttons_[0]->geometry().height();
	p->setGeometry(x, y, w, h);
	//p->show();
	buttons_.push_back(p);
}



void CommandWidget::shiftLeft()
{
	shifter_ = std::make_shared<Shifter>(Direction::Left, buttons_);
	connect(shifter_.get(), &Shifter::done, this, &CommandWidget::onShifterDone);
}

void CommandWidget::onShifterDone(CommandButton* button)
{
	button->deleteLater();
	buttons_.erase(std::find(buttons_.begin(), buttons_.end(), button));
}

void CommandWidget::cloneRight()
{
	auto p = buttons_[buttons_.size() - 1]->clone();
	int x = -buttons_[0]->geometry().width();
	int y = buttons_[0]->geometry().y();
	int w = buttons_[0]->geometry().width();
	int h = buttons_[0]->geometry().height();
	p->setGeometry(x, y, w, h);
	buttons_.emplace(buttons_.begin(), p);
	assert(buttons_[0] == p);
}



void CommandWidget::shiftToRight()
{
	cloneRight();
	shiftRight();
}






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

CommandItem CommandWidget::centralItem()
{ return buttons_[1]->item();}

void increaseItems(std::list<CommandItem>& items)
{
	auto i = items.back();
	items.pop_back();
	items.push_front(i);
}

void CommandWidget::shiftRight()
{
	shifter_ = std::make_shared<Shifter>(Direction::Right, buttons_);
	connect(shifter_.get(), &Shifter::done, this, &CommandWidget::onShifterDone);
}

