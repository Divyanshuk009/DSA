#include <iostream>
using namespace std;

bool isPali(string wd)
{

    int s = 0;
    int e = wd.length() - 1;

    while (s < e)
    {
        if (wd[s++] != wd[e--])
        {
            return 0;
        }

        // else
        // {
        //     return 1;
        // }
    }
    return 1;
}

int main()
{
    string name = "Bob";

    cout << isPali(name);
}