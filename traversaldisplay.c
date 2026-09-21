#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to traverse and print the linked list
void displayList(struct Node* head) {
    // 1. Check if the list is empty
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    // 2. Initialize a temporary pointer to the head node
    struct Node* current = head;

    printf("Linked List: ");
    
    // 3. Loop until the end of the list (where current becomes NULL)
    while (current != NULL) {
        printf("%d -> ", current->data); // Print current node's data
        current = current->next;         // Move to the next node
    }
    
    printf("NULL\n");
}
int main(){
    struct node* head = NULL;
    displayList(head);
    return 0;
    
}