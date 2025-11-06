#include <stdio.h>
#include <stdlib.h>
int count = 0;
struct node {
    int data;
    struct node* next;
} *new, *head = NULL, *h, *l, *sl;
void create() {
    new = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data for the node: ");
    scanf("%d", &new->data);
    new->next = NULL;
}
void push() {
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
void pop() {
    if (head == NULL) {
        printf("List is empty\n");
    } else if (head->next == NULL) {
        printf("Deleted element is %d\n", head->data);
        free(head);
        head = NULL;
        count--;
    } else {
        l = head;
        sl = head;
        while (l->next != NULL) {
            sl = l;
            l = l->next;
        }
        sl->next = NULL;
        printf("Deleted element is %d\n", l->data);
        free(l);
        count--;
    }
}
void display() {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        h = head;
        printf("Linked list elements are: ");
        while (h != NULL) {
            printf("%d -> ", h->data);
            h = h->next;
        }
        printf("NULL\n");
    }
}
void search() {
    int se, i = 0, f = 0;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Enter the data to be searched: ");
    scanf("%d", &se);
    h = head;
    while (h != NULL) {
        i++;
        if (h->data == se) {
            printf("Element %d found at position %d\n", se, i);
            f = 1;
        }
        h = h->next;
    }
    if (!f)
        printf("Element %d not found\n", se);
}
void main() {
    int ch;
    while (1) {
        printf("\nChoose an option:\n");
        printf("1) Push\n");
        printf("2) Pop\n");
        printf("3) Search\n");
        printf("4) Display\n");
        printf("5) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                search();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Wrong choice! Please try again.\n");
        }
    }
}

