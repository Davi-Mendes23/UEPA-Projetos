/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

char nomes[9][100];
int cadastrado = 0;

void CadastrarNomes() {
    printf("Cadastro de Nomes \n");
    
    for (int nome = 0; nome < 10; nome++) {
        printf("Insira o %dº nome: ", nome + 1);
        scanf("%s", &nomes[nome]);
    } printf("Nomes cadastrados com sucesso!\n\n");
}

void ExibirNomes() {
    if (cadastrado) {
        printf(" Mostrador de Nomes \n");
    
        for (int nome = 0; nome < 10; nome++) {
            printf("%s \n", nomes[nome]);
        } printf("\n");
    } else {
        printf("Erro: Não há nomes cadastrados!");
    }
}
int escolha, ativo = 1;
    
    while (ativo) {
        do {
            printf("Insira sua opção:\n\n");
            printf("[ 1 ] Cadastrar Nomes\n");
            printf("[ 2 ] Exibir Nomes\n");
            printf("[ 3 ] Sair do Programa\n");
            printf("Sua escolha: ");
            scanf("%d", &escolha);
            
            if (escolha < 1 || escolha > 3)
                printf("Erro: Escolha uma opção válida!\n\n");
        } while (escolha < 1 || escolha > 3);
        
        switch (escolha) {
            case 1:
                CadastrarNomes();
                cadastrado = 1;
                break;
            case 2:
                ExibirNomes();
                break;
            case 3:
                ativo = 0;
                break;
        }
    }

    return 0;

