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
    char resgitration[TAM_REG+1]; //matricula
    char name[TAM_NAME+1];//nome
    Date birth;//nascimento
    float average;//media das notas
    struct student *next; // proximo aluno
}student;

void print_Student(student *people) //Emprime os estudantes cadastrados
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

int Void(student *list)
{
    if(list != NULL) return 0;
    else return 1;
}

/*student *pupil(student *name_student)
{
    student *assistant, *first;
    if(name_student == NULL) first =NULL;
    name_student = (student *)malloc(sizeof(student));//aloca a memoria
    strcpy(name_student->resgitration, "1234");
    strcpy(name_student->name, "geovane");
    printf("Nascimento: ");
    scanf("%i/%i/%i", &name_student->birth.day, &name_student->birth.moth, &name_student->birth.year);
    name_student->average = 7.3;
    /*printf("Media: ");
    scanf("%f", &name_student->average);*//*
    name_student->next = NULL;
    if(first == NULL)
    {
        first = name_student;
    }
    else
    {
       //assistant = first;
      //  while(assistant->next!=NULL)
           // assistant = assistant->next;       
        assistant->next= name_student;
        assistant = name_student;   
    }      
    return name_student;    
}*/

int menu(int opc)
{
    printf("\nOPCAO\n[1] Adicinar\n [2] Excluir\n[3] Listar\n");
    //scanf("%i", &opc);
    opc = 1;
    return opc;
}

