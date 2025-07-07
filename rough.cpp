#include <iostream>
#include <vector>
using namespace std;

void merge(int arr1[], int n, int arr2[], int m, int arr3[])
{
    int i = 0;
    int j = 0;
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
    while (i < n)
    {
        arr3[k++] = arr1[i++];
    }

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

    int num1[3] = {7, 8, 9};

    int num2[4] = {1, 5, 6, 10};
    int arr3[7] = {0};

    merge(num1, 3, num2, 4, arr3);

    print(arr3, 7);

    vector<int> kpp = {2, 3, 4, 5};
    cout << kpp[3];
}