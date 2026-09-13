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
    // destructor
    ~node()
    {
        int value = this->data;
        // memory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "memory is free for node with data " << value << endl;
    }
};

void insertAtHead(node *&head, int d)
{

    //    new node create
    node *temp = new node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(node *&tail, int d)
{

    //    new node create
    node *temp = new node(d);
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(node *&head, int position, int d)
{
    node *temp = head;
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // creating a node for d;
    node *nodeToInsert = new node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteNode(int position, node *&head)
{

    if (position == 1)
    {

        node *temp = head;

        head = head->next;
        //   memory free start node
        delete temp;
    }
    else
    {
        // deleteing any middle or last node
        node *curr = head;
        node *prev = NULL;

        int cnt = 1;
        while (cnt <= position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        delete curr;
    }

    {
        /* code */
    }
}

void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    // 1. Create the initial node
    node *node1 = new node(10);
    node *head = node1;
    node *tail = node1;

    print(head); // Prints: 10

    // 2. Insert at the head
    insertAtHead(head, 12);
    print(head); // Prints: 12 10

    // 3. Insert at the tail
    insertAtTail(tail, 34);
    insertAtTail(tail, 46);

    // FIX 1: Changed 'tail' to 'head' to print the full list
    print(head); // Prints: 12 10 34 46

    // FIX 2: Changed 'tail' to 'head' so the function can count from the start
    insertAtPosition(head, 3, 89);
    print(head); // Prints: 12 10 89 34 46

    // 4. Delete the first node
    deleteNode(1, head);
    print(head); // Prints: 10 89 34 46

    return 0;
}
