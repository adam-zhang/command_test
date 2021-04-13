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
#include <memory>
#include "CommandItem.h"

class CommandButton;
class Shifter;

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
	int getIndex();
	int getLastIndex();
	void removeWidgets();
	void showButtons();
	void leftShiftButtons();
	void rightShiftButtons();
	void createTimer();
	void cloneLeft();
	void cloneRight();
	void shiftLeft();
	void shiftRight();
private slots:
	void onShifterDone(CommandButton*);
private:
	std::shared_ptr<Shifter> shifter_;
	std::list<CommandItem> items_;
	std::vector<CommandButton*> buttons_;
public:
	void shiftToLeft();
	void shiftToRight();
	CommandItem centralItem();
};
#endif//__COMMANDWIDGET__H
