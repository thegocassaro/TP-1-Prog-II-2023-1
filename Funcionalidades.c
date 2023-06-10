#include "Funcionalidades.h"

void geraArquivoBusca(Cadastro* cadastro, Atendimento* atendimento){

    //Localiza valores

    int* n_pacientes = (int*)getPaciente(cadastro, 0, QTD_P);
    int* n_consultas = (int*)getConsulta(atendimento, 0, NCONSULTAS, -1, -1);
    char cartao_sus[19];
    int i = 0, j = 0;

    scanf(" %s", cartao_sus);

    for(i=0; i<*n_pacientes; i++){

        if(!strcmp(cartao_sus, (char*)getPaciente(cadastro, i, CARTAO_P))) break;
    
    }

    for(j=0; j<*n_consultas; j++){

        if(!strcmp(cartao_sus, (char*)getConsulta(atendimento, j, CARTAO_P, -1, -1))) break;
    
    }

    if(i == *n_pacientes || j == *n_consultas){

        printf("Cartão do SUS não está registrado na base de dados.\n");
        return;

    } 


    //Imprime informações no arquivo busca

    char nome_arq_busca[25] = "busca_";
    sprintf(nome_arq_busca, "%s", );

    FILE* arq_busca = fopen("", "w");

}


