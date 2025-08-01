#include <iostream>
using namespace std;

void merge(int arr[], int s, int e)
{

    int mid = s + (e - s) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;
    int k = s;
    for (int i = 0; i < len1; i++)
    {
        arr[i] = arr[k++];
    }
}

void mergeSort(int arr[], int s, int e)
{
    if (s > e)
    {
        return;
    }

    int mid = s + (e - s) / 2;

    mergeSort(arr, s, mid);

    mergeSort(arr, mid + 1, e);
    merge(arr, s, e);
}

int main()
{

    int arr[5] = {2, 5, 1, 6, 4};

    int n = 5;

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
}