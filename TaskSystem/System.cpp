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
void System::Add(std::pair<std::pair<std::string,std::string>,TaskObject::SP>* addobject)
{
	this->taskobjects.push_back(*addobject);
}
/* 登録しているオブジェクトタスクを全て返します */

/*登録しているオブジェクトのタスク名を返します*/
void System::TasknameOutput()const
{
	for (auto it = this->taskobjects.begin(); it != this->taskobjects.end(); ++it)
	{
		/*消去されていない場合*/
		if ((*it).second->getKillCounter() == 0)
		{
			std::cout << (*it).second->getTaskname().second << std::endl;
		}
	}
}
/*登録しているオブジェクトの更新処理を行います*/
void System::UpDate()
{
	for (auto it = this->taskobjects.begin(); it != this->taskobjects.end(); ++it)
	{
		/*消去されていない場合*/
		if ((*it).second->getKillCounter() == 0)
		{
			(*it).second->UpDate();
		}
	}
}
/*登録しているオブジェクトの描画処理を行います*/
void System::Render()
{
	for (auto it = this->taskobjects.begin(); it != this->taskobjects.end(); ++it)
	{
		/*消去されていない場合*/
		if ((*it).second->getKillCounter() == 0)
		{
			(*it).second->Render();
		}
	}
}
/*登録しているオブジェクトの消去できるかをチェックします*/
void System::Destory()
{
	auto it = this->taskobjects.begin();
	while(it != this->taskobjects.end())
	{
		if ((*it).second)
		{
			if ((*it).second->getKillCounter() > 0)
			{
				this->taskobjects.erase(it);
				it = this->taskobjects.begin();
			}
			else
			{
				++it;
			}
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
/*グループ名・タスク名からオブジェクトの取得をします*/
template <typename T>
std::shared_ptr<T> System::GetTask(std::pair<std::string, std::string>* taskname_)
{
	for (auto it = this->taskobjects.begin(); it != this->taskobjects.end(); ++it)
	{
		if ((*it).second != nullptr)
		{
			//TaskObject::SP
			if ((*it).second->getTaskname() == taskname_)
			{
				return (*it).second;
			}
			++it;
		}
		else
		{
			++it;
		}
	}
	return nullptr;
}
template<class T>
std::shared_ptr<std::vector<std::shared_ptr<T>>> System::GetTasks(std::pair<std::string, std::string> taskname_)  
{
	std::shared_ptr<std::vector<std::shared_ptr<T>>> searchObjects = std::shared_ptr<std::vector<std::shared_ptr<T>>>(new std::vector<std::shared_ptr<T>>());
	if (auto it = this->taskobjects.begin(); it != this->taskobjects.end(); ++it)
	{
		if ((*it).second != nullptr)
		{
			if ((*it).second->getTaskname() == taskname_)
			{
				searchObjects->push_back(std::static_pointer_cast<T>((*it).second));
			}
		}
	}
	return searchObjects;
}