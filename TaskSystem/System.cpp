#include "System.h"
#include <string>

/*�R���X�g���N�^*/
System::System()
{
	std::cout << "System" << std::endl;
}
/*�f�X�g���N�^*/
System::~System()
{
	this->TaskObjectDelete();
	std::cout << "~System" << std::endl;
}
/*�I�u�W�F�N�g���V�X�e���ɓo�^���܂�*/
void System::Add(TaskObject::SP object)
{
	//this->taskobjects.push_back(object);
}
/*�I�u�W�F�N�g���V�X�e���ɓo�^���܂�*/
void System::Add(std::pair<std::string, std::string>& taskname_)
{
	this->taskobjects.push_back(taskname_);
}

/*�ǉ��\��̃I�u�W�F�N�g�𓝊��I�u�W�F�N�g�ɓo�^���܂�*/
void System::toTaskObjects()
{
	
}
/*�o�^���Ă���I�u�W�F�N�gVector��Ԃ��܂�*/
std::vector<TaskObject::SP> System::getTaskObjects()const
{
	
}
/*�o�^���Ă���I�u�W�F�N�g�̃^�X�N����Ԃ��܂�*/
void System::TasknameOutput()const
{
	
}
/*�o�^���Ă���I�u�W�F�N�g�̍X�V�������s���܂�*/
void System::UpDate()
{
	
}
/*�o�^���Ă���I�u�W�F�N�g�̕`�揈�����s���܂�*/
void System::Render()
{
	
}
/*�o�^���Ă���I�u�W�F�N�g�̏����ł��邩���`�F�b�N���܂�*/
void System::Destory()
{
	
}
/*�o�^���Ă���I�u�W�F�N�g�̃O���[�v���E�^�X�N�����������ăI�u�W�F�N�g���폜���܂�*/
void System::TaskNameDelete(std::string& group_ , std::string& taskname_)
{
	
}
/*�o�^���Ă���I�u�W�F�N�g�̑S�������s���܂�*/
void System::TaskObjectDelete()
{
	
}