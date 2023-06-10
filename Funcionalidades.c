#include "Funcionalidades.h"

void geraArquivoBusca(Cadastro* cadastro, Atendimento* atendimento){

    //Localiza valores

    int* n_pacientes = (int*)getPaciente(cadastro, NULO, QTD_P);
    int* n_consultas = (int*)getConsulta(atendimento, NULO, NCONSULTAS, NULO);
    char cartao_sus[19];
    int i = 0, j = 0;

    scanf(" %s", cartao_sus);

    for(i=0; i<*n_pacientes; i++){

        if(!strcmp(cartao_sus, (char*)getPaciente(cadastro, i, CARTAO_P))) break;
    
    }

    for(j=0; j<*n_consultas; j++){

        if(!strcmp(cartao_sus, (char*)getConsulta(atendimento, j, CARTAO_C, NULO))) break;
    
    }

    //debug
    printf("\n%d %d\n", *n_pacientes, *n_consultas);
    printf("%d %d\n", i, j);

    if(i == *n_pacientes && j == *n_consultas){     //trata caso onde nao foi feita consulta

        printf("Cartão do SUS não está registrado na base de dados.\n");
        return;

    }

    //Imprime informações no arquivo busca

    //trata caso onde nao foi feita consulta
    else if(i < *n_pacientes && j == *n_consultas) imprimeBuscaSemConsulta(cadastro, i, cartao_sus);   

    else imprimeBuscaConsultaRealizada(cadastro, atendimento, i, j, cartao_sus);


// NOME: CASSIAN ANDOR
// DATA DE NASCIMENTO: 19/11/1990 (32 ANOS)
// GENERO: MASCULINO
// TELEFONE: (27)99898-3131
// DIABETES: SIM
// FUMANTE: NAO
// ALERGIA A MEDICAMENTO: SIM - DIPIRONA PARACETAMOL
// HISTORICO DE CANCER: NAO
// TIPO DE PELE: III

// LESOES:
// TOTAL: 3
// ENVIADA PARA CIRURGIA: 1
// ENVIADA PARA CRIOTERAPIA: 1

// DESCRICAO DAS LESOES:
// L1 - CARCINOMA ESPINOCELULAR - FACE - 30MM - ENVIADA PARA CIRURGIA
// L2 - CERATOSE ACTINICA - ANTEBRACO - 90MM - ENVIADA PARA CRIOTERAPIA
// L3 - CERATOSE SEBORREICA - FACE - 40MM

    printf("Paciente encontrado. Arquivo de busca gerado.\n");

}



