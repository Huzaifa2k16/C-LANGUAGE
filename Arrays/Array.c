#include <stdio.h>

int main()
{
    int arr[100];
    int n;
    int i;
    int sum = 0;
    int max, min;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("\nEnter %d elements:\n", n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nArray Elements are:\n");

    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    max = arr[0];
    min = arr[0];

    for(i = 0; i < n; i++)
    {
        sum = sum + arr[i];

        if(arr[i] > max)
        {
            max = arr[i];
        }

        if(arr[i] < min)
        {
            min = arr[i];
        }
    }

    printf("\n\nSum = %d", sum);
    printf("\nMaximum Element = %d", max);
    printf("\nMinimum Element = %d", min);

    return 0;
}
