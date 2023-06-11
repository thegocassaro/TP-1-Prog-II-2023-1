#ifndef FUNCIONALIDADES_H_
#define FUNCIONALIDADES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Paciente.h"
#include "Consulta.h"

#define NULO -1

enum genero{MASC, FEM, OUTROS};
enum diagnostico{CA, CS, CB, CE, NEVO, MELA};

//Busca
void geraArquivoBusca(Cadastro* cadastro, Atendimento* atendimento);
void imprimeBuscaConsultaRealizada(Cadastro* cadastro, Atendimento* atendimento, int i, int j, char* cartao_sus);
void imprimeBuscaSemConsulta(Cadastro* cadastro, int i, char* cartao_sus);
char* converteValorResposta(int* valor, int pele);

//Relatório
void geraRelatorio(Cadastro* cadastro, Atendimento* atendimento);
int verificaGenero(Cadastro* cadastro, int i);
int verificaDiagnostico(Atendimento* atendimento, int j, int k);
int calculaDesvioPadrao(int* vetor, int media, int tamanho);

//Debug
void apagaRelatorio();

#endif