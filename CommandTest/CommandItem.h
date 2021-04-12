/********************************************************************************
> FileName:	CommandItem.h
> Author:	Mingping Zhang
> Email:	mingpingzhang@163.com
> Create Time:	Fri Apr  9 13:28:25 2021
********************************************************************************/
#ifndef __COMMANDITEM__H
#define __COMMANDITEM__H

#include <ostream>
#include <QDebug>

enum class CommandItem
{
	Setting,
	Music,
	Message,
	Navigation,
	Warning,
	None,
};


#endif//__COMMANDITEM__H
