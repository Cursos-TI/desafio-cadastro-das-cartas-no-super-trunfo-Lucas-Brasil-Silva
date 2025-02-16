#include <stdio.h>

//Exibe a introdução do jogo, explicando as regras e o funcionamento.
 void introducao() {
    printf("Bem vindo ao jogo Super Trunfo!\n");
    printf("Nesse jogo com o tema Países, as cartas serão divididas por estados, com cada estado tendo quatro cartas que representam diferentes cidades.\n");
    printf("Cada país será dividido em oito estados, identificados pelas letras de A a H.\n");
    printf("Cada estado terá quatro cidades, numeradas de 1 a 4.\n");
    printf("A combinação da letra do estado e o número da cidade define o código da carta (por exemplo, A01, A02, B01, B02).\n\n");
    printf("Vamos Jogar!!!\n\n");
 }

//Coleta as informações do usuário, como o estado, o código da carta, o nome da cidade, a população, a área em Km², o PIB e o número de pontos turísticos.
void coletar_informacoes(char *estado, char codigo_da_carta[3], char nome_da_cidade[20], int *populacao, double *area_em_km, double *pib, int *numero_de_pontos_turisticos) {
    
    printf("Digite o estado em maiúsculo:\n");
    scanf(" %c", estado);

    printf("Digite o código da carta:\n");
    scanf("%2s", codigo_da_carta);

    printf("Digite o nome da cidade:\n");
    scanf(" %[^\n]", nome_da_cidade);

    printf("Digite a população:\n");
    scanf("%d", populacao);

    printf("Digite a área em Km²:\n");
    scanf("%lf", area_em_km);
    
    printf("Digite o PIB:\n");
    scanf("%lf", pib);
    
    printf("Digite o número de pontos turísticos:\n");
    scanf("%d", numero_de_pontos_turisticos);
}

//Calcula as propriedades do estado, como a densidade populacional, o PIB per capita e o super poder.
void calcular_propriedades(int *populacao, double *area_em_km, double *pib_per_capita, double *pib, double *densidade_populacional, double *super_poder, int *numero_de_pontos_turisticos) {

    *densidade_populacional = *populacao / *area_em_km;
    *pib_per_capita = ( *pib * 1000000000 ) / *populacao;
    *super_poder = *populacao + *pib + *area_em_km + *pib_per_capita + *densidade_populacional + *numero_de_pontos_turisticos;
}

//Exibe os resultados informado para o jogador.
void exibir_resultados(char *estado, char codigo_da_carta[3], char nome_da_cidade[20], int *populacao, double *area_em_km, double *pib, int *numero_de_pontos_turisticos, double *densidade_populacional, double *pib_per_capita, double *super_poder) {

    printf("\nResultado da primeira sequência informada:\n");
    printf("Estado: %c\n", *estado);
    printf("Código da Carta: %c%s\n", *estado, codigo_da_carta);
    printf("Nome da Cidade: %s\n", nome_da_cidade);
    printf("População: %d\n", *populacao);
    printf("Área: %.2lf Km²\n", *area_em_km);
    printf("Densidade Populacional: %.2lf pessoas/Km²\n", *densidade_populacional);
    printf("PIB: %.2lf bilhões de reais\n", *pib);
    printf("PIB per Capita: %.2lf reais\n", *pib_per_capita);
    printf("Número de Pontos Turísticos: %d\n", *numero_de_pontos_turisticos);
    printf("Super Poder: %.2lf\n", *super_poder);

}


int main() {
    
    // Variáveis de entrada
    char estado;
    char codigo_da_carta[3];
    char nome_da_cidade[20];
    int populacao;
    double area_em_km;
    double pib;
    int numero_de_pontos_turisticos;
    
    // Variáveis calculadas
    double densidade_populacional;
    double pib_per_capita;
    double super_poder;

    //Exibe a introdução do jogo
    introducao();
    
    //Coleta as informações do usuário
    coletar_informacoes(&estado, codigo_da_carta, nome_da_cidade, &populacao, &area_em_km, &pib, &numero_de_pontos_turisticos);

    //Calcula as propriedades do estado
    calcular_propriedades(&populacao, &area_em_km, &pib_per_capita, &pib, &densidade_populacional, &super_poder, &numero_de_pontos_turisticos);

    //Exibe os resultados o resultado informado
    exibir_resultados(&estado, codigo_da_carta, nome_da_cidade, &populacao, &area_em_km, &pib, &numero_de_pontos_turisticos, &densidade_populacional, &pib_per_capita, &super_poder);


    return 0;
}
//conclusão_parcial_desafio_mestre_lucas_brasil