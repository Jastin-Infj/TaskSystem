#pragma once

#include <iostream>
#include <vector>
#include <memory>

#include "TaskObject.h"

///<summary>
///
///</summary>
///<returns>
///
///</returns>

class System
{
public:
	typedef std::shared_ptr<System> SP;


	///<summary>
	///コンストラクタ
	///</summary>
	System();

	
	///<summary>
	///デストラクタ
	///</summary>
	~System();

	
	///<summary>
	///タスクシステムの更新処理
	///</summary>
	///<returns>
	///なし
	///</returns>
	void UpDate();


	///<summary>
	///オブジェクトをシステムに仮登録します
	///</summary>
	///<returns>
	///なし
	///</returns>
	void Add(std::pair<std::pair<std::string, std::string>, TaskObject::SP>*);


	///<summary>
	///登録しているオブジェクトのタスク名を表示します
	///</summary>
	///<returns>
	///なし
	///</returns>
	void TasknameOutput()const;


	///<summary>
	///登録されているオブジェクトを全部消去を行います
	///</summary>
	///<returns>
	///なし
	///</returns>
	void TaskObjectDelete();
	

	///<summary>
	///タスク名・グループ名を検索して、オブジェクト単体を取得します
	///</summary>
	template <class T>
	std::shared_ptr<T> GetTask(std::pair<std::string, std::string>& taskname_)
	{
		for (auto it = this->taskobjects.begin(); it != this->taskobjects.end(); ++it)
		{
			if ((*it).second != nullptr)
			{
				if ((*it).second->getTaskname() == taskname_)
				{
					return std::static_pointer_cast<T>((*it).second);
				}
			}
		}
		return nullptr;
	}


	///<summary>
	///タスク名・グループ名を検索して、オブジェクト複数を取得します
	///</summary>
	template<class T>
	std::shared_ptr<std::vector<std::shared_ptr<T>>> GetTasks(std::pair<std::string, std::string> taskname_)
	{
		std::shared_ptr<std::vector<std::shared_ptr<T>>> searchObjects = std::shared_ptr<std::vector<std::shared_ptr<T>>>(new std::vector<std::shared_ptr<T>>());
		for (auto it = this->taskobjects.begin(); it != this->taskobjects.end(); ++it)
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

private:
	std::vector<std::pair<std::pair<std::string,std::string>,TaskObject::SP>> taskobjects;			//登録しているオブジェクト
	std::vector<std::pair<std::pair<std::string, std::string>, TaskObject::SP>> addobjects;			//登録予定のオブジェクト


	///<summary>
	///登録予定のオブジェクトを登録します
	///<summary>
	///<returns>
	///なし
	///</returns>
	void TaskApplication();


	///<summary>
	///登録されているオブジェクトの更新処理を行います
	///</summary>
	///<returns>
	///なし
	///</returns>
	void T_UpDate();


	///<summary>
	///登録されているオブジェクトの描画処理を行います
	///</summary>
	///<returns>
	///なし
	///</returns>
	void T_Render();


	///<summary>
	///登録されているオブジェクトの消去を行います
	///</summary>
	///<returns>
	///なし
	///</returns>
	void T_Destory();


	///<summary>
	///登録予定のオブジェクトが存在するかを判定します
	///</summary>
	///<returns>
	///存在する true 存在しない false
	///</returns>
	bool AddObjectCheck()const;


	///<summary>
	///登録オブジェクトから消去予定のオブジェクトがないかを判定します
	///</summary>
	///<returns>
	///存在する true 存在しない false
	///</returns>
	bool CheckKillTask()const;

};
extern System* Tasksystem;