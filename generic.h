#pragma once
#include"system.h"
class Generic :public Obj
{
public:
	Generic(const std::string name) :_name(name)
	{
		sysData->addObj(this);
		std::cout << _name << "类创建完成" << std::endl;
	}
	~Generic() = default;
	virtual void addRecoderData() override
	{
		sysData->addRecoderData({ 1.1111,2.2222 });
	}
private:
	const std::string _name;
};