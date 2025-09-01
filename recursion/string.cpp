#include <iostream>
using namespace std;

void reverse(string &s, int i, int j)
{

    cout << s << endl;
    if (i > j)
    {
        return;
    }
    swap(s[i], s[j]);
    i++;
    j--;

    reverse(s, i, j);
}

int main()
{
    string name = "Divyanshu";
    // string name2 = "Divyanshu kumar";
    // string name3[2] = {"Divyanshu kumar", "pop"};

    reverse(name, 0, 8);
    cout << name << endl;
    //     cout << name2 << endl;

    //     cout << name3[1];
}
