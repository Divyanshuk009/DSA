#include <iostream>

using namespace std;

void reverse(char name[], int n)
{
    int s = 0;
    int e = n - 1;

    while (s <= e)
    {
        swap(name[s++], name[e--]);
    }
}

int main()
{

    char naam[] = "hello";

    reverse(naam, 5);

    cout << naam;
}

// or

// void reverse(string &st, int si)
// {
//     int s = 0;
//     int e = st.size() - 1;

//     int mid = s + (e - s) / 2;
//     while (s < e)
//     {
//         swap(st[s++], st[e--]);
//     }
// }

// int main()
// {
//     string name = "golu";
//     reverse(name, 4);
//     cout << name;
// }