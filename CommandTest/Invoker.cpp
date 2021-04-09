/********************************************************************************
> FileName:	Invoker.cpp
> Author:	Mingping Zhang
> Email:	mingpingzhang@163.com
> Create Time:	Fri Apr  9 11:41:14 2021
********************************************************************************/

#include "Invoker.h"
#include <QPushButton>
#include <QHBoxLayout>

Invoker::Invoker(QWidget* parent)
	: QWidget(parent)
{
	initialize();
}

Invoker::~Invoker()
{

}

void Invoker::initialize()
{
	auto layout = new QHBoxLayout(this);
	auto left = new QPushButton("<<");
	auto right = new QPushButton(">>");
	auto center = new QPushButton("Click Me");
	connect(left, &QPushButton::clicked, this, &Invoker::onLeftClicked);
	connect(right, &QPushButton::clicked, this, &Invoker::onRightClicked);
	connect(center, &QPushButton::clicked, this, &Invoker::onCenterClicked);
	layout->addWidget(left);
	layout->addWidget(center);
	layout->addWidget(right);
}

void Invoker::onLeftClicked()
{
	emit(leftButtonClicked());
}

void Invoker::onRightClicked()
{
	emit(rightButtonClicked());
}

void Invoker::onCenterClicked()
{
	//emit(centerButtonClicked());
}
