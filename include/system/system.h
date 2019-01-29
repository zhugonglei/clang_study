#pragma once
#include "json.hpp"
#include "obj.h"
#include <iostream>
#include <memory>
#include <vector>

class SystemData
{
  public:
    Json::value jsonVal;               //������
    Json::CharReaderBuilder jsreader;  //��ȡ��
    Json::StreamWriterBuilder builder; //д����
    JSONCPP_STRING jsonErr;            //�쳣��
    SystemData(std::string jsonData)
    {
        //std::unique_ptr<Json::CharReader> const reader(jsreader.newCharReader());
        //if (!reader->parse(jsonData.c_str(), jsonData.c_str() + jsonData.length(), &jsonVal, &jsonErr))
        //{
        //	std::cerr << "json��������" << std::endl;
        //	return;
        //}
        readSDcard();
        saveData();
        //printJson(jsonVal["����"]["PID����"]);//���ܴ�ӡ��ȥ�Ժ������
        //printJsonII(jsonVal["����"]["PID����"]["ǰ��pid"]);
    }
    std::vector<std::vector<double>> _recoderData;
    std::vector<Obj *> _objData;
    SystemData() { std::cout << "sysData create successful" << std::endl; }
    ~SystemData() = default;
    void addObj(Obj *obj)
    {
        _objData.push_back(obj);
    }
    void addRecoderData(std::vector<double> data)
    {
        _recoderData.push_back(data);
    }
    void showRecoderData()
    {
        for (auto &it1 : _recoderData)
        {
            for (auto &it2 : it1)
                std::cout << it2 << ";";
            std::cout << std::endl;
        }
    }
    bool readSDcard()
    {
        FILE *file = fopen("demo.json", "r");
        if (file == nullptr)
        {
            std::cerr << "�ļ��򿪴���" << std::end return false;
        }
        char buf[1024];
        std::string line;
        while (fgets(buf, 1024, file) != nullptr) //��ȡһ��
            line += buf;
        //std::cout << line << std::endl;

        std::unique_ptr<Json::CharReader> const reader(jsreader.newCharReader());
        if (!reader->parse(line.c_str(), line.c_str() + line.length(), &jsonVal, &jsonErr))
        {
            std::cerr << "json��������!" << std::endl;
            return false;
        }
        fclose(file);
        return true;
    }
    //void rebuildSDcard(const DataConfigList &tempData, std::string name)
    //{
    //	if (name == "����")
    //		pathData.insert({ name ,{"chassis.txt" } }); //try_emplace ���Բ��� ���KEY ���ھͲ������˲����ھͲ���
    //	else if (name == "��̨")
    //		pathData.insert({ name, {"head.txt"} });
    //	else if (name == "����")
    //		pathData.insert({ name, {"intake.txt"} });
    //	else if (name == "��ת��")
    //		pathData.insert({ name, {"rotateIntake.txt" } });
    //	else if (name == "����")
    //		pathData.insert({ name, {"capIntake.txt"} });
    //	else if (name == "����")
    //		pathData.insert({ name, {"lift.txt" }		});
    //	else if (name == "����")
    //		pathData.insert({ name, {"shoot.txt"} });
    //	else if (name == "ǰ��pid")
    //		pathData.insert({ name,{ "frpid.txt"} });
    //	else if (name == "����pid")
    //		pathData.insert({ name, {"rotatepid.txt" }
    //			});
    //	else
    //	{
    //		std::cerr << "��ȡ�������ִ���,�������" << std::endl;
    //		return; //�����ú���
    //	}
    //	configData.try_emplace(name, tempData);
    //	bool flag = readSDcard(configData[name], name); //�ж��ļ��Ƿ��Ѿ�����
    //	if (!flag)
    //	{
    //		std::cerr << name << "û��������" << name << "config�ļ�.���´���!��ע���������������Ϣ" << std::endl;
    //		bool flag = saveData(tempData, name);
    //		if (!flag)
    //			std::cerr << name << " config�ļ����α���ʧ��!,����SD���Ƿ�������SD���Ƿ���!" << std::endl;
    //		else
    //			std::cout << name << " config�ļ������ɹ�" << std::endl;
    //	}
    //}

