#include "Consulta.h"

struct atendimento{

    Consulta** lista_consultas;
    int qtd_consultas;

};

struct consulta{

    char cartao_sus[19];

    int diabetes, fumante, alergia, historico_cancer;
    char* medicamento_alergia;
    int pele;                       //(I, II, III, IV, V, VI)

    Lesao* lesao;
    int qtd_lesoes;

};

struct lesao{

    char rotulo[3];                 //L1, L2, ..., LN
    char diagnostico[24];           //Carcinoma Basocelular, Carcinoma Espinocelular, Melanoma, Ceratose Actínica, Nevo e Ceratose Seborréica
    char regiao[15];                //Face, Orelha, Couro cabeludo, Peitoral, Dorso, Abdome,  Braço, Antebraço, Mão, Coxa, Canela e Pé
    int tamanho;                    //mm
    int cirurgia, crioterapia;

};



Atendimento* criaAtendimento(){

    Atendimento* atendimento = (Atendimento*)malloc(sizeof(Atendimento));
    atendimento->lista_consultas = (Consulta**)malloc(sizeof(Consulta*));
    atendimento->qtd_consultas = 0;

    return atendimento;

}



Atendimento* iniciaConsulta(Atendimento* atendimento, Cadastro* cadastro){

    Consulta* consulta = (Consulta*)malloc(sizeof(Consulta));

    char getResposta[4];
    char getMedicamento[TAM_MAX_MEDICAMENTO];
    int aux = 0;


    //Pega cartao sus e checa existencia
    char cartao_sus[19];
    scanf(" %s", cartao_sus);
    
    //DEBUG
    // printf("%s \n", cartao_sus);

    if(verificaCadastro(cadastro, cartao_sus) == 0){

        printf("Esse número de cartão não está cadastrado. Consulta abortada.\n");
        free(consulta);

        return atendimento;

    }

    strcpy(consulta->cartao_sus, cartao_sus);


    //Diabetes
    printf("(SIM ou NAO) Possui diabetes? ");
    scanf(" %s", getResposta);

    converteLetrasMaiusculo(getResposta);
    aux = verificaResposta(getResposta);
    //DEBUG
    // printf("%d\n", aux);
    
    // if(aux == -1) abortaProcesso(consulta);
    consulta->diabetes = aux;


    //Fumante
    printf("(SIM ou NAO) É fumante? ");
    scanf(" %s", getResposta);

    converteLetrasMaiusculo(getResposta);
    aux = verificaResposta(getResposta);
    //DEBUG
    // printf("%d\n", aux);
    
    // if(aux == -1) abortaProcesso(consulta);
    consulta->fumante = aux;
    

    //Alergia
    printf("(SIM ou NAO) Alergia a algum medicamento? ");
    scanf(" %s", getResposta);

    converteLetrasMaiusculo(getResposta);
    aux = verificaResposta(getResposta);
    //DEBUG
    // printf("%d\n", aux);
    
    // if(aux == -1) abortaProcesso(consulta);
    consulta->alergia = aux;

    if(consulta->alergia){

        scanf(" %[^\n]", getMedicamento);

        converteLetrasMaiusculo(getMedicamento);
        consulta->medicamento_alergia = strdup(getMedicamento);
        //DEBUG
        // printf("%s\n", getMedicamento);
        // printf("%d\n", aux);

    }


    //Historico de cancer
    printf("(SIM ou NAO) Possui histórico de câncer? ");
    scanf(" %s", getResposta);

    converteLetrasMaiusculo(getResposta);
    aux = verificaResposta(getResposta);
    //DEBUG
    // printf("%d\n", aux);
    
    // if(aux == -1) abortaProcesso(consulta);
    consulta->historico_cancer = aux;
    

    //Pele
    printf("(I, II, III, IV, V, VI) Tipo de pele? ");
    scanf(" %s", getResposta);

    converteLetrasMaiusculo(getResposta);
    aux = verificaPele(getResposta);
    //DEBUG
    // printf("%d\n", aux);

    // if(aux == -1) abortaProcesso(consulta);
    consulta->pele = aux;



    //Lesoes

    //Experimentando usar *lesao ao invés de **lesao, como normalmente faria

    consulta->lesao = (Lesao*)calloc(1, sizeof(Lesao));
    consulta->qtd_lesoes = 1;

    while(1){

        int id = consulta->qtd_lesoes - 1;
        
        //Rotulo
        sprintf( consulta->lesao[id].rotulo, "L%c", ('0' + consulta->qtd_lesoes) ); 


        //Diagnostico
        printf("Diagnóstico: ");
        scanf(" %s", getResposta);
        //DEBUG
        // printf("%s\n", getResposta);

        converteLetrasMaiusculo(getResposta);
        strcpy( consulta->lesao[id].diagnostico, getResposta );


        //Regiao
        printf("Região: ");
        scanf(" %s", getResposta);
        //DEBUG
        // printf("%s\n", getResposta);

        converteLetrasMaiusculo(getResposta);
        strcpy( consulta->lesao[id].regiao, getResposta );


        //Tamanho
        printf("(mm) Tamanho: ");
        scanf(" %d\n", &consulta->lesao[id].tamanho);
        //DEBUG
        // printf("%d\n", consulta->lesao[id].tamanho);


        //Cirurgia
        printf("(SIM ou NAO) Necessidade de cirurgia? ");
        scanf(" %s", getResposta);

        converteLetrasMaiusculo(getResposta);
        aux = verificaResposta(getResposta);
        //DEBUG
        // printf("%d\n", aux);
        
        // if(aux == -1) abortaProcesso(consulta);
        consulta->lesao[id].cirurgia = aux;


        //Crioterapia
        printf("(SIM ou NAO) Necessidade de crioterapia? ");
        scanf(" %s", getResposta);

        converteLetrasMaiusculo(getResposta);
        aux = verificaResposta(getResposta);
        //DEBUG
        // printf("%d\n", aux);
        
        // if(aux == -1) abortaProcesso(consulta);
        consulta->lesao[id].crioterapia = aux;


        //Mais lesoes?
        printf("(SIM ou NAO) Deseja cadastrar outra lesão? ");
        scanf(" %s", getResposta);

        converteLetrasMaiusculo(getResposta);
        aux = verificaResposta(getResposta);
        //DEBUG
        // printf("%d\n", aux);
        
        // if(aux == -1) abortaProcesso(consulta);

        if(aux == 0) break;

        //if aux == 1
        consulta->qtd_lesoes += 1;
        consulta->lesao = (Lesao*)realloc(consulta->lesao, sizeof(Lesao) * (consulta->qtd_lesoes));
    
        //se eu realoco um ponteiro que eu iniciei com calloc, ele setta os bytes pra zero também?

    }

    gravaLog(consulta);

    atendimento->lista_consultas = (Consulta**)realloc(atendimento->lista_consultas, sizeof(Consulta*) * (atendimento->qtd_consultas + 1));
    atendimento->lista_consultas[atendimento->qtd_consultas] = consulta;
    atendimento->qtd_consultas++;

    return atendimento;

}



