//
//  main.cpp
//  PIM
//
//  Created by Cedric on 2020/6/7.
//  Copyright ? 2020 Cedric. All rights reserved.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include "Tree.hpp"
#include "txt_reader.h"

int main()
{
    //Print(1, 1,1, "?!#$%^&",14);
    //char s = 0;
    //Print(0,0,0,0);
    string filename;
    cout << "输入待读取的文件名：" ;
    cin >> filename;
    PI* data_pt=read(filename);
    Tree t;
    t.PreOrder(t.GetRoot());
}
