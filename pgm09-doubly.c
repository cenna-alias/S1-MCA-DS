#include <stdio.h>
#include <stdlib.h>
int count = 0;
struct node {
    struct node* prev;
    int data;
    struct node* next;
} *new, *head = NULL, *h;
void create() {
    new = (struct node*)malloc(sizeof(struct node));
    if (new == NULL) {
        printf("Memory allocation failed!\n");
        exit(0);
    }
    printf("Enter the data for the node: ");
    scanf("%d", &new->data);
    new->next = NULL;
    new->prev = NULL;
}
void ins_beg() {
    create();
    if (head == NULL) {
        head = new;
    } else {
        new->next = head;
        head->prev = new;
        head = new;
    }
    count++;
}
void ins_end() {
    create();
    if (head == NULL) {
        head = new;
    } else {
        h = head;
        while (h->next != NULL) {
            h = h->next;
        }
        h->next = new;
        new->prev = h;
    }
    count++;
}
void ins_pos() {
    int pos, i;
    printf("Enter the position: ");
    scanf("%d", &pos);
    if (pos == 1) {
        ins_beg();
    } else if (pos == count + 1) {
        ins_end();
    } else if (pos < 1 || pos > count + 1) {
        printf("Invalid position\n");
    } else {
        create();
        h = head;
        for (i = 1; i < pos - 1; i++) {
            h = h->next;
        }
        new->next = h->next;
        new->prev = h;
        h->next->prev = new;
        h->next = new;
        count++;
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
    int sc, i = 0, f = 0;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Enter the element to search: ");
    scanf("%d", &sc);
    h = head;
    while (h != NULL) {
        i++;
        if (h->data == sc) {
            printf("Element %d found at position %d\n", sc, i);
            f = 1;
        }
        h = h->next;
    }
    if (!f)
        printf("Element not found\n");
}
void del_beg() {
    if (head == NULL) {
        printf("List is empty\n");
    } else if (head->next == NULL) {
        printf("Deleted element is %d\n", head->data);
        free(head);
        head = NULL;
        count--;
    } else {
        h = head;
        head = head->next;
        head->prev = NULL;
        printf("Deleted element is %d\n", h->data);
        free(h);
        count--;
    }
}
void del_end() {
    if (head == NULL) {
        printf("List is empty\n");
    } else if (head->next == NULL) {
        printf("Deleted element is %d\n", head->data);
        free(head);
        head = NULL;
        count--;
    } else {
        h = head;
        while (h->next != NULL) {
            h = h->next;
        }
        printf("Deleted element is %d\n", h->data);
        h->prev->next = NULL;
        free(h);
        count--;
    }
}
void del_pos() {
    int pos, i;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Enter the position to delete: ");
    scanf("%d", &pos);
    if (pos == 1) {
        del_beg();
    } else if (pos == count) {
        del_end();
    } else if (pos < 1 || pos > count) {
        printf("Invalid position\n");
    } else {
        h = head;
        for (i = 1; i < pos; i++) {
            h = h->next;
        }
        printf("Deleted element is %d\n", h->data);
        h->prev->next = h->next;
        h->next->prev = h->prev;
        free(h);
        count--;
    }
}
void main() {
    int ch = 0;
    do {
        printf("\n--- Doubly Linked List Operations ---\n");
        printf("1) Insert at beginning\n");
        printf("2) Insert at end\n");
        printf("3) Insert at a position\n");
        printf("4) Display\n");
        printf("5) Delete at beginning\n");
        printf("6) Delete at end\n");
        printf("7) Delete at a position\n");
        printf("8) Search\n");
        printf("9) Exit\n");
        printf("Choose option: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                ins_beg();
                break;
            case 2:
                ins_end();
                break;
            case 3:
                ins_pos();
                break;
            case 4:
                display();
                break;
            case 5:
                del_beg();
                break;
            case 6:
                del_end();
                break;
            case 7:
                del_pos();
                break;
            case 8:
                search();
                break;
            case 9:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (ch != 9);
}

