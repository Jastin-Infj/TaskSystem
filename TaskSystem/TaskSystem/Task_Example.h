#pragma once
#include "../TaskSystem/TaskSystem.h"
#include "../TaskSystem/TaskObject.h"

///<summary>
///�^�X�N�V�X�e�����������`�N���X�ł�
///</summary>
class TaskObjectExample : public TaskObject
{
public:

	///<summary>
	///�X�}�[�g�|�C���^�錾���ȗ����܂�
	///</summary>
	typedef std::shared_ptr<TaskObjectExample> SP;


	///<summary>
	///�E�B�[�N�|�C���^�錾���ȗ����܂�
	///</summary>
	typedef std::shared_ptr<TaskObjectExample> WP;



///�����o�֐�

	///<summary>
	///�R���X�g���N�^
	///</summary>
	TaskObjectExample();


	///<summary>
	///�f�X�g���N�^
	///</summary>
	virtual ~TaskObjectExample();


	///<summary>
	///<para>����������</para>
	///<para>����: �O���[�v���E�^�X�N��</para>
	///</summary>
	bool Init(std::pair<std::string, std::string>&)override;


	///<summary>
	///�I�u�W�F�N�g�𐶐����܂�
	///</summary>
	///<returns>
	///�������o����:�X�}�[�g�|�C���^  �o���Ȃ�:nullptr
	///</returns>
	static TaskObjectExample::SP Create(std::pair<std::string,std::string>&, bool = true);


private:


///�����o�֐�

	///<summary>
	///�X�V����
	///</summary>
	void UpDate()override;


	///<summary>
	///�`�揈��
	void Render()override;
};