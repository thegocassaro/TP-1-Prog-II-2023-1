#include "Paciente.h"

struct cadastro{

    Paciente** lista_pacientes;
    int qtd_pacientes;

};

struct paciente{

    char* nome;
    char cartao_sus[19];        //formato: 000-0000-0000-0000
    char data_nascimento[11];   //formato: 00/00/0000
    char telefone[15];          //formato: (00)00000-0000
    char genero[10];            //masculino, feminino, outros

};

//Pré-Cadastro

//Falta tratar os casos que não estao dentro dos formatos


Cadastro* criaCadastro(){

    Cadastro* cadastro = (Cadastro*)malloc(sizeof(Cadastro));
    cadastro->lista_pacientes = (Paciente**)malloc(sizeof(Paciente*));
    cadastro->qtd_pacientes = 0;

    return cadastro;

}



//Retorna um paciente caso acorra tudo certo / NULL se cartão já houver sido cadastrado

Cadastro* preCadastroPaciente(Cadastro* cadastro){

    Paciente* paciente = (Paciente*) malloc(sizeof(Paciente));

    char nome_aux[TAM_MAX_NOME];

    scanf(" %[^\n]", nome_aux);

    nome_aux[strlen(nome_aux)] = '\0';          //Remove \n

    paciente->nome = strdup(nome_aux);              


    scanf(" %s", paciente->cartao_sus);           


    //Checa repetição de cartão sus

    for(int i=0; i<cadastro->qtd_pacientes; i++){

        if(strcmp(paciente->cartao_sus, cadastro->lista_pacientes[i]->cartao_sus) == 0){

            printf("Esse número de cartão já existe. Por favor refaça o cadastro.\n");

            free(paciente->nome);
            free(paciente);

            paciente = NULL;

            return cadastro;

        }

    }

    //Continua leitura

    scanf(" %s", paciente->data_nascimento);
    scanf(" %s", paciente->telefone);
    scanf(" %s", paciente->genero);

    cadastro->lista_pacientes = (Paciente**)realloc(cadastro->lista_pacientes, sizeof(Paciente*) * (cadastro->qtd_pacientes + 1));
    cadastro->lista_pacientes[cadastro->qtd_pacientes] = paciente;
    cadastro->qtd_pacientes++;

    return cadastro;
}



void liberaPacientes(Cadastro* cadastro){

    for(int i=0; i<cadastro->qtd_pacientes; i++){
        free(cadastro->lista_pacientes[i]->nome);
        free(cadastro->lista_pacientes[i]);
    }

    free(cadastro->lista_pacientes);
    free(cadastro);

}



void* getPaciente(Cadastro* cadastro, int indice, int select){

    switch(select){

        case NOME_P:
            return cadastro->lista_pacientes[indice]->nome;

        case CARTAO_P:
            return cadastro->lista_pacientes[indice]->cartao_sus;

        case DATA_P:
            return cadastro->lista_pacientes[indice]->data_nascimento;

        case TELEFONE_P:
            return cadastro->lista_pacientes[indice]->telefone;

        case GENERO_P:
            return cadastro->lista_pacientes[indice]->genero;

        case QTD_P:
            return &cadastro->qtd_pacientes;

        default:
            printf("Erro na seleção de getPaciente\n");
            return NULL;

    }
    
}



void printDebugPaciente(Cadastro* cadastro){

    printf("%s %s %s %s %s\n", cadastro->lista_pacientes[0]->nome, 
    cadastro->lista_pacientes[0]->cartao_sus, 
    cadastro->lista_pacientes[0]->data_nascimento, 
    cadastro->lista_pacientes[0]->telefone, 
    cadastro->lista_pacientes[0]->genero);
    
}
