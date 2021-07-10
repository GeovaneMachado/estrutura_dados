#include<stdio.h>

int main()
{
    int num, i = 0, soma, seq;
    scanf("%i", &num);
    printf("%i\t", i);
    while (i < num)
    {
        soma = i;
        printf("%i\t%i\t", soma,i);
        i++;
        seq = i + soma;
    }
    
    return 0;
}