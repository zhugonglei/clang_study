//#pragma warning(disable:4996)//使用json必备
#pragma once

#include "chassis.h"
//#include "generic.h"

void init();
void autonomous();
void opcontrol();
extern Chassis *chassis;
//extern Generic* lift;
//extern Generic* intake;
//extern Generic* shoot;