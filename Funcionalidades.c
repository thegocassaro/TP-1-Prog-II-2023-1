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

    if(i == *n_pacientes && j == *n_consultas){     //trata caso onde nao foi feita consulta

        printf("Cartão do SUS não está registrado na base de dados.\n");
        return;

    }

    //Imprime informações no arquivo busca

    //trata caso onde nao foi feita consulta
    else if(i < *n_pacientes && j == *n_consultas) imprimeBuscaSemConsulta(cadastro, i, cartao_sus);   

    else imprimeBuscaConsultaRealizada(cadastro, atendimento, i, j, cartao_sus);

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



void geraRelatorio(Cadastro* cadastro, Atendimento* atendimento){

    int cont_pacientes_atendidos = 0, flag = 0, total = 0;

    int media_idade = 0, desvio_idade = 0, media_tam = 0, desvio_tam = 0;
    int *vetor_idades = NULL, *vetor_tam = NULL;

    float p_masc, p_fem, p_outros, p_cirurgias, p_crioterapias;
    float p_ca, p_cb, p_cs, p_nevo, p_ce, p_mela;

    int n_lesoes = 0, n_cirurgias = 0, n_crioterapias = 0;
    int cont_ca = 0, cont_cs = 0, cont_cb = 0, cont_ce = 0, cont_nevo = 0, cont_mela = 0, cont_tam = 0;
    int cont_masc = 0, cont_fem = 0, cont_outros = 0;

    int dia, mes, ano;


    int* n_pacientes = (int*)getPaciente(cadastro, NULO, QTD_P);
    int* n_consultas = (int*)getConsulta(atendimento, NULO, NCONSULTAS, NULO);
    int i = 0, j = 0, save_j = 0;   //save_j guarda ultima occorencia de consulta para um paciente

    for(i=0; i<*n_pacientes; i++){

        for(j=0; j<*n_consultas; j++){

            if(!strcmp((char*)getConsulta(atendimento, j, CARTAO_C, NULO), (char*)getPaciente(cadastro, i, CARTAO_P))){

                flag = 1;
                save_j = j;

            } 
    
        }

        if(flag == 1){

            cont_pacientes_atendidos++;

            sscanf((char*)getPaciente(cadastro, i, DATA_P), "%d/%d/%d", &dia, &mes, &ano);
            media_idade += calculaIdade(dia, mes, ano);
            vetor_idades = (int*)realloc(vetor_idades, sizeof(int) * cont_pacientes_atendidos);
            vetor_idades[cont_pacientes_atendidos - 1] = calculaIdade(dia, mes, ano);

            switch(verificaGenero(cadastro, i)){
                case MASC:
                    cont_masc++;
                    break;
                case FEM:
                    cont_masc++;
                    break;
                case OUTROS:
                    cont_masc++;
                    break;
                default:
                    break;
            }

            n_lesoes += *(int*)getConsulta(atendimento, save_j, NLESOES, NULO);
            n_cirurgias += *(int*)getConsulta(atendimento, save_j, QTD_CIRUR, NULO);
            n_crioterapias += *(int*)getConsulta(atendimento, save_j, QTD_CRIO, NULO);

            vetor_tam = (int*)realloc(vetor_tam, sizeof(int) * n_lesoes);

            for(int k=0; k<*(int*)getConsulta(atendimento, save_j, NLESOES, NULO); k++){

                switch(verificaDiagnostico(atendimento, save_j, k)){
                    case CA:
                        cont_ca++;
                        break;
                    case CB:
                        cont_cb++;
                        break;
                    case CS:
                        cont_cs++;
                        break;
                    case NEVO:
                        cont_nevo++;
                        break;
                    case CE:
                        cont_ce++;
                        break;
                    case MELA:
                        cont_mela++;
                        break;
                    default:
                        break;

                }

                media_tam += *(int*)getConsulta(atendimento, save_j, TAMANHO_L, k);
                vetor_tam[cont_tam] = *(int*)getConsulta(atendimento, save_j, TAMANHO_L, k);
                cont_tam++;

            }

        }

        flag = 0;
    
    }

    media_idade /= cont_pacientes_atendidos;
    desvio_idade = calculaDesvioPadrao(vetor_idades, media_idade, cont_pacientes_atendidos);

    total = cont_fem + cont_masc + cont_outros;
    p_masc =    (cont_masc / total) * 100;
    p_fem =     (cont_fem / total) * 100;
    p_outros =  (cont_outros / total) * 100;

    media_tam /= n_lesoes;
    desvio_tam = calculaDesvioPadrao(vetor_tam, media_tam, n_lesoes);

    p_cirurgias =       (n_cirurgias / n_lesoes) * 100;
    p_crioterapias =    (n_crioterapias / n_lesoes) * 100;

    total = cont_ca + cont_cb + cont_cs + cont_nevo + cont_ce + cont_mela;
    p_ca =      (cont_ca / total) * 100;
    p_cb =      (cont_cb / total) * 100;
    p_cs =      (cont_cs / total) * 100;
    p_nevo =    (cont_nevo / total) * 100;
    p_ce =      (cont_ce / total) * 100;
    p_mela =    (cont_mela / total) * 100;

    FILE* arq_relatorio = fopen("relatorio_final", "w");

    fprintf(arq_relatorio, "NUMERO TOTAL DE PACIENTES ATENDIDOS: %d\n", cont_pacientes_atendidos);
    fprintf(arq_relatorio, "IDADE MEDIA: %d +- %d ANOS\n", media_idade, desvio_idade);
    fprintf(arq_relatorio, "DISTRIBUICAO POR GENERO:\n");
    fprintf(arq_relatorio, "- FEMININO: %.2f%%\n", p_fem);
    fprintf(arq_relatorio, "- MASCULINO: %.2f%%\n", p_masc);
    fprintf(arq_relatorio, "- OUTROS: %.2f%%\n", p_outros);
    fprintf(arq_relatorio, "TAMANHO MEDIO DAS LESOES: %d +- %d\n", media_tam, desvio_tam);
    fprintf(arq_relatorio, "NUMERO TOTAL DE LESOES: %d\n", n_lesoes);
    fprintf(arq_relatorio, "NUMERO TOTAL DE CIRURGIAS: %d (%.2f%%)\n", n_cirurgias, p_cirurgias);
    fprintf(arq_relatorio, "NUMERO TOTAL DE CRIOTERAPIA: %d (%.2f%%)\n", n_crioterapias, p_crioterapias);
    fprintf(arq_relatorio, "DISTRIBUICAO POR DIAGNOSTICO:\n");
    fprintf(arq_relatorio, "- CERATOSE ACTINICA: %d (%.2f%%)\n", cont_ca, p_ca);
    fprintf(arq_relatorio, "- CARCINOMA BASOCELULAR: %d (%.2f%%)\n", cont_cb, p_cb);
    fprintf(arq_relatorio, "- CARCINOMA ESPINOCELULAR: %d (%.2f%%)\n", cont_ce, p_ce);
    fprintf(arq_relatorio, "- NEVO: %d (%.2f%%)\n", cont_nevo, p_nevo);
    fprintf(arq_relatorio, "- CERATOSE SEBORREICA: %d (%.2f%%)\n", cont_cs, p_cs);
    fprintf(arq_relatorio, "- MELANOMA: %d (%.2f%%)", cont_mela, p_mela);

    fclose(arq_relatorio);

    free(vetor_idades);
    free(vetor_tam);
    
}



