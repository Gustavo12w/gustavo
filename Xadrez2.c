#include <stdio.h>

#define CASAS_TORRE 3
#define CASAS_BISPO 3
#define CASAS_RAINHA 3
#define MOVIMENTOS_CAVALO 3

// Função recursiva para movimentação da Torre
void moverTorre(int casas) {
    if (casas == 0) return;
    printf("Direita\n");
    moverTorre(casas - 1);
}

// Função recursiva para movimentação do Bispo
void moverBispo(int casas, int mov_atual) {
    if (mov_atual > casas) return;
    printf("Diagonal superior direita\n");
    moverBispo(casas, mov_atual + 1);
}

// Função recursiva para movimentação da Rainha
void moverRainha(int casas) {
    if (casas == 0) return;
    printf("Diagonal inferior esquerda\n");
    moverRainha(casas - 1);
}

// Função que movimenta o Cavalo usando loops aninhados
void moverCavalo(int movimentos) {
    for (int i = 0; i < movimentos; i++) {
        for (int j = 0; j < movimentos; j++) {
            if (i == 2 && j == 1) {
                printf("Movimento em L: Duas casas para cima e uma para a direita\n");
                break;
            }
        }
    }
}

// Função para movimentação do Bispo usando loops aninhados
void moverBispoLoop(int casas) {
    for (int i = 1; i <= casas; i++) {
        for (int j = 1; j <= i; j++) {
            printf("Diagonal superior direita\n");
        }
    }
}

int main() {
    printf("Movimentação da Torre:\n");
    moverTorre(CASAS_TORRE);
    printf("\n");

    printf("Movimentação do Bispo (Recursivo):\n");
    moverBispo(CASAS_BISPO, 1);
    printf("\n");

    printf("Movimentação da Rainha:\n");
    moverRainha(CASAS_RAINHA);
    printf("\n");

    printf("Movimentação do Cavalo:\n");
    moverCavalo(MOVIMENTOS_CAVALO);
    printf("\n");

    printf("Movimentação do Bispo (Loops Aninhados):\n");
    moverBispoLoop(CASAS_BISPO);
    printf("\n");

    return 0;
}