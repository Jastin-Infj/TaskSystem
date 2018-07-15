#include <iostream>
#include <string>
#include "ResourceManager.h"

/*コンストラクタ*/
DrawOrder::DrawOrder()
{
#if (_DEBUG)
	std::cout << "DrawOrder()" << std::endl;
#endif // (_DEBUG)
}
/*デストラクタ*/
DrawOrder::~DrawOrder()
{
#if (_DEBUG)
	std::cout << "~DrawOrder()" << std::endl;
#endif // (_DEBUG)
}
/*描画順を設定します*/
void DrawOrder::setDrawOrder(float order_)
{
	if (order_ >= 1.0f)
	{
		order_ = 1.0f;
	}
	else if (order_ < 0.0f)
	{
		order_ = 0.0f;
	}
	this->order = order_;
}
/*描画順を返します*/
const float DrawOrder::getDrawOrder()const
{
	return this->order;
}
/*描画IDを設定します*/
void DrawOrder::setDrawOrderID(int& orderid_)
{
	this->id = orderid_;
}
/*描画IDを返します*/
int DrawOrder::getDrawOrderID()const
{
	return this->id;
}


/* コンストラクタ */
ResourceManager::ResourceManager()
{
#if (_DEBUG)
	std::cout << "ResourceManager()" << std::endl;
#endif // (_DEBUG)

}
/* デストラクタ */
ResourceManager::~ResourceManager()
{
#if (_DEBUG)
	std::cout << "~ResourceManager()" << std::endl;
#endif // (_DEBUG)
	this->DeleteResource();
}
/*テクスチャをシステムに登録します*/
void ResourceManager::setTextrue(const std::string& texname_,Textrue* image_)
{
	/*既存の名前があった場合は関数を終了させる*/
	for (auto it = this->textrues.begin(); it != this->textrues.end(); ++it)
	{
		if ((*it).first == texname_)
		{
			return;
		}
	}

	std::pair<std::string, Textrue*> textrue;
	textrue.first = texname_;
	textrue.second = image_;
	this->textrues.push_back(textrue);
}
/*サウンドをシステムに登録します*/
void ResourceManager::setSound(const std::string& soundname_, Sound* sound_)
{
	for (auto it = this->sounds.begin(); it != this->sounds.end(); ++it)
	{
		if ((*it).first == soundname_)
		{
			return;
		}
	}

	std::pair<std::string, Sound*>  sound;
	sound.first = soundname_;
	sound.second = sound_;
	this->sounds.push_back(sound);
}
/*登録してあるテクスチャから指定されたテクスチャを返します*/
Textrue* ResourceManager::getTextrue(const std::string& texname_)const
{
	for (auto it = this->textrues.begin(); it != this->textrues.end(); ++it)
	{
		if ((*it).first == texname_)
		{
			return (*it).second;
		}
	}
	return nullptr;
}
/*登録してあるサウンドから指定されたサウンドを返します*/
Sound* ResourceManager::getSound(const std::string& texname_)const
{
	for (auto it = this->sounds.begin(); it != this->sounds.end(); ++it)
	{
		if ((*it).first == texname_)
		{
			return (*it).second;
		}
	}
	return nullptr;
}
/* 登録してあるテクスチャを削除します */
void ResourceManager::DeleteTextrue()
{
	this->textrues.clear();
}
/*登録してあるサウンドを削除をします*/
void ResourceManager::DeleteSound()
{
	this->sounds.clear();
}
/*リソースを全削除をします*/
void ResourceManager::DeleteResource()
{
	this->DeleteTextrue();
	this->DeleteSound();
}