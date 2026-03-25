#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#define numcaixas 5   // Detalhes para o jogo Cobra na Caixa
#define numjogadores 7


int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    printf("\n\nMINI GAMES\n\n"); // Título do jogo

    int opcao1;

    while (1) {
        printf("Escolha um jogo:\n");
        printf("1 - Pergunta e Resposta\n");
        printf("2 - Cobra na Caixa!\n");
        printf("3 - Gousmas War\n");
        printf("4 - Sair\n");

        scanf("%d", &opcao1);

        if (opcao1 == 1) {
            char voltarMenu;
            do {
                printf("Pergunta e Resposta\n");
                printf("1 - Qual é a capital do Brasil?\n");
                printf("a) São Paulo\n");
                printf("b) Rio de Janeiro\n");
                printf("c) Brasília\n");
                printf("d) Salvador\n");

                char resposta;
                scanf(" %c", &resposta);

                if (resposta == 'a') {
                    printf("Resposta errada, a resposta correta era letra c) Brasília\n");
                } else if (resposta == 'b') {
                    printf("Resposta errada, a resposta correta era letra c) Brasília\n");
                } else if (resposta == 'c') {
                    printf("\nResposta correta!\n");
                } else if (resposta == 'd') {
                    printf("Resposta errada, a resposta correta era letra c) Brasília\n");
                } else {
                    printf("Opção inválida\n");
                }

                printf("\nDeseja voltar ao menu principal?\nSe sim digite 's', mas se quiser jogar novamente digite 'n'\n");
                scanf(" %c", &voltarMenu);

            } while (voltarMenu == 'n');

        } else if (opcao1 == 2) {
            char voltarMenu;
            do {
                int caixaEscolhida, caixaComCobra, caixaButao, turno;
                char personagem1[15], personagem2[15];

                srand(time(NULL));
                turno = rand() % 2;

                printf("\tVocê escolheu o jogo Cobra na Caixa\n");
                printf("O jogo consiste em você escolher uma caixa,\n");
                printf("caso apareça uma cobra você perde e o outro jogador ganha,\n");
                printf("se aparecer um botão você ganha e o outro perde,\n");
                printf("os jogadores jogam até encontrar uma das opções.\n\n");

                printf("Escolha 2 personagens:\n");
                printf("(1) Felipe\n");
                printf("(2) Pedro\n");
                printf("(3) Henrique\n");
                printf("(4) Antonio\n");
                printf("(5) Barbara\n");
                printf("(6) Laura\n");
                printf("(7) Bruno\n");

                printf("Jogador 1: ");
                scanf("%s", personagem1);
                printf("Jogador 2: ");
                scanf("%s", personagem2);

                printf("Os personagens escolhidos foram %s e %s.\n", personagem1, personagem2);

                while (1) {
                    do {
                        caixaButao = rand() % numcaixas + 1;
                        caixaComCobra = rand() % numcaixas + 1;
                    } while (caixaButao == caixaComCobra);

                    printf("%s, escolha uma caixa de 1 a 5: ", turno == 0 ? personagem1 : personagem2);
                    scanf("%d", &caixaEscolhida);

                    if (caixaEscolhida < 1 || caixaEscolhida > 5) {
                        printf("Escolha inválida! Por favor, escolha um número entre 1 e 5.\n");
                        continue;
                    }

                    if (caixaEscolhida == caixaComCobra) {
                        printf("Você achou a cobra! PERDEEEEU!\n");
                        break;
                    } else if (caixaEscolhida == caixaButao) {
                        printf("Você achou o botão! WINNER!\n");
                        break;
                    } else {
                        printf("Caixa vazia. Tente novamente.\n");
                    }

                    turno = 1 - turno;
                }

                printf("\nDeseja voltar ao menu principal?\nSe sim digite 's', mas se quiser jogar novamente digite 'n'\n");
                scanf(" %c", &voltarMenu);

            } while (voltarMenu == 'n');

        } else if (opcao1 == 3) {
            char voltarMenu;
            do {
                

                printf("\nDeseja voltar ao menu principal? (s/n): ");
                scanf(" %c", &voltarMenu);
            } while (voltarMenu == 'n');

        } else if (opcao1 == 4) {
            printf("\nAté a próxima jogatina!\n\n");
            break;

        } else {
            printf("Opção inválida\n");
        }
    }

    return 0;
}