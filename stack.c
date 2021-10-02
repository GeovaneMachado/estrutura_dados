#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TAM_SITE 60


typedef struct //struct da ficha da pilha 
{
    char site[TAM_SITE];
    struct url *next;
    struct url *previous; 
}url;

typedef struct //Cria struct para apontar o primeiro e ultimo da pilha
{
    url *head;
    url *taill;
}body;


body links(body aux, char *link) //Enserir um elemento na pilha
{    
    url *address;
    address = (url *)malloc(sizeof(url));//aloca a memoria
    strcpy(address->site, link);
    address->next = NULL;
    address->previous = NULL;
    if(aux.head == NULL) //Se head for null não tem nenhum elemento na pilha
    {
        aux.head = address; //head e taill apontam para address
        aux.taill = address;
    }
    else
    {
        address->previous = aux.taill;
        aux.taill->next = address;
        aux.taill = address;
    }
    return aux;
}

int Vazio(body aux)
{
    if(aux.taill == NULL) return 1;
    else return 0;
}

body excluir(body aux) //Exclui um elemento especifico da lista
{
    if(Vazio(aux)) // verifica se a lista esta Vazia
    {
        printf("Vazio\n"); 
    }
    else 
    {
        url *i = aux.taill;
        if(aux.head->next == NULL) //Se o head for o unico elemento na pilha
        {
            aux.head = NULL;
            aux.taill = NULL;
        }
        else 
        {
            aux.taill = i->previous;
            aux.taill->next = NULL;
        }
        printf("%s\n", i->site);
        free(i);
    } 
    return aux;
}

void free_memory(body corp) //Libera o espaço na memoria 
{
    if(Vazio(corp)) 
    {
        printf("!\n");
        return;
    }
    else
    {
           url *aux, *i;
        aux = corp.head->next;
        i = corp.head;
        while(i!=NULL)
        {
            printf("@");
            free(i);
            i = aux;
            aux = aux->next;
        }
    }
    printf("@\n");
}


int main()
{
    body aux;
    char link[TAM_SITE];
    int op = 0;
    aux.head =NULL;
    aux.taill = NULL;
    while(op!=1)
    {
        scanf("%s", link);
        if(strcmp(link, "B") == 0) aux = excluir(aux);
        else if(strcmp(link, "E") == 0) op = 1;
        else
        { 
            aux = links(aux, link);
        }   
    }
    free_memory(aux); 
    return 0;
}