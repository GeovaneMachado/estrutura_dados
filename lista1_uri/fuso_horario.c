#include<stdio.h>
int main()
{
    int S, T, F, soma;
    scanf("%i %i %i", &S, &T, &F);
    if  (S == 0)
    {
        S = 24;
    }
    soma = (S + T + F)%24;
    printf("%i\n", soma);
    return 0;
}