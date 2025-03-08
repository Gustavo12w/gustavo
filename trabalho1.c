#include <stdio.h>
#include <string.h>

typedef struct {
    char estado[50];
    char codigo[20];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int num_turismo;
} Carta;

float calcular_densidade_populacional(Carta carta) {
    return carta.populacao / carta.area;
}

float calcular_pib_per_capita(Carta carta) {
    return carta.pib / carta.populacao;
}

void comparar_cartas(Carta carta1, Carta carta2, const char* atributo) {
    float atributo_carta1 = 0, atributo_carta2 = 0;

    if (strcmp(atributo, "População") == 0) {
        atributo_carta1 = carta1.populacao;
        atributo_carta2 = carta2.populacao;
        printf("Comparação de cartas (Atributo: População):\n");
    } else if (strcmp(atributo, "Área") == 0) {
        atributo_carta1 = carta1.area;
        atributo_carta2 = carta2.area;
        printf("Comparação de cartas (Atributo: Área):\n");
    } else if (strcmp(atributo, "PIB") == 0) {
        atributo_carta1 = carta1.pib;
        atributo_carta2 = carta2.pib;
        printf("Comparação de cartas (Atributo: PIB):\n");
    } else if (strcmp(atributo, "Densidade Populacional") == 0) {
        atributo_carta1 = calcular_densidade_populacional(carta1);
        atributo_carta2 = calcular_densidade_populacional(carta2);
        printf("Comparação de cartas (Atributo: Densidade Populacional):\n");
    } else if (strcmp(atributo, "PIB per capita") == 0) {
        atributo_carta1 = calcular_pib_per_capita(carta1);
        atributo_carta2 = calcular_pib_per_capita(carta2);
        printf("Comparação de cartas (Atributo: PIB per capita):\n");
    }


    printf("Carta 1 - %s (%s): %.2f\n", carta1.cidade, carta1.estado, atributo_carta1);
    printf("Carta 2 - %s (%s): %.2f\n", carta2.cidade, carta2.estado, atributo_carta2);

   
    if (strcmp(atributo, "Densidade Populacional") == 0) {
      
        if (atributo_carta1 < atributo_carta2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
        } else if (atributo_carta1 > atributo_carta2) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    } else {
    
        if (atributo_carta1 > atributo_carta2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
        } else if (atributo_carta1 < atributo_carta2) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
        } else {
            printf("Resultado: Empate!\n");
        }
    }
}

int main() {
   
    Carta carta1 = {
        "São Paulo",
        "SP01",
        "São Paulo",
        12300000,  // População
        1521.11,   // Área
        694000000, // PIB
        400        // Número de pontos turísticos
    };

    Carta carta2 = {
        "Rio de Janeiro",
        "RJ01",
        "Rio de Janeiro",
        6000000,   // População
        1182.30,   // Área
        700000000, // PIB
        300        // Número de pontos turísticos
    };

    const char* atributo = "População";  

    
    comparar_cartas(carta1, carta2, atributo);

    return 0;
}
