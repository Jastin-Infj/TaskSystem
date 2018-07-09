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
	this->TaskObjectDelete();
	std::cout << "~System" << std::endl;
}
/*オブジェクトをシステムに登録します*/
void System::Add(TaskObject::SP object)
{
	//this->taskobjects.push_back(object);
}
/*オブジェクトをシステムに登録します*/
void System::Add(std::pair<std::string, std::string>& taskname_)
{
	this->taskobjects.push_back(taskname_);
}

/*追加予定のオブジェクトを統括オブジェクトに登録します*/
void System::toTaskObjects()
{
	
}
/*登録しているオブジェクトVectorを返します*/
std::vector<TaskObject::SP> System::getTaskObjects()const
{
	
}
/*登録しているオブジェクトのタスク名を返します*/
void System::TasknameOutput()const
{
	
}
/*登録しているオブジェクトの更新処理を行います*/
void System::UpDate()
{
	
}
/*登録しているオブジェクトの描画処理を行います*/
void System::Render()
{
	
}
/*登録しているオブジェクトの消去できるかをチェックします*/
void System::Destory()
{
	
}
/*登録しているオブジェクトのグループ名・タスク名を検索してオブジェクトを削除します*/
void System::TaskNameDelete(std::string& group_ , std::string& taskname_)
{
	
}
/*登録しているオブジェクトの全消去を行います*/
void System::TaskObjectDelete()
{
	
}