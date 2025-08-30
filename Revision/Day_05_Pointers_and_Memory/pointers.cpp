#include <iostream>
using namespace std;

int main()
{

    int num = 6;

    int *ptr = &num; // reference

    cout << "value of num is: " << *ptr << endl;
    cout << "address of num is (ptr): " << ptr << endl;
    cout << "address of num is (&num): " << &num << ", same as in ptr" << endl;

    cout << "value of num is after increment: " << *ptr++ << endl;

    cout << endl;
    double num_2 = 3.43;
    double *dbl = &num_2;

    cout << "value of num_2 is: " << *dbl << endl;
    cout << "address of num_2 is: " << dbl << endl;

    int i = 3;
    int *t = &i;

    cout << " before t " << t << endl;

    t = t + 1;
    cout << " after t (increase by 4 as size of int is 4 byte): " << t << endl;
}