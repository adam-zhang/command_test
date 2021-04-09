/********************************************************************************
> FileName:	ContentWidget.h
> Author:	Mingping Zhang
> Email:	mingpingzhang@163.com
> Create Time:	Fri Apr  9 13:24:57 2021
********************************************************************************/
#ifndef __CONTENTWIDGET__H
#define __CONTENTWIDGET__H

#include <QWidget>

class ContentWidget : public QWidget
{
	Q_OBJECT
public:
	ContentWidget(QWidget* parent = 0);
	~ContentWidget();
};
#endif//__CONTENTWIDGET__H
