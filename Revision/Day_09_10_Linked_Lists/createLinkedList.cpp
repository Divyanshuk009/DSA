#include <iostream>

struct Node
{
    int data;
    Node *next;
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList
{
private:
    Node *head; // Tracks the start of the list

public:
    // Constructor initializes an empty list
    LinkedList() : head(nullptr) {}

    // Insert a new node at the front
    void insertAtHead(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Insert a new node at the end
    void insertAtTail(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Traverse and print the list
    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL\n";
    }

    // Destructor to free dynamically allocated heap memory
    ~LinkedList()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            Node *nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};

int main()
{
    LinkedList list;

    // Build the list
    list.insertAtTail(10);
    list.insertAtTail(20);
    list.insertAtHead(5); // Becomes new front
    list.insertAtTail(30);

    // Expected Output: 5 -> 10 -> 20 -> 30 -> NULL
    std::cout << "Linked List: ";
    list.display();

    return 0;
}
