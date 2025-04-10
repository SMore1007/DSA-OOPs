#include<stdio.h>
#include<stdlib.h>

// Node struct
struct Node
{
    int data;
    struct Node* next;
};

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Function to insert at the end of the list
void insertAtEnd(struct Node** head_ref, int val)
{
    // Create a new node
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    // If list is empty, new node becomes the head
    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }

    // Otherwise, find the last node
    struct Node* temp = *head_ref;
    while (temp->next != NULL) 
    {
        temp = temp->next;
    }

    // Link the last node to new node
    temp->next = newNode;
}

int main()
{
    // head Node space
    struct Node* head   = (struct Node*) malloc(sizeof(struct Node));
    struct Node* second = (struct Node*) malloc(sizeof(struct Node));
    struct Node* third  = (struct Node*) malloc(sizeof(struct Node));
    struct Node* forth  = (struct Node*) malloc(sizeof(struct Node));

    // Assign the value to linked list
    head->data   = 10;
    second->data = 20;
    third->data  = 30;
    forth->data  = 40;

    // Link the linked list
    head->next   = second;
    second->next = third;
    third->next  = forth;
    forth->next  = NULL;

    printf("Previous Linked List:\n");
    printList(head);

    printf("\nInserting %d at the end\n", 60);
    insertAtEnd(&head, 60);

    printf("Updated Linked List:\n");
    printList(head);

    return 0;
}
