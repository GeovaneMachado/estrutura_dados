#include<stdio.h>

int main()
{
    int a, b, c, viagem1, viagem2, viagem3;
    scanf("%d %d %d", &a, &b, &c);
    viagem1 = a + b;
    viagem2 = b + c;
    viagem3 = c + a;
    if (a == b || b == c || c == a || a == viagem2 || b == viagem3 || c == viagem1)
    {
        printf("S\n");
    }
    else
    {
        printf("N\n");
    }
    return 0;
}