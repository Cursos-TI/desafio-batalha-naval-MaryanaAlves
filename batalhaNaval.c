#include <stdio.h>

int main() {
    char colunas[10]= {'A','B','C','D','E','F','G','H','I','J'};
    int tabuleiro[10][10]={0};
    int navio1[3]={3, 3, 3};
    int navio2[3]={3, 3, 3};

    printf(" ### Tabuleiro Batalha Naval ###\n");

    //Colunas de A-J
    printf("   ");
    for(int c=0; c<10; c++){
        printf("%c  ", colunas[c]);
    }
    printf("\n");
    
    //exibição dos návios no tabuleiro (número '3') sem sobreposição e sem ultrapassar o limite do tabuleiro
    for(int n1=0; n1<3; n1++){
        if(5+n1<10){
            if(tabuleiro[6][5+n1] == 0){
                tabuleiro[6][5+n1]= navio1[n1];
            } else {
                printf("Sobreposição detectada!\n");
            } 
        } else {
            printf("Você ultrapassou o limite do tabuleiro\n");
        }
    };

    for(int n2=0; n2<3; n2++){
        if(1+n2<10){
            if(tabuleiro[1+n2][1] == 0){
                tabuleiro[1+n2][1]= navio2[n2];
            } else {
                printf("Sobreposição detectada!\n");
            }
        } else {
            printf("Você ultrapassou o limite do tabuleiro\n");
        }
    };

    //exibição do tabuleiro + numero de linhas
    for(int i=0; i<10; i++){
        printf("%2d ",i+1);
        for(int j=0; j<10; j++){
            printf("%d  ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0
