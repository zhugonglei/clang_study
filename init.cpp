#include "main.h"
std::shared_ptr<SystemData> sysData;
std::shared_ptr<Chassis> chassis;
std::shared_ptr<Generic> lift;
std::shared_ptr<Generic> intake;
std::shared_ptr<Generic> shoot;
void init()
{
	sysData = std::make_shared<SystemData>();
	chassis = std::make_shared<Chassis>("µ×ÅÌ");
	lift = std::make_shared<Generic>("Éı½µ");
	intake = std::make_shared<Generic>("ÎüÍÂ");
	shoot = std::make_shared<Generic>("µ¯Éä");

}