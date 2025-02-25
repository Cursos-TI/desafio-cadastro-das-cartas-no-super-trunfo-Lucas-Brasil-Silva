#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Estrutura 'Carta' que armazena os atributos de cada cidade.
typedef struct {
    char estado;
    char codigo_da_carta[3];
    char nome_da_cidade[20];
    unsigned int populacao;
    float area_em_km;
    float pib;
    int numero_de_pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder;
} Carta;

//Exibe a introdução do jogo, explicando as regras e o funcionamento.
 void introducao() {
    printf("Bem vindo ao jogo Super Trunfo!\n");
    printf("O Super Trunfo - Países é um jogo baseado no conceito do famoso jogo de cartas 'Super Trunfo'. Cada carta representa uma cidade de um estado e possui atributos como população, PIB, área e outros fatores. O objetivo é comparar esses atributos com os de outra carta e ver qual tem valores superiores.\n");
    printf("Os estados vão de 'A' a 'H', e cada cidade é numerada de 1 a 4.\n");
    printf("Exemplo de código da carta: A01, B02, C03.\n");
 }

//Solicita ao jogador que insira os dados de uma cidade, sendo eles Estado, Nome cidade, População, Área, PIB...
void coletar_informacoes(Carta *carta) {
    
    printf("\nDigite o estado (A-H):\n");
    scanf(" %c", &carta->estado);

    printf("Digite o código da carta:\n");
    scanf("%2s", carta->codigo_da_carta);

    printf("Digite o nome da cidade:\n");
    scanf(" %[^\n]", carta->nome_da_cidade);

    printf("Digite a população:\n");
    scanf("%u", &carta->populacao);

    printf("Digite a área em Km²:\n");
    scanf("%f", &carta->area_em_km);
    
    printf("Digite o PIB:\n");
    scanf("%f", &carta->pib);
    
    printf("Digite o número de pontos turísticos:\n");
    scanf("%d", &carta->numero_de_pontos_turisticos);
}

//Calcula as propriedades do estado, como a densidade populacional, o PIB per capita e o super poder.
void calcular_propriedades(Carta *carta) {

    carta->densidade_populacional = carta->populacao / carta->area_em_km;
    carta->pib_per_capita = ( carta->pib * 1e9 ) / carta->populacao;
    carta->super_poder = carta->populacao + carta->area_em_km + carta->pib_per_capita + carta->pib + carta->numero_de_pontos_turisticos - carta->densidade_populacional;
}

//Exibe as informmações da cidade inserida pelo jogador.
void exibir_resultados(Carta *carta) {

    printf("\nResultado da primeira sequência informada:\n");
    printf("Estado: %c\n", carta->estado);
    printf("Código da Carta: %c%s\n", carta->estado, carta->codigo_da_carta);
    printf("Nome da Cidade: %s\n", carta->nome_da_cidade);
    printf("População: %u\n", carta->populacao);
    printf("Área: %.2f Km²\n", carta->area_em_km);
    printf("PIB: %.2f bilhões de reais\n", carta->pib);
    printf("Número de Pontos Turísticos: %d\n", carta->numero_de_pontos_turisticos);
    printf("PIB per Capita: %.2f reais\n", carta->pib_per_capita);
    printf("Densidade Populacional: %.2f pessoas/Km²\n", carta->densidade_populacional);
    printf("Super Poder: %.2f\n", carta->super_poder);

}


