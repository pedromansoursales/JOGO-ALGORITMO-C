#include <string.h>
#include <locale.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define numcaixas 5 // Detalhes para o jogo Cobra na Caixa
#define numjogadores 7


#define MAX_GOUSMAS 2
#define FURY_LIMIT 5

typedef struct {
	int fury;
	bool alive;
} Gousma;

typedef struct {
	Gousma gousmas[MAX_GOUSMAS];
} Player;

                                    // Inicializa cada jogador com duas Gousmas com furia 1
void initializePlayer(Player *player) {
	for (int i = 0; i < MAX_GOUSMAS; i++) {
		player->gousmas[i].fury = 1;
		player->gousmas[i].alive = true;
	}
}

                                    // Verifica se o jogador possui alguma Gousma ativa
bool hasGousma(Player *player) {
	for (int i = 0; i < MAX_GOUSMAS; i++) {
		if (player->gousmas[i].alive) return true;
	}
	return false;
}

                                    // Ataca uma Gousma alvo com a furia de uma Gousma atacante.
void attack(Gousma *attacker, Gousma *target) {
	if (!attacker->alive || !target->alive) return;

	target->fury += attacker->fury;     // Soma a furia do atacante com a  do alvo

	if (target->fury > FURY_LIMIT) {
		target->alive = false;
		target->fury = 0;
	}
}

                            // Permite dividir a furia entre duas Gousmas do mesmo jogador.
                            // O jogador escolhe qual gousma  doadora e qual a receptora.
                            // Se a doadora tiver pelo menos 2 de furia, transfere metade (divisão inteira) para a receptora.
                            // Se a receptora estiver desintegrada, ela é "revivida" com o valor transferido.
void splitGousma(Player *player) {
	int donorChoice, receiverChoice;
	printf("Escolha a Gousma doadora (1 ou 2): ");
	scanf("%d", &donorChoice);
	printf("Escolha a Gousma receptora (1 ou 2): ");
	scanf("%d", &receiverChoice);

	if (donorChoice < 1 || donorChoice> MAX_GOUSMAS ||
	        receiverChoice < 1 || receiverChoice> MAX_GOUSMAS) {
		printf("Escolha inválida!\n");
		return;
	}

	if (donorChoice == receiverChoice) {
		printf("Escolha gousmas diferentes para divisão!\n");
		return;
	}

	Gousma *donor = &player->gousmas[donorChoice - 1];
	Gousma *receiver = &player->gousmas[receiverChoice - 1];

	if (!donor->alive || donor->fury < 2) {
		printf("Gousma doadora inválida ou furia insuficiente para dividir!\n");
		return;
	}
	int transfer=donor->fury / 2;
	donor->fury -= transfer;

	if (!receiver->alive) {
		// Revive a gousma receptora com o valor transferido.
		receiver->alive = true;
		receiver->fury = transfer;
	} else {
		receiver->fury += transfer;
	}

	// Se, após a divisão, a receptora ultrapassar o limite, ela se desintegra.
	if (receiver->fury > FURY_LIMIT) {
		receiver->alive = false;
		receiver->fury = 0;
	}

	// Se a doadora ficar com 5 de furia, ela se desintegra.
	if (donor->fury == 0) {
		donor->alive = false;
	}
}

// Exibe o status atual das Gousmas de cada jogador.
void displayStatus(Player *player1, Player *player2) {
	printf("\nStatus:\n");
	for (int i = 0; i < MAX_GOUSMAS; i++) {
		printf("Jogador 1 - Gousma %d: Furia=%d, %s\n", i + 1, player1->gousmas[i].fury,
		       player1->gousmas[i].alive ? "Viva" : "Desintegrada");
		printf("Jogador 2 - Gousma %d: Furia=%d, %s\n", i + 1,
		       player2->gousmas[i].fury,
		       player2->gousmas[i].alive ? "Viva" : "Desintegrada");
	}
	printf("\n");
}


