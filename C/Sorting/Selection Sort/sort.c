#include<stdio.h>
#include<stdlib.h>


void swapp(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

void selectionSort(int ptr[], int n)
{
    int i, j, min_idx, temp;
    for (i=0;i<n-1;i++)
    {
        min_idx = i;
        for (j=i+1;j<n;j++)
        {
            if (ptr[j]<ptr[min_idx])
            {
                min_idx = j;
            }
        }
       swapp(&ptr[min_idx], &ptr[i]);
        
        
            
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