#include <iostream>
using namespace std;

void sort(int arr[], int length)
{

    if (length <= 1)
    {
        return;
    }

    for (int i = 0; i < length - 1; i++)
    {
        // for (int j = i + 1; j < length; j++)
        // {

        // }

        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }
    sort(arr, length - 1);
}

int main()
{
    int nums[] = {3, 2, 7, 7, 5, 1, 4};
    int length = sizeof(nums) / sizeof(nums[0]);

    sort(nums, length);

    int ans;

    for (int i = 0; i < length - 1; i++)
    {
        if (nums[i] == nums[i + 1])
        {
            ans = nums[i];
        }
        // else
        // {
        //     return -1;
        // }
    }

    // for (int i = 0; i < length; i++)
    // {
    //     cout << nums[i] << " ";
    // }
    cout << ans;
    return ans;
};
