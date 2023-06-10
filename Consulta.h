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

enum select{CARTAO_C, DIABETES_C, FUMANTE_C, ALERGIA_C, HISTORICO_C, MEDICAMENTO_C, PELE_C, 
            NLESOES, NCONSULTAS, LESOES, ROTULO_L, DIAGNOSTICO_L, REGIAO_L, TAMANHO_L, CIRURGIA_L, CRIOTERAPIA_L};

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

//Intermodulação
void* getConsulta(Atendimento* atendimento, int indice, int select, int indice_lesao, int select_lesao);
void* getLesao(Lesao* lesoes, int indice, int select);

//Debug
void apagaLogs();
void printDebugConsulta(Atendimento* atendimento);


#endif