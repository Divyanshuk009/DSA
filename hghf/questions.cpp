#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "enter a no." << endl;

    cin >> n;

    bool isprime = 1;
    // for (int i = 0; i <= n; i++)
    // {
    //     sum = sum + i;
    // }
    // cout << "sum of first " << n << " number is: " << sum;

    for (int i = 2; i < n; i++)
    {

        if (n % i == 0)
        {
            isprime = 0;
            break;
        }
    }
    if (isprime == 0)
    {
        cout << "not a prime no.";
    }
    else
    {
        cout << "a prime no.";
    }
}