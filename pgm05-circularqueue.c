#include <stdio.h>
#include <stdlib.h>
int rear = -1, front = -1;
int data, queue[10], size, i;
void enqueue()
{
    if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
    {
        printf("Queue is full\n");
    }
    else
    {
        rear = (rear + 1) % size;
        printf("Enter the data: ");
        scanf("%d", &data);
        queue[rear] = data;
        printf("The element is inserted\n");

        if (front == -1)
            front = 0;
    }
}
void dequeue()
{
    if (front == -1)
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        printf("The deleted element is %d\n", queue[front]);
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }
    }
}
void display()
{
    if (front == -1)
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        printf("Elements are:");
        if (front <= rear)
        {
            for (i = front; i <= rear; i++)
            {
                printf("\t%d", queue[i]);
            }
        }
        else
        {
            for (i = front; i < size; i++)
            {
                printf("\t%d", queue[i]);
            }
            for (i = 0; i <= rear; i++)
            {
                printf("\t%d", queue[i]);
            }
        }
        printf("\n");
    }
}
int main()
{
    int ch;
    printf("Enter the array size: ");
    scanf("%d", &size);
    do
    {
        printf("--OPTIONS--\n1. For insertion\n2. For deletion\n3. For displaying\n4. For exiting\n");
        printf("Enter your choice: ");
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
            printf("INVALID CHOICE\n");
        }
    } while (1);
    return 0;
}

