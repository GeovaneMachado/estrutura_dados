#include<stdio.h>

int main()
{
    int i, j = 20, N[20], copy[20]; 
    for(i = 0; i< 20; i++)
    {
        scanf("%i", &N[i]);
        copy[i] = N[i];
    }
    for(i = 0; i < 10; i++)
    {
        j--;
        N[j] = copy[i];
        N[i] = copy[j];
    }
    for(i = 0; i< 20; i++)
    {
        printf("N[%i] = %i\n", i, N[i]);
    }
    return 0;
}