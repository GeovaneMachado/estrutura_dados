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

typedef struct 
{
    student *head, *taill;
}body;

void *cria_aluno(student *people)
{
    student *people = people;
    body *list_people;
    people = (student *)malloc(sizeof(student));//aloca a memoria
    scanf("%s", people->resgitration);
    scanf("%s", people->name);
    scanf("%d/%d/%d", &people->birth.day, &people->birth.moth, &people->birth.year);
    scanf("%f", &people->average);
    people->next = NULL;
    people->previous = NULL;
    if(list_people->head == NULL)
    {
        list_people->head = people;
        list_people->taill = people;
    }
    else
    {
        people->previous = list_people->taill;
        list_people->taill = people;
    }
}

void print_Student(student people) //Emprime os estudantes cadastrados
{
    //if(Void(people)) printf("Lista vazia!\n");
   // else
   // {
        student *i;
        for(i=people;i!=NULL;i=i->next)
        {
            printf("%s, %s", i->resgitration, i->name);
            printf(", %i/%i/%i", i->birth.day, i->birth.moth, i->birth.year);
            printf(", %.2f\n", i->average);
        }    
  //  }
}

/*void print_reverse(student *first) //Impime a lista em ordem inversa
{
    //if(first==NULL) return; //Verifica se first é NULL para parar a recursao
    //else
    //{
        print_reverse(first->next); //aponta para o proximo elemento da lista
        printf("%s, %s", first->resgitration, first->name);
        printf(", %i/%i/%i", first->birth.day, first->birth.moth, first->birth.year);
        printf(", %.2f\n", first->average);     
    }//apos final que ira retorna o print de forma inversa
//}
*/