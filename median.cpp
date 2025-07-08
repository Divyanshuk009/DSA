#include <iostream>
using namespace std;
#include <vector>

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int i = 0;
    int j = 0;
    vector<int> nums3;

    while (i < nums1.size() && j < nums2.size())
    {
        if (nums1[i] < nums2[j])
        {
            nums3.push_back(nums1[i++]);
        }
        else
        {
            nums3.push_back(nums2[j++]);
        }
    }

    while (i < nums1.size())
    {
        nums3.push_back(nums1[i++]);
    }
    while (j < nums2.size())
    {
        nums3.push_back(nums2[j++]);
    }

    int s = 0;
    int e = nums3.size() - 1;
    double mid = s + (e - s) / 2;
    if (nums3.size() % 2 == 0)
    {
        return (nums3[mid] + nums3[mid + 1]) / 2.0;
    }
    else
    {
        return nums3[mid];
    }
}

int main()
{

    vector<int> nums1 = {1, 3, 5};
    vector<int> nums2 = {2, 4, 6};

    cout << findMedianSortedArrays(nums1, nums2);
}