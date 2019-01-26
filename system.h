#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <vector>
#include"obj.h"
#include <memory>
#include "json.h"
class SystemData
{
public:
	Json::Value jsonVal;//根数据
	Json::CharReaderBuilder jsreader;//读取器
	Json::StreamWriterBuilder  builder;//写入器
	JSONCPP_STRING  jsonErr;//异常流
	SystemData(std::string jsonData)
	{
		//std::unique_ptr<Json::CharReader> const reader(jsreader.newCharReader());
		//if (!reader->parse(jsonData.c_str(), jsonData.c_str() + jsonData.length(), &jsonVal, &jsonErr))
		//{
		//	std::cerr << "json解析错误" << std::endl;
		//	return;
		//}
		readSDcard();
		saveData();
	}
	std::vector<std::vector<double>> _recoderData;
	std::vector<Obj*> _objData;
	SystemData() { std::cout << "sysData create successful" << std::endl; }
	~SystemData() = default;
	void addObj(Obj* obj)
	{
		_objData.push_back(obj);
	}
	void addRecoderData(std::vector<double> data)
	{
		_recoderData.push_back(data);
	}
	void showRecoderData()
	{
		for (auto& it1 : _recoderData)
		{
			for (auto& it2 : it1)
				std::cout << it2 << ";";
			std::cout << std::endl;
		}
	}
	bool readSDcard()
	{
		FILE* file = fopen("demo.json", "r");
		if (file == nullptr)
		{
			std::cerr << "文件打开错误" << std::endl;
			return false;
		}
		char buf[1024];
		std::string line;
		while (fgets(buf, 1024, file) != nullptr) //读取一行
			line += buf;
		//std::cout << line << std::endl;

		std::unique_ptr<Json::CharReader> const reader(jsreader.newCharReader());
		if (!reader->parse(line.c_str(), line.c_str() + line.length(), &jsonVal, &jsonErr))
		{
			std::cerr << "json解析错误!" << std::endl;
			return false;
		}
		fclose(file);
		return true;
	}
	//void rebuildSDcard(const DataConfigList &tempData, std::string name)
	//{
	//	if (name == "底盘")
	//		pathData.insert({ name ,{"chassis.txt" } }); //try_emplace 尝试插入 如果KEY 存在就不插入了不存在就插入
	//	else if (name == "云台")
	//		pathData.insert({ name, {"head.txt"} });
	//	else if (name == "吸吐")
	//		pathData.insert({ name, {"intake.txt"} });
	//	else if (name == "旋转器")
	//		pathData.insert({ name, {"rotateIntake.txt" } });
	//	else if (name == "夹子")
	//		pathData.insert({ name, {"capIntake.txt"} });
	//	else if (name == "升降")
	//		pathData.insert({ name, {"lift.txt" }		});
	//	else if (name == "弹射")
	//		pathData.insert({ name, {"shoot.txt"} });
	//	else if (name == "前后pid")
	//		pathData.insert({ name,{ "frpid.txt"} });
	//	else if (name == "左右pid")
	//		pathData.insert({ name, {"rotatepid.txt" }
	//			});
	//	else
	//	{
	//		std::cerr << "读取部件名字错误,请检查程序" << std::endl;
	//		return; //跳出该函数
	//	}
	//	configData.try_emplace(name, tempData);
	//	bool flag = readSDcard(configData[name], name); //判断文件是否已经存在
	//	if (!flag)
	//	{
	//		std::cerr << name << "没有搜索到" << name << "config文件.重新创建!请注意重新配置相关信息" << std::endl;
	//		bool flag = saveData(tempData, name);
	//		if (!flag)
	//			std::cerr << name << " config文件二次保存失败!,请检查SD卡是否插入或者SD卡是否损坏!" << std::endl;
	//		else
	//			std::cout << name << " config文件创建成功" << std::endl;
	//	}
	//}
	std::string UTF8ToGBK(const std::string& strUTF8)
	{
		int len = MultiByteToWideChar(CP_UTF8, 0, strUTF8.c_str(), -1, nullptr, 0);
		WCHAR* wszGBK = new WCHAR[len + 1];
		memset(wszGBK, 0, len * 2 + 2);
		MultiByteToWideChar(CP_UTF8, 0, (LPCCH)strUTF8.c_str(), -1, wszGBK, len);
		len = WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, nullptr, 0, nullptr, nullptr);
		char* szGBK = new char[len + 1];
		memset(szGBK, 0, len + 1);
		WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, szGBK, len, nullptr, nullptr);
		std::string strTemp(szGBK);
		delete[]szGBK;
		delete[]wszGBK;
		return strTemp;
	}
	std::string GBKToUTF8(const std::string& strGBK)
	{
		std::string strOutUTF8 = "";
		WCHAR* str1;
		int n = MultiByteToWideChar(CP_ACP, 0, strGBK.c_str(), -1, nullptr, 0);
		str1 = new WCHAR[n];
		MultiByteToWideChar(CP_ACP, 0, strGBK.c_str(), -1, str1, n);
		n = WideCharToMultiByte(CP_UTF8, 0, str1, -1, nullptr, 0, nullptr, nullptr);
		char* str2 = new char[n];
		WideCharToMultiByte(CP_UTF8, 0, str1, -1, str2, n, nullptr, nullptr);
		strOutUTF8 = str2;
		delete[]str1;
		delete[]str2;
		return strOutUTF8;
	}
	bool saveData()
	{
		FILE* file = fopen("save.json", "w");
		if (file == nullptr)
		{
			std::cerr << " 保存失败" << std::endl;
			return false;
		}
		std::ostringstream os;
		std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
		writer->write(jsonVal, &os);
		//std::string tempStr= UTF8ToGBK(jsonVal.toStyledString());
		std::cout << os.str() << std::endl;
		fprintf(file, "%s", os.str().c_str()); //逐行录入
		fclose(file);
		return true;
	}
private:
};
extern SystemData* sysData;
