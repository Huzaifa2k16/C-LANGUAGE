/* Finding Max and Min while calculating the sum*/


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


/* Diplaying weekly temperature and calculating its average*/


#include <stdio.h>

int main()
{
    int temp[7];
    int i;
    int sum = 0;
    float average;

    printf("Enter temperature for 7 days:\n");

    for(i = 0; i < 7; i++)
    {
        printf("Day %d: ", i + 1);
        scanf("%d", &temp[i]);

        sum = sum + temp[i];
    }

    average = (float)sum / 7;

    printf("\nTemperatures of the whole week:\n");

    for(i = 0; i < 7; i++)
    {
        printf("Day %d temperature: %d\n", i + 1, temp[i]);
    }

    printf("\nAverage Temperature = %.2f\n", average);

    getchar();
    getchar();

    return 0;
}
