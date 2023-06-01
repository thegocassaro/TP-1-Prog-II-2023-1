#ifndef MINISADE_H_
#define MINISADE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct paciente Paciente;

//Pré-Cadastro
#define TAM_MAX_LINHA 105

Paciente* preCadastroPaciente();
void gravaPaciente(Paciente* paciente);
void liberaPacientes(Paciente* paciente);

//Debug
void printDebug(Paciente* paciente);

#endif