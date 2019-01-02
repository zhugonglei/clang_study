#pragma once
#include <iostream>
class Motor
{
public:
	Motor(size_t port,int sign=1):_port(port),_sign(sign){}
	~Motor() = default;
	void set(int pwm)
	{
		std::cout <<"["<<_port<<"]ºÅÂí´ï:"<< pwm*_sign << std::endl;
	}
private:
	size_t _port;
	int _sign=1;
};