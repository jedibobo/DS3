//
//  Tree.cpp
//  PIM
//
//  Created by Cedric on 2020/6/7.
//  Copyright © 2020 Cedric. All rights reserved.
//

#include "Tree.hpp"

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








