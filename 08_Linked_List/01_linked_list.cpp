#include<iostream>
using namespace std;

class Node
{
    private:
        /* data */
    public:
        int value; // data to node
        Node *next; // pointer to a next node

        Node(int val)
        {
            this->value = val;
            next = nullptr;
        }
        ~Node();
};


// Function to print the linked list
void printLL(Node* p) {
    while (p != nullptr) {
        cout << p->value << " -> ";
        p = p->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    // creating a linked memory space
    Node* head = new Node(0); // Pointer to a first element
    Node* second = new Node(0); // Pointer to a second element
    Node* third = new Node(0); // Pointer to a third element

    // Assigining a values
    head->value = 10;
    second->value = 20;
    third->value = 40;

    // Linking the linked list by pointer 
    head->next = second;
    second->next = third;
    third->next = NULL; 

    printLL(head);

    return 0;
    
}