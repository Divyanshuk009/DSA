#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;

        this->left = NULL;
        this->right = NULL;
    }
};

void inorder(node *root, int cnt)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left, cnt);
    if (root->left == NULL & root->right == NULL)
    {
        cnt++;
    }

    inorder(root->right, cnt);
}

int noOfLeafNodes()
{
}

int main()
{
    int cnt = 0;
}
