#include<stdio.h>
#include<stdlib.h>
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
    struct student *next, *previous; // proximo aluno
}student;
/*
typedef struct 
{
    student *head, *taill; //struct que aponta para o primeiro elemento e ultimo da lista
}body;
*/
/*
body *cria_aluno(student *people)
{
    body *list_people;
    student *i;
    if(people == NULL)
    {
        list_people = people;
    }
    else
    {
        list_people->head = people;
        for(i=people; i!=NULL; i = i->next)
        {
            if(i->next =NULL) list_people->taill = i;
        }
    }
    people = (student *)malloc(sizeof(student));//aloca a memoria
    /*scanf("%s", people->resgitration);
    scanf("%s", people->name);
    scanf("%d/%d/%d", &people->birth.day, &people->birth.moth, &people->birth.year);
    scanf("%f", &people->average);*/
    //***********************************************************
    /*scanf("%s", people->resgitration);
    scanf("%s", people->name);
    people->birth.day= 30; people->birth.moth=10; people->birth.year = 1999;
    people->average = 7.6;
    //***********************************************************
    people->next = NULL;
    people->previous = NULL;
    if(list_people->head == NULL)
    {
        list_people->head = people;
        list_people->taill = people;
    }
    else
    {
        list_people->taill->next = people;
        people->previous = list_people->taill;
        list_people->taill = people;
    }
    return list_people;
}
*/
void Void(student *people)
{
    if(people == NULL) return 1;
    else return 0;
}

void print_Student(student *people) //Emprime os estudantes cadastrados
{
    if(Void(people)) printf("Lista vazia!\n");
    else
    {
        student *i;
        for(i=people;i!=NULL;i=i->next)
        {
            printf("%s, %s", i->resgitration, i->name);
            printf(", %i/%i/%i", i->birth.day, i->birth.moth, i->birth.year);
            printf(", %.2f\n", i->average);
        }    
    }
}

