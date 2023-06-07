#ifndef PACIENTE_H_
#define PACIENTE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Consulta.h"

typedef struct cadastro Cadastro;
typedef struct paciente Paciente;

//Pré-Cadastro
#define TAM_MAX_LINHA 105
#define QTD_PACIENTES cadastro->qtd_pacientes
#define OI 23

Cadastro* inicializaListaCadastro();
Paciente* preCadastroPaciente(Cadastro* cadastro);
void gravaPaciente(Paciente* paciente);
void liberaPacientes(Paciente* paciente);

//Debug
void printDebugPaciente(Paciente* paciente);
void reiniciaBancoPacientes();

#endif