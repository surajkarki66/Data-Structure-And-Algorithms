#include<stdio.h>
#include<stdlib.h>

int factorial(int num) 
{
    if(num == 1) 
    {
        return 1;
    }
    else {
        return (num * factorial(num-1));
      
    }
}

int main() 
{
    int n, f;
    printf("\nEnter the number:");
    scanf("%d", &n);
    f = factorial(n);
    printf("%d", f);
    printf("\nThe factorial of %d = %d",n,f);
    return 0;

}