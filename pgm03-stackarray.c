#include <stdlib.h>
#include <stdio.h>
int top = -1;
int stack[5], data, i, size;
void push()
{
    if (top == size - 1)
    {
        printf("Stack is full\n");
    }
    else
    {
        printf("Enter the data : ");
        scanf("%d", &data);
        top++;
        stack[top] = data;
        printf("The element is inserted\n");
    }
}
void pop()
{
    if (top == -1)
    {
        printf("\nStack underflow\n");
    }
    else
    {
        printf("Popped element is %d\n", stack[top]);
        top--;
    }
}
void display()
{
    if (top == -1)
    {
        printf("\nStack is empty\n");
    }
    else
    {
        printf("The elements in stack are:\n");
        for (i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}
int main()
{
    int ch;
    printf("Enter the array size : ");
    scanf("%d", &size);
    do
    {
        printf("--OPTIONS--\n1. For push\n2. For pop\n3. For display\n4. For exit\n");
        printf("Enter the choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("\nINVALID CHOICE\n");
        }
    } while (1);
    return 0;
}

