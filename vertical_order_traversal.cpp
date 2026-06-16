#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // Map to store nodes based on their horizontal distance and level.
        // Structure: map<horizontal_distance, map<level, multiset<node_values>>>
        // `map` automatically sorts by horizontal distance, then by level.
        // `multiset` is used to automatically sort overlapping nodes at the exact same (x, y) position.
        map<int, map<int, multiset<int>>> nodes;
        
        // Queue for BFS traversal: stores pairs of <Node, <horizontal_distance, level>>
        queue<pair<TreeNode*, pair<int, int>>> q;
        
        if (root == nullptr) return {};
        
        // Root starts at horizontal distance 0, level 0
        q.push({root, {0, 0}});
        
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            
            TreeNode* curr = p.first;
            int hd = p.second.first;   // Horizontal Distance (x-axis)
            int level = p.second.second; // Level (y-axis)
            
            // Insert the current node's value into the map
            nodes[hd][level].insert(curr->val);
            
            // Traverse left child: horizontal distance decreases by 1, level increases by 1
            if (curr->left) {
                q.push({curr->left, {hd - 1, level + 1}});
            }
            
            // Traverse right child: horizontal distance increases by 1, level increases by 1
            if (curr->right) {
                q.push({curr->right, {hd + 1, level + 1}});
            }
        }
        
        vector<vector<int>> result;
        
        // Iterate over the map to build the final result
        for (auto p : nodes) { // Iterate through horizontal distances
            vector<int> col;
            for (auto q : p.second) { // Iterate through levels at this horizontal distance
                // Insert all node values at this exact position into the column
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            result.push_back(col);
        }
        
        return result;
    }
};

int main() {
    // Example usage:
    // Tree:
    //      1
    //    /   \
    //   2     3
    //  / \   / \
    // 4   5 6   7
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution sol;
    vector<vector<int>> result = sol.verticalTraversal(root);

    cout << "Vertical Order Traversal:\n";
    for (const auto& col : result) {
        for (int val : col) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
