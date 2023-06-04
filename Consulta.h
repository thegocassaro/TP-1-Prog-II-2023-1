#ifndef CONSULTA_H_
#define CONSULTA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct consulta Consulta;
typedef struct lesao Lesao;

#define TAM_MAX_LINHA 105
#define TAM_MAX_MEDICAMENTO 70

Consulta* criaConsulta();
Consulta* iniciaConsulta(Consulta* consulta);
void liberaConsulta(Consulta* consulta);

int verificaCadastro(char* cartao_sus);
int verificaResposta(char* resposta);
int verificaMedicamento(char* resposta, Consulta* consulta);
int verificaPele(char* resposta);
void converteLetrasMaiusculo(char* str);
void abortaProcesso(Consulta* consulta); //encerra processo se colocada saida nao esperada e desaloca memoria

//Debug
void printDebugConsulta(Consulta* consulta);


#endif