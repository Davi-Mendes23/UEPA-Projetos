/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
    printf ("nota \n");
    int n1 = 0;
    int n2 = 0;
    int n3 = 0;
    int n4 = 0;
    
    printf ("nota 1º bimestre \n");
    scanf ("%d", &n1);
    printf ("nota 2º bimestre \n");
    scanf ("%d", &n2);
    printf ("nota 3º bimestre \n");
    scanf ("%d", &n3);
    printf ("nota 4º bimestre \n");
    scanf ("%d", &n4);
    int nota = n1 + n2 + n3 + n4;
    int nf = nota / 4;
    
    if (nf >= 8)
     printf ("aprovado!");
    else
     printf ("reprovado!");

    return 0;
}

