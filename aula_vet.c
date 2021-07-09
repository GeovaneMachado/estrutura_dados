#include<stdio.h>
#include<string.h>
/*int main()
{
    int i, vetor[6];
    int maior = 0, menor = 99999;
    for (i = 0; i < 5; i++)
    {
        scanf("%i", &vetor[i]);
        if (vetor[i] > maior)
        {
            maior = vetor[i];
        }
        if (vetor[i] < menor)
        {
            menor = vetor[i];
        }
    }
    printf("Maior = %i\nMenor = %i", maior, menor);
    return 0;
}*/
int main()
{
    int i = 10;
    char string[10] = "Geovane"; 
    while (i--)
    {
        printf("%c", string[i]);
    } 
    return 0;
}