#include <stdio.h>

#define TAMANHO 10
#define NAVIO 3

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para verificar se um navio pode ser posicionado sem ultrapassar os limites e sem sobreposição
int podePosicionar(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int direcao, int tipo) {
    for (int i = 0; i < NAVIO; i++) {
        int x = linha + (tipo == 1 ? i * direcao : 0);
        int y = coluna + (tipo == 0 ? i * direcao : 0);
        
        if (x < 0 || x >= TAMANHO || y < 0 || y >= TAMANHO || tabuleiro[x][y] != 0) {
            return 0;
        }
    }
    return 1;
}

// Função para posicionar um navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int direcao, int tipo) {
    for (int i = 0; i < NAVIO; i++) {
        int x = linha + (tipo == 1 ? i * direcao : 0);
        int y = coluna + (tipo == 0 ? i * direcao : 0);
        tabuleiro[x][y] = NAVIO;
    }
}

// Função para posicionar um navio diagonalmente
int podePosicionarDiagonal(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int direcao) {
    for (int i = 0; i < NAVIO; i++) {
        int x = linha + i * direcao;
        int y = coluna + i * direcao;
        
        if (x < 0 || x >= TAMANHO || y < 0 || y >= TAMANHO || tabuleiro[x][y] != 0) {
            return 0;
        }
    }
    return 1;
}

void posicionarNavioDiagonal(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int direcao) {
    for (int i = 0; i < NAVIO; i++) {
        int x = linha + i * direcao;
        int y = coluna + i * direcao;
        tabuleiro[x][y] = NAVIO;
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);
    
    // Posicionando os navios horizontal e vertical
    if (podePosicionar(tabuleiro, 2, 1, 1, 0))
        posicionarNavio(tabuleiro, 2, 1, 1, 0);
    if (podePosicionar(tabuleiro, 5, 3, 1, 1))
        posicionarNavio(tabuleiro, 5, 3, 1, 1);
    
    // Posicionando os navios diagonais
    if (podePosicionarDiagonal(tabuleiro, 1, 1, 1))
        posicionarNavioDiagonal(tabuleiro, 1, 1, 1);
    if (podePosicionarDiagonal(tabuleiro, 6, 8, -1))
        posicionarNavioDiagonal(tabuleiro, 6, 8, -1);
    
    // Exibir tabuleiro
    exibirTabuleiro(tabuleiro);
    
    return 0;
}