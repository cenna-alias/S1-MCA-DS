#include <stdio.h>
#include <stdlib.h>

int parent[100], elements[100], n = 0;

void create() {
    int i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &elements[i]);
        parent[i] = i;
    }
    printf("Disjoint sets created.\n");
}

int getIndex(int x) {
    int i;
    for (i = 0; i < n; i++)
        if (elements[i] == x)
            return i;
    return -1;
}

int find(int i) {
    if (parent[i] != i)
        parent[i] = find(parent[i]);
    return parent[i];
}

void union_set(int x, int y) {
    int ix = getIndex(x), iy = getIndex(y);
    if (ix == -1 || iy == -1) {
        printf("Element not found!\n");
        return;
    }

    int rx = find(ix), ry = find(iy);
    if (rx != ry) {
        parent[rx] = ry;
        printf("Union performed between %d and %d\n", x, y);
    } else {
        printf("Both elements are already in the same set\n");
    }
}

int main() {
    int ch, x, y, idx;

    while (1) {
        printf("\n---- DISJOINT SET MENU ----\n");
        printf("1. Create\n2. Find\n3. Union\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                create();
                break;

            case 2:
                printf("Enter element to find: ");
                scanf("%d", &x);
                idx = getIndex(x);
                if (idx == -1)
                    printf("Element not found\n");
                else
                    printf("Representative of %d is %d\n",
                           x, elements[find(idx)]);
                break;

            case 3:
                printf("Enter two elements: ");
                scanf("%d %d", &x, &y);
                union_set(x, y);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}
