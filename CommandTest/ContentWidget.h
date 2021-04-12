/********************************************************************************
> FileName:	ContentWidget.h
> Author:	Mingping Zhang
> Email:	mingpingzhang@163.com
> Create Time:	Fri Apr  9 13:24:57 2021
********************************************************************************/
#ifndef __CONTENTWIDGET__H
#define __CONTENTWIDGET__H

#include <QWidget>
#include "CommandItem.h"
class QLabel;

class ContentWidget : public QWidget
{
	Q_OBJECT
public:
	ContentWidget(QWidget* parent = 0);
	~ContentWidget();
private:
	void initialize();
public:
	void setItem(CommandItem item);
private:
	QLabel* label_ = 0;

};
#endif//__CONTENTWIDGET__H
