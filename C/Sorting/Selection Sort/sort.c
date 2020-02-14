#include<stdio.h>
#include<stdlib.h>

void selectionSort(int ptr[], int n)
{
    int i, j,temp, pos;
    for (i=0;i<n-1;i++)
    {
        pos = i;
        for (j=i+1;j<n;j++)
        {
            if (ptr[pos] > ptr[j])
            {
                pos = j;
            }
        }
        temp = ptr[pos];
        ptr[pos] = ptr[i];
        ptr[i] = temp;
        
        
            
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
   

    selectionSort(ptr, n);
    return 0;

}