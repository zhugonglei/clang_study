#include"main.h"
void opcontrol()
{
	for (auto &it : sysData->_objData)
		it->addRecoderData();
	sysData->showRecoderData();
	while (true)
	{

	}
}