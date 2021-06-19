#include<stdio.h>
int main()
{
    int a, b, c, maior, maior2;
    scanf("%i %i %i", &a, &b, &c);
    maior = ((a + b + abs(a - b))/ 2);
    maior2 = ((c + b + abs(c - b))/ 2);
    maior = (maior + maior2 + abs(maior - maior2))/2;
    printf("%i eh o maior\n", maior);
    return 0;
}