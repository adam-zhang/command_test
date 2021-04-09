/********************************************************************************
> FileName:	GlobalSetting.h
> Author:	Mingping Zhang
> Email:	mingpingzhang@163.com
> Create Time:	Fri Apr  9 13:43:37 2021
********************************************************************************/
#ifndef __GLOBALSETTING__H
#define __GLOBALSETTING__H

#include "Theme.h"

class GlobalSetting
{
private:
	GlobalSetting();
	~GlobalSetting();
private:
	static Theme theme_;
public:
	static Theme theme()
	{ return theme_;}
	void setTheme(Theme theme)
	{ theme_ = theme;}

};


#endif//__GLOBALSETTING__H
