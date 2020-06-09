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

using namespace std;

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
    Tree() { this->root = PreCreate(); }
    void Release(TreeNode* root);
    TreeNode* GetRoot() { return root; }
    ~Tree() { Release(root); }
    void PreOrder(TreeNode* root);
    int Height(TreeNode* root);






};










#endif /* Tree_hpp */
