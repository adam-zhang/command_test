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
#include "CommandItem.h"

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
	void removeButtons();
	QLayout* makeButtonContainer();
	int getIndex();
	int getLastIndex();
	void removeWidgets();
	void hideButtons();
	void showButtons();
	void leftShiftButtons();
	void rightShiftButtons();
private:
	QLayout* buttonContainer_;
	int current_;
private:
	std::list<CommandItem> items_;
	std::vector<CommandButton*> buttons_;
public:
	void leftShift();
	void rightShift();
	CommandItem centralItem();
};
#endif//__COMMANDWIDGET__H
