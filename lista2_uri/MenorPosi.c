#include<stdio.h>

int main()
{
    int N, menor = 999999, posicao;
    scanf("%i", &N);
    int X[N], i;
    for(i= 0; i < N; i++)
    {
        scanf("%i", &X[i]);
        if(X[i] < menor)
        {
            menor = X[i];
            posicao = i;
        }
    }
    printf("Menor valor: %i\nPosicao: %i\n", menor, posicao);    
    return 0;
}