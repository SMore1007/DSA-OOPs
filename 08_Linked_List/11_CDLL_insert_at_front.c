#include <stdio.h>
#include <stdlib.h>

struct DNode {
    int data;
    struct DNode* next;
    struct DNode* prev;
};

void insertAtBeginCDLL(struct DNode** head, int data) {
    struct DNode* newNode = (struct DNode*)malloc(sizeof(struct DNode));
    newNode->data = data;

    if (*head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        *head = newNode;
    } else {
        struct DNode* last = (*head)->prev;

        newNode->next = *head;
        newNode->prev = last;
        last->next = newNode;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void printCDLL(struct DNode* head) {
    if (head == NULL) return;

    struct DNode* temp = head;
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("HEAD\n");
}

int main() {
    struct DNode* head = NULL;

    insertAtBeginCDLL(&head, 5);
    insertAtBeginCDLL(&head, 10);
    insertAtBeginCDLL(&head, 20);
    insertAtBeginCDLL(&head, 25);
    insertAtBeginCDLL(&head, 30);
    insertAtBeginCDLL(&head, 35);
    printf("--------------------Operations----------------------\n");
    printf("insertAtBeginCDLL(&head, 5);\ninsertAtBeginCDLL(&head, 10);\ninsertAtBeginCDLL(&head, 20);\ninsertAtBeginCDLL(&head, 25);\ninsertAtBeginCDLL(&head, 30);\ninsertAtBeginCDLL(&head, 35);\n");
    printf("------------------------------------------\n");
    printf("\nCircular Doubly Linked List:\n");
    printCDLL(head);

    return 0;
}
