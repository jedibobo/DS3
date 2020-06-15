#pragma once
#include <iomanip>
#include <fstream>    // file stream
#include <sstream>    // string stream
#include <iomanip>
#include "Tree.hpp"
void str2int(int& int_temp, const std::string& string_temp)
{
    std::stringstream stream(string_temp);
    stream >> int_temp;
}
int getNumberOfEdges(std::string strFileName)
{
    char flag;
    int edgeNum, count=0;
    FILE* fp = fopen(strFileName.c_str(), "rt+");//open the TXT file, can only read, cannot write
    while (!feof(fp)) {

        flag = fgetc(fp);
        if (flag == '\n') count++;
    }

    edgeNum = count + 1;//因为最后一行没有换行符\n，所以需要在count补加1
    fclose(fp);
    cout << " the edge number is " << edgeNum << endl;
    return edgeNum;
}
PI* read(std::string strFileName,int &num_lines)
{
    //PI data[100]={ {},{},{},{} };
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
    num_lines = 0;
    num_lines = getNumberOfEdges(strFileName);
    PI* data_pt= new PI[num_lines];
    string sline;//每一行
    string s1, s2, s3;
    int i=0;
    while (getline(infile, sline))
    {
        istringstream sin(sline);
        sin >> s1 >> s2>> s3;
        data_pt[i].name = s1;
        str2int(data_pt[i].exp,s2);
        str2int(data_pt[i].Num, s3);
        //cout << data_pt[i].name << " "<< data_pt[i].exp <<" "<< data_pt[i].Num <<"\n";
        i++;
    }
    return data_pt;//返回指针，也可以返回data这个数组名（可能会比指针好访问）
}
