#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to append a node at the end of the linked list
void append(struct Node** head_ref, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Procedure to swap the Kth element with the (K+1)th element
void swap(struct Node** head_ref, int k) {
    if (*head_ref == NULL || (*head_ref)->next == NULL || k <= 0)
        return;

    struct Node *prev_k = NULL, *current = *head_ref;
    for (int i = 0; current != NULL && i < k - 1; i++) {
        prev_k = current;
        current = current->next;
    }

    if (current == NULL || current->next == NULL)
        return;

    struct Node* next_k = current->next;
    if (prev_k != NULL)
        prev_k->next = next_k;
    else
        *head_ref = next_k;
    current->next = next_k->next;
    next_k->next = current;
}

// // Procedure to reverse the linked list
// void reverse(struct Node** head_ref) {
//     struct Node *prev = NULL, *current = *head_ref, *next = NULL;
//     while (current != NULL) {
//         next = current->next;
//         current->next = prev;
//         prev = current;
//         current = next;
//     }
//     *head_ref = prev;
// }

// Driver code
int main() {
    struct Node* head = NULL;
    for (int i = 1; i <= 5; i++)
        append(&head, i);

    printf("Original list: ");
    printList(head);

    int k = 2;
    swap(&head, k);
    printf("\nList after swapping %dth and %dth elements: ", k, k + 1);
    printList(head);

    // reverse(&head);
    // printf("\nReversed list: ");
    // printList(head);

    return 0;
}
