#include <stdio.h>
#include <stdlib.h>

// Node struct for doubly linked list
struct Node {
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

// Function to insert at a specific position in doubly linked list
void insertAtPosition(struct Node** head_ref, int val, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;

    // Insert at the head
    if (position == 1) {
        newNode->next = *head_ref;
        if (*head_ref != NULL)
            (*head_ref)->prev = newNode;
        *head_ref = newNode;
        return;
    }

    struct Node* temp = *head_ref;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    // Invalid position
    if (temp == NULL) {
        printf("Position out of bounds!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

int main() {
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

    printf("\nInserting %d at position %d\n", 90, 4);
    insertAtPosition(&head, 90, 4);

    printf("Updated Doubly Linked List:\n");
    printList(head);

    return 0;
}
