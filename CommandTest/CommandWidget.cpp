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
{
	initialize();
}

CommandWidget::~CommandWidget()
{
}

void CommandWidget::initialize()
{
	buttons_ = {
		new CommandButton(CommandItem::Music),
		new CommandButton(CommandItem::Setting),
		new CommandButton(CommandItem::Message),
		new CommandButton(CommandItem::Navigation),
		new CommandButton(CommandItem::Warning)
	};
	makeWidgets();
	assert(buttonContainer_);
	addButtons();
}

void CommandWidget::addButtons()
{
	for(auto i = 0; i != 3; ++i)
	{
		buttonContainer_->addWidget(buttons_[i]);
		shownButtons_.push_back(buttons_[i]);
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

//int CommandWidget::getIndex()
//{
//	auto w = shownButtons_.front();
//	return ::getIndex(buttons_, w);
//}

//int CommandWidget::getLastIndex()
//{
//	auto w = shownButtons_.end();
//	return ::getIndex(buttons_, w);
//}

//void CommandWidget::removeWidgets()
//{
//
//}

void CommandWidget::leftShift()
{
	addLastOne();
	removeFirstOne();
}

void showHidden(const QObjectList& list)
{
	qDebug() << list.size();
	for(auto child : list)
	{
		auto w = dynamic_cast<QWidget*>(child);
		if (w == NULL)
			continue;
		qDebug() << w->isHidden();
	}
}	

void CommandWidget::addLastOne()
{
	int index = ::getIndex(buttons_, shownButtons_.back());
	if (index == buttons_.size() - 1)
		index = 0;
	buttonContainer_->addWidget(buttons_[index + 1]);
	shownButtons_.push_back(buttons_[index + 1]);
	shownButtons_.back()->setVisible(true);
}

void CommandWidget::removeFirstOne()
{
	auto w = shownButtons_.front();
	buttonContainer_->removeWidget(shownButtons_.front());
	shownButtons_.pop_front();
	w->setVisible(false);
	showHidden(children());
}

void CommandWidget::rightShift()
{
	addFirstOne();
	removeLastOne();
}

void CommandWidget::addFirstOne()
{
	int index = ::getIndex(buttons, shownButtons_.front());
	if (index == 0)
		index = buttons_.size() - 1;
	buttonContainer_->addWidget(buttons_[index + 1]);

}

void CommandWidget::removeLastOne()
{
}
