#include <stdio.h>

// Definindo estrutura para carta
typedef struct {
    char nome[50];
    int forca;
    int velocidade;
    int inteligencia;
} Carta;

// Função de comparação simples - nível 1
void compararAtributoSimples(Carta c1, Carta c2, int atributo) {
    printf("\nResultado da comparação:\n");
    if (atributo == 1) {
        if (c1.forca > c2.forca)
            printf("%s venceu com Força!\n", c1.nome);
        else if (c1.forca < c2.forca)
            printf("%s venceu com Força!\n", c2.nome);
        else
            printf("Empate em Força!\n");
    } else if (atributo == 2) {
        if (c1.velocidade > c2.velocidade)
            printf("%s venceu com Velocidade!\n", c1.nome);
        else if (c1.velocidade < c2.velocidade)
            printf("%s venceu com Velocidade!\n", c2.nome);
        else
            printf("Empate em Velocidade!\n");
    } else if (atributo == 3) {
        if (c1.inteligencia > c2.inteligencia)
            printf("%s venceu com Inteligência!\n", c1.nome);
        else if (c1.inteligencia < c2.inteligencia)
            printf("%s venceu com Inteligência!\n", c2.nome);
        else
            printf("Empate em Inteligência!\n");
    } else {
        printf("Atributo inválido!\n");
    }
}

// Nível 2 - comparação com estruturas encadeadas + switch
void menuComparacao(Carta c1, Carta c2) {
    int escolha;
    printf("\nEscolha um atributo para comparar:\n");
    printf("1. Força\n");
    printf("2. Velocidade\n");
    printf("3. Inteligência\n");
    printf("Escolha: ");
    scanf("%d", &escolha);

    switch (escolha) {
        case 1:
        case 2:
        case 3:
            compararAtributoSimples(c1, c2, escolha);
            break;
        default:
            printf("Opção inválida!\n");
            break;
    }
}

// Nível 3 - comparação de dois atributos com operador ternário
void compararDoisAtributos(Carta c1, Carta c2, int a1, int a2) {
    int soma1 = 0, soma2 = 0;

    // Primeiro atributo
    soma1 += (a1 == 1) ? c1.forca : (a1 == 2) ? c1.velocidade : c1.inteligencia;
    soma2 += (a1 == 1) ? c2.forca : (a1 == 2) ? c2.velocidade : c2.inteligencia;

    // Segundo atributo
    soma1 += (a2 == 1) ? c1.forca : (a2 == 2) ? c1.velocidade : c1.inteligencia;
    soma2 += (a2 == 1) ? c2.forca : (a2 == 2) ? c2.velocidade : c2.inteligencia;

    printf("\nResultado da comparação dupla:\n");
    if (soma1 > soma2)
        printf("%s venceu com soma dos atributos!\n", c1.nome);
    else if (soma1 < soma2)
        printf("%s venceu com soma dos atributos!\n", c2.nome);
    else
        printf("Empate na soma dos atributos!\n");
}

int main() {
    Carta carta1 = {"Dragão Flamejante", 90, 70, 60};
    Carta carta2 = {"Cavaleiro Sombrio", 80, 75, 85};

    int opcao;
    do {
        printf("\n--- SUPER TRUNFO DIGITAL ---\n");
        printf("1. Comparar um único atributo\n");
        printf("2. Comparar dois atributos\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            menuComparacao(carta1, carta2);
        } else if (opcao == 2) {
            int atr1, atr2;
            printf("Escolha o primeiro atributo (1-Força, 2-Velocidade, 3-Inteligência): ");
            scanf("%d", &atr1);
            printf("Escolha o segundo atributo (1-Força, 2-Velocidade, 3-Inteligência): ");
            scanf("%d", &atr2);
            compararDoisAtributos(carta1, carta2, atr1, atr2);
        } else if (opcao != 0) {
            printf("Opção inválida!\n");
        }

    } while (opcao != 0);

    printf("Obrigado por jogar Super Trunfo!\n");
    return 0;
}