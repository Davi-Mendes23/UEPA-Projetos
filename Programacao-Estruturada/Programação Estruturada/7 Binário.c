/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    float numero = 0;
    do{
        printf ("Selecione: valor = 0 ou valor = 1 \n");
        scanf ("%f", &numero);
        if (numero < 0 || numero > 1)  printf ("Selecione valor permitido! \n");
    }while (numero < 0 || numero > 1);
    return 0;
}