void imprimeBuscaConsultaRealizada(Cadastro* cadastro, Atendimento* atendimento, int i, int j, char* cartao_sus){

    int* n_lesoes = (int*)getConsulta(atendimento, j, NLESOES, NULO);
    char nome_arq_busca[25];
    sprintf(nome_arq_busca, "busca_%s", cartao_sus);

    int dia, mes, ano;
    sscanf((char*)getPaciente(cadastro, i, DATA_P), "%d/%d/%d", &dia, &mes, &ano);

    FILE* arq_busca = fopen(nome_arq_busca, "w");

    fprintf(arq_busca, "NOME: %s\n",                             (char*)getPaciente(cadastro, i, NOME_P));
    fprintf(arq_busca, "DATA DE NASCIMENTO: %s (%d ANOS)\n",     (char*)getPaciente(cadastro, i, DATA_P), calculaIdade(dia, mes, ano));
    fprintf(arq_busca, "GENERO: %s\n",                           (char*)getPaciente(cadastro, i, GENERO_P));
    fprintf(arq_busca, "TELEFONE: %s\n",                         (char*)getPaciente(cadastro, i, TELEFONE_P));
    fprintf(arq_busca, "DIABETES: %s\n",                         converteValorResposta((int*)getConsulta(atendimento, j, DIABETES_C, NULO), 0));
    fprintf(arq_busca, "FUMANTE: %s\n",                          converteValorResposta((int*)getConsulta(atendimento, j, FUMANTE_C, NULO), 0));
    
    if(*(int*)getConsulta(atendimento, j, ALERGIA_C, NULO))   
        fprintf(arq_busca, "ALERGIA A MEDICAMENTO: SIM - %s\n",  (char*)getConsulta(atendimento, j, MEDICAMENTO_C, NULO));
    else
        fprintf(arq_busca, "ALERGIA A MEDICAMENTO: NAO\n");
    
    fprintf(arq_busca, "HISTORICO DE CANCER: %s\n",         converteValorResposta((int*)getConsulta(atendimento, j, HISTORICO_C, NULO), 0));
    fprintf(arq_busca, "TIPO DE PELE: %s\n",                converteValorResposta((int*)getConsulta(atendimento, j, PELE_C, NULO), 1));

    fprintf(arq_busca, "\nLESOES:\n");
    fprintf(arq_busca, "TOTAL: %d\n",                       *(int*)getConsulta(atendimento, j, NLESOES, NULO));
    fprintf(arq_busca, "ENVIADA PARA CIRURGIA: %d\n",       *(int*)getConsulta(atendimento, j, QTD_CIRUR, NULO));
    fprintf(arq_busca, "ENVIADA PARA CRIOTERAPIA: %d\n",    *(int*)getConsulta(atendimento, j, QTD_CRIO, NULO));
    fprintf(arq_busca, "\nDESCRICAO DAS LESOES:\n");

    for(int k=0; k<*n_lesoes; k++){

        fprintf(arq_busca, "%s - ",         (char*)getConsulta(atendimento, j, ROTULO_L, k));
        fprintf(arq_busca, "%s - ",         (char*)getConsulta(atendimento, j, DIAGNOSTICO_L, k));
        fprintf(arq_busca, "%s - ",         (char*)getConsulta(atendimento, j, REGIAO_L, k));
        fprintf(arq_busca, "%dMM",          *(int*)getConsulta(atendimento, j, TAMANHO_L, k));
        
        if      (*(int*)getConsulta(atendimento, j, CIRURGIA_L, k))       fprintf(arq_busca, " - ENVIADA PARA CIRURGIA\n");
        else if (*(int*)getConsulta(atendimento, j, CRIOTERAPIA_L, k))    fprintf(arq_busca, " - ENVIADA PARA CRIOTERAPIA\n");
        else    fprintf(arq_busca, "\n");

    }

    fclose(arq_busca);

}



void imprimeBuscaSemConsulta(Cadastro* cadastro, int i, char* cartao_sus){

    char nome_arq_busca[25];
    sprintf(nome_arq_busca, "busca_%s", cartao_sus);

    int dia, mes, ano;
    sscanf((char*)getPaciente(cadastro, i, DATA_P), "%d/%d/%d", &dia, &mes, &ano);

    FILE* arq_busca = fopen(nome_arq_busca, "w");

    fprintf(arq_busca, "NOME: %s\n",                             (char*)getPaciente(cadastro, i, NOME_P));
    fprintf(arq_busca, "DATA DE NASCIMENTO: %s (%d ANOS)\n",     (char*)getPaciente(cadastro, i, DATA_P), calculaIdade(dia, mes, ano));
    fprintf(arq_busca, "GENERO: %s\n",                           (char*)getPaciente(cadastro, i, GENERO_P));
    fprintf(arq_busca, "TELEFONE: %s\n",                         (char*)getPaciente(cadastro, i, TELEFONE_P));
    fprintf(arq_busca, "DIABETES: \n");
    fprintf(arq_busca, "FUMANTE: \n");
    fprintf(arq_busca, "ALERGIA A MEDICAMENTO: \n");
    fprintf(arq_busca, "HISTORICO DE CANCER: \n");
    fprintf(arq_busca, "TIPO DE PELE: \n");
    fprintf(arq_busca, "LESOES: \n");

    fclose(arq_busca);

}



char* converteValorResposta(int* valor, int pele){

    if(pele == 0){

        if(*valor == 1) return "SIM";
        else            return "NAO"; 

    }

    else{

        switch(*valor){

            case 1:
                return "I";
            case 2:
                return "II";
            case 3:
                return "III";
            case 4:
                return "IV";
            case 5:
                return "V";
            case 6:
                return "VI";
            default:
                break;

        }

    }

    printf("Erro na conversao de valores.\n");
    return NULL;

}