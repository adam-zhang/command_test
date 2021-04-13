/********************************************************************************
> FileName:	WidgetAssistant.cpp
> Author:	Mingping Zhang
> Email:	mingpingzhang@163.com
> Create Time:	Tue Mar 30 15:11:47 2021
********************************************************************************/

#include "WidgetAssistant.h"
#include <QWidget>
#include <QColor>

WidgetAssistant::WidgetAssistant()
{
}

WidgetAssistant::~WidgetAssistant()
{
}

void WidgetAssistant::setBackgroundColor(QWidget* widget, Qt::GlobalColor value)
{
	setBackgroundColor(widget, QColor(value));
}

void WidgetAssistant::setBackgroundColor(QWidget* widget, const QColor& value)
{
	widget->setAutoFillBackground(true);
	QPalette palette;
	palette.setBrush(QPalette::Window, QBrush(value));
	widget->setPalette(palette);
}

void WidgetAssistant::setForegroundColor(QWidget* widget, Qt::GlobalColor value)
{
	setForegroundColor(widget, QColor(value));
}

void WidgetAssistant::setForegroundColor(QWidget* widget, const QColor& value)
{
	QPalette palette;
	palette.setBrush(QPalette::WindowText, QBrush(value));
	widget->setPalette(palette);
}

void WidgetAssistant::setTransparentWinget(QWidget* widget)
{
	widget->setWindowOpacity(1);
	widget->setAttribute(Qt::WA_TranslucentBackground);
}
