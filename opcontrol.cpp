#include"main.h"
#include "poten.h"
#include <json.h>
#include <fstream>
#include "configRead.h"
#define MAX_BUF_LEN 1024

void delAllMark(std::string &s, const std::string &mark)
{
	size_t nSize = mark.size();
	while (1)
	{
		size_t pos = s.find(mark);    //  尤其是这里
		if (pos == std::string::npos)
		{
			return;
		}
		s.erase(pos, nSize);
	}

}
using DataTypeMotor = std::vector<std::string>;                                     //每一个马达的配置参数
using DataTypeMotorList =  std::vector<DataTypeMotor>;                         //马达组
void opcontrol()
{
	DataTypeMotorList data;
	size_t curr_line = 0;//计数器

	FILE* file = fopen("chassis.txt", "r");
	if (file == nullptr)
		std::cerr << "文件打开错误" << std::endl;
	char buf[MAX_BUF_LEN];
	while (fgets(buf, MAX_BUF_LEN, file) != nullptr)//读取一行
	{
		std::string line = buf;
		std::string key, val;
		delAllMark(line, " ");//删除多余的空格
		size_t del_idx = line.find("=");
		//我们每行只能有一个=
		if (line.find('=', del_idx + 1) != std::string::npos)//如果找到了第一个= 的后有还有=
		{
			std::cerr << "第 " << curr_line << " 超过一个=" << std::endl;
			std::cerr << "跳转第 " << curr_line + 1 << " 行读取" << std::endl;
			curr_line++;
			continue;
		}

		//解析密钥和值
		key = line.substr(0, del_idx);
		val = line.substr(del_idx + 1, line.length());
		//插入容器
		data.push_back({key,val});
		curr_line++;
	}
	for (auto &it : data)
	{
		for (auto &it1 : it)
			std::cout << it1;
		std::cout << std::endl;
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