#include <iostream>
using namespace std;

int score = 15; // global variable

void a(int &i)
{

    cout << score << " in a" << endl;
}

void b(int &i)
{

    cout << score << " in b" << endl;
}

int main()
{
    int i = 2; // local variable
    a(i);
    b(i);

    cout << i << endl;
}