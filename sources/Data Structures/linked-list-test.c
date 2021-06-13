#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char data;
    struct node *nextPtr;
} node_t;

typedef node_t *ListNodePtr;

void insert(ListNodePtr *head, char value);
void insertAtEnd(ListNodePtr *head, char value);
void insertAtBeginning(ListNodePtr *head, char value);
char delete(ListNodePtr *head, char value);
void deleteAtBeginning(ListNodePtr *head);
int isEmpty(ListNodePtr head);
void printList(ListNodePtr currentPtr);

int main(void) {

    ListNodePtr head = NULL;

    int choice = 0;
    char item = '\0';

    printf("Enter choice:\n1. to insert in abc order\n2. to insert at the end of list\n3. to insert at beginning of list\n4. delete item from list\n5. delete item from beginning of list\n6. end\n::");
    scanf("%d", &choice);

    printf("You chose: %d\n", choice);

    while (choice != 6) {
        switch(choice) {
            case 1:
                printf("Enter an item:\n");
                scanf("%s", &item);
                // insert(&head, item);
                printList(head);
                    printf("Enter choice:\n1. to insert in abc order\n2. to insert at the end of list\n3. to insert at beginning of list\n4. delete item from list\n5. delete item from beginning of list\n6. end\n::");

                scanf("%d", &choice);

                break;
            case 2:
                printf("Enter choice:\n1. to insert in abc order\n2. to insert at the end of list\n3. to insert at beginning of list\n4. delete item from list\n5. delete item from beginning of list\n6. end\n::");

                scanf("%d", &choice);

                break;
            case 3:
                printf("Enter an item:\n");
                scanf("%s", &item);
                insertAtBeginning(&head, item);
                printList(head);
                printf("Enter choice:\n1. to insert in abc order\n2. to insert at the end of list\n3. to insert at beginning of list\n4. delete item from list\n5. delete item from beginning of list\n6. end\n::");
                scanf("%d", &choice);
                break;
            case 4:
                printf("Enter choice:\n1. to insert in abc order\n2. to insert at the end of list\n3. to insert at beginning of list\n4. delete item from list\n5. delete item from beginning of list\n6. end\n::");

                scanf("%d", &choice);

                break;
            case 5:
                printf("Enter choice:\n1. to insert in abc order\n2. to insert at the end of list\n3. to insert at beginning of list\n4. delete item from list\n5. delete item from beginning of list\n6. end\n::");

                scanf("%d", &choice);

                break;
            case 6:
                return 0;
        }
    }


    return 0;
}

void insert(ListNodePtr *head, char value);
void insertAtEnd(ListNodePtr *head, char value) {

}

void insertAtBeginning(ListNodePtr *head, char value) {
    ListNodePtr new_node = malloc(sizeof(node_t));
    new_node->data = value;
    new_node->nextPtr = *head;
    *head = new_node;
}
char delete(ListNodePtr *head, char value);
void deleteAtBeginning(ListNodePtr *head);
int isEmpty(ListNodePtr head);
void printList(ListNodePtr currentPtr) {
    while (currentPtr != NULL) {
        printf("%c\n", currentPtr->data);
        currentPtr = currentPtr->nextPtr;
    }
}