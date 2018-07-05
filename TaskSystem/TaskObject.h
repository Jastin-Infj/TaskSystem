#pragma once
#include <vector>
#include <memory>

/*前方宣言*/
struct KillSystem;

///<summary>
///
///</summary>
///<returns>
///
///</returns>

///<summary>
///新しいオブジェクトを生成するクラス
///</summary>

class TaskObject : public KillSystem
{
public:
///メンバ変数

	typedef std::shared_ptr<TaskObject> SP;

///メンバ関数

	///<summary>
	///コンストラクタ
	///</summary>
	///<returns>
	///なし
	///</returns>
	TaskObject(std::pair<std::string,std::string>*);


	///<summary>
	///デストラクタ
	///</summary>
	virtual ~TaskObject();


	///<summary>
	///生成します
	///</summary>
	///<returns>
	///生成したスマートポインタ
	///</returns>
	static TaskObject::SP Create(std::pair < std::string, std::string>*, bool = true);

	///<summary>
	///タスク名を返します
	///</summary>
	std::string getTaskname()const;

	
	///<summary>
	///初期化処理
	///</summary>
	///<returns>
	///初期化処理終了 true
	///</returns>
	virtual bool Init();

	///<summary>
	///更新処理
	///</summary>
	///<returns>
	///なし
	///</returns>
	virtual void UpDate();


	///<summary>
	///描画処理
	///</summary>
	///<returns>
	///なし
	///</returns>
	virtual void Render();


	///<summary>
	///解放処理
	///</summary>
	///<returns>
	///解放処理終了　true
	///</returns>
	virtual bool Finalize();


private:

///メンバ変数

	///<summary>
	///グループ名 , タスク名
	///</summary>
	std::pair<std::string, std::string> taskname;
///メンバ関数
	
};