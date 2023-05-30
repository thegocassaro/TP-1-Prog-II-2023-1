#ifndef MINISADE_H_
#define MINISADE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct paciente Paciente;

//Pré-Cadastro
Paciente* preCadastroPaciente();
void LiberaPacientes(Paciente* paciente);

//Debug
void printDebug(Paciente* paciente);

#endif