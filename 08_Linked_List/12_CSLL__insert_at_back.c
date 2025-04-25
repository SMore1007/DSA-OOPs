#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtEndCSLL(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = *head;
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

    insertAtEndCSLL(&head, 10);
    insertAtEndCSLL(&head, 20);
    insertAtEndCSLL(&head, 30);
    insertAtEndCSLL(&head, 40);
    insertAtEndCSLL(&head, 50);
    insertAtEndCSLL(&head, 60);
    printf("Circular Singly Linked list Operation\n");
    printf("------------------Operations------------------------\n");
    printf("insertAtEndCSLL(&head, 10);\ninsertAtEndCSLL(&head, 20);\ninsertAtEndCSLL(&head, 30);\ninsertAtEndCSLL(&head, 40);\ninsertAtEndCSLL(&head, 50);\ninsertAtEndCSLL(&head, 60);\n");

    printf("-------------------------------------------------\n");
    printf("Circular Singly Linked List:\n");
    printCSLL(head);

    return 0;
}
