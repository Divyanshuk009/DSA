#include <iostream>
using namespace std;

int freq(int arr[], int length, int index = 0)
{
    int max = arr[0];
    for (int i = 0; i < length; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    return max;
}

int main()
{
    int arr[] = {3, 5, 5, 70, 1, 9, 0, 211};
    int length = sizeof(arr) / sizeof(arr[0]);
    cout << length << endl;
    cout << freq(arr, length);
}