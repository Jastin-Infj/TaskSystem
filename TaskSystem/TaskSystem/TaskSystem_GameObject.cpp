#include "TaskSystem.h"
#include "TaskSystem_GameObject.h"

bool TaskSystemGameObject::Initialize()
{
	std::cout << "����������" << std::endl;
	return true;
}
void TaskSystemGameObject::Update()
{
	std::cout << "�n�j" << std::endl;
}
void TaskSystemGameObject::Render()
{

}
bool TaskSystemGameObject::Finalize()
{
	return true;
}
TaskSystemGameObject::SP TaskSystemGameObject::Create(const std::pair<std::string, std::string>& taskName,const bool& tasksystemFlag)
{ 
	TaskSystemGameObject::SP createTasksystemgameobject = TaskSystemGameObject::SP(new TaskSystemGameObject);
	if (createTasksystemgameobject)
	{
		//�����̃A�h���X�l���Q�Ƃ������ꍇ��WP�ɕۑ������Ă���
		createTasksystemgameobject->me = createTasksystemgameobject;

		//�^�X�N�V�X�e���ɓo�^����O�ɏ������������s��
		bool addTasksystemFlag = createTasksystemgameobject->CreatedObjectInit(taskName);
		bool initializeFlag = false;
		if (addTasksystemFlag)
		{
			initializeFlag = createTasksystemgameobject->Initialize();
		}
		if (!addTasksystemFlag && !initializeFlag)
		{
			createTasksystemgameobject->Kill();
		}
		//�^�X�N�V�X�e���ɓo�^����
		if (tasksystemFlag)
		{
			taskSystem->Add(createTasksystemgameobject);
		}
		return createTasksystemgameobject;
	}
	return nullptr;
}