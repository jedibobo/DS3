#pragma warning(disable:4996)
#include <iostream>
#include "Tree.hpp"
#include "txt_reader.h"
#define _CRT_SECURE_NO_WARNINGS
int main()
{
    cout << "Please choose the action you want:" << endl;
    cout << "\n1. Input the tree by a file;\n2. Input the tree manually" << endl;
    int c;
    cin >> c;
    while (c != 1 && c != 2)
    {
        cout << "Please check your input" << endl;
        cout << "Please choose the action you want:" << endl;
        cout << "\n1. Input the tree by a file;\n2. Input the tree manually" << endl;
        cin >> c;
    }
    PI* q; Tree t;
    if (c == 1)
    {
        cout << "Please Input the file name" << endl;
        string fn;
        cin >> fn;
        int num_lines;
        q = read(fn, num_lines);
        cout << num_lines;
        t.construct(q);
        t.buildTree(t.GetRoot());
    }
    else
    {
        t.construct();
        system("cls");
        t.buildTree(t.GetRoot());
    }
    int x;
    TreeNode* p;

    //cout << "\n please enter any code to print the tree" << endl;
    //cin >> x;
    //t.buildTree(t.GetRoot());
    L1:cout << "\nPlease choose the action you want:" << endl;
    cout << "\n1. Check the present tree;\n2. Hire someone;\n3. Fire someone;\n4. Exit \n" << endl;
    char choice;
    cin >> choice;
    switch (choice)
    {
    case '1':
        system("cls");

        t.buildTree(t.GetRoot());

        break;
    case '2': {
        cout << "Please input the leader's name." << endl;
        string name;
        cin >> name;
        TreeNode* p = NULL;
        t.Find(name, t.GetRoot(), p);
        t.hire(p);
        break;
    }
    case '3': {
        cout << "Please input the name." << endl;
        string  name;
        cin >> name;
        p = NULL;
        t.Find(name, t.GetRoot(), p);
        if (t.Find(name, t.GetRoot(), p) != NULL) {
            t.fire(p);
        }
        else {
            cout << "Please check your input" << endl;
        }
        //t.fire(p);
        break;
    }
    case '4':
        return 0;

    default:
        cout << "Please check your illegal input." << endl;
        break;
    }
    goto L1;
}







