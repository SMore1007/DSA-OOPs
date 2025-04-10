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

// Function to insert at specific position
void insertAtPosition(struct Node** head_ref, int val, int position)
{
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    // If inserting at the head
    if (position == 1) {
        newNode->next = *head_ref;
        *head_ref = newNode;
        return;
    }

    // Traverse to one node before the desired position
    struct Node* temp = *head_ref;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    // If position is invalid
    if (temp == NULL) {
        printf("Position out of bounds!\n");
        free(newNode);
        return;
    }

    // Insert node
    newNode->next = temp->next;
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

    printf("\nInserting %d at position %d\n", 90, 4);
    insertAtPosition(&head, 90, 4);

    printf("Updated Linked List:\n");
    printList(head);

    return 0;
}
