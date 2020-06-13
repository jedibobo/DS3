//
//  Tree.cpp
//  PIM
//
//  Created by Cedric on 2020/6/7.
//  Copyright © 2020 Cedric. All rights reserved.
//

#include "Tree.hpp"

void Tree::PrintTree(TreeNode* root,int x) {
   
    if (root != NULL) {
        
        Print(x, Print_Y, 1, root->pi.name);
        
        for (int i = 0; i < root->ChildrenNum; i++) {
            if (i != 0) Print_Y = Print_Y + 3;
            PrintTree(root->Children[i], x+5);
            //y = y + 3;
        }
    }
}

void Tree::Release(TreeNode* root)
{
    if (root != NULL)
    {
        for (int i = 0; i < root->ChildrenNum; i++)
        {
            Release(root->Children[i]);
        }
        delete root;
    }
}

TreeNode* Tree::PreCreate()
{
    TreeNode* root;
    string n;
    int e, cn;
    cin >> n >> e >> cn;//name exp childrennum
    if (n == "#")
        root = NULL;
    else
    {
        root = new TreeNode;
        root->pi.name = n;
        root->pi.exp = e;
        root->ChildrenNum = cn;
        for (int i = 0; i < cn; i++)
        {
            root->Children.push_back(PreCreate());
        }
    }
    return root;
}

void Tree::PreOrder(TreeNode* root)
{
    if (root != NULL)
    {
        cout << root->pi.name << ',' << root->pi.exp << ' ';
        for (int i = 0; i < root->ChildrenNum; i++)
        {
            PreOrder(root->Children[i]);
        }
    }
}

int Tree::Height(TreeNode* root)
{
    if (root == NULL)
        return 0;
    else
    {
        int ChildrenHeight[100], max;
        for (int i = 0; i < root->ChildrenNum; i++)
        {
            ChildrenHeight[i] = Height(root->Children[i]);
        }
        max = 0;
        for (int i = 0; i < root->ChildrenNum; i++)
        {
            if (max < ChildrenHeight[i])
            {
                max = ChildrenHeight[i];
            }
        }
        return max + 1;
    }
}

void Tree::employ(TreeNode *p)
{
    string n; //name
    cin >> n;
    TreeNode* root;
    root = new TreeNode;
    root->pi.name = n;
    root->pi.exp = 0; //new staff's status = 0
    root->ChildrenNum = 0;
    p->Children.push_back(root);
    for (int i = 0; i < p->ChildrenNum; i++)
    {
        p->Children[i]->pi.exp++; //When a new staff is employed, the other staffs belonged to the same leader will increase their status. 
    }
    p->ChildrenNum++;
}






