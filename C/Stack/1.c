#include<stdio.h>

int max(int n, int A[])
{

    int i, max=A[0];
    for(i=0;i<n;i++) {
        scanf("%d",&A[i]);
    }
    for(i=0;i<n;i++) {
        printf("\n%d",A[i]);
    }
    for(i=0;i<n;i++) {
        
        if (A[i]>max) {
            max = A[i];
        }
    }

    printf("\n%d",max);


    return max;



}

int main(){
    int n, A[200];
    printf("\nHow many number?");
    scanf("%d",&n);
    printf("\n The maximum elemente is %d",max(n,A));
    return 0;

}