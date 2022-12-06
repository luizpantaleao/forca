#ifndef _FORCA_H
#define _FORCA_H 
#define TAMANHO_NOME 20

void abertura();
void adicionajogador();
void caminho();
void creditos();
void desenhaforca();
void escolhejogador();
void menu(int* c);
void palpite();
void regras();
void resetar();
int acertou();
int enforcou();
int ganhou();
int japalpitou(char letra);
int letraexiste(char letra);
int palpiteserrados();

#endif