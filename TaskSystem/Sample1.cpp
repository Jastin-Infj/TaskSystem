#include "Sample1.h"
#include "System.h"

#include <string>
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
	std::cout << this->getTaskname().second << "UpDate()" << std::endl;
}
bool Sample1::Finalize()
{
	return true;
}
void Sample1::Render()
{
	std::cout << this->getTaskname().second << "Render()" << std::endl;
}
Sample1::SP Sample1::Create(std::pair < std::string, std::string>* taskname_, bool flag)
{
	Sample1::SP to = Sample1::SP(new Sample1());
	if (to != nullptr)
	{
		if (!to->Init(taskname_))
		{
			to->Kill();
		}
		if (flag)
		{
			Tasksystem->Add(&to->getObjectMe(to));
		}
		return to;
	}
	return nullptr;
}
