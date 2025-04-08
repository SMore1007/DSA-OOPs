/*
    Insert the element at the beginning of the linked list
*/

#include<iostream>
using namespace std;

// Linked List structure
struct Node
{
    int data;
    Node *next;
};

// Head Node (Global)
Node *head = NULL;

// Function to insert the node at beginning
void insertAtBeginning(int Data)
{
    // Create a new node
    Node *dummyNode = new Node();

    // Assign data
    dummyNode->data = Data;

    // Link this node to current head
    dummyNode->next = head;

    // Update head
    head = dummyNode;
}

// Print the linked list
void printLL(Node *p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    // Create memory for nodes
    Node *second = new Node();
    Node *third = new Node();

    // Assigning data
    head = new Node(); // Initialize head
    head->data = 20;
    head->next = second;

    second->data = 30;
    second->next = third;

    third->data = 40;
    third->next = NULL;

    // Insert a new node at the beginning
    insertAtBeginning(10);

    // Print the list
    printLL(head);
    return 0;
}