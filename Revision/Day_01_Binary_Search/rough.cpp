#include <bits/stdc++.h>
using namespace std;

void reverse(char name[])
{
    int s = 0;
    int e = strlen(name) - 1;

    while (s <= e)
    {
        swap(name[s++], name[e--]);
    }
}

int main()
{
    char name[] = "golu";
    reverse(name);

    cout << name;
}