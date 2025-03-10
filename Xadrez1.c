#include <stdio.h>

int main() {
    // Movimento da Torre (5 casas para a direita) 
    printf("Movimento da Torre:\n");
    for (int i = 0; i < 5; i++) {
        printf("Direita\n");
    }
    printf("\n");

    // Movimento do Bispo (5 casas na diagonal para cima e à direita) 
    printf("Movimento do Bispo:\n");
    int j = 0;
    while (j < 5) {
        printf("Cima, Direita\n");
        j++;
    }
    printf("\n");

    // Movimento da Rainha (8 casas para a esquerda) 
    printf("Movimento da Rainha:\n");
    int k = 0;
    do {
        printf("Esquerda\n");
        k++;
    } while (k < 8);
    printf("\n");

    // Movimento do Cavalo (2 casas para baixo e 1 para a esquerda)
    printf("Movimento do Cavalo:\n");
    for (int m = 0; m < 2; m++) { // Duas casas para baixo
        printf("Baixo\n");
    }
    int n = 0;
    while (n < 1) { // Uma casa para a esquerda
        printf("Esquerda\n");
        n++;
    }
    
    return 0;
}