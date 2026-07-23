#include <stdio.h>

#define MAX 10

void inputMatrix(int matrix[MAX][MAX], int rows, int cols);
void displayMatrix(int matrix[MAX][MAX], int rows, int cols);
void addMatrix(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int rows, int cols);
void multiplyMatrix(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int r1, int c1, int c2);
void transposeMatrix(int A[MAX][MAX], int T[MAX][MAX], int rows, int cols);

int main()
{
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX], T[MAX][MAX];
    int r1, c1, r2, c2;
    int choice;

    printf("=================================\n");
    printf("      MATRIX OPERATIONS\n");
    printf("=================================\n");

    printf("Enter rows and columns of Matrix A: ");
    scanf("%d %d", &r1, &c1);

    printf("\nEnter Matrix A Elements:\n");
    inputMatrix(A, r1, c1);

    printf("\nEnter rows and columns of Matrix B: ");
    scanf("%d %d", &r2, &c2);

    printf("\nEnter Matrix B Elements:\n");
    inputMatrix(B, r2, c2);

    printf("\nChoose Operation\n");
    printf("1. Matrix Addition\n");
    printf("2. Matrix Multiplication\n");
    printf("3. Matrix Transpose\n");
    printf("Enter Choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            if(r1 == r2 && c1 == c2)
            {
                addMatrix(A, B, C, r1, c1);

                printf("\nResult of Matrix Addition:\n");
                displayMatrix(C, r1, c1);
            }
            else
            {
                printf("\nAddition not possible!\n");
            }
            break;

        case 2:
            if(c1 == r2)
            {
                multiplyMatrix(A, B, C, r1, c1, c2);

                printf("\nResult of Matrix Multiplication:\n");
                displayMatrix(C, r1, c2);
            }
            else
            {
                printf("\nMultiplication not possible!\n");
            }
            break;

        case 3:
            transposeMatrix(A, T, r1, c1);

            printf("\nTranspose of Matrix A:\n");
            displayMatrix(T, c1, r1);
            break;

        default:
            printf("\nInvalid Choice!\n");
    }

    return 0;
}
void inputMatrix(int matrix[MAX][MAX], int rows, int cols)
{
    int i, j;

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}
void displayMatrix(int matrix[MAX][MAX], int rows, int cols)
{
    int i, j;

    // Top Border
    for(j = 0; j < cols; j++)
    {
        printf("+-------");
    }
    printf("+\n");

    // Matrix Elements
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            printf("| %5d ", matrix[i][j]);
        }

        printf("|\n");

        // Border after every row
        for(j = 0; j < cols; j++)
        {
            printf("+-------");
        }
        printf("+\n");
    }
}

void addMatrix(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int rows, int cols)
{
    int i, j;

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}
void multiplyMatrix(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int r1, int c1, int c2)
{
    int i, j, k;

    for(i = 0; i < r1; i++)
    {
        for(j = 0; j < c2; j++)
        {
            C[i][j] = 0;

            for(k = 0; k < c1; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
void transposeMatrix(int A[MAX][MAX], int T[MAX][MAX], int rows, int cols)
{
    int i, j;

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            T[j][i] = A[i][j];
        }
    }
}
