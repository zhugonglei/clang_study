#pragma once
#include <sstream>

template <typename T>
T copySign(T val)
{
    if (val > 0)
        return 1;
    if (val < 0)
        return -1;
    return 0;
}

template <typename T>
T stringToNum(const std::string &str)
{
    std::istringstream iss(str);
    T num;
    iss >> num;
    return num;
}