#include <iostream>
using namespace std;

int getpivot(int num[], int size)
{
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (num[mid] >= num[0])
        {
            start = mid + 1;
        }

        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return start;
}

int main()
{

    int nums[8] = {6, 7, 8, 9, 10, 1, 2, 3};

    cout << "Pivot is at index: " << getpivot(nums, 8) << endl;
    cout << "and pivot element is: " << nums[getpivot(nums, 8)] << endl;
}
