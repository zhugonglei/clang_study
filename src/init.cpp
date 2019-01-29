#include "json.hpp"
#include "main.h"
#include "testconfig.hpp"
#include <iostream>

using json = nlohmann::json;
// SystemData* sysData;
// Chassis* chassis;
// Generic* lift;
// Generic* intake;
// Generic* shoot;

void init()
{
    // #if defined XXX
    std::cout << "你好世界" << std::endl;
    // #else

    // #endif
    //   json jsonData = {"撒旦法", 6, "暗示法的", 8};
    //   std::cout << jsonData[0] << std::endl;
    //��������е�һ��Ԫ��"a"��Ӧ�ļ�ֵ
    // std::for_each(jsonData.begin(), jsonData.end(), [](auto it) {std::cout <<
    // it << std::endl; });

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