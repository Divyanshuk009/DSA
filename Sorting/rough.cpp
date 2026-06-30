#include <iostream>
using namespace std;
#include <vector>

void sort(int arr[], int length)
{

    if (length <= 1)
    {
        return;
    }

    for (int i = 0; i < length - 1; i++)
    {
        // for (int j = i + 1; j < length; j++)
        // {

        // }

        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }
    sort(arr, length - 1);
}

int main()
{
    int arr[] = {3, 1, 3, 2, 7, 5, 1};
    int length = sizeof(arr) / sizeof(arr[0]);

    sort(arr, length);

    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    // cout << -3 * -5 << endl;
    // int dig = 34;
    // int dig2 *= 2;

    return 0;
}