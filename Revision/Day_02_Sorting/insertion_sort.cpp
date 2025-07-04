#include <iostream>

using namespace std;

void insertSort(int arr[], int si)
{

    for (int i = 0; i < si; i++)

    {
        int temp = arr[i];
        int j = i - 1;

        while (j >= 0)
        {
            if (arr[j] > temp)
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
            j--;
        }

        arr[j + 1] = temp;
    }
}

int main()
{

    int num[6] = {89, 5, 2, 1, 10, 3};
    insertSort(num, 6);
    for (int i = 0; i < 6; i++)
    {
        cout << num[i] << " ";
    }
}