#ifndef PACIENTE_H_
#define PACIENTE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cadastro Cadastro;
typedef struct paciente Paciente;

#define TAM_MAX_NOME 50

//enum só serve pra variáveis?
#define NOME_P     0
#define CARTAO_P   1
#define DATA_P     2
#define TELEFONE_P 3
#define GENERO_P   4
#define QTD_P      5

//Pré-Cadastro
Cadastro* criaCadastro();
Cadastro* preCadastroPaciente(Cadastro* cadastro);
void liberaPacientes(Cadastro* cadastro);
// void gravaPaciente(Paciente* paciente);

//Intermodulação
void* getPaciente(Cadastro* cadastro, int indice, int select);

//Debug
void printDebugPaciente(Cadastro* cadastro);
void reiniciaBancoPacientes();

#endif