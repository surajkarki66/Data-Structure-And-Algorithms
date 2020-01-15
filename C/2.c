// Dynamic memory allocation in 2d matrix
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int **m1,**m2,row1,col1,row2,col2,i,j;

    printf("\nHow many row?");
    scanf("%d",&row1);
    printf("\nHow many col?");
    scanf("%d",&col1);

    m1 = (int**)calloc(row1,sizeof(int));

    for (i=0;i<row1;i++) 
    {
        m1[i] = (int*) calloc(col1,sizeof(int));

    }

    for(i=0;i<row1;i++) {
        for (j=0;j<col1;j++) {
            scanf("%d",&m1[i][j]);

        }
    }

    row2 = col1;
    printf("\nHow many col?");
    scanf("%d",&col2);

    m2 = (int**)calloc(row2,sizeof(int));

    for(i=0;i<row2;i++) {
        m2[i] = (int*) calloc(col2,sizeof(int));
    }

    for(i=0;i<row2;i++) {
        for (j=0;j<col2;j++) {
            scanf("%d",&m2[i][j]);

        }
    }

    for(i=0;i<row1;i++) {
        for(j=0;j<col2;j++) {
            printf("\t%d",m1[i][j]*m2[i][j]);
        }
        printf("\n");
    }



    return 0;

}