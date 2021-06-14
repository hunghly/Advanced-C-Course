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
                insert(&head, item);
                printList(head);
                printf("Enter choice:\n1. to insert in abc order\n2. to insert at the end of list\n3. to insert at beginning of list\n4. delete item from list\n5. delete item from beginning of list\n6. end\n::");
                scanf("%d", &choice);

                break;
            case 2:
                printf("Enter an item:\n");
                scanf("%s", &item);
                insertAtEnd(&head, item);
                printList(head);
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
                printf("Enter an item:\n");
                scanf("%s", &item);
                delete(&head, item);
                printList(head);
                printf("Enter choice:\n1. to insert in abc order\n2. to insert at the end of list\n3. to insert at beginning of list\n4. delete item from list\n5. delete item from beginning of list\n6. end\n::");
                scanf("%d", &choice);
                break;
            case 5:
                deleteAtBeginning(&head);
                printList(head);
                printf("Enter choice:\n1. to insert in abc order\n2. to insert at the end of list\n3. to insert at beginning of list\n4. delete item from list\n5. delete item from beginning of list\n6. end\n::");
                scanf("%d", &choice);
                break;
            case 6:
                return 0;
        }
    }


    return 0;
}

void insert(ListNodePtr *head, char value) {
    ListNodePtr newPtr;
    ListNodePtr previousPtr;
    ListNodePtr currentPtr;

    newPtr = malloc(sizeof(node_t));

    if (newPtr != NULL) {
        // initialize values
        newPtr->data = value;
        newPtr->nextPtr = NULL;
        previousPtr = NULL;
        currentPtr = *head;

        // loop as long as the value is larger than current data
        while (currentPtr != NULL && value > currentPtr->data) {
            printf("looping");
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }

        // If previous pointer is not found then insert at start of list
        if (previousPtr == NULL) {
            printf("inserting new");
            newPtr->nextPtr = *head;
            *head = newPtr;
        } else {
            // insert new node between previousPtr and currentPtr
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        }
    }
    else {
        printf("No node inserted. No memory available\n");
    }

}
void insertAtEnd(ListNodePtr *head, char value) {
    ListNodePtr current = *head;
    // printf("Head is |%c|", current->data);
    if (current != NULL) {
        while (current->nextPtr != NULL) {
            current = current->nextPtr;
        }
        current->nextPtr = malloc(sizeof(node_t));
        current->nextPtr->data = value;
        current->nextPtr->nextPtr = NULL;
    }
    else {
        current = malloc(sizeof(node_t));
        current->data = value;
        current->nextPtr = NULL;
    }
    *head = current;


}

void insertAtBeginning(ListNodePtr *head, char value) {
    ListNodePtr new_node = malloc(sizeof(node_t));
    new_node->data = value;
    new_node->nextPtr = *head;
    *head = new_node;
}
char delete(ListNodePtr *head, char value) {
    ListNodePtr tmpPtr;
    ListNodePtr previousPtr;
    ListNodePtr currentPtr;
    if (value == (*head)->data) {
        tmpPtr = *head;
        *head = (*head)->nextPtr;
        free(tmpPtr);
    }
    // first value wasn't a match so loop
    else {
        previousPtr = *head;
        currentPtr = (*head)->nextPtr;
        while (currentPtr != NULL && currentPtr->data != value) {
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }

        if (currentPtr != NULL) {
            tmpPtr = currentPtr;
            previousPtr->nextPtr = currentPtr->nextPtr;
            free(tmpPtr);
            return value;
        }
    }
    return '\0';
}
void deleteAtBeginning(ListNodePtr *head) {
    ListNodePtr tmpPtr = NULL;
    if (head == NULL) {
        return;
    }
    else {
        tmpPtr = *head; // hold onto the node being removed
        *head = (*head)->nextPtr; // assign head to the next ptr
        free(tmpPtr);
    }
}
int isEmpty(ListNodePtr head) {
    return head == NULL;
}
void printList(ListNodePtr currentPtr) {
    printf("Printing List: ");
    while (currentPtr != NULL) {
        printf("%c", currentPtr->data);
        currentPtr = currentPtr->nextPtr;
    }
    printf(" :End List\n");
}