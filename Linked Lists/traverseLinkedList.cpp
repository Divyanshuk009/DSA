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
};

// Function to get the nth element (0-indexed)
node *getNthElement(node *head, int n)
{
    node *temp = head;
    int count = 0;

    // Traverse the list until we reach the index or the end of the list
    while (temp != NULL)
    {
        if (count == n)
        {
            return temp; // Found the nth node
        }
        count++;
        temp = temp->next; // Move to the next node
    }

    // If we exit the loop, n is out of bounds
    return NULL;
}

// Helper function to insert at tail
void insertAtTail(node *&tail, int d)
{
    node *temp = new node(d);
    tail->next = temp;
    tail = temp;
}

int main()
{
    // Creating a list: 10 -> 20 -> 30 -> 40 -> NULL
    node *node1 = new node(10);
    node *head = node1;
    node *tail = node1;
    insertAtTail(tail, 20);
    insertAtTail(tail, 30);
    insertAtTail(tail, 40);

    int targetIndex = 2; // We want the 3rd element (index 2)
    node *result = getNthElement(head, targetIndex);

    if (result != NULL)
    {
        cout << "Element at index " << targetIndex << " is: " << result->data << endl;
    }
    else
    {
        cout << "Index " << targetIndex << " is out of bounds!" << endl;
    }

    return 0;
}
