#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to display the linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to insert a node at the beginning
void insertAtBeginning(struct Node** head_ref, int new_data) {
    // 1. Allocate memory for new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    
    // 2. Put in the data
    new_node->data = new_data;
    
    // 3. Link the old list to the next of new node
    new_node->next = (*head_ref);
    
    // 4. Move the head to point to the new node
    *head_ref = new_node;
    printf("Inserted %d at the beginning.\n", new_data);
}

// Function to insert a node at the end
void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    
    new_node->data = new_data;
    new_node->next = NULL;
    
    // If the Linked List is empty, make the new node as head
    if (*head_ref == NULL) {
        *head_ref = new_node;
        printf("Inserted %d at the end (First node).\n", new_data);
        return;
    }
    
    // Otherwise, traverse until the last node
    while (last->next != NULL) {
        last = last->next;
    }
    
    // Change the next of last node
    last->next = new_node;
    printf("Inserted %d at the end.\n", new_data);
}

// Function to delete the first node
void deleteFromBeginning(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    
    struct Node* temp = *head_ref; // Store current head
    *head_ref = (*head_ref)->next; // Move head to next node
    
    printf("Deleted %d from the beginning.\n", temp->data);
    free(temp); // Free memory of old head
}

// Function to delete a node by its value
void deleteByValue(struct Node** head_ref, int key) {
    struct Node *temp = *head_ref, *prev = NULL;
    
    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next; // Changed head
        printf("Deleted %d from the list.\n", temp->data);
        free(temp);             // free old head
        return;
    }
    
    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    
    // If key was not present in linked list
    if (temp == NULL) {
        printf("Value %d not found in the list.\n", key);
        return;
    }
    
    // Unlink the node from linked list
    prev->next = temp->next;
    
    printf("Deleted %d from the list.\n", temp->data);
    free(temp); // Free memory
}

// Main function to test the code
int main() {
    // Initialize an empty list
    struct Node* head = NULL;

    // --- Insertion Operations ---
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtBeginning(&head, 5);
    insertAtEnd(&head, 30);
    
    // Display the list
    display(head);

    // --- Deletion Operations ---
    deleteFromBeginning(&head);
    display(head);
    
    deleteByValue(&head, 20);
    display(head);
    
    deleteByValue(&head, 99); // Testing a non-existent value

    return 0;
}
