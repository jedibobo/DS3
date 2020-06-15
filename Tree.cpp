#include "Tree.hpp"

void Tree::Print_form(TreeNode* root, int x) {
    Print(x, Print_Y, 1, "@");
    Print(x + 1, Print_Y, 1, root->pi.name);
    Print(x, Print_Y + 2, 1, "EXP:");
    Print(x + 5, Print_Y + 2, 1, root->pi.exp);
    for (int i = 0; i < 10; i++) {
        Print(x + i, Print_Y - 1, 1, "=");
        Print(x + i, Print_Y + 3, 1, "=");
    }
    for (int i = 0; i < 3; i++) {
        Print(x - 1, Print_Y + i, 1, "=");
        Print(x + 10, Print_Y + i, 1, "=");
    }
}

void Tree::buildTree(TreeNode* root) {

    Print_Y = 3;
    Print(0, 0, 1, "general manager");
    Print(20, 0, 1, "assistant manager");
    Print(40, 0, 1, "project manager");
    Print(60, 0, 1, "officer");
    Print(80, 0, 1, "temporary worker");

    this->PrintTree(root, 2);
    cout << "\n\n\n\n\n-------------------------------------------------------------------------------------------------" << endl;
}

void Tree::PrintTree(TreeNode* root, int x) {
    //system("cls");

    if (root != NULL) {

        //Print(x, Print_Y, 1, root->pi.name);
        Print_form(root, x);

        for (int i = 0; i < root->ChildrenNum; i++) {
            if (i != 0) Print_Y = Print_Y + 6;
            PrintTree(root->Children[i], x + 20);
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
    root->pi.Num = cn;
    root->ChildrenNum = cn;
    for (int i = 0; i < cn; i++)
    {
        cout << "Please input the " << i + 1 << "th subordinate of " << n << endl;
        root->Children.push_back(PreCreate());
        root->Children[i]->Parent = root;
    }
    return root;
}

TreeNode* Tree::PreCreate(PI*& p)
{
    TreeNode* root = new TreeNode;
    root->pi.name = p->name;
    root->pi.exp = p->exp;
    root->ChildrenNum = p->Num;
    p++;
    for (int i = 0; i < root->ChildrenNum; i++)
    {
        root->Children.push_back(PreCreate(p));
        root->Children[i]->Parent = root;
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
int Tree::fire(TreeNode* p)
{
    if (p == NULL)
    {
        cout << "This man can not be found." << endl;
        return 0;
    }
    if (p->ChildrenNum == 0) {
        p->Parent->ChildrenNum--;
        for (int i = 0; i < p->Parent->ChildrenNum; i++) {
            if (p->Parent->Children[i]->pi.name == p->pi.name) {
                TreeNode* temp;
                temp = p;
                for (int j = i; j < p->Parent->ChildrenNum; j++) {
                    p->Parent->Children[j] = p->Parent->Children[j + 1];
                }
                p->Parent->Children[p->Parent->ChildrenNum] = temp;
                p->Parent->Children.pop_back();
            }
        }
    }
    else if (p->ChildrenNum == 1) {
        if (p->Children[0]->ChildrenNum == 0)
            p->ChildrenNum--;
        TreeNode* temp;
        temp = p->Children[0];
        *p = *temp;
    }
    else {
        for (int i = 0; i < p->ChildrenNum; i++) {
            for (int j = i; j < p->ChildrenNum; j++) {
                if (p->Children[j]->pi.exp > p->Children[i]->pi.exp) {
                    TreeNode* temp;
                    //p->Children.push_back(temp);
                    temp = p->Children[j];
                    p->Children[j] = p->Children[i];
                    p->Children[i] = temp;
                }
            }
        }
        TreeNode* X;
        X = p->Children[0];
        X->ChildrenNum = p->ChildrenNum - 1;
        X->pi.exp++;
        for (int i = 1; i < p->ChildrenNum; i++) {
            X->Children.push_back(p->Children[i]);
        }
        *p = *X;
    }
    return 0;
}
int Tree::hire(TreeNode*& p)
{
    if (p == NULL)
    {
        cout << "This man can not be found." << endl;
        return 0;
    }
    cout << "Please input the new staff's name:" << endl;
    string n; //name
    cin >> n;
    TreeNode* root;
    root = new TreeNode;
    root->pi.name = n;
    root->pi.exp = 0; //new staff's status = 0
    root->ChildrenNum = 0;
    p->Children.push_back(root);
    root->Parent = p;
    for (int i = 0; i < p->ChildrenNum; i++)
    {
        p->Children[i]->pi.exp++; //When a new staff is employed, the other staffs belonged to the same leader will increase their status. 
    }
    p->ChildrenNum++;
    return 0;
}

int Tree::Find(string n, TreeNode* root, TreeNode*& p)
{
    if (root != NULL)
    {
        if (root->pi.name == n)
        {
            p = root;
            return 0;
        }
        for (int i = 0; i < root->ChildrenNum; i++)
        {
            Find(n, root->Children[i], p);
        }
    }
}





