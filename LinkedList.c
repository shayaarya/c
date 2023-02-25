#include <stdio.h>
#include <stdlib.h>

// Define a node in the linked list
struct node {
    int data;
    struct node *next;
};

// Insert a new node at the beginning of the list
void insert_node(struct node **head_ref, int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Print the contents of the list
void print_list(struct node *head) {
    printf("List contents: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    // Initialize the head of the list to NULL
    struct node *head = NULL;

    // Insert some nodes into the list
    insert_node(&head, 10);
    insert_node(&head, 20);
    insert_node(&head, 30);

    // Print the contents of the list
    print_list(head);

    // Free the memory allocated for the list
    while (head != NULL) {
        struct node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
