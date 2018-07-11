#include <iostream>
#include <string>
#include "TaskObject.h"
#include "System.h"		//taskobjectsを使用できるようにする

/*コンストラクタ*/
KillSystem::KillSystem()
{
	this->killcount = 0;
}
KillSystem::~KillSystem() {}
/*消滅をさせることを依頼します*/
void KillSystem::KillCount()
{
	this->killcount++;
}
/*消滅させるかどうかを判定します*/
bool KillSystem::KillCheck()
{
	return this->killcount > 0 ? true : false;
}
/*キルカウンターを返します*/
int  KillSystem::getKillcount()const
{
	return this->killcount;
}

/*コンストラクタ*/
TaskObject::TaskObject()
{
	std::cout << "TaskObject()" << std::endl;
}
/*デストラクタ*/
TaskObject::~TaskObject()
{
	std::cout << "~TaskObject()" << std::endl;
}
/*オブジェクトを生成します*/
TaskObject::SP TaskObject::Create(std::pair<std::string,std::string> *taskname_,bool createflag)
{
	TaskObject::SP to = TaskObject::SP(new TaskObject());
	if (to)
	{
		if (createflag)
		{
			/* タスク名を登録する */
			to->Init(taskname_);
			/* システムに登録をする */
			Tasksystem->Add(to);
			return to;
		}
	}
	return nullptr;
}
/*タスク名返します*/
std::pair<std::string,std::string> TaskObject::getTaskname()const
{
	return this->taskname;
}
/*初期化処理を行います*/
bool TaskObject::Init(std::pair<std::string, std::string>* taskname_)
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
/*オブジェクトを消去します*/
bool TaskObject::Kill()
{
	this->KillCount();
	if (this->getKillcount() > 0)
	{
		return true;
	}
	return false;
}
/*killのカウンタを返します*/
int  TaskObject::getKillCounter()
{
	return this->getKillcount();
}
/*グループ名・タスク名をセットします */
void TaskObject::setTaskName(std::pair<std::string, std::string>& taskname_)
{
	this->taskname = taskname_;
}
