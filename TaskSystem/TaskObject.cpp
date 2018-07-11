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
	std::cout << this->getTaskname().second <<"~TaskObject()" << std::endl;
}
/*タスク名返します*/
std::pair<std::string,std::string> TaskObject::getTaskname()const
{
	return this->taskname;
}
/*初期化処理を行います*/
bool TaskObject::Init(std::pair<std::string, std::string>* taskname_)
{
	this->NextTask = false;
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
void TaskObject::Kill()
{
	this->KillCount();
	this->NextTask = true;
}
/*killのカウンタを返します*/
int  TaskObject::getKillCounter()
{
	return this->getKillcount();
}
/*次回のタスクが生成できるかを返します*/
bool TaskObject::getNextTask()const
{
	return this->NextTask;
}
/*グループ名・タスク名をセットします */
void TaskObject::setTaskName(std::pair<std::string, std::string>& taskname_)
{
	this->taskname = taskname_;
}
/* 自分自身のオブジェクトを返します */
std::pair<std::pair<std::string, std::string>, TaskObject::SP> TaskObject::getObjectMe(const TaskObject::SP& obj)const
{
	std::pair<std::pair<std::string,std::string>,TaskObject::SP> object;
	object.first = this->taskname;
	object.second = obj;
	return object;
}
