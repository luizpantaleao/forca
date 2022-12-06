#include <stdio.h>

int menu() {
    int opcao = 0;

    printf("(1) Jogar (2) Ver Ranking (3) Cadastar Jogador (4) Créditos (5) Sair\n\n");
    printf("Escolha: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        return 1;
        break;
    
    case 2:
        return 1;
        break;

    case 3:
        return 1;
        break;

    case 4:
        return 1;
        break;

    case 5:
        return 1;
            break;
    default:
        break;
    }
}