#include <iostream>
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
        this->right = NULL;
        this->left = NULL;
    }
};

node *buildtree(node *root)
{

    cout << "enter root" << endl;

    int data;
    cin >> data;
    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }

    cout << "enter data for inserting left" << endl;
    root->left = buildtree(root->left);
    cout << "enter data in right " << endl;
    root->right = buildtree(root->right);
    return root;
}

int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);
    int ans = max(left, right) + 1;
    return ans;
}

int main()
{

    node *root = NULL;
    // creating a tree
    root = buildtree(root);

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // level order
    cout << "printing the level order traversal output " << endl;

    cout << "height is:" << height(root) << endl;
}