int main() {
	setlocale(LC_ALL, "Portuguese_Brazil");

    printf("-----------");
	printf("\n\nMINI GAMES\n\n"); // titulo do jogo
    printf("-----------\n\n");
	int opcao1;

	while (1) {         //jogo 1 pergunta e resposta
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
				printf("1 - Qual a capital do Brasil?\n");
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

                printf("Pergunta e Resposta\n");
                printf("2 - Quantas Copas do Mundo de Futebol a seleção brasileira já ganhou?\n");
                printf ("a) 5\n");
                printf ("b) 4\n");
                printf ("c) 6\n");
                printf ("d) 7\n");
            
                char resposta2;
                scanf(" %c", &resposta2); 

                if (resposta2 == 'a'){
                    printf("\nResposta correta!\n");
                }
                else if (resposta2 == 'b'){
                    printf("Resposta errada, a resposta correta era letra a) 5\n");
                }
                else if (resposta2 == 'c'){
                    printf("Resposta errada, a resposta correta era letra a) 5\n");
                }
                else if (resposta2 == 'd'){
                    printf("Resposta errada, a resposta correta era letra a) 5\n");
                }
                else {
                    printf("Opção inválida\n");
                }

                printf("Pergunta e Resposta\n");
                printf("3 - Qual é o maior planeta do sistema solar?\n");
                printf ("a) Terra\n");
                printf ("b) Marte\n");
                printf ("c) Júpiter\n");
                printf ("d) Saturno\n");
                
                char resposta3;
                scanf(" %c", &resposta3); 

                if (resposta3 == 'a'){
                    printf("Resposta errada, a resposta correta era letra c) Júpiter\n");
                }
                else if (resposta3 == 'b'){
                    printf("Resposta errada, a resposta correta era letra c) Júpiter\n");
                }
                else if (resposta3 == 'c'){
                    printf("\nResposta correta!\n");
                }
                else if (resposta3 == 'd'){
                    printf("Resposta errada, a resposta correta era letra c) Júpiter\n");
                }
                else {
                    printf("Opção inválida\n");
                }
            
                printf("Pergunta e Resposta\n");
                printf("4 - Qual o jogo mais vendido do mundo?\n");
                printf ("a) GTA5\n");
                printf ("b) Minecraft\n");
                printf ("c) Mario kart 8\n");
                printf ("d) The last of us part II\n");
                
                char resposta4;
                scanf(" %c",&resposta4); 

                if (resposta4 == 'a'){
                    printf("Resposta errada, a resposta correta era letra b) Minecraft\n");
                }
                else if (resposta4 == 'b'){
                    printf("\nResposta correta!\n");
                }
                else if (resposta4 == 'c'){
                    printf("Resposta errada, a resposta correta era letra b) Minecraft\n");
                }
                else if (resposta4 == 'd'){
                    printf("Resposta errada, a resposta correta era letra b) Minecraft\n");
                }
                else {
                    printf("Opção inválida\n");
                }
            
                printf("Pergunta e Resposta\n");
                printf("5 - qual foi o primeiro FPS que ficou famoso? \n");
                printf ("a) Counter Strike\n");
                printf ("b) doom\n");
                printf ("c) call of duty\n");
                printf ("d) Wolfenstein 3D\n");
                
                char resposta5;
                scanf(" %c",&resposta5); 

                if (resposta5 == 'a'){
                    printf("Resposta errada, a resposta correta era letra d) Wolfenstein 3D\n");
                }
                else if (resposta5 == 'b'){
                    printf("Resposta errada, a resposta correta era letra d) Wolfenstein 3D\n");
                }
                else if (resposta5 == 'c'){
                    printf("Resposta errada, a resposta correta era letra d) Wolfenstein 3D\n");
                }
                else if (resposta5 == 'd'){
                    printf("\nResposta correta!\n");
                }
                else {
                    printf("Opção inválida\n");
                }
            
                if (resposta == 'c' && resposta2 == 'a' && resposta3 == 'c' && resposta4 == 'b' && resposta5 == 'd'){
                    printf("\nParabéns, você acertou todas as perguntas!\n");
                } else {
                    printf("\nVocê errou alguma pergunta, tente novamente!\n");
                }

				printf("\nDeseja voltar ao menu principal?\nSe sim digite 's', mas se quiser jogar novamente digite 'n'\n");
				scanf(" %c", &voltarMenu);

			} while (voltarMenu == 'n');

		} else if (opcao1 == 2) {
			char voltarMenu;
			do {
				int caixaEscolhida, caixaComCobra, caixaBotao, turno;
				char personagem1[15], personagem2[15];

				srand(time(NULL));
				turno = rand() % 2;

				printf("\tVocê escolheu o jogo Cobra na Caixa\n");
				printf("O jogo consiste em você escolher uma caixa,\n");
				printf("caso apareça a uma cobra você perde e o outro jogador ganha,\n");
				printf("se aparecer um botão você ganha e o outro perde,\n");
				printf("os jogadores jogam até encontrar uma das opções.\n\n");

				printf("Escolha 2 personagens:\n");
				printf("(1) Felipe\n");
				printf("(2) Pedro\n");
				printf("(3) Henrique\n");
				printf("(4) Antonio\n");
				printf("(5) Barbara\n");
				printf("(6) Girotto\n");
				printf("(7) Bruno\n");

				printf("Jogador 1: ");
				scanf("%s", personagem1);
				printf("Jogador 2: ");
				scanf("%s", personagem2);

				printf("Os personagens escolhidos foram %s e %s.\n", personagem1, personagem2);

				while (1) {
					do {
						caixaBotao = rand() % numcaixas + 1;
						caixaComCobra = rand() % numcaixas + 1;
					} while (caixaBotao == caixaComCobra);

					printf("%s, escolha uma caixa de 1 a 5: ", turno == 0 ? personagem1 : personagem2);
					scanf("%d", &caixaEscolhida);

					if (caixaEscolhida < 1 || caixaEscolhida> 5) {
						printf("Escolha inválida! Por favor, escolha um número entre 1 e 5.\n");
						continue;
					}

					if (caixaEscolhida == caixaComCobra) {
						printf("Você achou a cobra! PERDEEEEU!\n");
						break;
					} else if (caixaEscolhida == caixaBotao) {
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
				printf("Gousmas War\n");
				printf("É um jogo de estrategia onde os jogadores controlam criaturas chamadas gousmas que podem atacar, se dividir e acumular furia a serem atacadas\n");

				Player player1, player2;
				initializePlayer(&player1);
				initializePlayer(&player2);

				int turn = 1;

				while (hasGousma(&player1) && hasGousma(&player2)) {
					displayStatus(&player1, &player2);
					printf("Turno do Jogador %d\n", turn);
					printf("Escolha a ação:\n1 - Atacar\n2 - Dividir\nEscolha: ");
					int choice;
					scanf("%d", &choice);

					Player *currentPlayer = (turn == 1) ? &player1 : &player2;
					Player *opponent = (turn == 1) ? &player2 : &player1;

					if (choice == 1) {
						int attackerChoice, targetChoice;
						printf("Escolha sua Gousma (1 ou 2): ");
						scanf("%d", &attackerChoice);
						printf("Escolha a Gousma do oponente (1 ou 2): ");
						scanf("%d", &targetChoice);

						if (attackerChoice < 1 || attackerChoice> MAX_GOUSMAS ||
						        targetChoice < 1 || targetChoice> MAX_GOUSMAS) {
							printf("Escolha inválida!\n");
						} else {
							attack(&currentPlayer->gousmas[attackerChoice - 1],
							       &opponent->gousmas[targetChoice - 1]);
						}
					} else if (choice == 2) {
						splitGousma(currentPlayer);
					} else {
						printf("Opção inválida!\n");
					}

					// Alterna o turno entre os jogadores.
					turn = (turn == 1) ? 2 : 1;
				}

				printf("Jogador %d venceu!\n", hasGousma(&player1) ? 1 : 2);




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
