#pragma once
#include"system.h"
#include"motor.h"
class Chassis:public Obj
{
public:
	Chassis(const std::vector<Motor> &motorList,const std::string &name):_motorList(motorList),_name(name)
	{
		_sideMotors = _motorList.size() / 2;
		if (_sideMotors % 2 != 0)
			std::cerr << "底盘马达设定数量必须是偶数!" << std::endl;
		sysData->addObj(this);
		std::cout << _name << "类创建完成" << std::endl;

	}
	~Chassis() = default;
	virtual void addRecoderData() override
	{
		sysData->addRecoderData({ static_cast<double>(_pwm) });
	}
	void set(int left, int right)
	{
		for (size_t i = 0; i < _sideMotors; i++)
			_motorList[i].set(left);
		for (size_t i = _sideMotors; i < _motorList.size(); i++)
			_motorList[i].set(left);
	}
	void forward(const int pwm)
	{
		_pwm = pwm;
		set(_pwm ,_pwm);
	}
private:
	const std::string _name;
	 std::vector<Motor> _motorList;
	int _pwm=0;
	size_t _sideMotors = 0;
};
