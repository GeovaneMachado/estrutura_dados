#include<stdio.h>
int main()
{
    int produto1, produto2, PROD;
    printf("Valor do produto 1:");
    scanf("%i", &produto1);
    printf("Valor do produto 2:");
    scanf("%i", &produto2);
    PROD = produto1 * produto2;
    printf("PROD = %i\n", PROD);
    return 0;
}