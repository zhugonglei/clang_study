#pragma once
#include <iostream>
#include "json.h"
class ADI
{
public:

	 ADI(const Json::Value& pragma ,const std::string name) :
		_port(pragma[name].asUInt()), _name(name)
	{
		init();
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
private:
	void init()
	{
		std::cout << "ADI " << _name << "[" << _port << "]" << " 构造成功" << std::endl;
	}
private:
	const size_t _port;
	const std::string _name;
};