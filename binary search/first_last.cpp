#include <iostream>

using namespace std;

int firstOccurence(int arr[], int size, int key)
{
    int s = 0;
    int e = size - 1;

    int ans = -1;

    int mid = s + (e - s) / 2;

    while (s <= e)
    {

        if (key == arr[mid])
        {
            ans = mid;

            e = mid - 1;
        }
        else if (key < arr[mid])
        {
            e = mid - 1;
            /* code */
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int lastOccurence(int arr[], int size, int key)
{
    int s = 0;
    int e = size - 1;

    int ans = -1;

    int mid = s + (e - s) / 2;

    while (s <= e)
    {

        if (key == arr[mid])
        {
            ans = mid;

            s = mid + 1;
        }
        else if (key < arr[mid])
        {
            e = mid - 1;
            /* code */
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{

    int even[8] = {2, 3, 5, 5, 5, 5, 5, 9};

    int index = firstOccurence(even, 8, 5);
    int index2 = lastOccurence(even, 8, 5);

    cout << "first occurence of 5 is at index: " << index << endl;
    cout << "last occurence of 5 is at index: " << index2 << endl;
}