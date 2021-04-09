/********************************************************************************
> FileName:	ImagesFactory.h
> Author:	Mingping Zhang
> Email:	mingpingzhang@163.com
> Create Time:	Fri Apr  9 11:28:07 2021
********************************************************************************/
#ifndef __IMAGESFACTORY__H
#define __IMAGESFACTORY__H

#include <QString>
#include <memory>

class ImagesFactory
{
public:
	ImagesFactory();
	~ImagesFactory();
public:
	virtual QString music() = 0;
	virtual QString navigation() = 0;
	virtual QString setting() = 0;
	virtual QString message() = 0;
	virtual QString warning() = 0;
};

class BladeImagesFactory : public ImagesFactory
{
	public:
		virtual QString music() 
		{ return QString(":/resources/images/blade/music_icon.png");}
		virtual QString navigation()
		{ return QString(":/resources/images/blade/navigation_icon.png");}
		virtual QString setting()
		{ return QString(":/resources/images/blade/setting_icon.png");}
		virtual QString message()
		{ return QString(":/resources/images/blade/message_icon.png");}
		virtual QString warning()
		{ return QString(":/resources/images/blade/warning_icon.png");}

};

class CometImagesFactory : public ImagesFactory
{
	public:
		virtual QString music() 
		{ return QString(":/resources/images/comet/music_icon.png");}
		virtual QString navigation()
		{ return QString(":/resources/images/comet/navigation_icon.png");}
		virtual QString setting()
		{ return QString(":/resources/images/comet/setting_icon.png");}
		virtual QString message()
		{ return QString(":/resources/images/comet/message_icon.png");}
		virtual QString warning()
		{ return QString(":/resources/images/comet/warning_icon.png");}

};

std::shared_ptr<ImagesFactory> getImagesFactory();

#endif//__IMAGESFACTORY__H
