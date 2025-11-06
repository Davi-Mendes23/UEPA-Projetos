/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    char opcao = 'g';
    float saque = 0.0;
    float saldo = 0.0;
    float deposito = 0.0;
    
    do{
        printf ("O que desejas realizar?\n (a) Consultar saldo \n (b) Saque \n (c) Deposito \n (d) Sair \n");
        printf("Sua escolha foi: ");
        scanf ("%s", &opcao);
        
        switch (opcao){
            case 'a':
            printf ("Seu saldo é: R$ %.2f \n",saldo);
            break;
            
            case 'b':
            printf("Digite o valor do saque: R$ \n");
            scanf ("%f", &saque);
            if (saldo < saque){
                printf ("Saldo insuficiente: \n");
            }
            saldo = saldo - saque;
            break;
            
            case 'c':
            printf ("Digite o valor do deposito: \n");
            scanf ("%f", &deposito);
            saldo = saldo + deposito;
            break;
            
            case 'd':
            printf ("Retire o seu cartão: \n");
            break;
        }
    } while (opcao != 'd');
    return 0;
}



