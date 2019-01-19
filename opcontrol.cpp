#include"main.h"
#include "poten.h"
#include <json.h>

void opcontrol()
{
	Json::Value root;   // 'root' will contain the root value after parsing.
	std::cin >> root;
	Json::Reader reader;
	// You can also read into a particular sub-value.
	std::cin >> root["subtree"];
	// Get the value of the member of root named 'encoding',
	// and return 'UTF-8' if there is no such member.
	std::string encoding = root.get("encoding", "UTF-8").asString();
	// Get the value of the member of root named 'plug-ins'; return a 'null' value if
	// there is no such member.
	const Json::Value plugins = root["plug-ins"];
	// Iterate over the sequence elements.
	//for (int index = 0; index < plugins.size(); ++index)
	//	loadPlugIn(plugins[index].asString());

	//// Try other datatypes. Some are auto-convertible to others.
	//foo::setIndentLength(root["indent"].get("length", 3).asInt());
	//foo::setIndentUseSpace(root["indent"].get("use_space", true).asBool());
	//// Since Json::Value has an implicit constructor for all value types, it is not
	//// necessary to explicitly construct the Json::Value object.
	//root["encoding"] = foo::getCurrentEncoding();
	//root["indent"]["length"] = foo::getCurrentIndentLength();
	//root["indent"]["use_space"] = foo::getCurrentIndentUseSpace();
	// If you like the defaults, you can insert directly into a stream.
	std::cout << root;
	// Of course, you can write to `std::ostringstream` if you prefer.
	// If desired, remember to add a linefeed and flush.
	std::cout << std::endl;


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