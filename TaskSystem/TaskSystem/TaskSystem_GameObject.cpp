#include "TaskSystem.h"
#include "TaskSystem_GameObject.h"

bool TaskSystemGameObject::Initialize()
{
	std::cout << "初期化処理" << std::endl;
	return true;
}
void TaskSystemGameObject::Update()
{
	std::cout << "ＯＫ" << std::endl;
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
		//自分のアドレス値を参照したい場合にWPに保存をしておく
		createTasksystemgameobject->me = createTasksystemgameobject;

		//タスクシステムに登録する前に初期化処理を行う
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
		//タスクシステムに登録する
		if (tasksystemFlag)
		{
			taskSystem->Add(createTasksystemgameobject);
		}
		return createTasksystemgameobject;
	}
	return nullptr;
}