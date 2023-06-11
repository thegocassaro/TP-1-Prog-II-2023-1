#ifndef MENU_H_
#define MENU_H_

#include <stdio.h>
#include <stdlib.h>

enum opcao{PRE_CADASTRO, ATENDIMENTO, BUSCA, RELATORIO, FINALIZAR};

void layoutMenu();
int selecionaOpcao();
char converteLetraMaiusculo(char c);

#endif