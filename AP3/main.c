#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "func.h"

int main()
{
    student *people , *assistant, *first=NULL;
    char resg[TAM_REG], name[TAM_NAME];
    int opc=1, cont;
    while (opc!=0)
    {    
        opc = menu(opc);
        switch (opc)
        {
        case 1: //Adicionar elementos a lista
            people = (student *)malloc(sizeof(student));//aloca a memoria
            printf("matricula");
            scanf("%s", resg);
            printf("Nome");
            scanf("%s", name);
            strcpy(people->resgitration, resg);
            strcpy(people->name, name);
            printf("Nascimento: ");
            scanf("%i/%i/%i", &people->birth.day, &people->birth.moth, &people->birth.year);
            people->average = 7.3;
            printf("Media: ");
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
            if(Void(first))printf("Lista vazia!"); //Verefica se a lista é vazia
            else
            {
                first = Delete(first); //Funcao para deletar o elemento se a lista nao for vazia
                assistant = first; //assistant aponta para o primeiro elemento da lista
                while (assistant->next != NULL)
                {
                    assistant = assistant->next; //atualiza o valor de assistant
                }
            }
            break;
        case 3:    
            print_Student(first);
            break;
        case 4:
            cont = count_student(first);
            printf("\n%i", cont);
            break;
        default:
            //opc = 0;
            break;
        }
    }
    return 0;
}
