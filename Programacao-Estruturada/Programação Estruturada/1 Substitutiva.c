/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    float nota1 = 0.0;
    float nota2 = 0.0;
    float nota3 = 0.0;
    float media = 0;
    int opcao = 0;
    
    printf ("Nota dos Alunos \n");
    do {
     printf ("Inserir nota do primeiro bimestre: \n");
     scanf ("%f", &nota1);
    } while (nota1 <0 || nota1 > 10);

    printf ("Inserir nota do segundo bimestre: \n");
    scanf ("%f", &nota2);
    
    float nota = nota1 + nota2;
    media = nota / 2;
    
    if (media >= 8){
        printf ("Aprovado! \n");
        printf ("Sua media é: %.2f +%.2f \2 = %.2f", nota1, nota2, media);
        return 0;
    }else if (media < 8){
        printf ("Você fez a recuperação? \n 1 - Sim \n 2 -Não: \n");
        scanf ("%d", &opcao);
    }
    if (opcao == 1){
        printf ("Inserir nota da recuperação \n");
        scanf ("%f", &nota3);
    }
    else{
        printf ("Sua media é: %.2f + %.2f \2 = %.2f", nota1, nota2, media);
        return 0;
    }
    if (nota1 > nota2){
        nota2 = nota3;
    }
    else
     nota1 = nota3;
     
    media = (nota1 + nota2) /2;
    
    printf ("Sua media é: (%.2f + %.2f)\2= %.2f", nota1, nota2, media);
    
    return 0;
}


