#include <iostream>
using namespace std;
#define pi 3.14 // can't be chnaged later inside code like pi=pi+1, can change from here only

int main()
{

    int r = 5;
    // double area = 3.14 * r * r;s

    double area = pi * r * r;

    cout << "area is: " << area << endl;
}