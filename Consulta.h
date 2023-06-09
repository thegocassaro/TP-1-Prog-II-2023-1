#ifndef CONSULTA_H_
#define CONSULTA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Paciente.h"

typedef struct atendimento Atendimento;
typedef struct consulta Consulta;
typedef struct lesao Lesao;

#define TAM_MAX_MEDICAMENTO 70

//data atual: 11/05/2023
#define DIA_ATUAL 11
#define MES_ATUAL 05
#define ANO_ATUAL 2023

//Consulta
Atendimento* criaAtendimento();
Atendimento* iniciaConsulta(Atendimento* atendimento, Cadastro* cadastro);
void liberaConsultas(Atendimento* atendimento);

int verificaCadastro(Cadastro* cadastro, char* cartao_sus);
int calculaIdade(int dia_b, int mes_b, int ano_b);
int verificaResposta(char* resposta);
int verificaPele(char* resposta);
void converteLetrasMaiusculo(char* str);
void abortaProcesso(Atendimento* atendimento);    //encerra processo se colocada saida nao esperada e desaloca memoria

//Logs
void gravaLog(Consulta* consulta);

//Debug
void apagaLogs();
void printDebugConsulta(Atendimento* atendimento);


#endif