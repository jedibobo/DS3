//
//  Tree.hpp
//  PIM
//
//  Created by Cedric on 2020/6/7.
//  Copyright © 2020 Cedric. All rights reserved.
//

#ifndef Tree_hpp
#define Tree_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
#include<windows.h>
#include<stdlib.h>
#include<string>

using namespace std;

template <typename T>
void Print(int x, int y,int state, T output,int color = 15) {    //打印基本单元
    //  x,y: 坐标
    //  state==0 时不进行打印
    COORD pos;
    HANDLE HAN_OUTPUT;
    pos.X = x;
    pos.Y = y;
    HAN_OUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(HAN_OUTPUT, color % 256);
    SetConsoleCursorPosition(HAN_OUTPUT, pos);
    if(state!=0) cout << output;
    
}

struct PI
{
    string name;
    int exp;
};

struct TreeNode
{
    PI pi;
    int ChildrenNum = 0;
    vector<TreeNode*> Children;
};

class Tree
{
private:
    TreeNode* root;
    TreeNode* PreCreate();
    
public:
    int Print_Y = 0;    //打印统计用
    Tree() { this->root = PreCreate(); }
    void Release(TreeNode* root);
    TreeNode* GetRoot() { return root; }
    ~Tree() { Release(root); }
    void PreOrder(TreeNode* root);
    int Height(TreeNode* root);
    void PrintTree(TreeNode* root,int x=0);
    void employ(TreeNode *p);
    



};










#endif /* Tree_hpp */
