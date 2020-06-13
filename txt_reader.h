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
    //打开文件
    std::string s;
    ifstream infile;
    const char* temp = strFileName.c_str();
    infile.open(temp);
    if (!infile.is_open())
    {
        std::cout << "文件读取失败" << std::endl;
        std::system("pause");
    }
    else
    {
        std::cout << "文件读取成功" << std::endl;
        std::system("pause");
    }
    system("cls");
    //读取txt文件,并打印
    string sline;//每一行
    string out;
    string s1, s2;
    while (getline(infile, sline))
    {
        istringstream sin(sline);
        sin >> s1 >> s2;
        cout << s1 << " "<< s2 <<"\n";
    }
    return data_pt;//返回指针，也可以返回data这个数组名（可能会比指针好访问）
}
