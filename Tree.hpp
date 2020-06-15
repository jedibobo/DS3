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
void Print(int x, int y, int state, T output, int color = 15) {    //打印基本单元
    //  x,y: 坐标
    //  state==0 时不进行打印
    COORD pos;
    HANDLE HAN_OUTPUT;
    pos.X = x;
    pos.Y = y;
    HAN_OUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(HAN_OUTPUT, color % 256);
    SetConsoleCursorPosition(HAN_OUTPUT, pos);
    if (state != 0) cout << output;

}

struct PI
{
    string name;
    int exp = 0;
    int Num = 0;
};

struct TreeNode
{
    PI pi;
    int ChildrenNum = 0;
    vector<TreeNode*> Children;
    TreeNode* Parent = NULL;
};

class Tree
{
private:
    TreeNode* root;
    TreeNode* PreCreate();
    TreeNode* PreCreate(PI*& p);
    int money = 5000;
public:
    int Print_Y = 3;
    int project_num = 0;
    Tree() { this->root = PreCreate(); }
    Tree(PI* p) { this->root = PreCreate(p); }
    void Release(TreeNode* root);
    TreeNode* GetRoot() { return root; }
    ~Tree() { Release(root); }
    int Find(string n, TreeNode* root, TreeNode*& p);
    void buildTree(TreeNode* root);
    void Print_form(TreeNode* root, int x);
    void PrintTree(TreeNode* root, int x = 0);
    void PreOrder(TreeNode* root);
    int Height(TreeNode* root);
    int fire(TreeNode* root);
    int hire(TreeNode*& root);
    vector<TreeNode*>::iterator it;
};










#endif /* Tree_hpp */
