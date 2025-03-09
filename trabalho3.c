#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    
    int area;
    int pib;
    int densidade_demografica;
} Carta;

int escolherAtributo(int usado) {
    int opcao;
    do {
        printf("\nEscolha um atributo para comparar:\n");
        if (usado != 1) printf("1 - Populacao\n");
        if (usado != 2) printf("2 - Area\n");
        if (usado != 3) printf("3 - PIB\n");
        if (usado != 4) printf("4 - Densidade Demografica\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
    } while (opcao < 1 || opcao > 4 || opcao == usado);
    return opcao;
}

int obterValor(Carta carta, int atributo) {
    switch (atributo) {
        case 1: return carta.populacao;
        case 2: return carta.area;
        case 3: return carta.pib;
        case 4: return carta.densidade_demografica;
        default: return 0;
    }
}

void determinarVencedor(Carta c1, Carta c2, int atributo1, int atributo2) {
    int valor1_c1 = obterValor(c1, atributo1);
    int valor1_c2 = obterValor(c2, atributo1);
    int valor2_c1 = obterValor(c1, atributo2);
    int valor2_c2 = obterValor(c2, atributo2);

   
    int pontos_c1 = 0, pontos_c2 = 0;
    
    if (atributo1 == 4) {
        pontos_c1 += (valor1_c1 < valor1_c2) ? 1 : 0;
        pontos_c2 += (valor1_c2 < valor1_c1) ? 1 : 0;
    } else {
        pontos_c1 += (valor1_c1 > valor1_c2) ? 1 : 0;
        pontos_c2 += (valor1_c2 > valor1_c1) ? 1 : 0;
    }

    if (atributo2 == 4) {
        pontos_c1 += (valor2_c1 < valor2_c2) ? 1 : 0;
        pontos_c2 += (valor2_c2 < valor2_c1) ? 1 : 0;
    } else {
        pontos_c1 += (valor2_c1 > valor2_c2) ? 1 : 0;
        pontos_c2 += (valor2_c2 > valor2_c1) ? 1 : 0;
    }

  
    int soma_c1 = valor1_c1 + valor2_c1;
    int soma_c2 = valor1_c2 + valor2_c2;

  
    printf("\nComparacao:\n");
    printf("%s - %d (%d) e %d (%d) - Soma: %d\n", c1.nome, valor1_c1, atributo1, valor2_c1, atributo2, soma_c1);
    printf("%s - %d (%d) e %d (%d) - Soma: %d\n", c2.nome, valor1_c2, atributo1, valor2_c2, atributo2, soma_c2);
    

    if (soma_c1 > soma_c2) {
        printf("\nVencedor: %s!\n", c1.nome);
    } else if (soma_c2 > soma_c1) {
        printf("\nVencedor: %s!\n", c2.nome);
    } else {
        printf("\nEmpate!\n");
    }
}

int main() {
   
    Carta carta1 = {"Brasil", 213000000, 8516000, 22000, 25};
    Carta carta2 = {"Alemanha", 83000000, 357000, 40000, 232};


    int atributo1 = escolherAtributo(0);
    int atributo2 = escolherAtributo(atributo1);

   
    determinarVencedor(carta1, carta2, atributo1, atributo2);
    
    return 0;
}
