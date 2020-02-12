// Tower of Hannoi

#include<stdio.h>

int count = 0;

void TOH(int n, char source, char temp, char destination) 
{
    if(n==1)
    {
        printf("\nMove Disc %d from %c to %c\n",n , source, destination);
        count++;
        return;
    }
    TOH(n-1, source, destination, temp);
    printf("\nMove Disc %d from %c to %c\n", n, source,destination);
    TOH(n-1, temp, source,destination);
}

int main() 
{
    int n;
    printf("\nEnter no of disc");
    scanf("%d", &n);
    TOH(n, 'A', 'B', 'C');
    printf("\nTotal count = %d", count);
    return 0;
}