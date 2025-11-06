/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int Op;
  
    
    printf("Digite O Numero De Acordo Com O Mes Que Deseja. \n");
    scanf("%d", &Op);
    
       switch ( Op )
       {
           
           
           case 1 :
           printf("Seu Mes É Janeiro");
           break;
           
           case 2 :
           printf("Seu Mes É Fevereiro");
           break;
           
           case 3 :
           printf("Seu Mes É Março");
           break;
           
           case 4 :
           printf("Seu Mes É Abril");
           break;
           
           case 5 :
           printf("Seu Mes É Maio");
           break;
           
           case 6 :
           printf("Seu Mes É Junho");
           break;
           
           case 7 :
           printf("Seu Mes É Julho");
           break;
           
           case 8 :
           printf("Seu Mes É Agosto");
           break;
           
           case 9 :
           printf("Seu Mes É Setembro");
           break;
           
           case 10 :
           printf("Seu Mes É Outubro");
           break;
           
           case 11 :
           printf("Seu Mes É Novembro");
           break;
           
           case 12 :
           printf("Seu Mes É Dezembro");
           break;
       }
       if (Op > 12){
           printf("Só temos 12 meses neste calendário.");
       }
       
    return 0;
}


