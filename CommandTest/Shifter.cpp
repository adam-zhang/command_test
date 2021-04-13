/********************************************************************************
> FileName:	Shifter.cpp
> Author:	Mingping Zhang
> Email:	mingpingzhang@163.com
> Create Time:	Mon Apr 12 18:24:50 2021
********************************************************************************/

#include "Shifter.h"
#include "CommandButton.h"
#include <QTimer>

Shifter::Shifter(Direction direction, const std::vector<CommandButton*>& buttons)
	: direction_(direction)
	  , buttons_(buttons)
{
	initialize();
}

Shifter::~Shifter()
{

}

void Shifter::initialize()
{
	timer_ = std::make_shared<QTimer>();
	timer_->setInterval(10);
	connect(timer_.get(), &QTimer::timeout, this, &Shifter::onTimeOut);
	timer_->start();
}

void Shifter::onTimeOut()
{
	if (direction_ == Direction::Left)
		shiftLeft();
	else
		shiftRight();
}


void Shifter::shiftLeft()
{
	for(auto button : buttons_)
	{
		auto rect = button->geometry();
		auto w = rect.width();
		rect.setX(rect.x() - 1);
		rect.setWidth(w);
		button->setGeometry(rect);
	}
	if (buttons_[1]->geometry().x() <= 0)
	{
		timer_->stop();
		emit done(buttons_[0]);
	}
}

void Shifter::shiftRight()
{
	for(auto button : buttons_)
	{
		auto rect = button->geometry();
		auto w = rect.width();
		rect.setX(rect.x() + 1);
		rect.setWidth(w);
		button->setGeometry(rect);
	}
	if (buttons_[0]->geometry().x() > 0)
	{
		timer_->stop();
		emit done(buttons_[buttons_.size() - 1]);
	}
}
