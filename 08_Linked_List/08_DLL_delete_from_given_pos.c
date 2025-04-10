#include <stdio.h>
#include <stdlib.h>

// Doubly Linked List Node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d <-> ", node->data);
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

    // Deleting head node
    if (position == 1) {
        *head_ref = temp->next;
        if (*head_ref != NULL)
            (*head_ref)->prev = NULL;
        free(temp);
        return;
    }

    // Traverse to the node to delete
    for (int i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds.\n");
        return;
    }

    // Update links
    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

int main() {
    // Allocate memory for nodes
    struct Node* head   = (struct Node*) malloc(sizeof(struct Node));
    struct Node* second = (struct Node*) malloc(sizeof(struct Node));
    struct Node* third  = (struct Node*) malloc(sizeof(struct Node));
    struct Node* forth  = (struct Node*) malloc(sizeof(struct Node));

    // Assign data
    head->data = 10;
    second->data = 20;
    third->data = 30;
    forth->data = 40;

    // Link nodes (both next and prev)
    head->next = second;
    head->prev = NULL;

    second->next = third;
    second->prev = head;

    third->next = forth;
    third->prev = second;

    forth->next = NULL;
    forth->prev = third;

    printf("Original Doubly Linked List:\n");
    printList(head);

    int positionToDelete = 3;
    printf("\nDeleting node at position %d\n", positionToDelete);
    deleteAtPosition(&head, positionToDelete);

    printf("Doubly Linked List after deletion:\n");
    printList(head);

    return 0;
}
