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
#include "CommandItem.h"
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
	connect(invoker, &Invoker::centerButtonClicked, this, &MainWidget::onCenterButtonClicked);
	layout->addWidget(invoker);
	commandWidget_ = new CommandWidget;
	layout->addWidget(commandWidget_);
	contentWidget_ = new ContentWidget;
	layout->addWidget(contentWidget_);
}

void MainWidget::onCenterButtonClicked()
{
	auto item = commandWidget_->centralItem();
	contentWidget_->setItem(item);
}

void MainWidget::onLeftButtonClicked()
{
	commandWidget_->shiftToLeft();
}

void MainWidget::onRightButtonClicked()
{
	commandWidget_->shiftToRight();
}
