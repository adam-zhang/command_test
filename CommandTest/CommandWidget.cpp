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
	auto i = ::getIndex(buttons_, shownButtons_.back());
	Logger::write("i", i);
	if (i == buttons_.size())
		i = 0;
	buttonContainer_->addWidget(buttons_[i + 1]);
	buttonContainer_->removeWidget(shownButtons_.front());
	shownButtons_.pop_front();
	shownButtons_.push_back(buttons_[i]);
}

void CommandWidget::rightShift()
{
}
