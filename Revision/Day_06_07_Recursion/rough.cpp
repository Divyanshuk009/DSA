#include <iostream>
using namespace std;

bool binarySearch(int arr[], int start, int end, int key)
{

    if (start > end)

    {
        return false;
    }

    int mid = start * (end - start) / 2;

    if (arr[mid] == key)
    {
        return true;
    }
    if (arr[mid] < key)
    {
        return binarySearch(arr, mid + 1, end, key);
    }
    else
    {
        return binarySearch(arr, start, mid - 1, key);
    }
}

int main()
{

    int nums[] = {3, 45, 6, 3, 1, 9};
    int size = sizeof(nums);
    int key = 9;
    // // cout << sizeof(nums[2]) << endl; 4bit
    // int *address = addressof(nums[1]);
    // cout << address << endl;
    cout << binarySearch(nums, 0, size - 1, key);
}
