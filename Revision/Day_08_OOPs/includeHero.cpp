#include <iostream>
using namespace std;
// #include "hero.cpp"

class Hero
{
    // properties
public: //  accessible outside the class (public)
    int health;
    int level;

private:
    int age; // only accessible inside the class (private)
public:
    // parameterised constructor

    Hero()
    {
        cout << "constructor called " << endl;
    }

    Hero(int health, int level)
    {
        cout << "this -> " << this << endl;
        this->health = health;
    }

    // copy constructor

    Hero(Hero &temp)
    {
        cout << "copy constructor called " << endl;
        this->health = temp.health;
        this->level = temp.level;
    }

    int gethealth()
    {
        return health;
    }

    int getlevel()
    {
        return level;
    }

    void sethealth(int h)
    {
        health = h;
    }

    void setlevel(int ch)
    {
        level = ch;
    }

    void print()
    {
        cout << "health " << this->health << endl;
        cout << "level " << this->level << endl;
    }
};

int main()
{

    Hero suresh(70, 6);

    suresh.print();

    Hero R(suresh);

    // R.health = suresh.health;
    // R.level = suresh.level;

    R.print();

    // Hero sonu;

    // // sonu.health = 30;
    // // sonu.level = 3;

    // cout << "health is : " << sonu.gethealth() << endl;
    // sonu.sethealth(67);
    // cout << "health is : " << sonu.gethealth() << endl;
    // sonu.setlevel(4);
    // cout << "level is : " << sonu.level << endl;

    // static allocation
    Hero golu;
    golu.sethealth(49);
    golu.setlevel(6);

    cout << "Address of golu: " << &golu << endl;

    cout << "health is " << golu.health << endl;
    cout << "level is " << golu.level << endl;

    // dynamic allocation

    Hero *b = new Hero;
    b->sethealth(90);
    b->setlevel(7);

    cout << "health is " << (*b).health << endl;
    cout << "level is " << (*b).level << endl;

    cout << "health is " << b->health << endl;
    cout << "level is " << b->level << endl;
}