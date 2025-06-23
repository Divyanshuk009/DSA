#include <iostream>
#include <vector>

using namespace std;

vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{

    vector<int> ans;

    for (int col = 0; col < mCols; col++)
    {
        if (col & 1)
        {
            // odd index -> bottom to top

            for (int row = nRows - 1; row >= 0; row--)
            {
                // cout << arr[row][col] << " ";
                ans.push_back(arr[row][col]);
            }
        }

        else
        {
            // 0 or even index -> top to bottom

            for (int row = 0; row < nRows; row++)
            {

                // cout << arr[row][col] << " ";
                ans.push_back(arr[row][col]);
            }
        }
    }
    return ans;
}

int main()
{

    vector<vector<int>> arr(3, vector<int>(3));

    cout << "enter elements: " << endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }

    wavePrint(arr, 3, 3);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}