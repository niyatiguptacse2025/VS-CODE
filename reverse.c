#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to reverse the linked list
struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;   // Tracks the previous node
    struct Node* current = head; // Tracks the current node
    struct Node* next = NULL;    // Temporarily stores the next node

    while (current != NULL) {
        next = current->next;    // 1. Save the next node
        current->next = prev;    // 2. Reverse the current node's pointer
        prev = current;          // 3. Move 'prev' one step forward
        current = next;          // 4. Move 'current' one step forward
    }
    
    // 'prev' now points to the new head of the reversed list
    return prev;
}

// Helper function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Helper function to insert a new node at the beginning
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    struct Node* head = NULL;

    // Create a list: 4 -> 3 -> 2 -> 1 -> NULL
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);

    printf("Original Linked List:\n");
    printList(head);

    // Reverse the list
    head = reverseList(head);

    printf("\nReversed Linked List:\n");
    printList(head);

    return 0;
}
