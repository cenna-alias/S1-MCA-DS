#include <stdio.h>
#include <stdlib.h>
int count = 0;
struct node {
    int data;
    struct node *next;
} *new, *head = NULL, *h;
void create() {
    new = (struct node *)malloc(sizeof(struct node));
    if (new == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter the data for the node: ");
    scanf("%d", &new->data);
    new->next = NULL;
}
void enqueue() {
    create();
    if (head == NULL) {
        head = new;
    } else {
        h = head;
        while (h->next != NULL) {
            h = h->next;
        }
        h->next = new;
    }
    count++;
}
void dequeue() {
    if (head == NULL) {
        printf("Queue is empty\n");
    } else {
        h = head;
        head = head->next;
        printf("Deleted element is %d\n", h->data);
        free(h);
        count--;
    }
}
void display() {
    if (head == NULL) {
        printf("Queue is empty\n");
    } else {
        h = head;
        printf("Queue elements are: ");
        while (h != NULL) {
            printf("%d -> ", h->data);
            h = h->next;
        }
        printf("NULL\n");
    }
}
void main() {
    int ch = 0;
    do {
        printf("\n--- Queue Operations ---\n");
        printf("1) Enqueue\n");
        printf("2) Dequeue\n");
        printf("3) Display\n");
        printf("4) Exit\n");
        printf("Choose an option: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (ch != 4);
}

