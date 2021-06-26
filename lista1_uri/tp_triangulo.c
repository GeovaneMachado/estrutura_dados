#include<stdio.h>

int main()
{
    double A, B, C, lado1, lado2, lado3, triangulo;
    double SOMA;
    scanf("%lf %lf %lf", &lado1, &lado2, &lado3);
    if (lado1 >= lado2 && lado1 >= lado3)
    {
        A = lado1;
        B = lado2;
        C = lado3;
    }
    else if (lado2 >= lado1 && lado2 >= lado3)
    {
        A = lado2;
        B = lado1;
        C = lado3;
    }
    else if (lado3 >= lado2 && lado3 >= lado2)
    {
        A = lado3;
        B = lado2;
        C = lado1;
    }
    triangulo = B +C;
    SOMA = (B * B) + (C * C);
    if (A >= triangulo)
    {
        printf("NAO FORMA UM TRIANGULO\n");
    }
    else if (A * A == SOMA)
    {
        printf("TRIANGULO RETANGULO\n");
    }
    else if (A * A > SOMA)
    {
        printf("TRIANGULO OBTUSANGULO\n");
    }
    else if (A * A < SOMA)
    {
        printf("TRIANGULO ACUTANGULO\n");
    }
    if(A == B && B == C)
    {
        printf("TRIANGULO EQUILATERO\n");
    }
    else if(A == B || B == C)
    {
        printf("TRIANGULO ISOSCELES\n");
    }
    return 0;
}