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
    char resgitration[TAM_REG];     //matricula
    char name[TAM_NAME];    //nome
    Date birth; //nascimento
    float average;  //media das notas
    struct student *next;
    struct student *previous; // proximo aluno
}student;

typedef struct
{
    student *head;
    student *taill;
}body;


student *cria_aluno(student *people) //Cria um elemento para adicionar na lista
{
    people = (student *)malloc(sizeof(student));//aloca a memoria
    /*scanf("%s", people->resgitration);
    scanf("%s", people->name);
    scanf("%d/%d/%d", &people->birth.day, &people->birth.moth, &people->birth.year);
    scanf("%f", &people->average);*/
    //**********************************************************************
    printf("\nMATRICULA: ");
    scanf("%s", people->resgitration);
    printf("NOME: ");
    scanf("%s", people->name);
    people->birth.day= 30; people->birth.moth=10; people->birth.year = 1999;
    people->average = 7.6;
    //**********************************************************************
    people->next = NULL;
    people->previous = NULL;
    return people;
}

void print_student(body corp) //Imprime os estudantes na lista 
{
    student *i;
    for(i= corp.head; i!=NULL; i=i->next)
    {
        printf("%s, %s", i->resgitration, i->name);
        printf(", %i/%i/%i", i->birth.day, i->birth.moth, i->birth.year);
        printf(", %.2f\n", i->average);
    }
}

body lugar_elemento(body list) //Enserir um elemento na lista fazer a busca e enserir na ordem
{    
    student *aux, *people;
    body corp = list;
    char reg[TAM_REG];
    int confere;
    scanf("%s", &reg);
    people = cria_aluno(people);
    if(corp.head == NULL) //Se head for null não tem nenhum elemento na lista
    {
        corp.head = people; //head e taill apontam para people
        corp.taill = people;
    }
    else
    {
        for(aux= corp.head; aux!=NULL; aux=aux->next)
        {
            confere = strcmp(aux->resgitration, reg); //Se as strings for igual confere = 0
            if(confere==0) //Se confere == 0 a matricula exite na lista para adicionar o elemento na ordem 
            {   
                if(aux->next != NULL) //Verfica se aux não é o ultimo elemento da lista
                {                
                    student *prev; 
                    people->previous = aux; // people previous aponta para aux
                    people->next = aux->next; //people next aponta para o next de aux 
                    prev = aux->next; //prev aponta para aux next 
                    prev->previous = people; // prev previous aponta para people 
                    aux->next = people; // aux next aponta para people, inserindo o elemento na ordem 
                    break;                    
                }
                else // se o elemento tiver que ir no ultimo lugar da lista 
                {
                    people->previous = corp.taill;
                    corp.taill->next = people;
                    corp.taill = people;
                    break;
                }
            }
        }
        if(confere != 0) //Se confere for diferente de 0 o elemento não existe na lista, fazendo ele ir por primeiro 
        {
            people->next = corp.head;
            corp.head->previous = people;
            corp.head = people;
        }
    }
    return corp;
}


int main()
{
    student *people;
    body aux;
    aux.head =NULL;
    aux.taill = NULL;
    int op=1;
    while (op!=0)
    {
        printf("\n\t**********MENU**********\n\t[1] -- CADASTRO\n\t[2] -- VISUALIZAR CADASTRO\n");
        scanf("%d", &op);
        switch (op)
        {
            case 1:
                aux = lugar_elemento(aux);
                break;
            case 2:
                print_student(aux);
                break;
            default:
                break;
        }   
    }    
    return 0;
}