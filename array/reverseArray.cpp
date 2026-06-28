#include <iostream>
using namespace std;

void reverse(int arr[], int length)
{
    int i = 0;
    int j = length - 1;
    while (i < j)
    {
        swap(arr[i++], arr[j--]);
    }
}

int main()
{
    int arr[] = {23, 43, 1, 3, 5, 12, 4, 6};
    int length = sizeof(arr) / sizeof(arr[0]);
    reverse(arr, length);
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}