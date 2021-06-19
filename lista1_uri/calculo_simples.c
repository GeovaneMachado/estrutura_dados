#include<stdio.h>
int main()
{
    int codigo1, codigo2, quantidade;
    float valor, soma;
    scanf("%i %i %f", &codigo1,&quantidade, &valor);
    soma = valor * quantidade;
    scanf("%i %i %f", &codigo2,&quantidade, &valor);
    soma = soma + valor * quantidade;
    printf("VALOR A PAGAR: R$ %.2f", soma);
    return 0;
}
