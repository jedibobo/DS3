#pragma once
#include <string>
#include <vector>
#include <iomanip>
#include<iostream>
#include <fstream>    // file stream
#include <sstream>    // string stream
#include <iomanip>
#include "Tree.hpp"

void write(PI*data_pt)
{
	ofstream outfile;
	outfile.open("F:\\���\\github\\DS3\\modified.txt");
    if (!outfile.is_open())
    {
        std::cout << "��д���ļ���ʧ��" << std::endl;
        std::system("pause");
    }
    else
    {
        std::cout << "��д���ļ��򿪳ɹ�" << std::endl;
        std::system("pause");
    }
	for (int i = 0; i < 10; i++)
		outfile << i << ", " << i + 1 << ", " << i * i << ", " << endl;

	outfile.close();
	cout << "д��txt�ɹ�" << endl;
}