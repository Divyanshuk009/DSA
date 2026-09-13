#include <iostream>
using namespace std;

class node
{

public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~node()
    {
        int value = this->data;

        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
    }
};

int main()
{

    return 0;
}