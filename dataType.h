#pragma once
#include <any>
#include <string>
#include <tuple>
#include <vector>

	using DataConfig = std::vector<std::string>;           //保存一组CONFIG的类型
	using DataConfigList = std::vector<DataConfig>;        //马达组
	using DataConfigListSet = std::vector<DataConfigList>; //config列表的类型

	using PidDebugTuple = std::tuple<uint32_t, double, double, double, double, double>; //PIDDATA的类型