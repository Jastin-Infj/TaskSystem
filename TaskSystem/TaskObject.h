#pragma once
#include <vector>
#include <memory>

///<summary>
///
///</summary>
///<returns>
///
///</returns>

///<summary>
///タスクを消滅させるクラス
///</summary>
class KillSystem
{
public:

	///メンバ関数

	///<summary>
	///コンストラクタ
	///</summary>
	KillSystem();


	///<summary>
	///デストラクタ
	///</summary>
	~KillSystem();


	///<summary>
	///キルカウンタを増加させます
	///</summary>
	///<returns>
	///なし
	///</returns>
	void KillCount();


	///<summary>
	///消滅させるかどうかを判定します
	///</summary>
	///<returns>
	///消滅させる　true : 消滅しない false
	///</returns>
	bool KillCheck();


	///<summary>
	///killcountを返します
	///</summary>
	int getKillcount()const;

private:

	///メンバ変数

	int killcount;
};


///<summary>
///新しいオブジェクトを生成するクラス
///</summary>
class TaskObject : private KillSystem
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
	TaskObject();


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
	///初期化処理
	///</summary>
	///<returns>
	///初期化処理終了 true
	///</returns>
	virtual bool Init(std::pair<std::string, std::string>*);

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


	///<summary>
	///オブジェクトを消去します
	///</summary>
	///<returns>
	///オブジェクトを消去　true : オブジェクトを消去していない　false
	///</returns>
	bool Kill();

	
	///<summary>
	///Killカウンタを返します
	///</summary>
	int  getKillCounter();


	///<summary>
	///グループ名・タスク名を返します
	///</summary>
	std::pair<std::string,std::string> getTaskname()const;


	///<summary>
	///グループ名・タスク名をセットします
	///</summary>
	void setTaskName(std::pair<std::string, std::string>&);


private:

///メンバ変数

	///<summary>
	///グループ名 , タスク名
	///</summary>
	std::pair<std::string, std::string> taskname;

///メンバ関数
	
};