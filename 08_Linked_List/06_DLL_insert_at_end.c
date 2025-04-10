#include <stdio.h>
#include <stdlib.h>

// Node struct for doubly linked list
struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to print the doubly linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d <-> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Function to insert at the end of the doubly linked list
void insertAtEnd(struct Node** head_ref, int val)
{
    // Create a new node
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;

    // If list is empty, new node becomes the head
    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }

    // Traverse to the last node
    struct Node* temp = *head_ref;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Link last node to new node
    temp->next = newNode;
    newNode->prev = temp;
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

    // Link nodes (both next and prev)
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

    printf("\nInserting %d at the end\n", 60);
    insertAtEnd(&head, 60);

    printf("Updated Doubly Linked List:\n");
    printList(head);

    return 0;
}
