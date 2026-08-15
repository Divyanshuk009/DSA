#include <iostream>
using namespace std;
#include <vector>

void merge(int arr1[], int n, int arr2[], int m, int arr3[])
{
    int i = 0, j = 0;
    int k = 0;
    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            arr3[k++] = arr1[i++];
        }
        else
        {
            arr3[k++] = arr2[j++];
        }
    }

    // copy first array k element
    while (i < n)
    {
        arr3[k++] = arr1[i++];
    }

    // copy second remaining element
    while (j < m)
    {
        arr3[k++] = arr2[j++];
    }
}

void print(int ans[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main()
{

    int arr1[4] = {1, 3, 5, 7};
    int arr2[3] = {2, 4, 6};

    int arr3[7] = {0};

    merge(arr1, 4, arr2, 3, arr3);
    print(arr3, 7);
}