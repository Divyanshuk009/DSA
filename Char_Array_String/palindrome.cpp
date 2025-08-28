#include <iostream>

using namespace std;

bool caseCheck(string word)
{
    int s = 0;
    int e = word.length() - 1;

    if (word[s] >= 'a' && word[e] <= 'z')
    {
        return true;
    }
    // s++;
    // e--;

    else
    {
        char temp = word[s] - 'A' + 'a';
        return temp;
    }
}

bool ispali(string name) // char name[] for char
{

    int s = 0;
    int e = name.length() - 1; // for char name[], length is strlen(name)

    while (s < e)
    {
        if (name[s++] != name[e--])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{

    string name; //= "naman";
    // string name2 = "apple";
    cout << "enter name: " << endl;
    cin >> name;
    // // int s = caseCheck(name);
    // // cout << s << endl;

    // int P = ispali(name);
    // // int q = ispali(name2);

    // cout << P << endl;
    // // cout << q;

    cout << ispali(name);
}