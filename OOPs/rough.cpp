#include <bits/stdc++.h>
using namespace std;

class A
{
public:
    void func()
    {
        cout << "i am A" << endl;
    }
};

class B
{
public:
    void func()
    {
        cout << "i am B" << endl;
    }
};

class c : public A, public B
{
};

int main()
{
    c obj;

    obj.A::func();
}