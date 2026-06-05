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
        // NOT DELETING THE NEXT NODE HERE
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
    cout << "--- WITHOUT RECURSIVE DESTRUCTOR ---" << endl;
    node *head = NULL;
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    // List is now 1 -> 2 -> 3

    cout << "Deleting head (Node 1)..." << endl;
    delete head;

    cout << "\nNotice how ONLY Node 1 was destroyed. Nodes 2 and 3 are lost in memory (Memory Leak)!" << endl;
    return 0;
}
