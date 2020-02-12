#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *left;
    struct node *right;
};

typedef struct node node;
node *root = NULL;


node *insert(node *root, int data)
{
    if (root == NULL)
    {
        root = (node*)malloc(sizeof(node));
        root->left = root->right = NULL;
        root->info = data;
        printf("\nRoot = %d", data);
    }

    else if (data == root->info)
    {
        printf("\nDuplicate data");
        exit(0);
    }

    else
    {

            if (data < root->info)
            {
                root->left = insert(root->left, data);
                printf("\nLeft = %d", data);
                
            }

            else 
            {
                root->right = insert(root->right, data);
                printf("\nRight = %d", data);
                
        
            }

    }
    return (root);


    
}

void preorder(node *root)
{
    if(root != NULL)
    {
        printf("\n%d", root->info);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node *root)
{
    if(root != NULL)
    {
        printf("\n\n");
        postorder(root->left);
        postorder(root->right);
        printf("\n%d", root->info);
    }
}

void inorder(node *root)
{
    if(root != NULL)
    {
        printf("\n\n");
        inorder(root->left);
        printf("\n%d", root->info);
        inorder(root->right);
    }
}

void search(node *root, int data)
{
    if (root == NULL)
    {
        printf("\nThe number does not exist.");

    }

    else if (data > root->info)
    {
        printf("\nGo Right.");
        search(root->right, data);
    }
    else if( data < root->info)
    {
        printf("\nGo Left.");
        search(root->left, data);
    }
    else
    {
        printf("\nNumber found:");
        printf("\%d", root->info);
    }
        
    
}

node *delete(node *root, int data)
{
    node *temp;
    if (root == NULL)
    {
        printf("\nEmpty tree");
        exit(0);
    }

    else if (data > root->info)
    {
        printf("\nGo Right.");
        root->right =  delete(root->right, data);
    }
    else if( data < root->info)
    {
        printf("\nGo Left.");
        root->left= delete(root->left, data);
    }

    else 
    {
        temp = root;
        if (root->left == NULL)
            root = root->right;
        
        else
            root = root->left;
        
        free(temp);
    }

    return temp;
    


}

node *find_min(node *root)
{
    if (root == NULL)
        printf("\nEmpty");

    else if ( root->left == NULL)
    {
        printf("\nMinimum = %d", root->info);
        return root;
    }
    else 
        return find_min(root->left);
}


node *find_max(node *root)
{
    if (root == NULL)
        printf("\nEmpty");

    else if ( root->right == NULL)
    {
        printf("\nMaximum = %d", root->info);
        return root;
    }
    else 
        return find_max(root->right);
}


int main()
{
    int choice,data, item;
   
    do 
    {
        printf("\nPress 1 insert data in Binary Tree:");
        printf("\nPress 2 Preorder Traversal:");
        printf("\nPress 3 Inorder Traversal:");
        printf("\nPress 4 Postorder Traversal:");
        printf("\nPress 5 Deleting node: ");
        printf("\nPress 6 Searching node:");
        printf("\nPress 7 finding minimum value in the tree:");
        printf("\nPress 8 finding maximum valur in the tree:");
        printf("\nPress 9 for exit:");
        printf("\nEnter your choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
           while(data != 0)
           {
                printf("\nEnter the data:");
                scanf("%d", &data);
                root = insert(root, data);
           }
           
            
            break;

        case 2:
            preorder(root);
            break;
        case 3:
            inorder(root);
            break;

        case 4:
            postorder(root);
            break;

        case 5:
            printf("\nEnter the node to delete:");
            scanf("%d", &data);
            root = delete(root, data);
            break;

        case 6:
            printf("\nEnter the data you want to search:");
            scanf("%d", &item);
            search(root, item);
            break;

        case 7:
            find_min(root);
            break;

        case 8:
            find_max(root);
            break;

        case 9:
            exit(0);


        default:
            printf("\nInvalid choice");
            break;
        }

    }while (choice != 4);

    
    return 0;
}