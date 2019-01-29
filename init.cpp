#include "main.h"
#include "userConfig.h"
#include <iostream>
#include "json.hpp"
using json=nlohmann::json;
//SystemData* sysData;
//Chassis* chassis;
//Generic* lift;
//Generic* intake;
//Generic* shoot;

void init()
{
	json jsondata;
	json array = json::array();//创建一个空数组
	 array = {
			{{"a",6}},
			"xin",8
	};
	//输出数组中第一个元素"a"对应的键值
	std::for_each(array.begin(), array.end(), [](auto it) {std::cout << it << std::endl; });

	//Motor a(val["底盘"]["马达"][3]);
	//ADI gyro(val["底盘"]["ADI"][0]);
	//on::Value::Members key = val["底盘"]["马达"]["左前"].getMemberNames();
	//std::cout << val["底盘"]["马达"].size() << std::endl;
	//std::cout << val["Skills"][0].asString() << std::endl;
	//size_t count = 0;
	//for (auto& it : val["底盘"]["马达"]["右后"])
	//{
	//	auto key = val["底盘"]["马达"]["右后"].getMemberNames();
	//	std::cout << key[count] << " : " << it.asInt() << std::endl;
	//	count++;
	//}
		//for (auto &it:key) //遍历json成员
		//{
		//	std::string name = it;
		//	int flag = val[it].asInt();
		//	std::cout << name << ":" << flag << std::endl;
		//}
	//sysData = new SystemData(jsonData);
	//chassis = new Chassis(sysData->jsonVal["底盘"]);
	//lift = new Generic({ Motor{5,-1} }, "升降");
	//intake = new Generic({ Motor{6,-1} }, "吸吐");
	//shoot = new Generic({ Motor{7,-1}, Motor{8,1} }, "弹射");

}