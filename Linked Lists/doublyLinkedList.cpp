#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    // constructor
    Node(int d)
    {
        this->data = d;
        this->prev = nullptr;
        this->next = nullptr;
    }

    // destructor;
    ~Node()
    {
        int val = this->data;
        if (next != nullptr)
        {
            delete next;
            next = nullptr;
        }

        cout << "memory free for node with data " << val << endl;
    }
};

// print Linked list
void print(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
};

// give length of LL
int getLength(Node *head)
{
    int len = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        len++;
        temp = temp->next;
    }
    return len;
};

void insetAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head; // temp ke next ko head me daalo

    head->prev = temp; // head ke prev ko temp me daalo

    head = temp;
}

void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void insertAtPosition(Node *&tail, Node *&head, int position, int d)
{
    // insert at Start
    if (position == 1)
    {
        insertAtTail(tail, d);
        return;
    }

    Node *temp = head;
    int cnt = 1;

    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // inserting at Last Position
    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }

    // creating a node for d
    Node *nodeToInsert = new Node(d);

    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

void deleteNode(int position, Node *&head)
{
    // delete  first or start node
    if (position == 1)
    {
        Node *temp = head;
        temp->next->prev = nullptr;
        head = temp->next;
        temp->next = nullptr;
        delete temp;
    }
}

int main()
{
    Node *n1 = new Node(10);
    Node *head = n1;
    Node *tail = n1;

    print(head);

    cout << getLength(head) << endl;

    insetAtHead(head, 46);
    insetAtHead(head, 23);
    insetAtHead(head, 12);
    insetAtHead(head, 56);

    insertAtTail(tail, 34);
    print(tail);
    insertAtPosition(tail, head, 3, 100);
    print(head);
    return 0;
}
