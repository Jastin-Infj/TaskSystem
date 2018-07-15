#include "Task_Example.h"
#include <string>
/*�R���X�g���N�^*/
TaskObjectExample::TaskObjectExample()
{
#if(_DEBUG)
	std::cout << "TaskObjectExample()" << std::endl;
#endif
}
/*�f�X�g���N�^*/
TaskObjectExample::~TaskObjectExample()
{
#if(_DEBUG)
	std::cout << this->getTaskname().second <<  "~TaskObjectExample()" << std::endl;
#endif
}
/*����������*/
bool TaskObjectExample::Init(std::pair<std::string, std::string>& taskname_)
{
#if(_DEBUG)
	std::cout << this->getTaskname().second << "TaskObjectExample.Init()" << std::endl;
#endif
	/*���O��o�^���܂�*/
	__super::setTaskName(taskname_);
	/*�`�揇�ʂ��i�[����*/
	__super::setDrawOrder();

	return true;
}
/*�X�V����*/
void TaskObjectExample::UpDate()
{
#if(_DEBUG)
	std::cout << this->getTaskname().second  << "    "<< "TaskObjectExample.UpDate()" << std::endl;
#endif
}
/*�`�揈��*/
void TaskObjectExample::Render()
{
#if(_DEBUG)
	std::cout << this->getTaskname().second << "     "<< "TaskObjectExample.Render()" << std::endl;
#endif
}
/*�I�u�W�F�N�g�𐶐����܂�*/
TaskObject::SP TaskObjectExample::Create(std::pair<std::string, std::string>& taskname_, bool flag)
{
	TaskObject::SP to = TaskObject::SP(new TaskObjectExample());
	if (to != nullptr)
	{
		to->me = to;
		if (!to->Init(taskname_))
		{
			to->Kill();
		}
		if (flag)
		{
			taskSystem->Add(to);
		}
		return to;
	}
	return nullptr;
}
