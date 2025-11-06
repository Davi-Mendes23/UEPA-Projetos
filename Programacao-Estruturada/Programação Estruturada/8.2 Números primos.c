/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int primo = 17;
    //int aux = 0;
    int cont = 2;
    
    printf ("Escolha um número \n");
    scanf ("%d", &primo);
    
    while (cont < primo){
        if (primo% cont == 0){
            printf ("Não primo \n");
            break;
        } else {
            printf ("Primo \n");
            break;
        }
    }

    return 0;
}

