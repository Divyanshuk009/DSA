#include <iostream>

using namespace std;

int main()
{
    int i, j, num;
    cout << "enter a number num" << endl;
    cin >> num;

    for (i = 0; i <= num; i++)
    {
        for (j = i; j <= i; j++)
        {
            cout << "*" << endl;
        }
    }
}