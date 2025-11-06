/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int escolha = 0;
    float jr = 0.0;
    float cl = 0.0;
    float nr = 0.0;
    float n = 0.0;
    float b = 0.0;
    
    
    
    do{
    printf ("Escolha o candidato: \n");
    printf ("1=Jair Rodrigues 2=Carlos Luz 3=Neves Rocha 4=Nulo 5=Branco \n"); //6=dados
    scanf ("%d", &escolha);
    switch (escolha){
        case 1:
        jr++;
        break;
        case 2:
        cl++;
        break;
        case 3:
        nr++;
        break;
        case 4:
        n++;
        break;
        case 5:
        b++;
        break;
        case 6:
        printf ("Numero de Votos:\n Jair Rodrigues = %.2f \n Carlos Luz = %.2f \n Neves Rocha = %.2f \n Nulo = %.2f \n Branco = %.2f \n",jr, cl, nr, n, b);
        float votos;
        votos = jr+cl+nr+n+b;
        printf ("Porcentagem dos Votos:\n Jair Rodrigues = %.2f %% \n Carlos Luz = %.2f %% \n Neves Rocha = %.2f %% \n Nulo = %.2f %% \n Branco = %.2f %% \n",((jr/votos)*100),((cl/votos)*100),((nr/votos)*100),((n/votos)*100),((b/votos)*100));
        if (jr > cl && jr > nr){
            printf ("Jair é o vencedor \n");
        }
        if (cl > jr && cl > nr){
            printf("Carlos é o vencedor \n");
        }
        if (nr > jr && nr > cl){
            printf ("Neves é o vencedor \n");
        }
    }
    } while (escolha!=6);
    
    return 0;
}

