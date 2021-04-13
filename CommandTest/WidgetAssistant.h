/********************************************************************************
> FileName:	WidgetAssistant.h
> Author:	Mingping Zhang
> Email:	mingpingzhang@163.com
> Create Time:	Tue Mar 30 15:11:47 2021
********************************************************************************/
#ifndef __WIDGETASSISTANT__H
#define __WIDGETASSISTANT__H

#include <Qt>

class QWidget;
class QColor;

class WidgetAssistant
{
private:
	WidgetAssistant();
	~WidgetAssistant();
public:
	static void setBackgroundColor(QWidget* widget, Qt::GlobalColor value);
	static void setBackgroundColor(QWidget* widget, const QColor& value);
	static void setForegroundColor(QWidget* widget, Qt::GlobalColor value);
	static void setForegroundColor(QWidget* widget, const QColor& value);
	static void setTransparentWinget(QWidget* widget);

};
#endif//__WIDGETASSISTANT__H
