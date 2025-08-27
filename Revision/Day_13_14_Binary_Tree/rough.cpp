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

// node *buildtree(node *root)
// {

//     cout << "enter the data" << endl;
//     int data;
//     cin >> data;
//     root = new node(data);
//     if (data == -1)
//     {
//         return NULL;
//     }

//     cout << "enter data to left of" << data << endl;
//     root->left = buildtree(root->left);
//     cout << "enter data to right of" << data << endl;
//     root->right = buildtree(root->right);
//     return root;
// }

void inorder(node *root, int &count)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left, count);
    // leaf node
    if (root->left == NULL && root->right == NULL)
    {
        count++;
    }
    inorder(root->right, count);
}