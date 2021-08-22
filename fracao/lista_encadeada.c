#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct 
{
    int day;
    int month;
    int year;
}Data;

struct Funcionario
{
    int id;
    char nome[41];
    double salario;
    Data nascimento;
    struct funcionario *next;   
};
typedef struct Funcionario funcionario;

void printF(funcionario *ok)
{
    funcionario *aux;
    for(aux = ok; aux != NULL; aux= ok->next)
    {
        printf("Funcionario\nid: %d\nnome: %s\nsalario: %lf\n", aux->id, aux->nome, aux->salario);
        printf("idade: %i/%i/%i", aux->nascimento.day, aux->nascimento.month, aux->nascimento.year);
    }
}

int main()
{
    funcionario *first=NULL, *aux, *ok;
    int i;
    for(i=0; i<3; i++)
    {
        ok = (funcionario *)malloc(sizeof(funcionario));
        printf("id: ");
        scanf("%i", ok->id);
        printf("\nNome:");
        scanf("%s", ok->nome);
        printf("\nsalario:");
        scanf("%lf", ok->salario);
        printf("\nNascimento:");
        scanf("%i %i %i", ok->nascimento.day, ok->nascimento.month, ok->nascimento.year);
        ok->next = NULL;
        if(first == NULL)
        {
            first = ok;
            aux = ok;
        }
        else
        {
            aux->next = ok;
            aux = ok;
        }
    }
    printF(&ok);
    return 0;
}

