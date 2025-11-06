/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    float mortalidade = 0.0;
    float natalidade = 0.0;
    float habitantes = 0.0;
    float nascidos = 0.0;
    float obitos = 0.0;
    int opcao = 0;
    
    printf ("Insira qual deseja calcular: \n 1 - Natalidade 2 - Mortalidade. \n");
    scanf ("%d", &opcao);
    
    if (opcao == 1){
        printf ("Insira o numero de habitantes: \n");
        scanf ("%f", &habitantes);
        printf ("Insira o numero de nascidos: \n");
        scanf ("%f", &nascidos);
    }
    else{
        printf ("Insira o numero de habitantes: \n");
        scanf ("%f", &habitantes);
        printf ("Insira o numero de habitantes: \n");
        scanf ("%f", &obitos);
    }
    
    natalidade = (nascidos * 1000) / habitantes;
    mortalidade = (obitos * 1000) / habitantes;
    
    switch (opcao)
    {
        case 1:
        printf ("A taxa de natalidade é: \n (%.2f * 1000)/ %.2f = %.2f", nascidos, habitantes, natalidade);
        break;
        case 2:
        printf ("A taxa de mortalidade é: \n (%.2f * 1000)/ %.2f = %.2f", obitos, habitantes, mortalidade);
        break;
    }

    return 0;
}

