#include <stdio.h>
void main()
{
    int a[10], i, n, max, min;
    printf("Enter the size : ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    max = a[0];
    for (i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    min = a[0];
    for (i = 0; i < n; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
        }
    }
    printf("The maximum number in the array is %d\n", max);
    printf("The minimum number in the array is %d\n", min);
}

