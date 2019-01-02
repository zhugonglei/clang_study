#pragma once
#include"system.h"
class Chassis:public Obj
{
public:
	Chassis(const std::string &name):_name(name)
	{
		sysData->addObj(this);
		std::cout << _name << "类创建完成" << std::endl;

	}
	~Chassis() = default;
	virtual void addRecoderData() override
	{
		sysData->addRecoderData({112.22,333,33});
	}
private:
	const std::string _name;
};
