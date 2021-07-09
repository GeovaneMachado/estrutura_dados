#include<stdio.h>

int main()
{
    int numbers[5] = {0, 0, 0, 0, 0}, pares = 0, i;
    for(i =0; i<5; i++)
    {
        scanf("%i", &numbers[i]);
        if(numbers[i] % 2 == 0)
        {
            pares++;
        }
    }
    printf("%i valores pares\n", pares);
    return 0;
}