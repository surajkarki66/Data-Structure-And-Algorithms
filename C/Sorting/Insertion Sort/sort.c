#include<stdio.h>
#include<stdlib.h>

void insertion(int A[], int n)
{
    int i, j, temp;
    for(i = 1;i<= n-1;i++)
    {
        temp = A[i];
        j = i - 1;
        while ((temp < A[j]) && (j>=0))
        {
            A[j+1] = A[j];
            j = j - 1;
        }
        A[j+1] = temp;
        
    }
    for (i=0;i<n;i++) 
    {
        printf("\n%d", A[i]);
    }
}

int main()
{
    int n, i;
    int *ptr;
    printf("\nEnter how many numbers:");
    scanf("%d", &n);
    ptr = (int *)malloc(n * sizeof(int));
    printf("\nEnter the data:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &ptr[i]);
       
    }
   
    insertion(ptr, n);
    return 0;
}