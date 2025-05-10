#include <stdio.h>
#include <stdlib.h>

struct DNode {
    int data;
    struct DNode* next;
    struct DNode* prev;
};

void insertAtEndCDLL(struct DNode** head, int data) {
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

    insertAtEndCDLL(&head, 11);
    insertAtEndCDLL(&head, 22);
    insertAtEndCDLL(&head, 30);
    insertAtEndCDLL(&head, 35);
    insertAtEndCDLL(&head, 20);
    insertAtEndCDLL(&head, 60);

    printf("------------------Operation------------------------\n");
    printf("insertAtEndCDLL(&head, 11);\ninsertAtEndCDLL(&head, 22);\ninsertAtEndCDLL(&head, 30);\ninsertAtEndCDLL(&head, 35);\ninsertAtEndCDLL(&head, 20);\ninsertAtEndCDLL(&head, 60);\n");
    printf("------------------------------------------\n");
    printf("Circular Doubly Linked List:\n");
    printCDLL(head);

    return 0;
}
