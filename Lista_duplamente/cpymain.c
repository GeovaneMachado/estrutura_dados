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

typedef struct //Cria struct para apontar o primeiro e ultimo da lista
{
    student *head;
    student *taill;
}body;


student *cria_aluno(student *people) //Cria um elemento para adicionar na lista
{
    people = (student *)malloc(sizeof(student));//aloca a memoria
    scanf("%s", people->resgitration);
    scanf("%s", people->name);
    scanf("%d/%d/%d", &people->birth.day, &people->birth.moth, &people->birth.year);
    scanf("%f", &people->average);
    people->next = NULL;
    people->previous = NULL;
    return people;
}


body lugar_elemento(body list) //Enserir um elemento na lista fazer a busca e enserir na ordem
{    
    student *aux, *people;
    body corp = list;
    char reg[TAM_REG];
    int confere;
    scanf("%s", reg);
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

int Vazio(body aux)
{
    if(aux.head == NULL && aux.taill == NULL) return 1;
    else return 0;
}

body excluir(body aux) //Exclui um elemento especifico da lista
{
    if(Vazio(aux)) // verifica se a lista esta Vazia
    {
        printf("Lista Vazia!"); 
        return aux;
    }
    else 
    {
        student *i, *prev, *nex;
        char reg[TAM_REG];
        scanf("%s", reg); //Le a matricula que tem que excluir
        for(i= aux.head; i!=NULL; i=i->next)
        {
            if(strcmp(i->resgitration, reg) == 0)
            {
                if(i == aux.head) //Se o primeiro elemento for igual a i;
                {
                    if(aux.head->next == NULL) //Se o head for o unico elemento na lista 
                    {
                        aux.head = NULL;
                        aux.taill = NULL;
                    }
                    else
                    {                        
                        aux.head = i->next;
                        aux.head->previous = NULL;
                    }
                    free(i);
                    continue;
                }
                else if(i == aux.taill) //Se o ultimo elemento for igual a i;
                {
                    aux.taill = i->previous;
                    aux.taill->next = NULL;
                    free(i);
                    continue;
                }
                else
                {
                    prev = i->previous; //Se algum elemento do meio da lista for igual a i;
                    prev->next = i->next;
                    prev->previous = i->previous;
                    free(i);
                    continue;
                }                
            }
        }
        return aux;
    } 
}
void free_memory(body corp) //Libera o espaço na memoria 
{
    student *aux = corp.head->next, *i;
    if(Vazio(corp)) return;
    for(i= corp.head; i!=NULL; i=i->next)
    {
        printf("*");
        free(i);
        i = aux;
        aux = aux->next;
    }
    printf("*");
}

void print_student_first(body corp) //Imprime os estudantes na lista 
{
    if(Vazio(corp))
    {
        printf("Lista Vazia!");
        return;
    } 
    student *i;
    for(i= corp.head; i!=NULL; i=i->next)
    {
        printf("%s, %s", i->resgitration, i->name);
        printf(", %i/%i/%i", i->birth.day, i->birth.moth, i->birth.year);
        printf(", %.2f\n", i->average);
    }
}

void print_student_end(body corp) //Imprime os estudantes na lista 
{
    if(Vazio(corp))
    {
        printf("Lista Vazia!");
        return;
    } 
    student *i;
    for(i= corp.taill; i!=NULL; i=i->previous)
    {
        printf("%s, %s", i->resgitration, i->name);
        printf(", %i/%i/%i", i->birth.day, i->birth.moth, i->birth.year);
        printf(", %.2f\n", i->average);
    }
}

int main()
{
    body aux;
    aux.head =NULL;
    aux.taill = NULL;
    int op=1;
    while (op!=0)
    {
        scanf("%d", &op);
        switch (op)
        {
            case 1:
                aux = lugar_elemento(aux); //Cria o elemento na lista e insere na ordem;
                break;
            case 2:
                aux = excluir(aux);
                break;
            case 3:
                print_student_first(aux); //Imprime na ordem o estudante a partir do primeiro
                break;
            case 4:
                print_student_end(aux); //Imprime na ordem o estudante a partir do ultimo
                break;
            default:
                break;
        }   
    }
    free_memory(aux); 
    return 0;
}