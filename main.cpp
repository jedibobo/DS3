//
//  main.cpp
//  PIM
//
//  Created by Cedric on 2020/6/7.
//  Copyright © 2020 Cedric. All rights reserved.
//

#include <iostream>

#include "Tree.hpp"
#include "txt_reader.h"

int main()
{
    //Print(1, 1, 1, "?!#$%^&", 14);
    Tree t;
    t.PreOrder(t.GetRoot());
    int x;
    cout << "\n please enter any code to print the tree" << endl;
    cin >> x;
    t.buildTree(t.GetRoot());
}







