#include <iostream>
#include <string>
#include "TaskObject.h"
#include "System.h"

/*コンストラクタ*/
TaskObject::TaskObject(std::pair<std::string, std::string> *taskname_)
{
	this->taskname = *taskname_;
	std::cout << "TaskObject" << std::endl;
}
/*デストラクタ*/
TaskObject::~TaskObject()
{
	std::cout << "~TaskObject()" << std::endl;
}
/*オブジェクトを生成します*/
TaskObject::SP TaskObject::Create(std::pair<std::string,std::string> *taskname_,bool createflag)
{
	TaskObject::SP to = TaskObject::SP(new TaskObject(taskname_));
	if (to)
	{
		if (createflag)
		{
			to->Init();
			Tasksystem->Add(to);
			return to;
		}
	}
	return nullptr;
}
/*タスク名返します*/
std::string TaskObject::getTaskname()const
{
	return this->taskname.second;
}
/*初期化処理を行います*/
bool TaskObject::Init()
{
	std::cout << this->taskname.second << "init()" << std::endl;
	return true;
}
/*更新処理を行います*/
void TaskObject::UpDate()
{
	std::cout << this->taskname.second << "update()" << std::endl;
}
/*描画処理を行います*/
void TaskObject::Render()
{
	std::cout << this->taskname.second << "render()" << std::endl;
}
/*解放処理を行います*/
bool TaskObject::Finalize()
{
	std::cout << this->taskname.second << "finalize()" << std::endl;
	return true;
}