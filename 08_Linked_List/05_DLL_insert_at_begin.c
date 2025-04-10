#include <stdio.h>
#include <stdlib.h>

// Node struct for doubly linked list
struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to print the linked list (forward direction)
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d <-> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Insert a node at the beginning of a doubly linked list
void insertAtBegin(struct Node** head_ref, int val)
{
    // Create the memory space for new node
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

    // Assign data
    newNode->data = val;

    // Set next of new node as current head
    newNode->next = *head_ref;
    newNode->prev = NULL;

    // Change prev of current head node to new node if list is not empty
    if (*head_ref != NULL)
        (*head_ref)->prev = newNode;

    // Move the head to point to the new node
    *head_ref = newNode;
}

int main()
{
    // Allocate nodes
    struct Node* head   = (struct Node*) malloc(sizeof(struct Node));
    struct Node* second = (struct Node*) malloc(sizeof(struct Node));
    struct Node* third  = (struct Node*) malloc(sizeof(struct Node));
    struct Node* forth  = (struct Node*) malloc(sizeof(struct Node));

    // Assign data
    head->data   = 10;
    second->data = 20;
    third->data  = 30;
    forth->data  = 40;

    // Link nodes (next and prev)
    head->next = second;
    head->prev = NULL;

    second->next = third;
    second->prev = head;

    third->next = forth;
    third->prev = second;

    forth->next = NULL;
    forth->prev = third;

    printf("Previous Doubly Linked List:\n");
    printList(head);

    printf("\nInserting %d at beginning\n", 80);
    insertAtBegin(&head, 80);

    printList(head);

    return 0;
}
