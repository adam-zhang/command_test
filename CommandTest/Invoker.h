/********************************************************************************
> FileName:	Invoker.h
> Author:	Mingping Zhang
> Email:	mingpingzhang@163.com
> Create Time:	Fri Apr  9 11:41:14 2021
********************************************************************************/
#ifndef __INVOKER__H
#define __INVOKER__H

#include <QWidget>
#include "CommandItem.h"

class Invoker : public QWidget
{
	Q_OBJECT
public:
	Invoker(QWidget* parent = 0);
	~Invoker();
private:
	void initialize();
private slots:
	void onLeftClicked();
	void onRightClicked();
	void onCenterClicked();
signals:
	void leftButtonClicked();
	void rightButtonClicked();
	void centerButtonClicked(CommandItem);

};
#endif//__INVOKER__H
