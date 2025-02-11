#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
//Teste larissa

int main() {
    
    char estado;
    char codigo_da_carta[3];
    char nome_da_cidade[20];
    int populacao;
    float area_em_km;
    float pib;
    int numero_de_pontos_turisticos;

    printf("Bem vindo ao jogo Super Trunfo!\n");
    printf("Nesse jogo com o tema Países, as cartas serão divididas por estados, com cada estado tendo quatro cartas que representam diferentes cidades.\n");
    printf("Cada país será dividido em oito estados, identificados pelas letras de A a H.\n");
    printf("Cada estado terá quatro cidades, numeradas de 1 a 4.\n");
    printf("A combinação da letra do estado e o número da cidade define o código da carta (por exemplo, A01, A02, B01, B02).\n\n");
    printf("Vamos Jogar!!!\n\n");
    
    printf("Digite o estado em maiúsculo:\n");
    scanf("%c", &estado);

    printf("Digite o código da carta:\n");
    scanf("%2s", codigo_da_carta);

    printf("Digite o nome da cidade:\n");
    scanf(" %[^\n]", nome_da_cidade);

    printf("Digite a população:\n");
    scanf("%d", &populacao);

    printf("Digite a área em Km²:\n");
    scanf("%f", &area_em_km);
    
    printf("Digite o PIB:\n");
    scanf("%f", &pib);
    
    printf("Digite o número de pontos turísticos:\n");
    scanf("%d", &numero_de_pontos_turisticos);

    printf("\nResultado da primeira sequência informada:\n");
    printf("Estado: %c\n", estado);
    printf("Código da Carta: %c%s\n", estado, codigo_da_carta);
    printf("Nome da Cidade: %s\n", nome_da_cidade);
    printf("População: %d\n", populacao);
    printf("Área: %.2f Km²\n", area_em_km);
    printf("PIB: %.2f bilhões de reais\n", pib);
    printf("Número de Pontos Turísticos: %d\n", numero_de_pontos_turisticos);

    return 0;
}
