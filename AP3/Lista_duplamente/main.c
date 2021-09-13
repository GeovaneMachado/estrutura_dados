#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "funcoes.h"

int main()
{
    student people;
    body *list_people;
    int op;
    while (op!=0)
    {
        scanf("%i", &op);
        switch (op)
        {
            case 1:
                people = cria_aluno(people);
                break;
            case 2:
                print_Student(people);
                break;
            default:
                break;
        }   
    }    
    return 0;
}