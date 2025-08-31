#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>> &ans)
{
    // base case
    if (index >= nums.size())
    {
        ans.push_back(output); // store the current subset
        return;
    }
    //  EXCLUDE the current element (nums[index]) from the subset and move to another
    solve(nums, output, index + 1, ans);

    // INCLUDE the current element in the subset
    int element = nums[index]; // get the current element
    output.push_back(element); // add it to the current output subset

    // Move to the next index with the current element included
    solve(nums, output, index + 1, ans);
}

int main()
{

    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans;
    int index = 0;
    vector<int> output;
    solve(nums, output, index, ans);

    // print the result
    cout << "All subsets:\n";
    for (auto subset : ans)
    {
        cout << "[ ";
        for (int num : subset)
        {
            cout << num << " ";
        }
        cout << "]\n";
    }
}