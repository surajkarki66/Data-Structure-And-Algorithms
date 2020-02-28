#include<stdio.h>
#include<stdlib.h>

void linear_search(int A[], int n, int value) 
{
    int i, flag = 0;
    for (i=0;i<n;i++)
    {
        if (A[i] == value)
        {
            flag = 1;
            printf("\nData found at position %d", i+1);
            break;
        }
    }

    if (flag == 0)
    {
        printf("\nData is not found");
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

    linear_search(ptr,n,query);
    return 0;

}