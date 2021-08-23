#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "func.h"

int main()
{
    student *people , *assistant, *first=NULL;
    int opc=1;
    while (opc!=0)
    {    
        opc = menu(opc);
        switch (opc)
        {
        case 1:
            people = (student *)malloc(sizeof(student));//aloca a memoria
            strcpy(people->resgitration, "1234");
            strcpy(people->name, "geovane");
            printf("Nascimento: ");
            scanf("%i/%i/%i", &people->birth.day, &people->birth.moth, &people->birth.year);
            people->average = 7.3;
            /*printf("Media: ");
            scanf("%f", &people->average);*/
            people->next = NULL;
            if(first == NULL)
            {
                first = people;
                assistant =people;    
            }
            else
            {
                /*assistant = first;
                while (assistant->next =NULL)
                {
                    assistant = assistant->next;
                }    */
                assistant->next = people;
                assistant = people; 
            }
            break;    
        default:
            opc = 0;
            break;
        }
        print_Student(people);
    }
    return 0;
}
