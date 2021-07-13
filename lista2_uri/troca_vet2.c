#include<stdio.h>

int main()
{
    int i, N[1000], T, count;
    scanf("%i", &T);
    count = 0; 
    for(i = 0; i< 1000; i++)
    {
        N[i] = count;
        count++;
        if (count == T)
        {
            count= 0;
        }      
    }
    for(i = 0; i< 1000; i++)
    {
        printf("N[%i] = %i\n", i, N[i]);
    }
    return 0;
}