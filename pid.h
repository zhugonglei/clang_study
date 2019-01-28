#pragma once
#include "json.h"
#include <string>
#include <iostream>
class Pid
{
public:
	Pid(const Json::Value pragma, const std::string &name):_name(name)
	{
		for (auto& it : pragma[name])
			for (auto& it1 : it)
				_pragma.push_back(it1.asDouble());
		std::cout << "PID基类构建完成,以下为参数:" << std::endl;
		for (auto& it : _pragma)
			std::cout << it << std::endl;
	}

private:
	std::vector<double> _pragma;
	std::string _name;
};
