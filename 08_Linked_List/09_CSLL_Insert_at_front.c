#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtBeginCSLL(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head)
            temp = temp->next;

        newNode->next = *head;
        temp->next = newNode;
        *head = newNode;
    }
}

void printCSLL(struct Node* head) {
    if (head == NULL) return;

    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("HEAD\n");
}

int main() {
    struct Node* head = NULL;


    insertAtBeginCSLL(&head, 5);
    insertAtBeginCSLL(&head, 6);
    insertAtBeginCSLL(&head, 8);
    insertAtBeginCSLL(&head, 5);
    insertAtBeginCSLL(&head, 52);
    insertAtBeginCSLL(&head, 3);
    printf("------------------Operations------------------------\n");
    printf("insertAtBeginCSLL(&head, 5);\ninsertAtBeginCSLL(&head, 6);\ninsertAtBeginCSLL(&head, 8);\ninsertAtBeginCSLL(&head, 52);\ninsertAtBeginCSLL(&head, 3);\n");

    printf("-------------------------------------------------\n");

    printf("Circular Singly Linked List:\n");
    printCSLL(head);

    return 0;
}
