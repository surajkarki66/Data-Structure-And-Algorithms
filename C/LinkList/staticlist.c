#include<stdio.h>
#include<stdlib.h>

struct Lnode
{
    int info;
    struct Lnode *next;
};

int main()
{
    struct Lnode n1, n2, n3;
    struct Lnode *start, *temp;
    start = &n1;
    n1.info = 18;n1.next = &n2;
    n2.info = 20;n2.next = &n3;
    n3.info = 45;n3.next = NULL;
    temp = start;
    printf("\n%x----->", start);
    while (temp != NULL)
    {   printf("\n%d-----%x", temp->info, temp->next);
        temp = temp->next;
    }
    return 0;

    
}
