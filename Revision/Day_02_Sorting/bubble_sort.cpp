#include <iostream>

using namespace std;

void bbSort(int arr[], int si)
{

    for (int i = 1; i < si; i++) // to traverse all element in the array
    {

        // bool swapped = false;
        for (int j = 0; j < si; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                // swapped = true;
            }
        }
        // if (swapped == false)
        // {
        //     break;
        // }
    }
}

int main()
{

    int num[] = {8, 3, 4, 1, 7, 1, 5};
    bbSort(num, 6);

    for (int i = 0; i < 7; i++)
    {

        cout << num[i] << " ";

        /* code */
    }

    return 0;
}