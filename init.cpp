#include "main.h"
SystemData* sysData;
Chassis *chassis;
Generic* lift;
Generic* intake;
Generic* shoot;
void init()
{
	sysData = new SystemData();
	chassis = new Chassis({ Motor{1,1},Motor{2,1},Motor{3,-1},Motor{4,-1} }, "µ×ÅÌ");
	lift = new Generic({ Motor{5,-1} }, "Éý½µ");
	intake = new Generic({ Motor{6,-1} }, "ÎüÍÂ");
	shoot = new Generic({ Motor{7,-1}, Motor{8,1} }, "µ¯Éä");

}