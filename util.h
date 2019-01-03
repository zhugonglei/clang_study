#pragma once
namespace ncrapi
{
	template<typename T>
	T copySign(T val)
	{
		if (val > 0)
			return 1;
		if (val < 0)
			return -1;
		return 0;
	}
}