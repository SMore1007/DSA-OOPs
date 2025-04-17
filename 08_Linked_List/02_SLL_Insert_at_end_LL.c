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
    struct Node* head = NULL;
    struct Node* temp = NULL;
    struct Node* prev = NULL;

    int total_nodes = 0;

    printf("Enter total Number of Nodes : \n");
    scanf("%d", &total_nodes);

    for (int i = 0; i < total_nodes; i++)
    {
        struct Node *temp = (struct Node*) malloc(sizeof(struct Node));

        int data_buffer = 0;
        printf("Enter Data for the node %d \n", i +1);
        scanf("%d", &data_buffer);

        temp->data = data_buffer;
        temp->next = NULL;

        if(head == NULL){
            head = temp;
        }else{
            // Link the previous node to the new one
            prev->next = temp;
        }
        // Update previous node
        prev = temp;
        
    }

    printf("Previous Linked List:\n");
    printList(head);

    printf("\nInserting %d at the end\n", 60);
    insertAtEnd(&head, 60);

    printf("Updated Linked List:\n");
    printList(head);

    return 0;
}
