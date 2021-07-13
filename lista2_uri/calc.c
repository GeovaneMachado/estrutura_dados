#include<stdio.h>
#include<string.h>

int main()
{
    int N, i;
    char valores[14], numero1[3], numero2[4], numero3[3];
    scanf("%i", &N);
    int sum[N];
    for(i = 0; i < N; i++)
    {
        scanf("%s", &valores);
        numero1[0] = valores[2];
        numero1[1] = valores[3];
        numero2[0] = valores[5];
        numero2[1] = valores[6];
        numero2[2] = valores[7];
        numero3[0] = valores[11];
        numero3[1] = valores[12];
        sum[i] = atoi(numero1) + atoi(numero2) + atoi(numero3);
    }
    for(i = 0; i < N; i++)
    {
        printf("%i\n", sum[i]);
    }
    return 0;
}