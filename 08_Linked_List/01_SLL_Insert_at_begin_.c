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

void insertAtBegin(struct Node** head_ref, int val)
{
    // Create the memory space for node
    struct Node* dummyNode = (struct Node*) malloc(sizeof(struct Node));

    // Assign the data
    dummyNode->data = val;

    // Make next of dummyNode at head
    dummyNode->next = *head_ref;

    // Move the head to the point to the dummyNode

    *head_ref = dummyNode;
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

    printf("Previous Linked List\n");
    printList(head);
    printf("\nInserting %d at begining\n", 80);
    insertAtBegin(&head, 80);
    printList(head);
    return 0;
}