#include <iostream>

using namespace std;

int getpivot(int arr[], int si)
{
    int s = 0;
    int e = si - 1;

    int mid = s + (e - s) / 2;

    while (s < e)
    {
        if (arr[mid] >= arr[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    return e; // can return e or s
}

int main()
{

    int nums[8] = {6, 7, 8, 9, 10, 1, 2, 3};

    cout << "Pivot is at index: " << getpivot(nums, 8) << endl;
    cout << "and pivot element is: " << nums[getpivot(nums, 8)] << endl;
}
