#include "main.h"
#include "userConfig.h"
SystemData* sysData;
Chassis *chassis;
Generic* lift;
Generic* intake;
Generic* shoot;
void init()
{
	sysData = new SystemData();
	chassis = new Chassis( CHASSIS_PRAGMA);
	//lift = new Generic({ Motor{5,-1} }, "Éý½µ");
	//intake = new Generic({ Motor{6,-1} }, "ÎüÍÂ");
	//shoot = new Generic({ Motor{7,-1}, Motor{8,1} }, "µ¯Éä");

}