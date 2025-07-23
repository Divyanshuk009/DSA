#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    // constructor

    node(int d)
    {
        this->data = d;
        this->next = nullptr;
    }
    ~node()
    {
        int value = this->data;
        if (this->next != nullptr)
        {
            delete next;
            next = nullptr;
        }
        cout << "memory is free for node with data " << value << endl;
    }
};

void insertNode(node *)
{
}

int main()
{

    return 0;
}