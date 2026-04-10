#include <iostream>

using namespace std;

int sqr(int key)
{

    int s = 0;
    int e = key;
    int mid = (s + e) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (mid * mid == key)
        {
            return mid;
        }
        else if (mid * mid < key)
        {

            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = (s + e) / 2;
    }
    return ans;
}

// int sqrroot(int x)
// {

//     return sqr(x);
// }

int main()
{
    cout << sqr(64);
}