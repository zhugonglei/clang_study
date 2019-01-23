#pragma once
#include <any>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>

using DataConfig = std::vector<std::string>;                           //保存一组CONFIG的类型
using DataConfigList = std::vector<DataConfig>;                        //马达组 必须有序 否则错乱了
using DataUnorderedList = std::unordered_map<std::string, DataConfig>; //无序的哈希表
using DataConfigListSet = std::unordered_map<std::string, DataConfigList>; //config列表的类型 无序哈希
using PidDebugTuple = std::tuple<uint32_t, double, double, double, double, double>; //PIDDATA的类型
