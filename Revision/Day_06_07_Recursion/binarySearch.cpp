#include <iostream>
using namespace std;

bool binarySearch(int arr[], int start, int end, int key)
{

    // base case
    if (start > end)

    {
        return false;
    }
    int mid = start + (end - start) / 2;
    if (arr[mid] == key)
    {
        return true;
    }

    if (arr[mid] < key)
    {
        return binarySearch(arr, mid + 1, end, key);

        /* code */
    }
    else
    {
        return binarySearch(arr, start, mid - 1, key);
    }
}

int main()
{
    int arr[5] = {2, 3, 5, 6, 8};
    int size = 5;
    int key = 6;

    cout << "present or not: " << binarySearch(arr, 0, size - 1, key) << endl;

    if (binarySearch(arr, 0, size - 1, key) == 0)
    {
        cout << "not present" << endl;
    }
    else
    {
        cout << "present" << endl;
    }
}