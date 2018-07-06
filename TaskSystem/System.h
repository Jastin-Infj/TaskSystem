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

private:
	std::vector<TaskObject::SP> taskobjects;	//登録しているオブジェクト
};
extern System* Tasksystem;