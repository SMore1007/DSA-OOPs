#include <stdio.h>
#include <stdlib.h>

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

// Function to delete a node at a given position
void deleteAtPosition(struct Node** head_ref, int position) {
    if (*head_ref == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node* temp = *head_ref;

    // If head node needs to be deleted
    if (position == 1) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    // Traverse to the previous node of the node to be deleted
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    // If position is invalid or node is NULL
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of bounds.\n");
        return;
    }

    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;

    free(nodeToDelete);
}

int main()
{
    // Create nodes
    struct Node* head   = (struct Node*) malloc(sizeof(struct Node));
    struct Node* second = (struct Node*) malloc(sizeof(struct Node));
    struct Node* third  = (struct Node*) malloc(sizeof(struct Node));
    struct Node* forth  = (struct Node*) malloc(sizeof(struct Node));

    // Assign data
    head->data = 10;
    second->data = 20;
    third->data = 30;
    forth->data = 40;
    // Link nodes
    head->next = second;
    second->next = third;
    third->next = forth;
    forth->next = NULL;

    printf("Original Linked List:\n");
    printList(head);

    int positionToDelete = 3;
    printf("\nDeleting node at position %d\n", positionToDelete);
    deleteAtPosition(&head, positionToDelete);

    printf("Linked List after deletion:\n");
    printList(head);

    return 0;
}
