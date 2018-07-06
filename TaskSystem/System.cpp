#include "System.h"
#include <string>

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
		/*消去されていない場合*/
		if ((*it)->getKillCounter() == 0)
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
		/*消去されていない場合*/
		if ((*it)->getKillCounter() == 0)
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
		/*消去されていない場合*/
		if ((*it)->getKillCounter() == 0)
		{
			(*it)->Render();
		}
	}
}
/*登録しているオブジェクトの消去できるかをチェックします*/
void System::Destory()
{
	auto it = this->taskobjects.begin();
	while(it != this->taskobjects.end())
	{
		if ((*it)->getKillCounter() > 0)
		{
			this->taskobjects.erase(it);
			it = this->taskobjects.begin();
		}
		else
		{
			++it;
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