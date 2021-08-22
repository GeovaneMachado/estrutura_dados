#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int dia;
    int mes;
    int ano;
} Data;


struct funcionario{
    int id;
    char nome[41];
    double salario;
    Data nascimento;
    struct funcionario *next;
};
typedef struct funcionario Funcionario;


void imprimeFunc(Funcionario *p){
    Funcionario *aux; 
    for (aux = p; aux != NULL; aux = aux->next){
        printf("Funcionario id: %d, nome: %s, salario: %.2lf, nasc: %d/%d/%d\n", aux->id, aux->nome, aux->salario, aux->nascimento.dia, aux->nascimento.mes, aux->nascimento.ano);
    }
    return;
}

void imprimeFuncInverso(Funcionario *p){
    if (!p)
        return;
    imprimeFuncInverso(p->next);
    printf("Funcionario id: %d, nome: %s, salario: %.2lf, nasc: %d/%d/%d\n", p->id, p->nome, p->salario, p->nascimento.dia, p->nascimento.mes, p->nascimento.ano);
}


int main(void) {
    Funcionario *f, *aux, *first = NULL;
    int id = 1, i = 1;

    while(id != 0){
        printf("\nInsira os dados do %dº funcionario:\n", i++);
        printf("id: ");
        scanf("%d", &id);

        if (id != 0){
            f = (Funcionario *)malloc(sizeof(Funcionario));
            f->id = id;

            printf("Nome: ");
            scanf("%s", f->nome);

            printf("Salario: ");
            scanf("%lf", &f->salario);
            
            printf("Data de Nascimento:\n");
            printf("     Dia: ");
            scanf("%d", &f->nascimento.dia);
            printf("     Mes: ");
            scanf("%d", &f->nascimento.mes);
            printf("     Ano: ");
            scanf("%d", &f->nascimento.ano);

            f->next = NULL;
            if (first == NULL){
                first = f;
                aux = f;
            } else {
                aux->next=f;
                aux=f;
            }
        }
    }
    printf("\n\nCadastro Finalizado!\n\n");
    printf("\nOs dados inseridos foram:\n");
    imprimeFunc(first);
    printf("\nOs dados inseridos, porém invertidos:\n");
    imprimeFuncInverso(first);
    return 0;