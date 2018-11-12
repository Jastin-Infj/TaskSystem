#include "TaskSystem.h"
#include "TaskSystem_GameObject.h"

bool TaskSystemGameObject::Initialize()
{

	return true;
}
void TaskSystemGameObject::UpDate()
{
	
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
		if (!createTasksystemgameobject->CreatedObjectInit(taskName) && !createTasksystemgameobject->Initialize())
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