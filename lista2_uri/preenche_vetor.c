#include<stdio.h>

int main()
{
    int i, N[10], num;
    scanf("%i", &num);
    N[0] = num;
    for(i = 1; i< 10; i++)
    {
        N[i] = N[i-1] * 2; 
    }
    for(i = 0; i< 10; i++)
    {
        printf("N[%i] = %i\n", i, N[i]);
    }
    return 0;
}