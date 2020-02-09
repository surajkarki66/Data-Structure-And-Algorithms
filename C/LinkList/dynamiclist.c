#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *next;
};

typedef struct node Lnode;
Lnode *start = NULL;

void create_linklist()
{
    Lnode *new_node, *ptr;
    int data, ch;

    do 
    {
        printf("\nEnter the data:");
        scanf("%d", &data);
        new_node = (Lnode*) malloc(sizeof(Lnode));
        new_node->info = data;
        if(start == NULL)
        {
            new_node->next = NULL;
            start = new_node;  // we use start for storing the address of first node

        }

        else
        {
            ptr = start;
            while (ptr->next != 0)
            {
                ptr = ptr->next;
            }
            ptr->next = new_node;
            new_node->next = NULL;
            
        }
        printf("\nD0 you like to exit?");
        printf("\nPress 1");
        scanf("%d", &ch);
    }while(ch =! 1);
}

void add_node_beg()
{
    Lnode *new_node;
    int data;
    printf("\nEnter the data:");
    scanf("%d", &data);
    new_node = (Lnode*)malloc(sizeof(Lnode));
    new_node->info = data;
    new_node->next = start;
    start = new_node;
    printf("\n%d is added at the beggining of list.", data);

}

void add_node_end()
{   
    Lnode *new_node, *ptr;
    int data;
    printf("\nEnter the value of node:");
    scanf("%d", &data);
    new_node = (Lnode*)malloc(sizeof(Lnode));
    new_node->info = data;
    new_node->next = NULL;
    if (start == NULL)
    {
        start = new_node;
    }
    else
    {
        ptr = start;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
        
    }
    printf("\n%d added at the end of list.", data);



}

void add_pos()
{
    Lnode *newnode, *ptr;
    int data, pos, k;
    printf("\nEnter the data:");
    scanf("%d", &data);
    printf("\nIn which position do you want to insert?");
    scanf("%d", &pos);
    ptr = start;
    k = 0;
    while(k<pos) 
    {
        ptr  = ptr->next;
        if(ptr == NULL) {
            printf("\nOut of index");
            return;
        }
        k++;
    }
    newnode = (Lnode*)malloc(sizeof(Lnode));
    newnode->info = data;
    newnode->next = ptr->next;
    ptr->next = newnode;

}

void delete_beg() 
{   Lnode *ptr;
    if (start == NULL) 
    {
        printf("\nData is underflow");
        exit(1);
    }
    ptr = start;
    start = ptr->next;
    printf("%d is deleted",ptr->info);
    free(ptr);

}

void delete_end()
{
    Lnode *ptr, *preptr;
    if (start == NULL) 
    {
        printf("\nData is underflow.");
        exit(0);
    }
    while(ptr->next != NULL) 
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;
    printf("\n%d is deleted", ptr->info);
    free(ptr);
}

void delete_pos()
{
    Lnode *ptr, *preptr;
    int k,pos;
    if (start == NULL)
    {
        printf("\nData is underflow");
        exit(1);
    }
    printf("\nEnter the position:");
    scanf("%d", &pos);
    ptr = start;
    k = 0;
           
    while (k<pos) 
    {   

        preptr = ptr;
        ptr = ptr->next;
        if (ptr == NULL)
        {
            printf("\nOut of index");
            exit(1);
            return;
        }
    }
    preptr->next = ptr->next;
    printf("\n%d is deleted", ptr->info);
    free(ptr);

}


void display()
{
    Lnode *ptr;
    int count = 0;
    if(start == NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        ptr = start;
        printf("\nThe data of link list are:");
        while (ptr != NULL)
        {
            printf("\n%d", ptr->info);
            ptr = ptr->next;
            count++;
        }
        printf("\nThere are %d elements.", count);
    }
    
   
    
}

int main()
{
    int choice;
   
    do 
    {
        printf("\nPress 1 for Creating list:");
        printf("\nPress 2 for Showing list:");
        printf("\nPress 3 to add node at the beginning:");
        printf("\nPress 4 to add node at the end:");
        printf("\nPress 5 to add node at specified position:");
        printf("\nPress 6 to delete the node at the beggining:");
        printf("\nPress 7 to delete the node at end");
        printf("\nPress 8 to delete the node at required position:");
        printf("\nEnter your choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create_linklist();
            printf("\nLink List created");
            break;

        case 2:
            display();
            break;
        case 3:
            add_node_beg();
            break;

        case 4:
            add_node_end();
            break;

        case 5:
            add_pos();
            break;

        case 6:
            delete_beg();
            break;

        case 7:
            delete_end();
            break;

        case 8:
            delete_pos();
            break;

        case 10:
            exit(0);

        default:
            printf("\nInvalid choice");
            break;
        }

    }while (choice != 10);
    return 0;
}
