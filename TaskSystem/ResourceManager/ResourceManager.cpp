#include <iostream>
#include <string>
#include "ResourceManager.h"

/*�R���X�g���N�^*/
DrawOrder::DrawOrder(){}
/*�f�X�g���N�^*/
DrawOrder::~DrawOrder(){}
/*�`�揇��ݒ肵�܂�*/
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
/*�`�揇��Ԃ��܂�*/
const float DrawOrder::getDrawOrder()const
{
	return this->order;
}
/*�`��ID��ݒ肵�܂�*/
void DrawOrder::setDrawOrderID(int& orderid_)
{
	this->id = orderid_;
}
/*�`��ID��Ԃ��܂�*/
int DrawOrder::getDrawOrderID()const
{
	return this->id;
}


/* �R���X�g���N�^ */
ResourceManager::ResourceManager()
{
#if (_DEBUG)
	std::cout << "ResourceManager()" << std::endl;
#endif // (_DEBUG)

}
/* �f�X�g���N�^ */
ResourceManager::~ResourceManager()
{
#if (_DEBUG)
	std::cout << "~ResourceManager()" << std::endl;
#endif // (_DEBUG)
	this->DeleteResource();
}
/*�e�N�X�`�����V�X�e���ɓo�^���܂�*/
void ResourceManager::setTexture(const std::string& texname_,const Texture& image_)
{
	/*�����̖��O���������ꍇ�͊֐����I��������*/
	for (auto it = this->textures.begin(); it != this->textures.end(); ++it)
	{
		if ((*it).first == texname_)
		{
			return;
		}
	}

	std::pair<std::string, Texture> textrue;
	textrue.first = texname_;
	textrue.second = image_;
	this->textures.push_back(textrue);
}
/*�T�E���h���V�X�e���ɓo�^���܂�*/
void ResourceManager::setSound(const std::string& soundname_,const Sound& sound_)
{
	for (auto it = this->sounds.begin(); it != this->sounds.end(); ++it)
	{
		if ((*it).first == soundname_)
		{
			return;
		}
	}

	std::pair<std::string, Sound>  sound;
	sound.first = soundname_;
	sound.second = sound_;
	this->sounds.push_back(sound);
}
/*�o�^���Ă���e�N�X�`������w�肳�ꂽ�e�N�X�`����Ԃ��܂�*/
Texture ResourceManager::getTexture(const std::string& texname_)const
{
	for (auto it = this->textures.begin(); it != this->textures.end(); ++it)
	{
		if ((*it).first == texname_)
		{
			return (*it).second;
		}
	}
	return Texture();
}
/*�o�^���Ă���T�E���h����w�肳�ꂽ�T�E���h��Ԃ��܂�*/
Sound ResourceManager::getSound(const std::string& texname_)const
{
	for (auto it = this->sounds.begin(); it != this->sounds.end(); ++it)
	{
		if ((*it).first == texname_)
		{
			return (*it).second;
		}
	}
	/*��̃T�E���h��Ԃ�*/
	return Sound();
}
/* �o�^���Ă���e�N�X�`�����폜���܂� */
void ResourceManager::DeleteTextrue()
{
	this->textures.clear();
}
/*�o�^���Ă���T�E���h���폜�����܂�*/
void ResourceManager::DeleteSound()
{
	this->sounds.clear();
}
/*���\�[�X��S�폜�����܂�*/
void ResourceManager::DeleteResource()
{
	this->DeleteTextrue();
	this->DeleteSound();
}