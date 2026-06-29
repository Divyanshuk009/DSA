#include <iostream>
using namespace std;
#include <vector>

int main()
{
    vector<int> nums = {3, 4, 2, 5, 6};

    int n = nums.size();
    vector<int> ans(n, 1);
    int left = 1;
    for (int i = 0; i < n; i++)
    {
        ans[i] = left;
        left *= nums[i];
    }

    int right = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        ans[i] *= right;
        right *= nums[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}