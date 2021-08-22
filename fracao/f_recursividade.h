#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

/*typedef struct
{
    char nome[30];
    int tamanho;
    int codigo;
    double preco;
    struct prox *next;    
}verificar;*/

int menu(void)
{
    int opc;
    printf("O que voce deseja fazer:\n[1]-Cadastrar produto\n[2]-Cadastrar pessoa\n[3]- Comprar\n[4]-Pagar: ");
    scanf("%i", &opc);
    return opc;
}