#include"main.h"
#include "poten.h"
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
using DataTypeMotorList = std::vector<DataTypeMotor>;                         //马达组
void opcontrol()
{
	DataTypeMotorList data;
	FILE* file = fopen("chassis.txt", "r");
	if (file == nullptr)
		std::cerr << "文件打开错误" << std::endl;
	char buf[MAX_BUF_LEN];
	std::string line;

	while (fgets(buf, MAX_BUF_LEN, file) != nullptr)//读取一行
	{
		line = buf;
		DataTypeMotor tempData;
		delAllMark(line, " ");//删除多余的空格
		size_t del_idx = line.find("=");//记录等号的位置
		//解析密钥和值
		tempData.push_back(line.substr(0, del_idx));//添加KEY的值
		std::string val = line.substr(del_idx + 1, line.length());//添加VAL的值
		size_t val_idx = val.find(",");//搜索VAL的值记住找点 "," 的位置
		if (val_idx != std::string::npos)//如果搜到了逗号
			while (1)
			{
				tempData.push_back(val.substr(0, val_idx));//添加从0到逗号的区域
				val.erase(0, val_idx + 1);//删除逗号和逗号前的值
				val_idx = val.find(",");//迭代 继续找,号 m
				if (val_idx == std::string::npos)//如果最后没找到逗号了
				{
					tempData.push_back(val);//剩下的所有值全加进去
					break;
				}

			}
		else//没找到逗号就一个值咯
			tempData.push_back(val);
		//插入容器
		data.push_back({ tempData });
	}
	fclose(file);
	for (auto &it : data)
	{
		for (auto &it1 : it)
			std::cout << it1 << " ";
		//std::cout << std::endl;
	}
	FILE *outFile = fopen("chassisFilter", "w");
	if (outFile == nullptr)
		std::cerr << "文件保存失败" << std::endl;
	for (auto &it : data)
	{
		std::string tempStr;//临时变量
		for (auto &it1 : it)
		{
			if (it1 == it.front())//如果是第一个元素 KEY
			{
				tempStr = it1;
				tempStr += "=";
			}
			else //VAL
			{
				tempStr += it1;
				if (it1 != it.back())//最后一个值后面不加逗号
					tempStr += ",";
			}
		}
		fprintf(outFile, "%s", tempStr.c_str());//逐行录入
	}
	fclose(file);
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