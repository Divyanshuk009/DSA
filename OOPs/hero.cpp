#include <iostream>

using namespace std;

class Hero
{
    // properties;
    int health;
    int age;
};

int main()
{

    Hero h1;
    cout << "size : " << sizeof(h1) << endl; // = total size of properties (8bit)
}