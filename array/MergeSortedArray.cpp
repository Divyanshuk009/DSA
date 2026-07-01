#include <iostream>
using namespace std;
#include <vector>

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n, vector<int> &nums3)
{
    // vector<int> nums3;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (nums1[i] < nums2[j])
            {
                nums3.push_back(nums1[i]);
            }
            else if (nums1[i] > nums2[j])
            {
                nums3.push_back(nums2[j]);
            }
            else
            {
                nums3.push_back(nums1[i]);
            }
        }
    }
}

int main()
{
    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {2, 4, 6, 8};
    vector<int> arr3;

    merge(arr1, arr1.size(), arr2, arr2.size(), arr3);

    for (int i = 0; i < arr3.size(); i++)
    {
        cout << arr3[i] << " ";
    }

    return 0;
}