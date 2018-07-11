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
	///オブジェクトをシステムに登録します
	///</summary>
	///<returns>
	///なし
	///</returns>
	void Add(TaskObject::SP);


	///<summary>
	///登録しているオブジェクトVectorを返します
	///</summary>
	///<returns>
	///現在登録しているオブジェクトVector
	///</returns>
	std::vector<TaskObject::SP> getTaskObjects()const;


	///<summary>
	///登録しているオブジェクトのタスク名を表示します
	///</summary>
	///<returns>
	///なし
	///</returns>
	void TasknameOutput()const;


	///<summary>
	///登録されているオブジェクトの更新処理を行います
	///</summary>
	///<returns>
	///なし
	///</returns>
	void UpDate();


	///<summary>
	///登録されているオブジェクトの描画処理を行います
	///</summary>
	///<returns>
	///なし
	///</returns>
	void Render();


	///<summary>
	///登録されているオブジェクトの消去を行います
	///</summary>
	///<returns>
	///なし
	///</returns>
	void Destory();


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
	template <typename T>
	std::shared_ptr<T> GetTask(std::pair<std::string, std::string>*);


	///<summary>
	///タスク名・グループ名を検索して、オブジェクト複数を取得します
	///</summary>
	template<typename T>
	std::vector<std::pair<std::pair<std::string, std::string>, std::shared_ptr<T>>> GetTasks(std::pair<std::string,std::string>);


private:
	std::vector<std::pair<std::pair<std::string,std::string>,TaskObject::SP>> taskobjects;	//登録しているオブジェクト
};
extern System* Tasksystem;