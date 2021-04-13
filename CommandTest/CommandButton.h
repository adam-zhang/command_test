/********************************************************************************
> FileName:	CommandButton.h
> Author:	Mingping Zhang
> Email:	mingpingzhang@163.com
> Create Time:	Fri Apr  9 13:31:41 2021
********************************************************************************/
#ifndef __COMMANDBUTTON__H
#define __COMMANDBUTTON__H

#include <QLabel>
#include "CommandItem.h"

class CommandButton : public QLabel
{
	Q_OBJECT
public:
	CommandButton(CommandItem item, QWidget* parent = 0);
	virtual ~CommandButton();
private:
	CommandItem item_;
public:
	CommandItem item()
	{ return item_;}
	CommandButton* clone();
private:
	void initialize();
};
#endif//__COMMANDBUTTON__H
