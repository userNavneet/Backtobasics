#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
typedef struct Node {
    int data;
    struct Node* next;
};
Node
// Function to create a new node
struct Node* newNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(struct Node** headRef, int data) {
    struct Node* newNode = newNode(data);
    newNode->next = *headRef;
    *headRef = newNode;
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(struct Node** headRef, int data) {
    struct Node* newNode = newNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    struct Node* temp = *headRef;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete a node with a given key
void deleteNode(struct Node** headRef, int key) {
    struct Node* temp = *headRef;
    struct Node* prev = NULL;
    if (temp != NULL && temp->data == key) {
        *headRef = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Key not found in the list\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Main function to test the linked list operations
int main() {
    struct Node* head = NULL;

    // Insert some nodes
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);

    // Print the initial list
    printf("Initial list: ");
    printList(head);

    // Insert a node at the beginning
    insertAtBeginning(&head, 0);
    printf("List after inserting 0 at the beginning: ");
    printList(head);

    // Delete a node with key 2
    deleteNode(&head, 2);
    printf("List after deleting node with key 2: ");
    printList(head);

    return 0;
}