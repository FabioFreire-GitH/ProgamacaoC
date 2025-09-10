#include <stdio.h>

int main (){

    /* Abaixo inclui as variaveis das cartas 1 e 2 do jogo super trunfo */
    char estado1, estado2; 
    char codigo1[4], codigo2[4];
    char cidade1[20], cidade2[20];
    unsigned long int populacao1, populacao2;  //Utilizarei o unsigned long int, pois abrange numeros grandes (epscificador de formato %lu)
    float area1, area2;
    float pib1, pib2;
    int atracoes1, atracoes2; //variaveis de pontos turisticos
    float dp1, dp2; // Densidade populacional
    float pibpc1, pibpc2; // PIB per capita
    double superPoder1, superPoder2; // Variaveis que irão armazenar o valor do super poder de cada carta
    int opcao; //variavel para o menu de opcoes

    /*Abaixo será inserido as informacoes da carta 1*/
    printf("|Insira das infomações da Carta 1|\n\n");
    printf("Insira a Letra do Estado (A ate H): ");
    scanf(" %c", &estado1);
    printf("Insira um codigo (01-04): ");
    scanf("%s", codigo1);
    printf("Insira o nome da Cidade: ");
    scanf(" %19[^\n]", cidade1);
    printf("População: ");
    scanf("%lu", &populacao1);
    printf("Área em km2: ");
    scanf("%f", &area1);
    printf("PIB: ");
    scanf("%f", &pib1);
    printf("Quantidade de Pontos Turisticos: ");
    scanf("%d", &atracoes1);
    dp1 = (float)(populacao1/area1);
    pibpc1 = (float)(pib1/populacao1);
    superPoder1 = (double)(populacao1 + area1 + pib1 + atracoes1 + (1 / dp1) + pibpc1); //Cálculo do super poder da carta 1
  
     /*Abaixo será inserido as informacoes da carta 2*/
    printf("|Insira das infomações da Carta 2|\n\n");
    printf("Insira a Letra do Estado (A ate H): ");
    scanf(" %c", &estado2);
    printf("Insira um codigo (01-04): ");
    scanf("%s", codigo2);
    printf("Insira o nome da Cidade: ");
    scanf(" %19[^\n]", cidade2);
    printf("População: ");
    scanf("%lu", &populacao2);
    printf("Área em km2: ");
    scanf("%f", &area2);
    printf("PIB: ");
    scanf("%f", &pib2);
    printf("Quantidade de Pontos Turisticos: ");
    scanf("%d", &atracoes2);
    dp2 = (float)(populacao2/area2);
    pibpc2 = (float)(pib2/populacao2);
    superPoder2 = (double)(populacao2 + area2 + pib2 + atracoes2 + (1 / dp2) + pibpc2); //Cálculo do super poder da carta 2

    /*Abaixo será exibido as informacoes inseridas da carta 1*/
    printf(" ___________________________________\n");
    printf("|             CARTA 1               \n");
    printf("|Codido da carta: %c%s              \n", estado1,codigo1);//nao entendi uma forma de melhorar
    printf("|Cidade: %s                         \n", cidade1);
    printf("|1)População: %lu                     \n", populacao1);
    printf("|2)Área: %.2f km2                     \n", area1);
    printf("|3)PIB: %.2f                          \n", pib1);
    printf("|4)Pontos turisticos: %d              \n", atracoes1);
    printf("|5)Densidade Populacional: %.2f hab/km2\n", dp1);
    printf("|6)PIB per capita: %.2f reais         \n", pibpc1);
    printf("|7)Super Poder: %.2f                   \n", superPoder1); //Exibição do super poder da carta 1 
    printf("|___________________________________\n");
    printf("\n");
           
    /*Abaixo será exibido as informacoes inseridas da carta 2*/
    printf(" ___________________________________\n");
    printf("|             CARTA 2               \n");
    printf("|Codido da carta: %c%s              \n", estado2,codigo2);
    printf("|Cidade: %s                         \n", cidade2);
    printf("|1)População: %lu                     \n", populacao2);
    printf("|2)Área: %.2f km2                     \n", area2);
    printf("|3)PIB: %.2f                          \n", pib2);
    printf("|4)Pontos turisticos: %d              \n", atracoes2);
    printf("|5)Densidade Populacional: %.2f hab/km2\n", dp2);
    printf("|6)PIB per capita: %.2f reais         \n", pibpc2);
    printf("|7)Super Poder: %.2f                   \n", superPoder2); //Exibição do super poder da carta 2
    printf("|___________________________________\n");
    printf("\n");

    printf("Compara vencedor\n");
    printf("Escolha uma atributo da carta (1 a 7):\n");
    scanf("%d", &opcao);
    
    if (opcao == 1){
        printf("Comparação de cartas (atributo: População)\n");
        printf("Carta 1 - %s: %lu habitantes\n", cidade1, populacao1);
        printf("Carta 2 - %s: %lu habitantes\n", cidade2, populacao2);
        if (populacao1 > populacao2){
            printf("Resultado: Carta 1 %s venceu!\n", cidade1);
        } else if (populacao2 > populacao1){
            printf("Resultado: Carta 2 %s venceu!\n", cidade2);
        } else {
            printf("Empate! Ambas as cartas possuem %lu habitantes\n", populacao1);
        }
    } else if (opcao == 2){
        printf("Comparação de cartas (atributo: Área)\n");
        printf("Carta 1 - %s: %.2f km2\n", cidade1, area1);
        printf("Carta 2 - %s: %.2f km2\n", cidade2, area2);
        if (area1 > area2){
            printf("Resultado: Carta 1 %s venceu!\n", cidade1);
        } else if (area2 > area1){
            printf("Resultado: Carta 2 %s venceu!\n", cidade2);
        } else {
            printf("Empate! Ambas as cartas possuem %.2f km2\n", area1);
        }
    } else if (opcao == 3){
        printf("Comparação de cartas (atributo: PIB)\n");
        printf("Carta 1 - %s: %.2f\n", cidade1, pib1);
        printf("Carta 2 - %s: %.2f\n", cidade2, pib2);
        if (pib1 > pib2){
            printf("Resultado: Carta 1 %s venceu!\n", cidade1);
        } else if (pib2 > pib1){
            printf("Resultado: Carta 2 %s venceu!\n", cidade2);
        } else {
            printf("Empate! Ambas as cartas possuem %.2f de PIB\n", pib1);
        }
    } else if (opcao == 4){
        printf("Comparação de cartas (atributo: Pontos Turisticos)\n");
        printf("Carta 1 - %s: %d pontos turisticos\n", cidade1, atracoes1);
        printf("Carta 2 - %s: %d pontos turisticos\n", cidade2, atracoes2);
        if (atracoes1 > atracoes2){
            printf("Resultado: Carta 1 %s venceu!\n", cidade1);
        } else if (atracoes2 > atracoes1){
            printf("Resultado: Carta 2 %s venceu!\n", cidade2);
        } else {
            printf("Empate! Ambas as cartas possuem %d pontos turisticos\n", atracoes1);
        }
    } else if (opcao == 5){
        printf("Comparação de cartas (atributo: Densidade Populacional)\n");
        printf("Carta 1 - %s: %.2f hab/km2\n", cidade1, dp1);
        printf("Carta 2 - %s: %.2f hab/km2\n", cidade2, dp2);
        if (dp1 < dp2){
            printf("Resultado: Carta 1 %s venceu!\n", cidade1);
        } else if (dp2 < dp1){
            printf("Resultado: Carta 2 %s venceu!\n", cidade2);
        } else {
            printf("Empate! Ambas as cartas possuem %.2f hab/km2\n", dp1);
        }
    } else if (opcao == 6){
        printf("Comparação de cartas (atributo: PIB per capita)\n");
        printf("Carta 1 - %s: %.2f reais\n", cidade1, pibpc1);
        printf("Carta 2 - %s: %.2f reais\n", cidade2, pibpc2);
        if (pibpc1 > pibpc2){
            printf("Resultado: Carta 1 %s venceu!\n", cidade1);
        } else if (pibpc2 > pibpc1){
            printf("Resultado: Carta 2 %s venceu!\n", cidade2);
        } else {
            printf("Empate! Ambas as cartas possuem %.2f reais de PIB per capita\n", pibpc1);
        }
    } else if (opcao == 7){ 
        printf("Comparação de cartas (atributo: Super Poder)\n");
        printf("Carta 1 - %s: %.2f\n", cidade1, superPoder1);
        printf("Carta 2 - %s: %.2f\n", cidade2, superPoder2);
        if (superPoder1 > superPoder2){
            printf("Resultado: Carta 1 %s venceu!\n", cidade1);
        } else if (superPoder2 > superPoder1){
            printf("Resultado: Carta 2 %s venceu!\n", cidade2);
        } else {
            printf("Empate! Ambas as cartas possuem %.2f de Super Poder\n", superPoder1);
        }
    } else {
        printf("Opção inválida! Por favor, escolha um número entre 1 e 7.\n");
    }

return 0;

}