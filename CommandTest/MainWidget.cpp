/********************************************************************************
> FileName:	MainWidget.cpp
> Author:	Mingping Zhang
> Email:	mingpingzhang@163.com
> Create Time:	Fri Apr  9 11:22:11 2021
********************************************************************************/

#include "MainWidget.h"
#include "Invoker.h"
#include "CommandWidget.h"
#include "ContentWidget.h"
#include <QLabel>
#include <QVBoxLayout>

MainWidget::MainWidget(QWidget* parent)
	: QWidget(parent)
{
	initialize();
}

MainWidget::~MainWidget()
{
}

void MainWidget::initialize()
{
	auto layout = new QVBoxLayout(this);
	auto invoker = new Invoker;
	connect(invoker, &Invoker::leftButtonClicked, this, &MainWidget::onLeftButtonClicked);
	connect(invoker, &Invoker::rightButtonClicked, this, &MainWidget::onRightButtonClicked);
	layout->addWidget(invoker);
	commandWidget_ = new CommandWidget;
	layout->addWidget(commandWidget_);
	layout->addWidget(new ContentWidget);
}

void MainWidget::onLeftButtonClicked()
{
	commandWidget_->leftShift();
}

void MainWidget::onRightButtonClicked()
{
	commandWidget_->rightShift();
}
