/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    float x = 0.0;
    float y = 0.0;
    int opcao = 0;
    
    printf ("Inserir primeiro valor \n");
    scanf ("%f", &x);
    printf ("Inserir segundo valor \n");
    scanf ("%f", &y);
    printf ("Inserir operação 1= +, 2 = -, 3 = *, ou 4 = / \n");
    scanf ("%d", &opcao);
    
    switch (opcao)
    {
        case 1:
        printf ("Resultado %.2f + %.2f = %.2f", x, y, x + y);
        break;
        case 2:
        printf ("Resultado %.2f - %.2f = %.2f", x, y, x - y);
        break;
        case 3:
        printf ("Resultado %.2f * %.2f = %.2f", x, y, x * y);
        break;
        case 4:
        printf ("Resultado %.2f / %.2f = %.2f", x, y, x / y);
        break;
    }
    return 0;
}


