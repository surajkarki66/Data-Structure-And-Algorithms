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

void binary_search(int A[], int n, int val)
{
    int loc, beg, end, mid, flag = 0;
    loc = 0;
    beg = 0;
    end = n-1;


    while ((beg <= end) && (val != A[mid]))
    {
        mid = (beg+end)/2;
        if (val == A[mid])
        {
            printf("\nSearch found at %d", mid+1);
            loc = mid;
            flag = flag + 1;
        }

        else if (val < A[mid])
        {
            end = mid - 1;
        }

        else {
            beg = mid + 1;
        }
    }
    if (flag == 0)
    {
        printf("\nSearch not found.");
    }
    
}


int main()
{
    int n, i, query;
    int *ptr;
    printf("\nEnter how many elements?");
    scanf("%d", &n);
    ptr = (int*)malloc(n*sizeof(int));
    for (i = 0;i<n;i++)
    {
        scanf("%d", &ptr[i]);

    }
    printf("\nThe data is ");
    for (i = 0;i<n;i++)
    {
       printf("\n\t%d", ptr[i]);
    }
    printf("\nEnter the search value:");
    scanf("%d", &query);
    bubbleSort(ptr,n);
    binary_search(ptr, n, query);

   
    return 0;

}