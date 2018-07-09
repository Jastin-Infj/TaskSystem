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
	///オブジェクトのアドレス値をシステムに登録します
	///</summary>
	///<returns>
	///なし
	///</returns>
	void Add(TaskObject::SP);

	///<summary>
	///オブジェクトのグループ名・タスク名をシステムに登録します
	///</summary>
	///<returns>
	///なし
	///</returns>
	void Add(std::pair<std::string, std::string>&);


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
	///グループ名・タスク名で登録しているオブジェクトを削除します
	///</summary>
	///<returns>
	///なし
	///</returns>
	void TaskNameDelete(std::string&,std::string&);
private:
	std::vector<std::pair<std::string, std::string>, TaskObject::SP> taskobjects;
	std::vector<std::pair<std::string, std::string>, TaskObject::SP> addobjects;

	///<summary>
	///登録予定のオブジェクトを統括用のオブジェクトに追加します
	///</summary>
	///<returns>
	///なし
	///</returns>
	void toTaskObjects();
};
extern System* Tasksystem;