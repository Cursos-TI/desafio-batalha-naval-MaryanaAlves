#include <stdio.h>

#define LINHAS 10
#define COLUNAS 10
#define LINHAHAB 3
#define COLUNAHAB 5

int main() {
    char colunasLetras[LINHAS]= {'A','B','C','D','E','F','G','H','I','J'};
    int tabuleiro[LINHAS][COLUNAS]={0};
    int navio1[3]={3, 3, 3};
    int navio2[3]={3, 3, 3};

    printf(" ### Tabuleiro Batalha Naval antes das *Habilidades* ###\n");

    //Colunas de A-J
    printf("   ");
    for(int c=0;c<10;c++){
        printf("%c  ", colunasLetras[c]);
    }
    printf("\n");

    //navio 1 na horizontal
    for(int n=0;n<3;n++){
        int linha=6, coluna=5+n;
        if(linha>=0 && linha<10 && coluna>=0 && coluna<10){
            if(tabuleiro[linha][coluna]==0) tabuleiro[linha][coluna]=3;
        }
    }

    //navio 2 na vertical
    for(int n=0;n<3;n++){
        int linha=1+n, coluna=1;
        if(linha>=0 && linha<10 && coluna>=0 && coluna<10){
            if(tabuleiro[linha][coluna]==0) tabuleiro[linha][coluna]=3;
        }
    }

    //navio 3 na diagonal
    for(int n=0;n<3;n++){
        int linha=7+n, coluna=0+n;
        if(linha>=0 && linha<10 && coluna>=0 && coluna<10){
            if(tabuleiro[linha][coluna]==0) tabuleiro[linha][coluna]=3;
        }
    }

    //navio 4 na diagonal
    for(int n=0;n<3;n++){
        int linha=3-n, coluna=7-n;
        if(linha>=0 && linha<10 && coluna>=0 && coluna<10){
            if(tabuleiro[linha][coluna]==0) tabuleiro[linha][coluna]=3;
        }
    }

    //exibição do tabuleiro + numero de linhas
    for(int i=0;i<10;i++){
        printf("%2d ",i+1);
        for(int j=0;j<10;j++){
            printf("%d  ",tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf(" ### Tabuleiro Batalha Naval depois das *Habilidades* ###\n");

    //logica do cone
    int origemLinhaCone = 3;
    int origemColunaCone = 4;
    for(int i=0;i<LINHAHAB;i++){
        for(int j=0;j<COLUNAHAB;j++){
            if(j>=2-i && j<=2+i){
                int linha=origemLinhaCone+i;
                int coluna=origemColunaCone+j;
                if(linha>=0 && linha<10 && coluna>=0 && coluna<10){
                    tabuleiro[linha][coluna]=5;
                }
            }
        }
    }

    //logica da cruz
    int origemLinhaCruz = 1;
    int origemColunaCruz = 2;
    for(int i=0;i<LINHAHAB;i++){
        for(int j=0;j<COLUNAHAB;j++){
            if(i==1 || j==2){
                int linha = origemLinhaCruz + i - 1;
                int coluna = origemColunaCruz + j - 2;
                if(linha>=0 && linha<10 && coluna>=0 && coluna<10){
                    tabuleiro[linha][coluna]=5;
                }
            }
        }
    }

    //logica do octaedro
    int origemLinha = 7;
    int origemColuna = 2;
    for(int i=0;i<3;i++){
        for(int j=0;j<5;j++){
            if( (i==0 && j==2) || (i==1 && (j>=1 && j<=3)) || (i==2 && j==2)){
                int linha = origemLinha-1+i;
                int coluna = origemColuna-2+j;
                if(linha>=0 && linha<10 && coluna>=0 && coluna<10){
                    tabuleiro[linha][coluna]=5;
                }
            }
        }
    }

    //exibição do tabuleiro final
    for(int i=0;i<10;i++){
        printf("%2d ",i+1);
        for(int j=0;j<10;j++){
            printf("%d  ",tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
