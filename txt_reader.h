#pragma once
#include <iomanip>
#include <fstream>    // file stream
#include <sstream>    // string stream
#include <iomanip>
#include "Tree.hpp"
PI* read(std::string strFileName)
{
    PI data[100];
    PI* data_pt = data;
    //���ļ�
    std::string s;
    ifstream infile;
    const char* temp = strFileName.c_str();
    infile.open(temp);
    if (!infile.is_open())
    {
        std::cout << "�ļ���ȡʧ��" << std::endl;
        std::system("pause");
    }
    else
    {
        std::cout << "�ļ���ȡ�ɹ�" << std::endl;
        std::system("pause");
    }
    system("cls");
    //��ȡtxt�ļ�,����ӡ
    string sline;//ÿһ��
    string out;
    string s1, s2;
    while (getline(infile, sline))
    {
        istringstream sin(sline);
        sin >> s1 >> s2;
        cout << s1 << " "<< s2 <<"\n";
    }
    return data_pt;//����ָ�룬Ҳ���Է���data��������������ܻ��ָ��÷��ʣ�
}
