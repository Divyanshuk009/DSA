#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int row, col;
    // Q.1

    // while (row <= n)
    // {
    //     col = 1;
    //     while (col <= n)
    //     {
    //         cout << col;
    //         col++;
    //     }
    //     cout << endl;
    //     row++;
    // }

    // Q.2
    // while (row <= n)
    // {
    //     col = 1;
    //     while (col <= row)
    //     {
    //         cout << "* ";
    //         col++;
    //     }
    //     cout << endl;
    //     row++;
    // }

    // Q.3
    while (row <= n)
    {
        col = 1;
        while (col <= row)
        {
            cout << row;
            col = col + 1;
        }
    }
    cout << endl;
    row = row + 1;
}