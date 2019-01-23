#include"main.h"
#include "poten.h"
#include "configRead.h"
#include "json.h"
void opcontrol()
{
	//Json::Value  CHASSIS_PRAGMA = { {"左右矫正比例", "1.1"},
	//								   {"左右自瞄速度", "15"},
	//								   {"遥控器矫正", "10"},
	//								   {"最大旋转速度", "127"} };
	//std::cout << CHASSIS_PRAGMA.toStyledString() << std::endl;

	const char * stu = R"(  {
"年龄" : 22,
"height" : 1.78,
"姓名" : "Denny",
"number_array" : [1,2,3,4],
"object" : 
{
"someone" : "Kelly",
"sometime" : 2018,
"somewhere" : "city"
},
"object_array" : 
[
{
"string1" : "1-1",
"string2" : "1-2"
},
{
"string1" : "2-1",
"string2" : "2-2"
},
{
"string1" : "3-1",
"string2" : "3-2"
}
],
"play_football" : true,
"string_array" : 
[
"string01",
"string02",
"string03"
]
})";

	Json::Reader reader;
	Json::Value root;
	if (reader.parse(stu, root))  // reader将Json字符串解析到root，root将包含Json里所有子元素  
	{
		std::cout <<"姓名:"<< root["姓名"].asString() << " 年龄: " << root["年龄"].asInt()<<" "<<root["object"] << std::endl;
	}

	//Json::Value root;
	//Json::Reader reader;
	//std::ifstream ifs("example.json");//open file example.json

	//if (!reader.parse(ifs, root)) {
	//	// fail to parse
	//}
	//else {
	//	// success
	//	std::cout << root["你好"].asString() << std::endl;
	//	std::cout << root["indent"]["length"].asInt() << std::endl;
	//}

	//ncrapi::Poten poten(1, 5);
	//std::fstream fs("Text1.txt");
	//if (!fs.is_open())
	//	std::cerr << "file open error" << std::endl;
	//std::string temp;
	//while (std::getline(fs, temp))
	//{
	//	std::istringstream iss(temp);
	//	int val;
	//	iss >> val;
	//	poten.get(val, 1);
	//	poten.print();
	//	Sleep(10);
	//}
	//fs.close();

	//size_t i = 0;

	//while (i<=100)
	//{
	//	chassis->forward(127);
	//	lift->set(50);
	//	intake->set(-10);
	//	shoot->set(20);
	//	for (auto &it : sysData->_objData)
	//		it->addRecoderData();
	//	i++;
	//	Sleep(100);
	//}
	//sysData->showRecoderData();
	delete sysData;
	delete chassis;
}