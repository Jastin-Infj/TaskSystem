#pragma once
#include <vector>


class Textrue {};
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


	///<summary>
	///<para>�`��D��x��ݒ肵�܂�</para>
	///<para>0.0f �` �f�t�H���g(1.0f)</para>
	///</summary>
	void setDrawOrder(float);


	///<summary>
	///�`��̗D��x��Ԃ��܂�
	///</summary>
	const float getDrawOrder()const;

	
	///<summary>
	///�`��ID��ݒ肵�܂�
	///</summary>
	void setDrawOrderID(int&);


	///<summary>
	///�`��ID��Ԃ��܂�
	///</summary>
	int getDrawOrderID()const;


private:
	///<summary>
	///�`�揇�̗D��x �͈�: 0.0 �` 1.0
	///</summary>
	float order;


	///<summary>
	///�^�X�N�`��ID
	///</summary>
	int id;
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


	///<summary>
	///�e�N�X�`�����V�X�e���ɓo�^���܂�
	///</summary>
	void setTextrue(const std::string& ,Textrue*);


	///<summary>
	///�T�E���h���V�X�e���ɓo�^���܂�
	///</summary>
	void setSound(const std::string&, Sound*);


	///<summary>
	///�o�^���Ă���e�N�X�`������w��̃e�N�X�`�����擾���܂� (string: �e�N�X�`����)
	///</summary>
	///<returns>
	///�e�N�X�`�����ƈ�v�����e�N�X�`���̃|�C���^
	///</returns>
	Textrue* getTextrue(const std::string&)const;


	///<summary>
	///�o�^���Ă���T�E���h����w��̃T�E���h���擾���܂� (string: �T�E���h��)
	///</summary>
	///<returns>
	///�T�E���h���ƈ�v�����T�E���h�̃|�C���^
	///</returns>
	Sound* getSound(const std::string&)const;


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
	std::vector<std::pair<std::string, Textrue*>> textrues;


	///<summary>
	///�o�^����Ă���T�E���h
	///</summary>
	std::vector<std::pair<std::string, Sound*>>   sounds;
};
