#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Windows.h>
#include "forca.h"

char nomesorteado[TAMANHO_NOME];
char palpites[26];
int palpitesdados = 0;
int opcao = 0;
int erros = 0;
 

int letraexiste(char letra) {

    for(int j = 0; j < strlen(nomesorteado); j++) {
        if(letra == nomesorteado[j]) {
            return 1;
        }
    }

    return 0;
}

int palpiteserrados() {
    int erros = 0;
    for(int i = 0; i < palpitesdados; i++) {

        if(!letraexiste(palpites[i])) {
            erros++;
        }
    }
    return erros;
}

int enforcou() {
    return palpiteserrados() >= 5;
}

int ganhou() {
    for(int i = 0; i < strlen(nomesorteado); i++) {
        if(!japalpitou(nomesorteado[i])) {
            return 0;
        }
    }

    return 1;
}


void abertura() {
    printf("/**************************************/\n");
    printf("/ JOGO DA FORCA - SELECAO BRASILEIRA -*/\n");

}

void palpite() {
    char palpite;
    printf("Qual letra? ");
    scanf(" %c", &palpite);

    if(letraexiste(palpite)) {
        printf("Voce acertou: o nome do jogador tem a letra %c\n\n", palpite);
    } else {
        printf("\nVoce errou: o nome do jogador NAO tem a letra %c\n\n", palpite);
    }

    palpites[palpitesdados] = palpite;
    palpitesdados++;
}

int japalpitou(char letra) {
    int achou = 0;
    for(int j = 0; j < palpitesdados; j++) {
        if(palpites[j] == letra) {
            achou = 1;
            break;
        }
    }

    return achou;
}

void desenhaforca() {

    int erros = palpiteserrados();
    printf("  _______       \n");
    printf(" |/      |      \n");
    printf(" |      %c%c%c  \n", (erros>=1?'(':' '), (erros>=1?'_':' '), (erros>=1?')':' '));
    printf(" |      %c%c%c  \n", (erros>=3?'\\':' '), (erros>=2?'|':' '), (erros>=3?'/': ' '));
    printf(" |       %c     \n", (erros>=2?'|':' '));
    printf(" |      %c %c   \n", (erros>=4?'/':' '), (erros>=4?'\\':' '));
    printf(" |              \n");
    printf("_|___           \n");
    printf("\n\n");

    for(int i = 0; i < strlen(nomesorteado); i++) {

        if(japalpitou(nomesorteado[i])) {
            printf("%c ", nomesorteado[i]);
        } else {
            printf("_ ");
        }

    }
    printf("\n");

}

void escolhejogador() {
    FILE* f;

    f = fopen("jogadores.txt", "r");
    if(f == 0) {
        printf("Banco de dados de jogadores indisponivel\n\n");
        exit(1);
    }

    int qtddenomes;
    fscanf(f, "%d", &qtddenomes);

    srand(time(0));
    int randomico = rand() % qtddenomes;

    for(int i = 0; i <= randomico; i++) {
        fscanf(f, "%s", nomesorteado);
    }

    fclose(f);
}


void adicionajogador()
 {
    
        char novojogador[TAMANHO_NOME];

        printf("Digite o novo jogador, em letras maiusculas: ");
        scanf("%s", novojogador);

        FILE* f;

        f = fopen("jogadores.txt", "r+");
        if(f == 0) {
            printf("Banco de dados de jogadores indisponivel\n\n");
            exit(1);
        }

        int qtd;
        fscanf(f, "%d", &qtd);
        qtd++;
        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", qtd);

        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s", novojogador);

        fclose(f);
        printf("\nJogador adicionado com sucesso\n\n");
        menu(&opcao);

    }

    void creditos(){
        printf("\nJogo por:\n");
        printf("\nLuiz Eduardo Pantaleao\n");
        printf("Matheus Antunes\n\n");
        menu(&opcao);
    }

    void menu(int* c) {
        erros = 0;
        int escolha;
        printf("/**************************************/\n");
        printf("       o__        o__     |   |\\\n");
        printf("      /|          /\\      |   |X\\\n");
        printf("      / > o        <\\     |   |XX\\\n\n");
        printf("/**************************************/\n");
        printf("(1) Jogar (2) Cadastar Jogador (3) Regras (4) Creditos (5) Sair \n\n");
        printf("Escolha: ");
        scanf("%d", &escolha); 
        *c = escolha;
        caminho();    
}	
    void regras(){
        printf("\n1 - Esta registrada apenas o nome ou sobrenome de cada jodador, pelo qual ele for mais conhecido\n");
        printf("2 - Os nomes estao registrados sem acento\n");
        printf("3 - Os nomes estao registrados em letras maiusculas\n");
        printf("4 - O maximo de caracteres para um nome e 20\n");
        printf("5 - Ao adicionar um novo nome devem ser observadas as regras acimas\n");
        printf("6 - Os nomes estao registrados em letras maiusculas\n\n");
        menu(&opcao);
    }

    void resetar(){
        palpitesdados = 0;
        char limpar = (char) 0;
        for(int i=0; i<=25; i++){
            palpites[i] = limpar;
        }
    }
    
    
    void caminho(){
        switch (opcao)
            {
            case 1:
                escolhejogador();

            do {

                desenhaforca();
                palpite();

            } while (!ganhou() && !enforcou());

            if(ganhou()) {
                printf("\nParabens, o Brasil vai ser HEXA!!\n\n");

                printf("  .''.\n");
                printf(" (~~~~)\n");
                printf("   ||\n");
                printf(" __||__\n");
                printf("/______\\\n");
                printf("  |  |' _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n");
                printf("  |  |'|o| - - - - - - - - - - - - - - - - - - - - - - - - -||\n");
                printf("  |  |'| |                                                  ||\n");
                printf("  |  |'| |                      . ' .                       ||\n");
                printf("  |  |'| |                  . '       ' .                   ||\n");
                printf("  |  |'| |             .  '     . ' .     ' .               ||\n");
                printf("  |  |'| |         . '      ,"       ".                ' .           ||\n");
                printf("  |  |'| |      . '        /:           :\\        ' .       ||\n");
                printf("  |  |'| |  . '            ;  .          ;            ' .   ||\n");
                printf("  |  |'| |    ' .          \\: . .       :/          . '     ||\n");
                printf("  |  |'| |        ' .        `. . .    ,/       . '         ||\n");
                printf("  |  |'| |            ' .      `-.,,.-'     . '             ||\n");
                printf("  |  |'| |                ' .           . '                 ||\n");
                printf("  |  |'| |                    ' .   . '                     ||\n");
                printf("  |  |'| |                        '                         ||\n");
                printf("  |  |'|o|-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_||\n");
                printf("  |  |'\n");
                printf("  |  |' \n");
                printf("  |  |'\n");
                printf("  |  |'\n");
                printf("  '~~'\n\n");
                Sleep(5000);
                resetar(); 
                menu(&opcao);
                break;
            } else {
                printf("\nVoce perdeu. Continue tentando!\n");
                printf("O jogador era **%s**\n\n", nomesorteado);
                Sleep(3000); 
                resetar();
                menu(&opcao);
                break;
            
            }

            case 2:
                adicionajogador();
                break;
            
            case 3:
                regras();
                break;

            case 4:
                creditos();
                break;

            case 5:
                printf("Ate a proxima!");
                exit(1);

            default:
                printf("Ate a proxima!");
                exit(1);
            } 
        }