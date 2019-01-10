#include"main.h"
#include "poten.h"
#include <fstream> 
#include <sstream>
void opcontrol()
{


	ncrapi::Poten poten(1, 5);
	std::fstream fs("Text1.txt");
	if (!fs.is_open())
		std::cerr << "file open error" << std::endl;
	std::string temp;
	while (std::getline(fs, temp))
	{
		std::istringstream iss(temp);
		int val;
		iss >> val;
		poten.get(val, 1);
		poten.print();
		Sleep(10);
	}
	fs.close();

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