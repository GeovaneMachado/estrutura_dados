#include<stdio.h>
int main()
{
    double venda_mes, salario, bonus;
    char nome[10];
    scanf("%s", &nome);
    scanf("%lf", &salario);
    scanf("%lf", &venda_mes);
    bonus = venda_mes * 0.15;
    salario = salario + bonus;
    printf("TOTAL = %.2lf",  salario);
    return 0;
}