#pragma once

#include "TaskObject.h"
class TaskSystemGameObject : public TaskObject
{
public:
	typedef std::shared_ptr<TaskSystemGameObject> SP;
	typedef std::weak_ptr<TaskSystemGameObject>   WP;

	static TaskSystemGameObject::SP Create(const std::pair<std::string, std::string>& taskName, const bool& tasksystemFlag = true);
	virtual bool   Initialize();
	virtual void   Update()override;
	virtual void   Render()override;
	virtual bool   Finalize()override;
};