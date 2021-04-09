/********************************************************************************
> FileName:	MainWidget.h
> Author:	Mingping Zhang
> Email:	mingpingzhang@163.com
> Create Time:	Fri Apr  9 11:22:11 2021
********************************************************************************/
#ifndef __MAINWIDGET__H
#define __MAINWIDGET__H

#include <QWidget>

class CommandWidget;

class MainWidget : public QWidget
{
	Q_OBJECT
public:
	MainWidget(QWidget* = 0);
	~MainWidget();
private:
	void initialize();
private:
	CommandWidget* commandWidget_ = 0;
private slots:
	void onLeftButtonClicked();
	void onRightButtonClicked();
};
#endif//__MAINWIDGET__H
