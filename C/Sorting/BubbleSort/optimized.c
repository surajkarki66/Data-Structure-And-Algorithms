#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int ptr[], int n)
{
    int i, j, flag = 0, temp;
    for (i=0;i<n-1;i++)
    {
        for (j=0;j<n-1-i;j++)
        {
            if (ptr[j] > ptr[j+1])
            {
                flag = 1;
                temp = ptr[j];
                ptr[j] = ptr[j+1];
                ptr[j+1] = temp;
            }
        }
        
        if (flag == 0)
        {
            printf("\nArray is sorted.");
            return;
        }
            
    }
    printf("[");
     for (i=0;i<n;i++)
    {
        printf("%d, ", ptr[i]);
    }
    printf("]");
  

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
   

    bubbleSort(ptr, n);
    return 0;

}