//Compara a carta do jogador com uma carta adversária aleatória.
void comparar_cartas(const Carta *cartaJogador,const Carta cartasPadrao[], const int atributosEscolhido[]) {
    srand(time(NULL));
    int cartaAleatoria = rand() % 4;
    const Carta *cartaAdversaria = &cartasPadrao[cartaAleatoria];

    
    printf("\n");
    for (int i = 0; i < 2; i++) {
        switch (atributosEscolhido[i]) {
        case 1:
            printf("Carta %c%s - %s - População: %u\n", cartaJogador->estado, cartaJogador->codigo_da_carta, cartaJogador->nome_da_cidade, cartaJogador->populacao);
            printf("Carta %c%s - %s - População: %u\n", cartaAdversaria->estado, cartaAdversaria->codigo_da_carta, cartaAdversaria->nome_da_cidade, cartaAdversaria->populacao);
            if (cartaJogador->populacao == cartaAdversaria->populacao) {
                printf("Tivemos um Empate!!\n\n");
            } else if (cartaJogador->populacao > cartaAdversaria->populacao) {
                printf("Carta %c%s - %s - Venceu!!\n\n", cartaJogador->estado, cartaJogador->codigo_da_carta, cartaJogador->nome_da_cidade);
            } else {
                printf("Carta %c%s - %s - Venceu!!\n\n", cartaAdversaria->estado, cartaAdversaria->codigo_da_carta, cartaAdversaria->nome_da_cidade);
            }
            break;
        
        case 2:
            printf("Carta %c%s - %s - Área: %.2f\n", cartaJogador->estado, cartaJogador->codigo_da_carta, cartaJogador->nome_da_cidade, cartaJogador->area_em_km);
            printf("Carta %c%s - %s - Área: %.2f\n", cartaAdversaria->estado, cartaAdversaria->codigo_da_carta, cartaAdversaria->nome_da_cidade,cartaAdversaria->area_em_km);
            if (cartaJogador->area_em_km == cartaAdversaria->area_em_km) {
                printf("Tivemos um Empate!!\n\n");
            } else if (cartaJogador->area_em_km > cartaAdversaria->area_em_km) {
                printf("Carta %c%s - %s - Venceu!!\n\n", cartaJogador->estado, cartaJogador->codigo_da_carta, cartaJogador->nome_da_cidade);
            } else {
                printf("Carta %c%s - %s - Venceu!!\n\n", cartaAdversaria->estado, cartaAdversaria->codigo_da_carta, cartaAdversaria->nome_da_cidade);
            }
            break;

        case 3:
            printf("Carta %c%s - %s - PIB: %.2f\n", cartaJogador->estado, cartaJogador->codigo_da_carta, cartaJogador->nome_da_cidade, cartaJogador->pib);
            printf("Carta %c%s - %s - PIB: %.2f\n", cartaAdversaria->estado, cartaAdversaria->codigo_da_carta, cartaAdversaria->nome_da_cidade,cartaAdversaria->pib);
            if (cartaJogador->pib == cartaAdversaria->pib) {
                printf("Tivemos um Empate!!\n\n");
            } else if (cartaJogador->pib > cartaAdversaria->pib) {
                printf("Carta %c%s - %s - Venceu!!\n\n", cartaJogador->estado, cartaJogador->codigo_da_carta, cartaJogador->nome_da_cidade);
            } else {
                printf("Carta %c%s - %s - Venceu!!\n\n", cartaAdversaria->estado, cartaAdversaria->codigo_da_carta, cartaAdversaria->nome_da_cidade);
            }
            break;

        case 4:
            printf("Carta %c%s - %s - Números de pontos Turísticos: %d\n", cartaJogador->estado, cartaJogador->codigo_da_carta, cartaJogador->nome_da_cidade, cartaJogador->numero_de_pontos_turisticos);
            printf("Carta %c%s - %s - Números de pontos Turísticos: %d\n", cartaAdversaria->estado, cartaAdversaria->codigo_da_carta, cartaAdversaria->nome_da_cidade, cartaAdversaria->numero_de_pontos_turisticos);
            if (cartaJogador->numero_de_pontos_turisticos == cartaAdversaria->numero_de_pontos_turisticos) {
                printf("Tivemos um Empate!!\n\n");
            } else if (cartaJogador->numero_de_pontos_turisticos > cartaAdversaria->numero_de_pontos_turisticos) {
                printf("Carta %c%s - %s - Venceu!!\n\n", cartaJogador->estado, cartaJogador->codigo_da_carta, cartaJogador->nome_da_cidade);
            } else {
                printf("Carta %c%s - %s - Venceu!!\n\n", cartaAdversaria->estado, cartaAdversaria->codigo_da_carta, cartaAdversaria->nome_da_cidade);
            }
            break;

        case 5:
            printf("Carta %c%s - %s - PIB per Capita: %.2f\n", cartaJogador->estado, cartaJogador->codigo_da_carta, cartaJogador->nome_da_cidade, cartaJogador->pib_per_capita);
            printf("Carta %c%s - %s - PIB per Capita: %.2f\n", cartaAdversaria->estado, cartaAdversaria->codigo_da_carta, cartaAdversaria->nome_da_cidade, cartaAdversaria->pib_per_capita);
            if (cartaJogador->pib_per_capita == cartaAdversaria->pib_per_capita) {
                printf("Tivemos um Empate!!\n\n");
            } else if (cartaJogador->pib_per_capita > cartaAdversaria->pib_per_capita) {
                printf("Carta %c%s - %s - Venceu!!\n\n", cartaJogador->estado, cartaJogador->codigo_da_carta, cartaJogador->nome_da_cidade);
            } else {
                printf("Carta %c%s - %s - Venceu!!\n\n", cartaAdversaria->estado, cartaAdversaria->codigo_da_carta, cartaAdversaria->nome_da_cidade);
            }
            break;

        case 6:
            printf("Carta %c%s - %s - Densidade Populacional: %.2f\n", cartaJogador->estado, cartaJogador->codigo_da_carta, cartaJogador->nome_da_cidade,cartaJogador->densidade_populacional);
            printf("Carta %c%s - %s - Densidade Populacional: %.2f\n", cartaAdversaria->estado, cartaAdversaria->codigo_da_carta, cartaAdversaria->nome_da_cidade,cartaAdversaria->densidade_populacional);
            if (cartaJogador->densidade_populacional == cartaAdversaria->densidade_populacional) {
                printf("Tivemos um Empate!!\n\n");
            } else if (cartaJogador->densidade_populacional < cartaAdversaria->densidade_populacional) {
                printf("Carta %c%s - %s - Venceu!!\n\n",cartaJogador->estado, cartaJogador->codigo_da_carta, cartaJogador->nome_da_cidade);
            } else {
                printf("Carta %c%s - %s - Venceu!!\n\n",cartaAdversaria->estado, cartaAdversaria->codigo_da_carta, cartaAdversaria->nome_da_cidade);
            }
            break;
        
        case 7:
            printf("Carta %c%s - %s - Super Poder: %.2f\n", cartaJogador->estado, cartaJogador->codigo_da_carta, cartaJogador->nome_da_cidade, cartaJogador->super_poder);
            printf("Carta %c%s - %s - Super Poder: %.2f\n", cartaAdversaria->estado, cartaAdversaria->codigo_da_carta, cartaAdversaria->nome_da_cidade, cartaAdversaria->super_poder);
            if (cartaJogador->super_poder == cartaAdversaria->super_poder) {
                printf("Tivemos um Empate!!\n\n");
            } else if (cartaJogador->super_poder > cartaAdversaria->super_poder) {
                printf("Carta %c%s - %s - Venceu!!\n\n",cartaJogador->estado, cartaJogador->codigo_da_carta, cartaJogador->nome_da_cidade);
            } else {
                printf("Carta %c%s - %s - Venceu!!\n\n", cartaAdversaria->estado, cartaAdversaria->codigo_da_carta, cartaAdversaria->nome_da_cidade);
            }
            break;
        default:
            printf("Opção Invalida! Vamos tentar novamente.");
            break;
        }
    }
}

