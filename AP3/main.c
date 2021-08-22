#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "func.h"

int main()
{
    student *people , *assistant, *first = NULL;
    int opc=1;
    while (opc!=0)
    {    
        opc = menu(opc);
        switch (opc)
        {
        case 1:
            people = pupil(people, first);
            break;
        
        default:
            opc = 0;
            break;
        }
    print_Student(people);
    }
    return 0;
}
