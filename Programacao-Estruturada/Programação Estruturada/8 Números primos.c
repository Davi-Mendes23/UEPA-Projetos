/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int primo(int numero){
    int resultado =1;
    for (int i =2; i < numero; i++) if (numero % i == 0) resultado = 0;
    return resultado;
}
int main() {
    int numero;
    
    do {
        printf ("Insira um número inteiro natural: \n");
        scanf ("%d", &numero);
        if (numero < 1) printf ("Apenas Naturais não nulos! \n");
    } while (numero < 1);
    
    if (primo (numero)) {
        printf ("O numero %d é um numero primo!", numero);
    } else {
        printf ("O numero %d não é um número primo!", numero);
    }
    
    return 0;
}


