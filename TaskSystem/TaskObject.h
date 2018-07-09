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
	///�I�u�W�F�N�g�̏����˗������܂�
	///</summary>
	///<returns>
	///�Ȃ�
	///</returns>
	void Kill();


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
	typedef std::shared_ptr<TaskObject> WP;

///�����o�֐�

	///<summary>
	///�R���X�g���N�^
	///</summary>
	///<returns>
	///�Ȃ�
	///</returns>
	TaskObject(std::pair<std::string,std::string>*);


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
	///�^�X�N����Ԃ��܂�
	///</summary>
	std::string getTaskname()const;

	///<summary>
	///�^�X�N���E�O���[�v����Ԃ��܂�
	///</summary>
	std::pair<std::string, std::string> getObjectname()const;
	
	///<summary>
	///����������
	///</summary>
	///<returns>
	///�����������I�� true
	///</returns>
	virtual bool Init();

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
	///�L���J�E���^�𑝉������܂�
	///</summary>
	///<returns>
	///�Ȃ�
	///</returns>
	void TaskKill();


	///<summary>
	///Kill�J�E���^��Ԃ��܂�
	///</summary>
	int  getKillCounter()const;


private:

///�����o�ϐ�

	///<summary>
	///�O���[�v�� , �^�X�N��
	///</summary>
	std::pair<std::string, std::string> taskname;

///�����o�֐�
	
};