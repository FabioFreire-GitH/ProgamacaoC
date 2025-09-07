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
    
    /*Abaixo será exibido as informacoes inseridas da carta 1*/
    printf(" ___________________________________\n");
    printf("|             CARTA 1               \n");
    printf("|Codido da carta: %c%s              \n", estado1,codigo1);//nao entendi uma forma de melhorar
    printf("|Cidade: %s                         \n", cidade1);
    printf("|População: %lu                     \n", populacao1);
    printf("|Área: %.2f km2                     \n", area1);
    printf("|PIB: %.2f                          \n", pib1);
    printf("|Pontos turisticos: %d              \n", atracoes1);
    printf("|Densidade Populacional: %.2f hab/km2\n", dp1);
    printf("|PIB per capita: %.2f reais         \n", pibpc1);
    printf("|Super Poder: %.2f                   \n", superPoder1); //Exibição do super poder da carta 1 
    printf("|___________________________________\n");
    printf("\n\n");
  
   
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
    
    /*Abaixo será exibido as informacoes inseridas da carta 2*/
    printf(" ___________________________________\n");
    printf("|             CARTA 2               \n");
    printf("|Codido da carta: %c%s              \n", estado2,codigo2);
    printf("|Cidade: %s                         \n", cidade2);
    printf("|População: %lu                     \n", populacao2);
    printf("|Área: %.2f km2                     \n", area2);
    printf("|PIB: %.2f                          \n", pib2);
    printf("|Pontos turisticos: %d              \n", atracoes2);
    printf("|Densidade Populacional: %.2f hab/km2\n", dp2);
    printf("|PIB per capita: %.2f reais         \n", pibpc2);
    printf("|Super Poder: %.2f                   \n", superPoder2); //Exibição do super poder da carta 2
    printf("|___________________________________\n");
    printf("\n\n");

    /*Abaixo será feita a comparação entre as cartas*/
    printf("Comparação entre as cartas:\n");
    printf("O Super Poder da Carta 1 é maior que o Super Poder da Carta 2? %d\n", superPoder1 > superPoder2);
    printf("O Super Poder da Carta 2 é maior que o Super Poder da Carta 1? %d\n", superPoder2 > superPoder1);
    printf("O Super Poder da Carta 1 é igual ao Super Poder da Carta 2? %d\n", superPoder1 == superPoder2);
    
    //abaixo serão feitas as comparações entre os atributos individuais das cartas
    printf("A Carta 1 tem mais Pontos Turisticos que a Carta 2? %d\n", atracoes1 > atracoes2);
    printf("A Carta 2 tem mais Pontos Turisticos que a Carta 1? %d\n", atracoes2 > atracoes1);
    printf("A Carta 1 tem mais População que a Carta 2? %d\n", populacao1 > populacao2);
    printf("A Carta 2 tem mais População que a Carta 1? %d\n", populacao2 > populacao1);
    printf("A Carta 1 tem mais Área que a Carta 2? %d\n", area1 > area2);
    printf("A Carta 2 tem mais Área que a Carta 1? %d\n", area2 > area1);
    printf("A Carta 1 tem mais PIB que a Carta 2? %d\n", pib1 > pib2);
    printf("A Carta 2 tem mais PIB que a Carta 1? %d\n", pib2 > pib1);
    printf("A Carta 1 tem menos Densidade Populacional que a Carta 2? %d\n", dp1 < dp2);
    printf("A Carta 2 tem menos Densidade Populacional que a Carta 1? %d\n", dp2 < dp1);
    
    // NAO UTILIZEI O IF POIS AINDA NAO APRENDI, MAS ACHO QUE DA PRA MELHORAR ISSO AQUI EM CIMA.



return 0;


}