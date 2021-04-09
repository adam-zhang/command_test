/********************************************************************************
> FileName:	CommandWidget.h
> Author:	Mingping Zhang
> Email:	mingpingzhang@163.com
> Create Time:	Fri Apr  9 11:41:36 2021
********************************************************************************/
#ifndef __COMMANDWIDGET__H
#define __COMMANDWIDGET__H

#include <QWidget>
#include <vector>
#include <list>

class CommandButton;

class CommandWidget : public QWidget
{
	Q_OBJECT
public:
	CommandWidget(QWidget* parent = 0);
	~CommandWidget();
private:
	void initialize();
	void makeWidgets();
	void addButtons();
	QLayout* makeButtonContainer();
	int getIndex();
	int getLastIndex();
	void removeWidgets();
	//int getIndex(CommandButton*);
private:
	QLayout* buttonContainer_;
private:
	std::vector<CommandButton*> buttons_;
	std::list<CommandButton*> shownButtons_;
public:
	void leftShift();
	void rightShift();
};
#endif//__COMMANDWIDGET__H
