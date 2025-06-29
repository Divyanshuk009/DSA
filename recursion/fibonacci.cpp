#include <iostream>
using namespace std;

int fib(int n)
{
    // base cases
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n = 9;

    cout << "Fibonacci sequence up to " << n << ":\n";
    for (int i = 0; i <= n; i++)
    {
        cout << fib(i) << " ";
    }
    cout << endl;

    return 0;
}
