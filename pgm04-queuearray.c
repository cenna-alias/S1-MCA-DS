#include <stdio.h>
#include <stdlib.h>
int front = -1, rear = -1;
int queue[15], data, i, size;
void enqueue()
{
    if (rear == size - 1)
    {
        printf("The queue is full\n");
    }
    else
    {
        printf("Enter the data to be inserted: ");
        scanf("%d", &data);
        rear++;
        queue[rear] = data;
        printf("The element is inserted\n");
        if (front == -1)
        {
            front = 0;
        }
    }
}
void dequeue()
{
    if ((front == -1) || (front > rear))
    {
        printf("\nThe queue is empty\n");
    }
    else
    {
        printf("%d is deleted\n", queue[front]);
        front++;
    }
}
void display()
{
    if (front == -1 || front > rear)
    {
        printf("\nThe queue is empty\n");
    }
    else
    {
        printf("The elements are:\n");
        for (i = front; i <= rear; i++)
        {
            printf("%d\n", queue[i]);
        }
    }
}
int main()
{
    int ch;
    printf("Enter the array size: ");
    scanf("%d", &size);
    do
    {
        printf("--OPTIONS--\n1. For enqueue\n2. For dequeue\n3. For display\n4. Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
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
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    } while (1);
    return 0;
}

