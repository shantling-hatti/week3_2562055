#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;


void create() {
    int n, i, value;
    struct node *newnode, *temp;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &value);

        newnode->data = value;
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
            temp = head;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }
}


void insert_begin() {
    struct node *newnode;
    int value;

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data to insert at beginning: ");
    scanf("%d", &value);

    newnode->data = value;
    newnode->next = head;
    head = newnode;
}


void display() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


void delete_end() {
    struct node *temp, *prev;

    if (head == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Last node deleted\n");
        return;
    }

    temp = head;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
    printf("Last node deleted\n");
}


int main() {
    int choice;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Create List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Display List\n");
        printf("4. Delete at End\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                printf("Before Insertion:\n");
                display();
                insert_begin();
                printf("After Insertion:\n");
                display();
                break;
            case 3:
                display();
                break;
            case 4:
                delete_end();
                break;
            case 5:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}
