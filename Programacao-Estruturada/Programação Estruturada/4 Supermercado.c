/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
    float bruto = 0.0;
    int cliente = 0;
    
    printf ("Inserir primeiro valor \n");
    scanf ("%f", &bruto);
    printf ("Escolha tipo de cliente 1 = comum, 2 = vip, 3 = funcionário \n");
    scanf ("%d", &cliente);
    
    switch (cliente)
    {
     case 1:
     printf ("Valor da compra %.2f", bruto);
     break;
      case 2:
     printf ("Valor da compra %.2f", bruto * 0.95);
     break;
      case 3:
     printf ("Valor da compra %.2f", bruto * 0.9);
     break;
    }

    return 0;
}


