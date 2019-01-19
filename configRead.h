#pragma once
#include <algorithm>
#include <exception>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <sstream>
#include <string>
#include <type_traits>
#define MAX_BUF_LEN 1024


//  Helper函数，如果字符串读取，则将字符串转换为bool
//  true它返回true，否则返回false
bool to_bool(std::string str) {
	std::transform(str.begin(), str.end(), str.begin(), ::tolower);
	if (str.compare("true") == 0) return true;
	else if (str.compare("false") == 0) return false;
	else throw std::invalid_argument("Boolean can only be false or true, impartial to case.");
}

class ConfigReader
{
	// Default Constructor构建内部数据结构
	ConfigReader()
	{
		if (!parse_file()) throw ConfigReaderException();
	}

	// /在以下情况下使用的异常：
// /  - 构造函数失败
	class ConfigReaderException : public std::exception
	{
		virtual const char* what() const throw()
		{
			return "A ConfigReaderException happened";
		}
	};

	//如果发生不可更改的错误，请尝试解析配置文件
	//我们返回fasel，如果该行是格式错误的跳过行，否则
	// 返回true
	bool parse_file()
	{
		size_t curr_line = 0;//计数器

		FILE* file = fopen("chassis.txt", "r");
		if (file == nullptr)
			return false;
		char buf[MAX_BUF_LEN];
		while (fgets(buf, MAX_BUF_LEN, file) != nullptr)//读取一行
		{
			std::string line = buf;
			std::string key, val;
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
			std::cout << "key:" << key << " val:" << val << std::endl;
			//插入容器
		/*	m_cfg_data[key] = val;*/

			curr_line++;
		}
		return true;
	}

	static ConfigReader* s_instance;

	// / Datastruct在内部保存配置文件
	std::unordered_map<std::string, std::string> m_cfg_data;

public:

	//返回与key对应的值作为std :: string
	std::string get(std::string key)
	{
		auto search = m_cfg_data.find(key);

		if (search == m_cfg_data.end())
		{
			std::cerr << "Can't find key: " << key << std::endl;
			return "";
		}

		return search->second;
	}

	/**
	* SFINAE用于补偿解析原始数据类型。
	*如果请求复杂数据类型，我们假设一个构造函数
	形式为foo（std::string）的*可用。
	*/
	// / INTEGRAL TYPES
	template<class T, typename std::enable_if<std::is_integral<T>::value && !std::is_same<bool, T>::value>::type* = nullptr>
	T get_as(std::string key)
	{
		auto found_val = this->get(key);
		T ret_val = 0;
		try
		{
			ret_val = std::stoi(found_val);
		}
		catch (const std::invalid_argument& ia)
		{
			std::cerr << "Key: " << key << " throws Invalid Argument" << std::endl;
			std::cerr << ia.what() << std::endl;
			return T();
		}
		return ret_val;
	}

	// /浮动类型
	template<class T, typename std::enable_if<std::is_floating_point<T>::value>::type* = nullptr>
	T get_as(std::string key)
	{
		auto found_val = this->get(key);
		T ret_val = 0.0f;
		try
		{
			ret_val = std::stod(found_val);
		}
		catch (const std::invalid_argument& ia)
		{
			std::cerr << "Key: " << key << " throws Invalid Argument" << std::endl;
			std::cerr << ia.what() << std::endl;
			return T();
		}
		return ret_val;
	}

	// / BOOL
	template<class T, typename std::enable_if<std::is_same<bool, T>::value>::type* = nullptr>
	T get_as(std::string key)
	{
		auto found_val = this->get(key);
		T ret_val = to_bool(found_val);
		return ret_val;
	}
	// / COMPLEX TYPE
	template<class T, typename std::enable_if<std::is_class<T>::value>::type* = nullptr>
	T get_as(std::string key)
	{
		auto found_val = this->get(key);
		return T(found_val);
	}

	//实现单例
	static ConfigReader* instance()
	{
		if (ConfigReader::s_instance == nullptr) ConfigReader::s_instance = new ConfigReader();
		return s_instance;
	}
};