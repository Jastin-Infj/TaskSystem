#pragma once
#include "../ResourceManager/ResourceManager.h"
#include <vector>
#include <memory>


///<summary>
///�^�X�N�����ł�����N���X
///</summary>
class KillTaskSystem
{
public:

	///�����o�֐�

	///<summary>
	///�R���X�g���N�^
	///</summary>
	KillTaskSystem();


	///<summary>
	///�f�X�g���N�^
	///</summary>
	~KillTaskSystem();


	///<summary>
	///�L���J�E���^�𑝉������܂�
	///</summary>
	///<returns>
	///�Ȃ�
	///</returns>
	void KillCount();


	///<summary>
	///���ł����邩�ǂ����𔻒肵�܂�
	///</summary>
	///<returns>
	///���ł�����@true : ���ł��Ȃ� false
	///</returns>
	bool KillCheck();


	///<summary>
	///killcount��Ԃ��܂�
	///</summary>
	int getKillcount()const;


private:

	///�����o�ϐ�

	///<summary>
	///�L���J�E���^
	///</summary>
	int killcount;

};


///<summary>
///�V�����I�u�W�F�N�g�𐶐�����N���X
///</summary>
class TaskObject : private KillTaskSystem
{
public:
///�����o�ϐ�

	///<summary>
	///�X�}�[�g�|�C���^
	///</summary>
	typedef std::shared_ptr<TaskObject> SP;


	///<summary>
	///�E�B�[�N�|�C���^
	///</summary>
	typedef std::weak_ptr<TaskObject>   WP;


	///<summary>
	///�����̃f�[�^
	///</summary>
	TaskObject::WP me;

///�����o�֐�


	///<summary>
	///�R���X�g���N�^
	///</summary>
	///<returns>
	///�Ȃ�
	///</returns>
	TaskObject();


	///<summary>
	///�f�X�g���N�^
	///</summary>
	virtual ~TaskObject();


	///<summary>
	///�X�V����
	///</summary>
	///<returns>
	///�Ȃ�
	///</returns>
	virtual void Update();


	///<summary>
	///�`�揈��
	///</summary>
	///<returns>
	///�Ȃ�
	///</returns>
	virtual void Render();


	///<summary>
	///�������
	///</summary>
	///<returns>
	///��������I���@true
	///</returns>
	virtual bool Finalize();


	///<summary>
	///�L���J�E���^�𑝉������܂�
	///</summary>
	///<returns>
	///�Ȃ�
	///</returns>
	void Kill();


	///<summary>
	///Kill�J�E���^��Ԃ��܂�
	///</summary>
	int  getKillCounter()const;


	///<summary>
	///�O���[�v���E�^�X�N����Ԃ��܂�
	///</summary>
	std::pair<std::string,std::string> getTaskname()const;


	///<summary>
	///�O���[�v���E�^�X�N�����Z�b�g���܂�
	///</summary>
	void setTaskName(const std::pair<std::string, std::string>&);


	///<summary>
	///����̃^�X�N�������ł���󋵂���Ԃ��܂�
	///</summary>
	bool getNextTask()const;


	///<summary>
	///����̃^�X�N�𐶐��o���邩��ύX���܂�
	///</summary>
	void setNextTask(const bool);


	///<summary>
	///�|�[�Y�t���O��Ԃ��܂�
	///</summary>
	///<returns>
	///�|�[�Y��:true �|�[�Y�ł͂Ȃ�:false
	///</returns>
	bool getisPause()const;


	///<summary>
	///<para>�|�[�Y��ݒ肵�܂�</para>
	///<para>���f���� true ���f���� false </para>
	///</summary>
	///<returns>
	///�Ȃ�
	///</returns>
	void setPause(const bool);


	///<summary>
	///<para>�`��D�揇�ʂ�ݒ肵�܂��@�����قǃ��C���[�͏�ɂȂ�܂�</para>
	///<para>�͈�: 0.0f�`1.0f(�f�t�H���g�l)</para>
	///</summary>
	void setDrawOrder(float = 1.0f);


	///<summary>
	///�`��D�揇�ʂ�Ԃ��܂�
	///</summary>
	const float getDrawOrder()const;


	/// <summary>
	/// �^�X�N���𐶐����ɏ������ݒ���s���܂�
	/// </summary>
	/// <param name="taskname">
	/// �O���[�v���E�^�X�N��
	/// </param>
	/// <returns>
	/// �^�X�N���̐ݒ芮�� true / �^�X�N���ɋ󔒂����� false
	/// </returns>
	bool CreatedObjectInit(const std::pair<std::string,std::string>& taskname);


	///<summary>
	///�^�X�N�����������[�h�ƈ�v���Ă��邩��Ԃ��܂�
	///</summary>
	///<param name="taskname_">
	///�������[�h
	///</param>
	///<returns>
	///��v���Ă��� true / ��v���Ă��Ȃ� false
	///</returns>
	bool isTasknameSecond(const std::string& taskname_)const;

private:

///�����o�ϐ�

	///<summary>
	///�O���[�v�� , �^�X�N��
	///</summary>
	std::pair<std::string, std::string> taskname;

	///<summary>
	///�I�����Ɏ��̃^�X�N�������ł��邩
	///</summary>
	bool NextTask;

	///<summary>
	///<para>�|�[�Y�����t���O</para>
	///<para>�|�[�Y��:true �|�[�Y���Ă��Ȃ�:false</para>
	///</summary>
	bool isPause;


	///<summary>
	///�`��D�揇��
	///</summary>
	float order;


///�����o�֐�

};