void converteLetrasMaiusculo(char* str){

    int tam_str = strlen(str);

    for(int i=0; i<tam_str; i++){

        if(str[i] >= 'a' && str[i] <= 'z') str[i] -= 32;

    }

}



int verificaResposta(char* resposta){

    if(!strcmp(resposta, "SIM")) return 1;

    else if(!strcmp(resposta, "NAO")) return 0;

    else return -1;
}



int verificaPele(char* resposta){

    if(!strcmp(resposta, "I")) return 1;
    if(!strcmp(resposta, "II")) return 2;
    if(!strcmp(resposta, "III")) return 3;
    if(!strcmp(resposta, "IV")) return 4;
    if(!strcmp(resposta, "V")) return 5;
    if(!strcmp(resposta, "VI")) return 6;

    return -1;

}



//Retorna 1 se existe / 0 se não

int verificaCadastro(Cadastro* cadastro, char* cartao_sus){

    int* n_pacientes = (int*)getPaciente(cadastro, 0, QTD_P);
    char nome_lido[TAM_MAX_NOME];
    char cartao_sus_lido[19];
    char data_lida[11];

    for(int i=0; i<*n_pacientes; i++){

        strcpy(cartao_sus_lido, (char*)getPaciente(cadastro, i, CARTAO_P));

        //Se existir cartao, tambem exibe o nome e idade do paciente
        if(strcmp(cartao_sus, cartao_sus_lido) == 0){

            //por algum motivo, depois do primeiro uso do strtok, quando tentei chamar a funcao de novo, usando 
            //token = strtok(linha, ";");       -> aqui ainda funciona e retorna o nome
            //token = strtok(NULL, ";");        -> aqui ja retorna null, sempre
            //e logo em seguida dava seg fault

            strcpy(nome_lido, (char*)getPaciente(cadastro, i, NOME_P));
            strcpy(data_lida, (char*)getPaciente(cadastro, i, DATA_P));

            int dia, mes, ano;
            sscanf(data_lida, "%d/%d/%d", &dia, &mes, &ano);

            int idade = calculaIdade(dia, mes, ano);

            printf("NOME: %s\n", nome_lido);
            printf("IDADE: %d\n\n", idade);

            return 1;

        }

    }

    return 0;

}



