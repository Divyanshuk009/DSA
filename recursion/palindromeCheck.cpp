#include <iostream>

using namespace std;

bool pali(string s, int i, int j)
{

    //  Base case
    if (i >= j)
    {
        return true;
    }

    if (s[i] != s[j])
    {
        cout << "not a palindrome" << endl;
        return false;
    }

    // i++;
    // j--;

    return pali(s, i + 1, j - 1);
}

int main()
{
    string n = "naman";

    cout << pali(n, 0, n.size() - 1);
}