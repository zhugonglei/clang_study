#pragma once
#include <iostream>
#include <vector>
#include"obj.h"
#include <memory>
class SystemData
{
public:
	std::vector<std::vector<double>> _recoderData;
	std::vector<Obj *> _objData;
	SystemData() { std::cout << "sysData create successful" << std::endl; }
	~SystemData() = default;
	void addObj(Obj * obj)
	{
		_objData.push_back(obj);
	}
	void addRecoderData(std::vector<double> data)
	{
		_recoderData.push_back(data);
	}
	void showRecoderData()
	{
		for (auto &it1 : _recoderData)
		{
			for (auto &it2 : it1)
				std::cout << it2 << ";";
			std::cout << std::endl;
		}
	}
	void playBack()
	{

	}
private:

};
extern SystemData* sysData;