//Função principal que gerencia a ordem dos programas.
int main() {

    int opcaoInicial;
    int atributosEscolhido[2];
    
    //Declaração das estruturas de cartas do jogador e aleatórias do sistema.
    Carta cartaJogador;     
    Carta cartasPadrao[4] = {
        {'S', "01", "São Paulo", 12325232, 1521, 763, 4},
        {'R', "02", "Rio de Janeiro", 6775561, 1221, 366, 5},
        {'M', "03", "Belo Horizonte", 2530701, 331, 88, 3},
        {'P', "04", "Curitiba", 1963726, 435, 83, 6}};

    const char *listaAtributos[] = {"População","Área","PIB","Pontos Turísticos","PIB per Capita","Densidade Populacional","Super Poder"};

    //Menu interativo inicial, onde o jogador pode escolher entre iniciar o jogo ou sair.
    printf("\nVamos Jogar Super Trunfo - Países\n");
    printf("Escolha uma Opção:\n");
    printf("1. Introdução\n2. Jogar\n3. Sair\n");
    printf("Digite o número de uma das opções: ");
    scanf("%d", &opcaoInicial);

    switch (opcaoInicial) {
        case 1:
            introducao();
            break;

        case 2:
            coletar_informacoes(&cartaJogador);
            calcular_propriedades(&cartaJogador);
            exibir_resultados(&cartaJogador);

            for (int i = 0; i < 4; i++) {
                calcular_propriedades(&cartasPadrao[i]);
            }
            
            //Menu interativo para o jogador escolher, quais atributos irá comparar.
            printf("\nEscolha dois Atributo para comparar?\n");
            for (int i = 0; i < 2; i++) {
                
                printf("Escolha o %s atributo a ser comparado:\n", i == 0 ? "primeiro" : "segundo");
                
                for (int i = 0; i < 7; i++) {
                    if (atributosEscolhido[0] - 1 != i) {
                        printf("%d. %s\n",i + 1,listaAtributos[i]);
                    }
                }
                
                printf("Digíte o número do atributo: ");
                scanf("%d", &atributosEscolhido[i]);
            }

            comparar_cartas(&cartaJogador, cartasPadrao, atributosEscolhido);
            break;

        case 3:
            printf("Você saiu do Jogo!\nInicie o programa para jogar novamente.");
            break;
        
        default:
            printf("Opção Invalida. Por favor tente novamente!\n");
            break;
    }

    return 0;
}
