#pragma once
#include "TaskObject.h"

/*
このクラスはサンプル１です
*/
class Sample1 : public TaskObject
{
public:
	typedef std::shared_ptr<Sample1> SP;

	Sample1();
	virtual ~Sample1();

	bool Init(std::pair<std::string, std::string>*)override;
	
	/* 生成をします */
	static Sample1::SP Create(std::pair < std::string, std::string>*, bool = true);
private:

	void UpDate()override;
	void Render()override;
	bool Finalize()override;
};