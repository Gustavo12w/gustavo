#include <stdio.h>
#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5

// Função para inicializar o tabuleiro com água (0) e um navio (3) como exemplo
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
    // Adicionando um navio como exemplo
    tabuleiro[5][5] = 3;
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para criar a matriz de habilidade em cone
void criarCone(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (j >= (TAM_HABILIDADE / 2) - i && j <= (TAM_HABILIDADE / 2) + i) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Função para criar a matriz de habilidade em cruz
void criarCruz(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i == TAM_HABILIDADE / 2 || j == TAM_HABILIDADE / 2) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Função para criar a matriz de habilidade em octaedro
void criarOctaedro(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if ( abs(i - TAM_HABILIDADE / 2) + abs(j - TAM_HABILIDADE / 2) <= TAM_HABILIDADE / 2) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Função para aplicar a matriz de habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], int x, int y) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int posX = x + i - TAM_HABILIDADE / 2;
            int posY = y + j - TAM_HABILIDADE / 2;
            if (posX >= 0 && posX < TAM_TABULEIRO && posY >= 0 && posY < TAM_TABULEIRO && habilidade[i][j] == 1) {
                tabuleiro[posX][posY] = 5;
            }
        }
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    int habilidade[TAM_HABILIDADE][TAM_HABILIDADE];

    inicializarTabuleiro(tabuleiro);
    
    printf("Tabuleiro inicial:\n");
    exibirTabuleiro(tabuleiro);

    printf("\nTabuleiro com habilidade em cone:\n");
    criarCone(habilidade);
    aplicarHabilidade(tabuleiro, habilidade, 4, 4);
    exibirTabuleiro(tabuleiro);

    inicializarTabuleiro(tabuleiro);
    printf("\nTabuleiro com habilidade em cruz:\n");
    criarCruz(habilidade);
    aplicarHabilidade(tabuleiro, habilidade, 4, 4);
    exibirTabuleiro(tabuleiro);

    inicializarTabuleiro(tabuleiro);
    printf("\nTabuleiro com habilidade em octaedro:\n");
    criarOctaedro(habilidade);
    aplicarHabilidade(tabuleiro, habilidade, 4, 4);
    exibirTabuleiro(tabuleiro);

    return 0;
}