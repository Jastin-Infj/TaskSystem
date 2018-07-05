#include "System.h"
#include <string>
/*コンストラクタ*/
KillSystem::KillSystem()
{
	this->killcount = 0;
}
KillSystem::~KillSystem() {}
/*消滅をさせることを依頼します*/
void KillSystem::Kill()
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
System::System()
{
	std::cout << "System" << std::endl;
}
/*デストラクタ*/
System::~System()
{
	std::cout << "~System" << std::endl;
}
/*オブジェクトをシステムに登録します*/
void System::Add(TaskObject::SP object)
{
	this->taskobjects.push_back(object);
}
/*登録しているオブジェクトVectorを返します*/
std::vector<TaskObject::SP> System::getTaskObjects()const
{
	return this->taskobjects;
}
/*登録しているオブジェクトのタスク名を返します*/
void System::TasknameOutput()const
{
	for (auto it = this->taskobjects.begin(); it != this->taskobjects.end(); ++it)
	{
		if ((*it)->getKillcount() == 0)
		{
			std::cout << (*it)->getTaskname() << std::endl;
		}
	}
}
/*登録しているオブジェクトの更新処理を行います*/
void System::UpDate()
{
	for (auto it = this->taskobjects.begin(); it != this->taskobjects.end(); ++it)
	{
		if ((*it)->getKillcount() == 0)
		{
			(*it)->UpDate();
		}
	}
}
/*登録しているオブジェクトの描画処理を行います*/
void System::Render()
{
	for (auto it = this->taskobjects.begin(); it != this->taskobjects.end(); ++it)
	{
		if ((*it)->getKillcount() == 0)
		{
			(*it)->Render();
		}
	}
}
/*登録しているオブジェクトの消去できるかをチェックします*/
void System::Destory()
{
	for (auto it = this->taskobjects.begin(); it != this->taskobjects.end(); ++it)
	{
		if ((*it)->KillCheck())
		{
			std::cout << &it << std::endl;
			delete &it;
			
		}
	}
}
/*登録しているオブジェクトの全消去を行います*/
void System::TaskObjectDelete()
{
	auto it = this->taskobjects.begin();
	while (it != this->taskobjects.end())
	{
		this->taskobjects.erase(it);
		it = this->taskobjects.begin();
	}
}