    std::string UTF8ToGB(const char *str)
    {
        std::string result;
        WCHAR *strSrc;
        LPSTR szRes;

        int i = MultiByteToWideChar(CP_UTF8, 0, str, -1, nullptr, 0);
        strSrc = new WCHAR[i + 1];
        MultiByteToWideChar(CP_UTF8, 0, str, -1, strSrc, i);

        i = WideCharToMultiByte(CP_ACP, 0, strSrc, -1, nullptr, 0, nullptr, nullptr);
        szRes = new CHAR[i + 1];
        WideCharToMultiByte(CP_ACP, 0, strSrc, -1, szRes, i, nullptr, nullptr);

        result = szRes;
        delete[] strSrc;
        delete[] szRes;
        return result;
    }

    std::string GBKToUTF8(const std::string &strGBK)
    {
        std::string strOutUTF8 = "";
        WCHAR *str1;
        int n = MultiByteToWideChar(CP_ACP, 0, strGBK.c_str(), -1, nullptr, 0);
        str1 = new WCHAR[n];
        MultiByteToWideChar(CP_ACP, 0, strGBK.c_str(), -1, str1, n);
        n = WideCharToMultiByte(CP_UTF8, 0, str1, -1, nullptr, 0, nullptr, nullptr);
        char *str2 = new char[n];
        WideCharToMultiByte(CP_UTF8, 0, str1, -1, str2, n, nullptr, nullptr);
        strOutUTF8 = str2;
        delete[] str1;
        delete[] str2;
        return strOutUTF8;
    }
    bool saveData()
    {
        FILE *file = fopen("save.json", "w");
        if (file == nullptr)
        {
            std::cerr << " ����ʧ��" << std::endl;
            return false;
        }
        std::ostringstream os;
        std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
        writer->write(jsonVal, &os);
        fprintf(file, "%s", os.str().c_str()); //����¼��
        //std::string tempStr= jsonVal.toStyledString();
        //fprintf(file, "%s", tempStr.c_str()); //����¼��
        fclose(file);
        return true;
    }
    void ���л�jsonData()
    {
    }
    //�ݹ��ӡ ���ܴ�ӡ��KEY������
    void printJson(Json::Value data)
    {
        Json::Value::Members mem = data.getMemberNames();
        for (auto iter = mem.begin(); iter != mem.end(); iter++)
        {
            std::cout << *iter << "\t: ";
            if (data[*iter].type() == Json::objectValue)
            {
                std::cout << std::endl;
                printJson(data[*iter]);
            }
            else if (data[*iter].type() == Json::arrayValue)
            {
                std::cout << std::endl;
                auto cnt = data[*iter].size();
                for (auto i = 0; i < cnt; i++)
                {
                    printJson(data[*iter][i]);
                }
            }
            else if (data[*iter].type() == Json::stringValue)
            {
                std::cout << data[*iter].asString() << std::endl;
            }
            else if (data[*iter].type() == Json::realValue)
            {
                std::cout << data[*iter].asDouble() << std::endl;
            }
            else if (data[*iter].type() == Json::uintValue)
            {
                std::cout << data[*iter].asUInt() << std::endl;
            }
            else
            {
                std::cout << data[*iter].asInt() << std::endl;
            }
        }
        return;
    }
    void printJsonII(Json::Value data)
    {
        Json::Value::Members members;
        members = data.getMemberNames();                                                                             // ��ȡ����key��ֵ
        for (Json::Value::Members::iterator iterMember = members.begin(); iterMember != members.end(); iterMember++) // ����ÿ��key
        {
            std::string strKey = *iterMember;
            if (data[strKey.c_str()].isString())
            {
                std::string strVal = data[strKey.c_str()].asString();
                std::cout << strKey.c_str() << ":" << strVal.c_str() << std::endl;
            }
            else if (data[strKey.c_str()].isInt())
            {
                int iVal = data[strKey.c_str()].asInt();
                std::cout << strKey.c_str() << ":" << iVal << std::endl;
            }
            else if (data[strKey.c_str()].isDouble())
            {
                double dVal = data[strKey.c_str()].asDouble();
                std::cout << strKey.c_str() << ":" << dVal << std::endl;
            }
            else
            {
                std::string strVal = data[strKey.c_str()].toStyledString();
                std::cout << strKey.c_str() << ":" << strVal.c_str() << std::endl;
            }
        }
    }

  private:
};
extern SystemData *sysData;
