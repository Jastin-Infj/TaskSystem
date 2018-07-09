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
	///オブジェクトの消去依頼をします
	///</summary>
	///<returns>
	///なし
	///</returns>
	void Kill();


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
	typedef std::shared_ptr<TaskObject> WP;

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
	///タスク名・グループ名を返します
	///</summary>
	std::pair<std::string, std::string> getObjectname()const;
	
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


	///<summary>
	///キルカウンタを増加させます
	///</summary>
	///<returns>
	///なし
	///</returns>
	void TaskKill();


	///<summary>
	///Killカウンタを返します
	///</summary>
	int  getKillCounter()const;


private:

///メンバ変数

	///<summary>
	///グループ名 , タスク名
	///</summary>
	std::pair<std::string, std::string> taskname;

///メンバ関数
	
};