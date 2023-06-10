#ifndef FUNCIONALIDADES_H_
#define FUNCIONALIDADES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Paciente.h"
#include "Consulta.h"

#define NULO -1


//Busca
void geraArquivoBusca(Cadastro* cadastro, Atendimento* atendimento);
void imprimeBuscaConsultaRealizada(Cadastro* cadastro, Atendimento* atendimento, int i, int j, char* cartao_sus);
void imprimeBuscaSemConsulta(Cadastro* cadastro, int i, char* cartao_sus);
char* converteValorResposta(int* valor, int pele);


#endif