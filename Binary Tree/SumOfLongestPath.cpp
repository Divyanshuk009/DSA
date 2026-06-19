#include <iostream>
#include <vector>
#include <algorithm> // For std::max
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data) : data(data), left(nullptr), right(nullptr) {}
};

void solve(TreeNode *root, int sum, int &maxSum, int len, int &maxlen)
{

    if (root == NULL)
    {
        if (len > maxlen)
        {
            maxlen = len;
            maxSum = sum;
        }
        else if (len == maxlen)
        {
            maxSum = max(sum, maxSum);
        }
        return;
    }
    sum = sum + root->data;
    solve(root->left, sum, maxSum, len + 1, maxlen);
    solve(root->right, sum, maxSum, len + 1, maxlen);
}

int sumOfLongestPath(TreeNode *root)
{
    int sum = 0;
    int maxSum = INT_MIN;
    int len = 0;
    int maxlen = 0;

    solve(root, sum, maxSum, len, maxlen);
    return maxSum;
}

int main()
{
    // 1. Manually building a sample tree for testing
    //        4
    //       / \
    //      2   5
    //     / \   \
    //    7   1   2
    //   /       /
    //  9       6

    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(2);
    root->left->left->left = new TreeNode(9);
    root->right->right->left = new TreeNode(6);

    // Both paths 4->2->7->9 and 4->5->2->6 have length 4 (longest).
    // Sums: 4+2+7+9 = 22, 4+5+2+6 = 17
    // Expected output: 22

    int result = sumOfLongestPath(root);

    cout << "Expected Output: 22" << endl;
    cout << "Your Code's Output: " << result << endl;

    return 0;
}
