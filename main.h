#pragma once

#include "chassis.h"
#include "generic.h"

void init();
void autonomous();
void opcontrol();
extern std::shared_ptr<Chassis> chassis;
extern std::shared_ptr<Generic> lift;
extern std::shared_ptr<Generic> intake;
extern std::shared_ptr<Generic> shoot;