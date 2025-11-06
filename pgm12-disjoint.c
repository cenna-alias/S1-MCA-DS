#include <stdio.h>
#include <stdlib.h>
struct node {
    struct node *rep;
    struct node *next;
    int data;
} *heads[50], *tails[50];
static int countroot = 0;
void makeset(int x) {
    struct node *new = (struct node *)malloc(sizeof(struct node));
    if (new == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    new->rep = new;
    new->next = NULL;
    new->data = x;
    heads[countroot] = new;
    tails[countroot] = new;
    countroot++;
    printf("Set created for element %d\n", x);
}
struct node* find(int a) {
    int i;
    struct node *tmp;

    for (i = 0; i < countroot; i++) {
        tmp = heads[i];
        while (tmp != NULL) {
            if (tmp->data == a)
                return tmp->rep;
            tmp = tmp->next;
        }
    }
    return NULL;
}
void unionsets(int a, int b) {
    int i, j, pos = -1, flag = 0;
    struct node *tail2 = NULL;
    struct node *rep1 = find(a);
    struct node *rep2 = find(b);
    if (rep1 == NULL || rep2 == NULL) {
        printf("\nOne or both elements are not present.\n");
        return;
    }
    if (rep1 == rep2) {
        printf("\nBoth elements are in the same set.\n");
        return;
    }
    for (j = 0; j < countroot; j++) {
        if (heads[j] == rep2) {
            pos = j;
            flag = 1;
            tail2 = tails[j];
            countroot--;
            for (i = pos; i < countroot; i++) {
                heads[i] = heads[i + 1];
                tails[i] = tails[i + 1];
            }
            break;
        }
    }
    for (j = 0; j < countroot; j++) {
        if (heads[j] == rep1) {
            tails[j]->next = rep2;
            tails[j] = tail2;
            break;
        }
    }
    while (rep2 != NULL) {
        rep2->rep = rep1;
        rep2 = rep2->next;
    }
    printf("\nUnion completed.\n");
}
int search(int x) {
    int i;
    struct node *tmp;

    for (i = 0; i < countroot; i++) {
        tmp = heads[i];
        while (tmp != NULL) {
            if (tmp->data == x)
                return 1;
            tmp = tmp->next;
        }
    }
    return 0;
}
void display() {
    int i;
    struct node *tmp;

    if (countroot == 0) {
        printf("\nNo sets available.\n");
        return;
    }
    printf("\nThe current sets are:\n");
    for (i = 0; i < countroot; i++) {
        tmp = heads[i];
        printf("Set %d: ", i + 1);
        while (tmp != NULL) {
            printf("%d -> ", tmp->data);
            tmp = tmp->next;
        }
        printf("NULL\n");
    }
}
int main() {
    int c, x, y;
    struct node *rep;
    while (1) {
        printf("\n\n--- Disjoint Set Operations ---\n");
        printf("1: Make Set\n");
        printf("2: Display Sets\n");
        printf("3: Union\n");
        printf("4: Find Set Representative\n");
        printf("5: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &c);
        switch (c) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                if (search(x))
                    printf("Element already present.\n");
                else
                    makeset(x);
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Enter the two elements to union:\n");
                printf("First element: ");
                scanf("%d", &x);
                printf("Second element: ");
                scanf("%d", &y);
                unionsets(x, y);
                break;
            case 4:
                printf("Enter the element to find: ");
                scanf("%d", &x);
                rep = find(x);
                if (rep == NULL)
                    printf("Element not present.\n");
                else
                    printf("Element %d belongs to the set with representative %d\n", x, rep->data);
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

