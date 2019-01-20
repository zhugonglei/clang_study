#pragma once
#include <iostream>
class Motor
{
public:
	explicit Motor(const std::string &name, const std::string &port, const std::string &isRevase, const std::string &gearset = "绿齿轮") : _pragma({ name, port, isRevase })
	{
		init();
	}
	explicit Motor(const DataConfig &pragma) : _pragma(pragma)
	{
		init();
	}
	void set(int pwm)
	{
		std::cout << _pragma[0] <<" pwm:"<<pwm << std::endl;
	}

	/**
	 *获取马达的名字
	 * @return std::string 返回马达的名字
	 */
	std::string getName()
	{
		return _pragma.at(0);
	}
	/**
	 *获取马达的端口号
	 * @return std::string 返回马达的名字
	 */
	std::string getPort()
	{
		return _pragma.at(1);
	}
	/**
	 *返回马达正反
	 * @return std::string 返回马达正反
	 */
	std::string getRevase()
	{
		return _pragma.at(2);
	}
	/**
	 * @获取齿轮中文名字
	 *
	 * @return std::string 返回齿轮的中文名字
	 */
	std::string getGearName()
	{
		return _pragma.at(3);
	}
	/**
	 *获取当前齿轮的速度
	 * @return int 范湖齿轮的速度 红齿轮100 绿齿轮200 蓝齿轮600
	 */
	int getGearSpeed()
	{
		return _speed;
	}

private:
	void init()
	{
		if (_pragma.at(3) == "红齿轮")
		{
			_speed = 100;
		}
		else if (_pragma.at(3) == "绿齿轮")
		{
			_speed = 200;
		}
		else if (_pragma.at(3) == "蓝齿轮")
		{
			_speed = 600;
		}
		else
		{
			_speed = 100;
			std::cerr << "齿轮设置错误,已经马达设置为默认绿齿轮" << std::endl;
		}
		std::cout << _pragma.at(0) << ":" << _pragma.at(1) << " " << _pragma.at(2) << " " << _pragma.at(3) << " 构造成功" << std::endl;
	}
	const DataConfig _pragma;
	int _speed = 0;
};