#pragma once
#include <iostream>
#include "json.h"
class Motor
{
public:

	explicit Motor(const Json::Value& pragma) : _pragma(pragma)
	{
		init();
	}
	void set(int pwm)
	{

		std::cout << _pragma <<" pwm:"<<pwm << std::endl;
	}

	/**
	 *获取马达的名字
	 * @return std::string 返回马达的名字
	 */
	int getName()
	{
		return _pragma["端口"].asInt();
	}
	/**
	 *获取马达的端口号
	 * @return std::string 返回马达的名字
	 */
	bool getPort()
	{
		return _pragma["正反"].asBool();
	}
	/**
	 *返回马达正反
	 * @return std::string 返回马达正反
	 */
	int getRevase()
	{
		return _pragma["齿轮"].asInt();
	}
	/**
	 * @获取齿轮中文名字
	 *
	 * @return std::string 返回齿轮的中文名字
	 */
	//std::string getGearName()
	//{
	//	return _pragma.at(3);
	//}
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
		if (_pragma["齿轮"] == "0")
		{
			_speed = 100;
		}
		else if (_pragma["齿轮"] == "1")
		{
			_speed = 200;
		}
		else if (_pragma["齿轮"] == "2")
		{
			_speed = 600;
		}
		else
		{
			_speed = 100;
			std::cerr << "齿轮设置错误,已经马达设置为默认绿齿轮" << std::endl;
		}
		std::cout << _pragma["端口"] << ":" << _pragma["正反"] << " " << _pragma["齿轮"] << " "  << " 构造成功" << std::endl;
	}
	const Json::Value _pragma;
	int _speed = 0;
};