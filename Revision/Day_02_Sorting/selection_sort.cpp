#include <iostream>
using namespace std;

int selectSort(int arr[], int si)
{

    for (int i = 0; i < si - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < si; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        swap(arr[minIndex], arr[i]); // swap with i not j as j is already updated to minIndex
    }
    return 0;
}

int main()
{

    int num[6] = {5, 3, 2, 4, 6, 1};

    selectSort(num, 6);

    // Print the sorted array
    for (int i = 0; i < 6; i++)
    {
        cout << num[i] << " ";
    }
    // cout << endl;

    return 0;
}