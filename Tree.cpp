//
//  Tree.cpp
//  PIM
//
//  Created by Cedric on 2020/6/7.
//  Copyright © 2020 Cedric. All rights reserved.
//

#include "Tree.hpp"

void Tree::PrintTree(TreeNode* root, int x) {
    //system("cls");

    if (root != NULL) {

        Print(x, Print_Y, 1, root->pi.name);

        for (int i = 0; i < root->ChildrenNum; i++) {
            if (i != 0) Print_Y = Print_Y + 3;
            PrintTree(root->Children[i], x + 10);
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
    cout << "Please input this man's name, experience and the number of his subordinates" << endl;
    cin >> n >> e >> cn; //name exp childrennum
    root = new TreeNode;
    root->pi.name = n;
    root->pi.exp = e;
    root->ChildrenNum = cn;
    for (int i = 0; i < cn; i++)
    {
        cout << "Please input the " << i + 1 << "th subordinate of " << n << endl;
        root->Children.push_back(PreCreate());
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