int calculaIdade(int dia_b, int mes_b, int ano_b){

    int idade = 0;

    if(MES_ATUAL > mes_b){

        idade = ANO_ATUAL - ano_b;

    }

    else if(MES_ATUAL < mes_b){

        idade = (ANO_ATUAL - ano_b) - 1;

    }

    else if(MES_ATUAL == mes_b){

        if(DIA_ATUAL < dia_b){

            idade = (ANO_ATUAL - ano_b) - 1;

        }

        else if(DIA_ATUAL >= dia_b){

            idade = ANO_ATUAL - ano_b;

        }

    }

    return idade;
    
    // // TENTATIVA DE USAR A time.h

    // // tm_year -> number of years since 1900
    // // tm_mon -> range 0 to 11

    // int dia_a = 11, mes_a = 4, ano_a = (2023 - 1900);

    // mes_b -= 1;
    // ano_b -= 1900;

    // struct tm data_atual, data_nascimento;

    // data_atual.tm_mday = dia_a;
    // data_atual.tm_mon = mes_a;
    // data_atual.tm_year = ano_a;

    // data_nascimento.tm_mday = dia_b;
    // data_nascimento.tm_mon = mes_b;
    // data_nascimento.tm_year = ano_b;

    // time_t data_a = mktime(&data_atual);
    // time_t data_b = mktime(&data_nascimento);

    // double diff_segundos = difftime(data_a, data_b);

    // //debug
    // printf("%.0f", diff_segundos);

    // //1 segundo = 3.1688×10^-8 anos

    // int diferenca_dias = ( diff_segundos / (3.1688 * pow(10, -8)) );

    // //resultado esperado: 599.525.453

    // return diferenca_dias;

}



void liberaConsultas(Atendimento* atendimento){

    for(int i=0; i<atendimento->qtd_consultas; i++){
    
        if(atendimento->lista_consultas[i]->alergia == 1) free(atendimento->lista_consultas[i]->medicamento_alergia);
        if(atendimento->lista_consultas[i]->qtd_lesoes > 0)free(atendimento->lista_consultas[i]->lesao);
        free(atendimento->lista_consultas[i]);

    }

    free(atendimento->lista_consultas);
    free(atendimento);

}



void abortaProcesso(Atendimento* atendimento){

}



void gravaLog(Consulta* consulta){

    //Checa o indice do ultimo log
    FILE* checa_logs;
    int cont_logs = 1;

    while(1){

        char str[10];
        sprintf(str, "log_%d", cont_logs);

        checa_logs = fopen(str, "r");

        if(checa_logs == NULL) break;

        cont_logs++;
        fclose(checa_logs);

    }

    //Grava novo arquivo log apos consulta
    char str[10];
    sprintf(str, "log_%d", cont_logs);

    FILE* log = fopen(str, "w");

    fprintf(log, "%s\n", consulta->cartao_sus);

    for(int i=1; i<=consulta->qtd_lesoes; i++)
        fprintf(log, "L%d\n", i);

    fclose(log);

}



void apagaLogs(){

    FILE* checa_logs;
    int cont_logs = 1;

    while(1){

        char str[10];
        sprintf(str, "log_%d", cont_logs);

        checa_logs = fopen(str, "r");

        if(checa_logs == NULL) break;

        fclose(checa_logs);
        remove(str);

        cont_logs++;

    }

}



void printDebugConsulta(Atendimento* atendimento){

    printf("%d %d %d %d %d %d %d %d %d %s %s %s %s\n",  atendimento->lista_consultas[0]->diabetes,
                                                        atendimento->lista_consultas[0]->fumante,
                                                        atendimento->lista_consultas[0]->historico_cancer,
                                                        atendimento->lista_consultas[0]->alergia,
                                                        atendimento->lista_consultas[0]->pele,
                                                        atendimento->lista_consultas[0]->qtd_lesoes,
                                                        atendimento->lista_consultas[0]->lesao->tamanho,
                                                        atendimento->lista_consultas[0]->lesao->cirurgia,
                                                        atendimento->lista_consultas[0]->lesao->crioterapia,
                                                        atendimento->lista_consultas[0]->medicamento_alergia,
                                                        atendimento->lista_consultas[0]->lesao->rotulo,
                                                        atendimento->lista_consultas[0]->lesao->diagnostico,
                                                        atendimento->lista_consultas[0]->lesao->regiao

    );

}

/*
//DEBUG
printf("chegou aqui\n");
exit(1);
*/