#pragma once
#include"system.h"
#include"motor.h"
#include <string>
class Generic :public Obj
{
public:
	Generic(const Json::Value& pragma,const std::string name) :_name(name)
	{
		for (auto& it : pragma["马达"])
			_motorList.push_back(it);
		sysData->addObj(this);
		std::cout << _name << "类创建完成" << std::endl;
	}
	~Generic() = default;
	virtual void addRecoderData() override
	{
		sysData->addRecoderData({ static_cast<double>(_pwm)});
	}
	void set(const int pwm)
	{
		_pwm = pwm;
		_pwm = std::clamp(_pwm, -127, 127);
		for (auto &it : _motorList)
			it.set(_pwm);
	}
private:
	const std::string _name;
	 std::vector<Motor> _motorList;
	size_t _motorsNum = 0;
	int _pwm=0;

};