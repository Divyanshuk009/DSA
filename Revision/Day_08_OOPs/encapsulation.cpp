#include <iostream>
using namespace std;

class student
{

private:
    string name;
    int age = 20;
    int height;

public:
    int getAge()
    {
        return this->age;
    }
};

int main()
{
    student first;

    cout << first.getAge() << endl;
    cout << "all ok " << endl;
}