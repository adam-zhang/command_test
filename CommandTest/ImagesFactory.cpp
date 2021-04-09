/********************************************************************************
> FileName:	ImagesFactory.cpp
> Author:	Mingping Zhang
> Email:	mingpingzhang@163.com
> Create Time:	Fri Apr  9 11:28:07 2021
********************************************************************************/

#include "ImagesFactory.h"
#include "GlobalSetting.h"

ImagesFactory::ImagesFactory()
{
}

ImagesFactory::~ImagesFactory()
{
}

std::shared_ptr<ImagesFactory> getImagesFactory()
{
	if (GlobalSetting::theme() == Theme::Comet)
		return std::make_shared<CometImagesFactory>();
	return std::make_shared<BladeImagesFactory>();
}
