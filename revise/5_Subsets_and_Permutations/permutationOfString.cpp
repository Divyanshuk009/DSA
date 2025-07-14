#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int> nums, vector<vector<int>> &ans, int index)
{
    // base case
    if (index >= nums.size())
    {
        ans.push_back(nums);
        return;
    }

    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[index], nums[i]);
        solve(nums, ans, index + 1);
        // backtrack
        // swap(nums[index], nums[i]);
    }
}

int main()
{

    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans;
    int index = 0;

    solve(nums, ans, index);
    // Print the permutations
    for (auto v : ans)
    {
        for (int x : v)
        {
            cout << x << " ";
        }
        cout << endl;
    }
}