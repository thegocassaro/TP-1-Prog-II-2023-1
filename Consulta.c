#include "Consulta.h"

struct consulta{

    int diabetes, fumante, alergia, historico_cancer;
    char* medicamento_alergia;
    int pele;                       //(I, II, III, IV, V, VI)

    Lesao* lesao;
    int cont_lesao;

};

struct lesao{

    char rotulo[3];                 //L1, L2, ..., LN
    char diagnostico[24];           //Carcinoma Basocelular, Carcinoma Espinocelular, Melanoma, Ceratose Actínica, Nevo e Ceratose Seborréica
    char regiao[15];                //Face, Orelha, Couro cabeludo, Peitoral, Dorso, Abdome,  Braço, Antebraço, Mão, Coxa, Canela e Pé
    int tamanho;                    //mm
    int cirurgia, crioterapia;

};



Consulta* criaConsulta(){

    Consulta* consulta = (Consulta*)calloc(1, sizeof(Consulta));
    return consulta;

}



Consulta* iniciaConsulta(Consulta* consulta){

    char getResposta[4];
    char getMedicamento[TAM_MAX_MEDICAMENTO];
    int aux = 0;


    //Diabetes
    printf("(SIM ou NAO) Possui diabetes? ");
    scanf(" %s\n", getResposta);

    converteLetrasMaiusculo(getResposta);
    aux = verificaResposta(getResposta);
    if(aux == -1) abortaProcesso(consulta);
    consulta->diabetes = aux;


    //Fumante
    printf("(SIM ou NAO) É fumante? ");
    scanf(" %s\n", getResposta);

    converteLetrasMaiusculo(getResposta);
    aux = verificaResposta(getResposta);
    if(aux == -1) abortaProcesso(consulta);
    consulta->fumante = aux;
    

    //Alergia
    printf("(SIM ou NAO) Alergia a algum medicamento? ");
    scanf(" %s\n", getResposta);

    converteLetrasMaiusculo(getResposta);
    aux = verificaResposta(getResposta);
    if(aux == -1) abortaProcesso(consulta);
    consulta->alergia = aux;


    //Medicamento
    if(consulta->alergia == 1){

        printf("Nome do medicamento: ");
        scanf(" %s\n", getResposta);

        converteLetrasMaiusculo(getResposta);
        consulta->medicamento_alergia = strdup(getResposta);
    }
    
    else consulta->medicamento_alergia = NULL;


    //Historico de cancer
    printf("(SIM ou NAO) Possui histórico de câncer? ");
    scanf(" %s\n", getResposta);

    converteLetrasMaiusculo(getResposta);
    aux = verificaResposta(getResposta);
    if(aux == -1) abortaProcesso(consulta);
    consulta->historico_cancer = aux;
    

    //Pele
    printf("(I, II, III, IV, V, VI) Tipo de pele? ");
    scanf(" %s\n", getResposta);

    converteLetrasMaiusculo(getResposta);
    aux = verificaPele(getResposta);
    if(aux == -1) abortaProcesso(consulta);
    consulta->pele = aux;



    //Lesoes

    //Experimentando usar *lesao ao invés de **lesao, como normalmente faria

    consulta->lesao = (Lesao*)calloc(1, sizeof(Lesao));
    consulta->cont_lesao = 1;

    while(1){

        int id = consulta->cont_lesao - 1;
        
        //Rotulo
        sprintf( consulta->lesao[id].rotulo, "L%c", ('0' + consulta->cont_lesao) ); 


        //Diagnostico
        printf("Diagnóstico: ");
        scanf(" %s\n", getResposta);

        converteLetrasMaiusculo(getResposta);
        strcpy( consulta->lesao[id].diagnostico, getResposta );


        //Regiao
        printf("Região: ");
        scanf(" %s\n", getResposta);

        converteLetrasMaiusculo(getResposta);
        strcpy( consulta->lesao[id].regiao, getResposta );


        //Tamanho
        printf("(mm) Tamanho: ");
        scanf(" %d\n", consulta->lesao[id].tamanho);


        //Cirurgia
        printf("(SIM ou NAO) Necessidade de cirurgia? ");
        scanf(" %s\n", getResposta);

        converteLetrasMaiusculo(getResposta);
        aux = verificaResposta(getResposta);
        if(aux == -1) abortaProcesso(consulta);
        consulta->lesao[id].cirurgia = aux;


        //Crioterapia
        printf("(SIM ou NAO) Necessidade de crioterapia? ");
        scanf(" %s\n", getResposta);

        converteLetrasMaiusculo(getResposta);
        aux = verificaResposta(getResposta);
        if(aux == -1) abortaProcesso(consulta);
        consulta->lesao[id].crioterapia = aux;


        //Mais lesoes?
        printf("(SIM ou NAO) Deseja cadastrar outra lesão? ");
        scanf(" %s\n", getResposta);

        converteLetrasMaiusculo(getResposta);
        aux = verificaResposta(getResposta);
        if(aux == -1) abortaProcesso(consulta);

        else if(aux == 0) break;

        //if aux == 1
        consulta->cont_lesao += 1;
        consulta->lesao = (Lesao*)realloc(consulta->lesao, sizeof(Lesao) * (consulta->cont_lesao));
    
        //se eu realoco um ponteiro que eu iniciei com calloc, ele setta os bytes pra zero também?

    }

    return consulta;

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

}



int verificaCadastro(char* cartao_sus){                 //Retorna 1 se existe / 0 se não

    FILE* file = fopen("banco_pacientes", "r");

    if(file == NULL){
        printf("Erro na abertura do arquivo 'banco_pacientes'");
        exit(0);
    }

    int n_pacientes = 0;
    char linha[TAM_MAX_LINHA];
    char* token;

    fscanf(file, "%d\n", &n_pacientes);

    for(int i=0; i<n_pacientes; i++){

        fscanf(file, " %[^\n]", linha);

        token = strtok(linha, ";");
        token = strtok(NULL, ";");

        if(strcmp(cartao_sus, token) == 0){

            fclose(file);

            return 1;

        }

    }

    fclose(file);

    return 0;

}

//oi

void liberaConsulta(Consulta* consulta){

    free(consulta->medicamento_alergia);
    free(consulta->lesao);
    free(consulta);

}