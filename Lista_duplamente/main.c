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
    struct student *next, *previous; // proximo aluno
}student;

student *head, *taill;

student *cria_aluno(student *people)
{
    people = (student *)malloc(sizeof(student));//aloca a memoria
    /*scanf("%s", people->resgitration);
    scanf("%s", people->name);
    scanf("%d/%d/%d", &people->birth.day, &people->birth.moth, &people->birth.year);
    scanf("%f", &people->average);*/
    //***********************************************************
    printf("\nMATRICULA: ");
    scanf("%s", people->resgitration);
    printf("NOME: ");
    scanf("%s", people->name);
    people->birth.day= 30; people->birth.moth=10; people->birth.year = 1999;
    people->average = 7.6;
    //***********************************************************
    people->next = NULL;
    people->previous = NULL;
    return people;
}
void print_student(student *people)
{
    student *i;
    for(i=people; i!=NULL; i=i->next)
    {
        printf("%s, %s", i->resgitration, i->name);
        printf(", %i/%i/%i", i->birth.day, i->birth.moth, i->birth.year);
        printf(", %.2f\n", i->average);
    }
}

int main()
{
    student *people;// *aux;
    head = NULL;
    taill = NULL;
    int op;
    while (op!=0)
    {
        printf("\n\t**********MENU**********\n\t[1] -- CADASTRO\n\t[2] -- VISUALIZAR CADASTRO\n");
        scanf("%d", &op);
        switch (op)
        {
            case 1:
                people = cria_aluno(people);
                printf("\nroda ate aqui essa merda");
                if(head == NULL)
                {
                    head = people;
                    taill = people;
                }
                else
                {
                   // aux = people;
                    people->previous = taill;
                    taill->next = people;
                    taill = people;
                }
                break;
            case 2:
                print_student(people);
                break;
            default:
                break;
        }   
    }    
    return 0;
}