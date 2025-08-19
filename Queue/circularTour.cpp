#include <bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump p[], int n)
{
    int deficit = 0;
    int balance = 0;
    int start = 0;

    for (int i = 0; i < n; i++)
    {
        balance += p[i].petrol - p[i].distance;
        if (balance < 0)
        {
            deficit += balance;
            start = i + 1;
            balance = 0;
        }
    }
    if (deficit + balance >= 0)
    {
        return start;
    }
    else
    {
        return -1;
    }
};

int main()
{
    // Test case 1
    petrolPump p1[] = {{6, 4}, {3, 6}, {7, 3}};
    int n1 = sizeof(p1) / sizeof(p1[0]);

    int result1 = tour(p1, n1);
    if (result1 == -1)
        cout << "Test 1: No possible tour" << endl;
    else
        cout << "Test 1: Start tour from petrol pump: " << result1 << endl;
}
