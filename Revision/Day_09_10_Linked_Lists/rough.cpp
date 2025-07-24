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
        this->next = nullptr;
    }
};

void insertAtHead(node *&head, int d)
{
    node *temp = new node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(node *&tail, int d)
{
    node *temp = new node(d);
    tail->next = temp;
    tail = temp;
}

void print(node *head)
{
    node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    node *node1 = new node(34);
    node *node2 = new node(59);
    node *node3 = new node(90);
    // node4 not used, so skipping

    node1->next = node2;
    node2->next = node3;
    node3->next = nullptr;

    node *head = node1;

    // Find actual tail
    node *tail = head;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }

    insertAtHead(head, 69); // Adds 69 at the beginning
    print(head);            // Output: 69 34 59 90

    insertAtTail(tail, 100); // Adds 100 at the end
    print(head);             // Output: 69 34 59 90 100

    return 0;
}
