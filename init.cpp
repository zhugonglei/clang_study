#include "main.h"
#include "userConfig.h"
#include "json.h"
#include <iostream>
#include "motor.h"
#include "adi.h"
//SystemData* sysData;
//Chassis *chassis;
//Generic* lift;
//Generic* intake;
//Generic* shoot;

void init()
{

	std::string stu = R"({
  "机器人类型": "全能机",
  "队伍编号": "8982B",
  "用户": "sheep",
  "底盘": {
    "马达": [
      {
        "名字": "左前",
        "端口": 1,
        "正反": 0,
        "齿轮": 1
      },
      {
        "名字": "左后",
        "端口": 2,
        "正反": 1,
        "齿轮": 1
      },
      {
        "名字": "右前",
        "端口": 3,
        "正反": 1,
        "齿轮": 1
      },
      {
        "名字": "右后",
        "端口": 4,
        "正反": 0,
        "齿轮": 1
      }
    ],
    "ADI": [ { "陀螺仪": 1 } ],
    "参数": [  ]
  }
})";
	
Json::Value val;
Json::CharReaderBuilder jsreader;
std::unique_ptr<Json::CharReader> const reader(jsreader.newCharReader());
JSONCPP_STRING  err;
if (!reader->parse(stu.c_str(), stu.c_str() + stu.length(), &val, &err))
{
	std::cerr << "参数读取错误,请注意格式" << std::endl;
	return;
}
Motor a(val["底盘"]["马达"][3]);
ADI gyro(val["底盘"]["ADI"][0]);
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
	//sysData = new SystemData();
	//chassis = new Chassis( CHASSIS_PRAGMA);
	//lift = new Generic({ Motor{5,-1} }, "升降");
	//intake = new Generic({ Motor{6,-1} }, "吸吐");
	//shoot = new Generic({ Motor{7,-1}, Motor{8,1} }, "弹射");

}