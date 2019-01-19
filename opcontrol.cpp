#include"main.h"
#include "poten.h"
#include <json.h>
#include <fstream>
#define MAX_BUF_LEN 1024
void opcontrol()
{
	FILE* file = fopen("example.json", "r");
	char buf[MAX_BUF_LEN];
	while (fgets(buf, MAX_BUF_LEN, file) != nullptr)//读取一行
	{
		std::string temp = buf;
		std::cout << temp ;
	}

	//Json::Value root;
	//Json::Reader reader;
	//std::string test = "{\"name\" : \
	//						\"Tocy\", \"salary\" : 100, \"msg\" : \"work hard\", \
 //       \"files\" : [\"1.ts\", \"2.txt\"]}";
	//std::vector<std::pair<std::string, std::string>> test2 = ;
	//if (!reader.parse(test2, root)) {
	//	// "parse fail";
	//}
	//else
	//	std::cout << root["王八蛋"].asString();//print "UP000000"

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
}