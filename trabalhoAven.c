#include <iostream>
#include <string>

using namespace std;

struct Carta {
    string nome;
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
};

void compararCartas(Carta c1, Carta c2, int opcao) {
    cout << "\nComparando: " << c1.nome << " vs " << c2.nome << "\n";
    switch (opcao) {
        case 1:
            cout << "Atributo: População\n";
            cout << c1.nome << ": " << c1.populacao << " habitantes\n";
            cout << c2.nome << ": " << c2.populacao << " habitantes\n";
            if (c1.populacao > c2.populacao) cout << c1.nome << " venceu!\n";
            else if (c1.populacao < c2.populacao) cout << c2.nome << " venceu!\n";
            else cout << "Empate!\n";
            break;
        case 2:
            cout << "Atributo: Área\n";
            cout << c1.nome << ": " << c1.area << " km²\n";
            cout << c2.nome << ": " << c2.area << " km²\n";
            if (c1.area > c2.area) cout << c1.nome << " venceu!\n";
            else if (c1.area < c2.area) cout << c2.nome << " venceu!\n";
            else cout << "Empate!\n";
            break;
        case 3:
            cout << "Atributo: PIB\n";
            cout << c1.nome << ": " << c1.pib << " trilhões USD\n";
            cout << c2.nome << ": " << c2.pib << " trilhões USD\n";
            if (c1.pib > c2.pib) cout << c1.nome << " venceu!\n";
            else if (c1.pib < c2.pib) cout << c2.nome << " venceu!\n";
            else cout << "Empate!\n";
            break;
        case 4:
            cout << "Atributo: Pontos Turísticos\n";
            cout << c1.nome << ": " << c1.pontosTuristicos << " locais\n";
            cout << c2.nome << ": " << c2.pontosTuristicos << " locais\n";
            if (c1.pontosTuristicos > c2.pontosTuristicos) cout << c1.nome << " venceu!\n";
            else if (c1.pontosTuristicos < c2.pontosTuristicos) cout << c2.nome << " venceu!\n";
            else cout << "Empate!\n";
            break;
        case 5:
            cout << "Atributo: Densidade Demográfica\n";
            cout << c1.nome << ": " << c1.densidadeDemografica << " hab/km²\n";
            cout << c2.nome << ": " << c2.densidadeDemografica << " hab/km²\n";
            if (c1.densidadeDemografica < c2.densidadeDemografica) cout << c1.nome << " venceu!\n";
            else if (c1.densidadeDemografica > c2.densidadeDemografica) cout << c2.nome << " venceu!\n";
            else cout << "Empate!\n";
            break;
        default:
            cout << "Opção inválida!\n";
    }
}

int main() {
    Carta carta1 = {"Brasil", 214000000, 8515767, 1.84, 30, 25.1};
    Carta carta2 = {"França", 67000000, 551695, 2.78, 45, 121.4};

    int escolha;
    do {
        cout << "\nEscolha o atributo para comparação:\n";
        cout << "1 - População\n";
        cout << "2 - Área\n";
        cout << "3 - PIB\n";
        cout << "4 - Pontos Turísticos\n";
        cout << "5 - Densidade Demográfica\n";
        cout << "0 - Sair\n";
        cout << "Opção: ";
        cin >> escolha;

        if (escolha != 0) compararCartas(carta1, carta2, escolha);
    } while (escolha != 0);

    cout << "Jogo encerrado!\n";
    return 0;
}
