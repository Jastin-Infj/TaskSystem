#pragma once
#include <vector>


class Texture {};
class Sound {};


///<summary>
///�`�揇��ݒ肷��N���X
///</summary>
class DrawOrder 
{
public:
	///<summary>
	///�R���X�g���N�^
	///</summary>
	DrawOrder();


	///<summary>
	///�f�X�g���N�^
	///</summary>
	~DrawOrder();


	/// <summary>
	/// �`��D��x��ݒ肵�܂�
	/// </summary>
	/// <param name="order_">
	/// �`��D�揇��
	/// </param>
	void setDrawOrder(float order_);


	///<summary>
	///�`��̗D��x��Ԃ��܂�
	///</summary>
	const float getDrawOrder()const;

	
	/// <summary>
	/// �`��ID��ݒ肵�܂�
	/// </summary>
	/// <param name="resource_id">
	/// ResourceID
	/// </param>
	void setDrawOrderID(int& resource_id);


	///<summary>
	///�`��ID��Ԃ��܂�
	///</summary>
	///<returns>
	///�`��ID 
	///</returns>
	int getDrawOrderID()const;


private:
	float order;	//�`�揇�̗D��x
	int   id;		//�^�X�N�`��ID
};


///<summary>
///���\�[�X���Ǘ�����N���X
///</summary>
class ResourceManager
{
public:
	///<summary>
	///�R���X�g���N�^
	///</summary>
	ResourceManager();


	///<summary>
	///�f�X�g���N�^
	///<summary>
	~ResourceManager();

	
	/// <summary>
	/// �e�N�X�`�����V�X�e���ɓo�^���܂�
	/// </summary>
	/// <param name="texturename">
	/// �e�N�X�`����
	/// </param>
	/// <param name="texture">
	/// �o�^����e�N�X�`��
	/// </param>
	void setTexture(const std::string& texturename ,const Texture& texture);


	///<summary>
	///�T�E���h���V�X�e���ɓo�^���܂�
	///</summary>
	/// <param name="soundname">
	/// �T�E���h��
	/// </param>
	/// <param name="sound">
	/// �o�^����T�E���h
	/// </param>
	void setSound(const std::string& soundname, const Sound& sound);


	///<summary>
	///�o�^���Ă���e�N�X�`������w��̃e�N�X�`�����擾���܂�
	///</summary>
	/// <param name="texturename">
	/// �������[�h
	/// </param>
	/// <returns>
	/// �e�N�X�`�����ƈ�v�����e�N�X�`��
	/// </returns>
	Texture getTexture(const std::string& texturename)const;


	///<summary>
	///�o�^���Ă���T�E���h����w��̃T�E���h���擾���܂�
	///</summary>
	/// <param name="soundname">
	/// �������[�h
	/// </param>
	///<returns>
	///�T�E���h���ƈ�v�����T�E���h�̃|�C���^
	///</returns>
	Sound getSound(const std::string& soundname)const;


	///<summary>
	///�o�^���Ă���e�N�X�`���E�T�E���h��S�폜���܂�
	///</summary>
	void DeleteResource();


	///<summary>
	///�o�^���Ă���e�N�X�`����S�č폜�����܂�
	///</summary>
	void DeleteTextrue();


	///<summary>
	///�o�^���Ă���T�E���h��S�č폜�����܂�
	///</summary>
	void DeleteSound();

private:
	///<summary>
	///�o�^���Ă���e�N�X�`��
	///</summary>
	std::vector<std::pair<std::string, Texture>> textures;


	///<summary>
	///�o�^����Ă���T�E���h
	///</summary>
	std::vector<std::pair<std::string, Sound>>   sounds;
};
extern ResourceManager* rm;		//ResourceManager�ɃA�N�Z�X�p�ϐ