#include <iostream>

using namespace std;

//  print row wise sum ->
void printSum(int arr[][3], int row, int col)
{

    for (int row = 0; row < 3; row++)
    {
        int sum = 0;
        for (int col = 0; col < 3; col++)
        {
            sum += arr[row][col];
        }
        cout << sum << " ";
    }
}

int main()
{

    /*  // custom values ->
    int arr[3][3] = {{1, 11, 111}, {2, 22, 222}, {3, 33, 333}};

     for (int i = 0; i < 3; i++)
     {
         for (int j = 0; j < 3; j++)
         {
             cout << arr[i][j] << " ";
         }
         cout << endl;
     }

     */

    int arr[3][3];
    cout << "Enter elements: " << endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    printSum(arr, 3, 3);
}