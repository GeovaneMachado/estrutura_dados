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
    int resgitration; //matricula
    char name[TAM_NAME];//nome
    Date birth;//nascimento
    float average;//media das notas
    struct student *previous;
    struct student *next; // proximo aluno
}student;

student *cria_aluno(student *guri)
{
    student *aluno, *first = guri, *end = guri;
    guri = (student *)malloc(sizeof(student));//aloca a memoria
    scanf("%d", guri->resgitration);
    scanf("%s", guri->name);
    scanf("%d/%d/%d", &guri->birth.day, &guri->birth.moth, &guri->birth.year);
    scanf("%f", &guri->average);
    guri->next = NULL;
    guri->previous = NULL;
    if(first == NULL)
    {
        first = guri;
        end = guri;
    }
    else
    {
        end->next = guri;
        guri->previous = end;
        end = guri;
    }
    return ;
}


void print_Student(student *people) //Emprime os estudantes cadastrados
{
    if(people == NULL ) printf("Lista vazia!\n");
    else
    {
        student *i;
        for(i=people;i!=NULL;i=i->next)
        {
            printf("%d, %s", i->resgitration, i->name);
            printf(", %i/%i/%i", i->birth.day, i->birth.moth, i->birth.year);
            printf(", %.2f\n", i->average);
        }    
    }
}
int main()
{
    student *aluno, *first, *prev;
    int i = 0;
    while(i <= 3)
    {
        aluno = cria_aluno(aluno);
        i++;
    }
    print_Student(aluno);
    return 0;
}