int verificaGenero(Cadastro* cadastro, int i){

    char genero[10];

    strcpy(genero, (char*)getPaciente(cadastro, i, GENERO_P));

    if(!strcmp(genero, "MASCULINO")) return MASC;
    else if(!strcmp(genero, "FEMININO")) return FEM;
    else if(!strcmp(genero, "OUTROS")) return OUTROS;
    else return -1;

}



int verificaDiagnostico(Atendimento* atendimento, int j, int k){

    char diagnostico[24];

    strcpy(diagnostico, (char*)getConsulta(atendimento, j, DIAGNOSTICO_L, k));

    if(!strcmp(diagnostico, "CERATOSE ACTINICA")) return CA;
    else if(!strcmp(diagnostico, "CARCINOMA BASOCELULAR")) return CB;
    else if(!strcmp(diagnostico, "CARCINOMA ESPINOCELULAR")) return CE;
    else if(!strcmp(diagnostico, "NEVO")) return NEVO;
    else if(!strcmp(diagnostico, "CERATOSE SEBORREICA")) return CS;
    else if(!strcmp(diagnostico, "MELANOMA")) return MELA;
    else return -1;

}



int calculaDesvioPadrao(int* vetor, int media, int tamanho){

    int diferenca = 0, somatorio = 0, variancia = 0;

    for(int i=0; i<tamanho; i++){

        diferenca = vetor[i] - media;
        somatorio = pow(diferenca, 2);

    }

    variancia = somatorio / tamanho;

    return sqrt(variancia);

}



void apagaRelatorio(){

    remove("relatorio_final");

}