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
    struct Node* head = NULL;
    struct Node* temp = NULL;
    struct Node* prev = NULL;

    int total_nodes = 0;
    printf("How many Nodes Do you want to create: \n");
    scanf("%d", &total_nodes);

    for (int i = 0; i < total_nodes; i++) 
    {
        int temp_buffer;

        // Create a new node
        temp = (struct Node*) malloc(sizeof(struct Node));

        printf("Enter a Data for node %d", i+1);
        scanf("%d", &temp_buffer);

        temp->data = temp_buffer;
        temp->next = NULL;

        if (head == NULL) {
            // First node becomes head
            head = temp;
        } else {
            // Link the previous node to the new one
            prev->next = temp;
        }
        // Update previous node
        prev = temp;
    }

    printf("Previous Linked List\n");
    printList(head);

    printf("\nInserting %d at beginning\n", 80);
    insertAtBegin(&head, 80);

    printList(head);
    return 0;
}
