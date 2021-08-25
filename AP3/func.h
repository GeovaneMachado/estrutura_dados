#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TAM_REG 10
#define TAM_NAME 40

typedef struct //struct da data de nascimento do aluno  
{
    int day; 
    int moth;
    int year;
}Date;

typedef struct //struct da ficha do aluno
{
    char resgitration[TAM_REG]; //matricula
    char name[TAM_NAME];//nome
    Date birth;//nascimento
    float average;//media das notas
    struct student *next; // proximo aluno
}student;

void print_Student(student *people) //Emprime os estudantes cadastrados
{
    if(Void(people)) printf("Lista vazia!");
    else
    {
        student *i;
        for(i=people;i!=NULL;i=i->next)
        {
            printf("\n-------------------------------");
            printf("\nRegistration: %s\nName: %s", i->resgitration, i->name);
            printf("\nNascimento: %i/%i/%i", i->birth.day, i->birth.moth, i->birth.year);
            printf("\nAverage: %.f", i->average);
            printf("\n-------------------------------");
        }    
    }
}
int count_student(student *first)
{
        student *i;
        int count=0;
        for(i=first;i!=NULL;i=i->next) count++;
        return count;
}

int Void(student *list)
{
    if(list != NULL) return 0;
    else return 1;
}

student *Delete(student *first)//Deleta um elemento na lista
{
    student *assistant, *previous, *nulo= NULL;
    int confere, cont;
    char delete_reg[TAM_REG]; 
    scanf("%s", delete_reg); //Le o elemento para deletar
    for(assistant=first; assistant != NULL; assistant = assistant->next)//for para percorrer a lista
    {
        confere =strcmp(delete_reg, assistant->resgitration); //Compara os valores, se for 0 sao iguais
        if(confere == 0) //Verifica se os elementos sao iguais
        {
            confere = 1;
            if (assistant == first)//Verifica se assistant e igual a first 
            {
                first = first->next; // first aponta para proximo se forem iguais
                free(assistant);
                cont = count_student(first);
                if(cont == 0) return nulo;
                return first;
            }
            else 
            {
                for(previous=first;previous!=NULL; previous=previous->next) //For para comparar qual é igual depois do primeiro e deletar
                {
                    if(previous->next == assistant)
                    {
                        previous->next = assistant->next;
                        free(assistant);//Deleta elemento da lista
                        cont = count_student(first);
                        if(cont == 0) return nulo;
                        return first;
                    }
                }
            }
        }   
    }
    if(confere != 0) return first;     
}

int menu(int opc)
{
    printf("\nOPCAO\n[1] Adicinar\n [2] Excluir\n[3] Listar\n[4] Contar elementos\n");
    scanf("%i", &opc);
    return opc;
}

