#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "func.h"

int main()
{
    student *people , *assistant, *first=NULL, *previous=first, *i;
    char resg[TAM_REG], name[TAM_NAME];
    int opc, stop = 1, cont;
    while (stop !=0)
    {    
        scanf("%i", &opc);
        switch (opc)
        {
            case 1: //Adicionar elementos a lista
                people = (student *)malloc(sizeof(student));//aloca a memoria
                scanf("%s", people->resgitration);
                scanf("%s", people->name);
                scanf("%d/%d/%d", &people->birth.day, &people->birth.moth, &people->birth.year);
                scanf("%f", &people->average);
                people->next = NULL;
                if(first == NULL) //Se first == NULL first e assistant ira apontar pra people
                {
                    first = people;
                    assistant =people;    
                }
                else //Assistant->next aponta para people e depois recebe os dados
                {
                    assistant->next = people;
                    assistant = people; 
                }
                break;
            case 2: //Deletar elementos
                    first = Delete(first); //Funcao para deletar o elemento se a lista nao for vazia
                    assistant = first; //assistant aponta para o primeiro elemento da lista
                    if(first !=NULL)
                    {
                        while (assistant->next != NULL)
                        {
                            assistant = assistant->next; //atualiza o valor de assistant
                        }
                    }                
                break;
            case 3:    
                print_Student(first); //Imprime os estudantes na ordem de inclusao
                break;
            case 4:
                if(Void(first))printf("Lista vazia!");
                else print_reverse(first); //Imprime os estudantes na ordem reversa de inclusao
                break;
            case 5:
                cont = count_student(first);
                printf("%i", cont);
                break;
            default: 
                stop = 0;
                break;
        }
    }
    freeMemory(first); //Libera a memoria
    return 0;
}
