#include<stdio.h>

void bubbleSort(int A[], int n)
{
    int i, j, temp;
    for (i=0;i<n-1;i++)
    {
        for (j=0;j<n-1-i;j++)
        {
            if (A[j] > A[j+1])
            {
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
    printf("[");
     for (i=0;i<n;i++)
    {
        printf("%d, ", A[i]);
    }
    printf("]");
  

}

int main()
{
    int A[9] = {1,2,4,3,5,6,3,5,6};
    bubbleSort(A, 9);
    return 0;

}