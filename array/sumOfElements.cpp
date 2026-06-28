#include <iostream>
using namespace std;

int main()
{
    int arr[] = {2, 1, 4, 0, 5, 6, 1, 3, 5};
    int length = sizeof(arr) / sizeof(arr[0]);
    int count = 0;

    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum = sum + arr[i];
    }

    cout << "sum of elements of array is: " << sum;

    return 0;
}