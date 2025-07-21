#include <iostream>
using namespace std;

double pow(double a, int n)
{

    long long N = n;

    if (N < 0)
    {
        a = 1 / a;
        N = -N;
    }

    if (N == 0)
    {
        return 1;
    }
    if (N == 1)
    {
        return a;
    }
    double ans = pow(a, N / 2);

    if (n % 2 == 0)
    {
        return ans * ans;
    }
    else
    {
        return a * ans * ans;
    }
}

int main()
{
    double a;
    int n;
    cout << "enter a numner and it's power: " << endl;
    cin >> a >> n;
    cout << pow(a, n);
}