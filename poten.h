#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include"util.h"
namespace ncrapi {
	class Poten
	{
	public:
		Poten(const size_t &port, const size_t &maxDataNum, const int &maxFlag = 5) :_port(port), _maxDataNums(maxDataNum), _MaxFlag(maxFlag)
		{
			std::cout << "poten[" << _port << "]create successful" << std::endl;
			_maxDataNums = std::clamp(_maxDataNums, static_cast<size_t>(2), static_cast <size_t>(50));
			std::cout << "MaxData is : " << _maxDataNums << std::endl;

		}

		int get(int num, int state = 2) //模拟参数num 实际没有
		{
			int tempVal = num;
			int temp = tempVal - _lastData;//变化值
			if (state == 2)//如果是自动读取模式
			{
				if (abs(temp) >= _threshold + 20 && _count > _maxDataNums)//如果变化超限 且记录数等于最大记录数
				{
					std::cerr << "数值变化超限! 模拟值:";
					tempVal = (_lastData + _threshold * _state);
				}
				else//变化没有超限
				{
					_threshold = (_threshold + abs(temp)) / 2;//计算平均阈值
					if (temp > 0)
						_flag++;
					else if (temp < 0)
						_flag--;
					else
						_flag = 0;
					_flag = std::clamp(_flag, -_MaxFlag, _MaxFlag);
				}
				_state = copySign(_flag);
			}
			else//自主设定模式
			{
				_state = state;
				if ((abs(temp) >= _threshold + 20 && _count > _maxDataNums ) || (copySign(temp) != state && abs(temp) >= 3))//如果变化超限 且记录数等于最大记录数
				{
					tempVal = (_lastData + _threshold * state);
					std::cerr << "数值变化超限!输入值:"<< num<<" 模拟值:tempVal" << std::endl;
				
				}
				else//变化没有超限
				{
					_threshold = (_threshold + abs(temp)) / 2;//计算平均阈值
				}
			}
			_count++;
			if (abs(tempVal - num) <= 100)
				_lastData = tempVal;
			else
				_lastData = num;
			return tempVal;
		}
		void print()
		{
			std::cout << "平均变化值:" << _threshold << " 上次值:" << _lastData;
			if (_state == 1)
				std::cout << " 上升" << std::endl;
			else if (_state == -1)
				std::cout << " 下降" << std::endl;
			else
				std::cout << " 静止" << std::endl;
		}
	private:
		const size_t _port;
		const int _MaxFlag;//flag的最大值
		int _lastData = 0;//上次的值
		int _threshold = 0;//平均变化值
		size_t _count = 0;//读取次数计数器
		int _flag = 0;//计数FLAG
		int _state = 0;//-1 下降 0静止 1升降
		size_t _maxDataNums = 0;//最大数据记录
	};
}