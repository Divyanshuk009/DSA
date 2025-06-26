#include <iostream>
using namespace std;

int main()
{
    int i = 5;

    int *p = &i;   // p stores the address of i
    int **p2 = &p; // p2 stores the address of pointer p

    cout << endl;

    cout << "address of i (&i): " << &i << endl;
    cout << "value of p (which is &i): " << p << endl;
    cout << "address of p (&p): " << &p << endl;

    cout << endl;

    cout << "value of *p2 (which is p / &i): " << *p2 << endl;
    cout << "value of **p2 (which is i): " << **p2 << endl;

    cout << endl;

    cout << "again printing address of i: " << &i << endl;
    cout << "again printing value of p: " << p << endl;
    cout << "again printing *p2 (should be same as p): " << *p2 << endl;

    cout << endl;

    cout << "again printing address of p: " << &p << endl;
    cout << "again printing *p2 (address stored in p): " << *p2 << endl;

    return 0;
}
