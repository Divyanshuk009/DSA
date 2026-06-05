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
        cout << "Destructor called for node with value: " << this->data << endl;
        // The recursive deletion logic
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
    }
};

void insertAtHead(node *&head, int d)
{
    node *temp = new node(d);
    temp->next = head;
    head = temp;
}

int main()
{
    cout << "--- WITH RECURSIVE DESTRUCTOR ---" << endl;
    node *head = NULL;
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    // List is now 1 -> 2 -> 3

    cout << "Deleting head (Node 1)..." << endl;
    delete head;

    cout << "\nNotice how all nodes (1, 2, 3) were destroyed!" << endl;
    return 0;
}
