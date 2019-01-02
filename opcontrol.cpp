#include"main.h"
void opcontrol()
{
	size_t i = 0;

	while (i<=100)
	{
		chassis->forward(127);
		lift->set(50);
		intake->set(-10);
		shoot->set(20);
		for (auto &it : sysData->_objData)
			it->addRecoderData();
		i++;
		Sleep(100);
	}
	sysData->showRecoderData();
}