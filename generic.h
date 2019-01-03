#pragma once
#include"system.h"
#include"motor.h"
#include <string>
class Generic :public Obj
{
public:
	Generic(const std::vector<Motor> &motorList,const std::string name) :_motorList(motorList),_name(name)
	{
		if (_motorList.size() == 0)
			std::cerr<<_name << "达设定数量必须大于0!" << std::endl;
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
	int _pwm;

};