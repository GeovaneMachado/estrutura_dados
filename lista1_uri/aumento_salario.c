#include<stdio.h>

int main()
{
    float salario, soma;
    scanf("%f", &salario);
    if (salario  > 0 && salario <= 400.00)
    {
        soma = salario * 0.15;
        salario = salario + soma;
        printf("Novo salario: %.2f\nReajuste ganho: %.2f\nEm percentual: 15 %c\n", salario, soma, 0x25);
    }
    else if (salario >= 400.01 && salario <= 800.00)
    {
        soma = salario * 0.12;
        salario = salario + soma;
        printf("Novo salario: %.2f\nReajuste ganho: %.2f\nEm percentual: 12 %c\n", salario, soma, 0x25);
    }
    else if (salario >= 800.01 && salario <= 1200.00)
    {
        soma = salario * 0.1;
        salario = salario + soma;
        printf("Novo salario: %.2f\nReajuste ganho: %.2f\nEm percentual: 10 %c\n", salario, soma, 0x25);
    }
    else if (salario >= 1200.01 && salario <= 2000.00)
    {
        soma = salario * 0.07;
        salario = salario + soma;
        printf("Novo salario: %.2f\nReajuste ganho: %.2f\nEm percentual: 7 %c\n", salario, soma, 0x25);
    }
    else if (salario > 2000)
    {
        soma = salario * 0.04;
        salario = salario + soma;
        printf("Novo salario: %.2f\nReajuste ganho: %.2f\nEm percentual: 4 %c\n", salario, soma, 0x25);
    }
    return 0;
}