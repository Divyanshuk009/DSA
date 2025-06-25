#include <iostream>
using namespace std;

void print(int *p)
{

    cout << *p << " - value print" << endl;  // value print
    cout << p << " - address print" << endl; // address print
}

int main()
{
    int value = 5;
    int *p = &value;

    print(p);
}