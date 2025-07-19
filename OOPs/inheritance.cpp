#include <iostream>
using namespace std;

class Human
{
public:
    int height;
    int weight;
    int age;

private:
    int salary;

public:
    int getAge()
    {
        return this->age;
    }
    int setWeight(int w)
    {
        return this->weight = w;
    }
};

class male : public Human
{

public:
    string color;

    void sleep()
    {
        cout << "male sleeping" << endl;
    }
};

int main()
{
    male obj1;

    cout << obj1.age << endl;
    cout << obj1.height << endl;

    //  cout << obj1.salary << endl;  //salary not accessible as it is private

    obj1.setWeight(89);
    cout << obj1.weight << endl;
    obj1.sleep();
}