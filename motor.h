#pragma once
#include <iostream>
#include "json.h"
class Motor
{
public:

	 Motor(const Json::Value& pragma) :
		_port(pragma["端口"].asUInt()), _isRevase(pragma["正反"].asBool()),_gear(pragma["齿轮"].asUInt()),_name(pragma["名字"].asString())
	{
		init();
	}
	void set(int pwm)
	{

		std::cout <<"马达["<< _port <<"] pwm:"<<pwm << std::endl;
	}

	/**
	 *获取马达的名字
	 * @return std::string 返回马达的名字
	 */
	std::string getName()
	{
		return _name;
	}
	/**
	 *获取马达的端口号
	 * @return std::string 返回马达的名字
	 */
	size_t getPort()
	{
		return _port;
	}
	/**
	 *返回马达正反
	 * @return std::string 返回马达正反
	 */
	bool  getRevase()
	{
		return _gear;
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
		if (_gear == 0)
		{
			_speed = 100;
		}
		else if (_gear == 1)
		{
			_speed = 200;
		}
		else if (_gear == 2)
		{
			_speed = 600;
		}
		else
		{
			_speed = 100;
			std::cerr << "齿轮设置错误,已经马达设置为默认绿齿轮" << std::endl;
		}
		std::cout << "马达 "<<_name<< "[" <<_port<<"]"<< ":" << _isRevase << " " << _gear << " " << " 构造成功" << std::endl;
	}
private:
	const size_t _port;
	const bool _isRevase;
	const size_t _gear;
	const std::string _name;
	int _speed = 0;
};