#include "Sample1.h"
#include "System.h"

Sample1::Sample1()
{
	std::cout << "Sample1()" << std::endl;
}
Sample1::~Sample1()
{
	std::cout << "~Sample()" << std::endl;
}
bool Sample1::Init(std::pair<std::string, std::string>* taskname_)
{
	this->setTaskName(*taskname_);
	return true;
}
void Sample1::UpDate()
{

}
bool Sample1::Finalize()
{
	return true;
}
void Sample1::Render()
{

}
Sample1::SP Sample1::Create(std::pair < std::string, std::string>* taskname_, bool flag)
{
	Sample1::SP to = Sample1::SP(new Sample1());
	if (to != nullptr)
	{
		if (flag)
		{
			if (!to->Init(taskname_))
			{
				to->Kill();
			}
		}
		return to;
	}
	return nullptr;
}
