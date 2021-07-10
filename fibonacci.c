#include<stdio.h>

int main()
{
    int num, i = 0, soma, seq1 = -1, seq2 = 1;
    scanf("%i", &num);
    while (i< num)
    {
        soma = seq2 + seq1;
        seq1 = seq2;
        seq2 = soma;
        i++;
        printf("%i",soma);
        if(i<num)
        {
            printf(" ");
        }
        else
        {
            printf("\n");
        }
    }
    return 0;
}