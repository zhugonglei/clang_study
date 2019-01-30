#include "main.h"
#include "system/tsl/ordered_map.h"
#include "testconfig.hpp"
#include <iostream>

// SystemData* sysData;
// Chassis* chassis;
// Generic* lift;
// Generic* intake;
// Generic* shoot;

void init()
{

    tsl::ordered_map<std::string, int> m{{"陈老师", 100}, {"狗老鼠", 50}, {"大挂", 80}, {"薄薄", 60}};

    for (auto &it : m)
        std::cout << it.first << " " << it.second << std::endl;
    std::cout << m.find("大挂")->second << std::endl;
    // std::for_each(userData.begin(), userData.end(), [](auto it) { std::cout << it << std::endl; });
    //std::cout << userData["底盘"] << std::endl;
    // std::cout
    //     << userData.dump(4) << std::endl;
    // Motor a(val["����"]["���"][3]);
    // ADI gyro(val["����"]["ADI"][0]);
    // on::Value::Members key = val["����"]["���"]["��ǰ"].getMemberNames();
    // std::cout << val["����"]["���"].size() << std::endl;
    // std::cout << val["Skills"][0].asString() << std::endl;
    // size_t count = 0;
    // for (auto& it : val["����"]["���"]["�Һ�"])
    //{
    //	auto key = val["����"]["���"]["�Һ�"].getMemberNames();
    //	std::cout << key[count] << " : " << it.asInt() << std::endl;
    //	count++;
    //}
    // for (auto &it:key) //����json��Ա
    //{
    //	std::string name = it;
    //	int flag = val[it].asInt();
    //	std::cout << name << ":" << flag << std::endl;
    //}
    // sysData = new SystemData(jsonData);
    // chassis = new Chassis(sysData->jsonVal["����"]);
    // lift = new Generic({ Motor{5,-1} }, "����");
    // intake = new Generic({ Motor{6,-1} }, "����");
    // shoot = new Generic({ Motor{7,-1}, Motor{8,1} }, "����");
}