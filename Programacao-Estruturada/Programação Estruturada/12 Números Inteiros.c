/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int numeros[9][2];
int cadastrado = 0;

void CadastrarInteiros() {
    int id;
    do {
        printf("Insira o ID da pessoa: ");
        scanf("%d", &id);
        
        if (id < 1 || id > 10)
            printf("Erro: Insira um ID válido (entre 1 e 10)!\n\n");
    } while (id < 1 || id > 10);
    
    printf(" Cadastro de Numeros Inteiros \n");
    
    for (int numero = 0; numero < 3; numero++) {
        printf("Insira o %dº número: ", numero + 1);
        scanf("%d", &numeros[id - 1][numero]);
    } printf("Números cadastrados com sucesso!\n\n");
}

void ExibirInteiros() {
    if (cadastrado) {
        printf("( EXIBIÇÃO DE NÚMEROS INTEIROS )\n");
    
       for (int id = 0; id < 10; id++) {
            printf("ID %d: %d, %d e %d \n", id + 1, numeros[id][0], numeros[id][1], numeros[id][2]);
        } printf("\n");
    } else {
        printf("Erro: Não há números inteiros cadastrados!\n\n");
    }
}

int main() {
    int escolha, ativo = 1;
    
    while (ativo) {
        do {
            printf("Insira sua opção:\n\n");
            printf("[ 1 ] Cadastrar Números Inteiros\n");
            printf("[ 2 ] Exibir Números Inteiros\n");
            printf("[ 3 ] Sair do Programa\n");
            printf("Sua escolha: ");
            scanf("%d", &escolha);
            
            if (escolha < 1 || escolha > 3)
                printf("Erro: Escolha uma opção válida!\n\n");
        } while (escolha < 1 || escolha > 3);
        
        switch (escolha) {
            case 1:
                CadastrarInteiros();
                cadastrado = 1;
                break;
            case 2:
                ExibirInteiros();
                break;
            case 3:
                ativo = 0;
                break;
        }
    }

   return 0;
}

