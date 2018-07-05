#pragma once
#include <vector>
#include <memory>

/*�O���錾*/
struct KillSystem;

///<summary>
///
///</summary>
///<returns>
///
///</returns>

///<summary>
///�V�����I�u�W�F�N�g�𐶐�����N���X
///</summary>

class TaskObject : public KillSystem
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


private:

///�����o�ϐ�

	///<summary>
	///�O���[�v�� , �^�X�N��
	///</summary>
	std::pair<std::string, std::string> taskname;
///�����o�֐�
	
};