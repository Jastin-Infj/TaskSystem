#pragma once
#include <vector>
#include <memory>

///<summary>
///
///</summary>
///<returns>
///
///</returns>

///<summary>
///�^�X�N�����ł�����N���X
///</summary>
class KillSystem
{
public:

	///�����o�֐�

	///<summary>
	///�R���X�g���N�^
	///</summary>
	KillSystem();


	///<summary>
	///�f�X�g���N�^
	///</summary>
	~KillSystem();


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

	int killcount;
};


///<summary>
///�V�����I�u�W�F�N�g�𐶐�����N���X
///</summary>
class TaskObject : private KillSystem
{
public:
///�����o�ϐ�

	typedef std::shared_ptr<TaskObject> SP;

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
	///�������܂�
	///</summary>
	///<returns>
	///���������X�}�[�g�|�C���^
	///</returns>
	static TaskObject::SP Create(std::pair < std::string, std::string>*, bool = true);
	

	///<summary>
	///����������
	///</summary>
	///<returns>
	///�����������I�� true
	///</returns>
	virtual bool Init(std::pair<std::string, std::string>*);

	///<summary>
	///�X�V����
	///</summary>
	///<returns>
	///�Ȃ�
	///</returns>
	virtual void UpDate();


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
	///�I�u�W�F�N�g���������܂�
	///</summary>
	///<returns>
	///�I�u�W�F�N�g�������@true : �I�u�W�F�N�g���������Ă��Ȃ��@false
	///</returns>
	bool Kill();

	
	///<summary>
	///Kill�J�E���^��Ԃ��܂�
	///</summary>
	int  getKillCounter();


	///<summary>
	///�O���[�v���E�^�X�N����Ԃ��܂�
	///</summary>
	std::pair<std::string,std::string> getTaskname()const;


	///<summary>
	///�O���[�v���E�^�X�N�����Z�b�g���܂�
	///</summary>
	void setTaskName(std::pair<std::string, std::string>&);


private:

///�����o�ϐ�

	///<summary>
	///�O���[�v�� , �^�X�N��
	///</summary>
	std::pair<std::string, std::string> taskname;

///�����o�֐�
	
};