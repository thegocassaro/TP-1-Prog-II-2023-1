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


    //Pega cartao sus e checa existencia
    char cartao_sus[19];
    scanf(" %s", cartao_sus);
    int checa_cartao = verificaCadastro(cartao_sus);

    if(checa_cartao == 0){

        printf("Esse número de cartão não está cadastrado. Consulta abortada.\n");
        free(consulta);

        return NULL;

    }


    //Diabetes
    printf("(SIM ou NAO) Possui diabetes? ");
    scanf(" %s", getResposta);

    converteLetrasMaiusculo(getResposta);
    aux = verificaResposta(getResposta);
    //DEBUG
    printf("%d\n", aux);
    
    // if(aux == -1) abortaProcesso(consulta);
    consulta->diabetes = aux;


    //Fumante
    printf("(SIM ou NAO) É fumante? ");
    scanf(" %s", getResposta);

    converteLetrasMaiusculo(getResposta);
    aux = verificaResposta(getResposta);
    //DEBUG
    printf("%d\n", aux);
    
    // if(aux == -1) abortaProcesso(consulta);
    consulta->fumante = aux;
    

    //Alergia
    printf("(SIM ou NAO) Alergia a algum medicamento? ");
    scanf(" %s", getResposta);

    converteLetrasMaiusculo(getResposta);
    aux = verificaResposta(getResposta);
    //DEBUG
    printf("%d\n", aux);
    
    // if(aux == -1) abortaProcesso(consulta);
    consulta->alergia = aux;

    if(consulta->alergia){

        scanf(" %[^\n]", getMedicamento);

        converteLetrasMaiusculo(getMedicamento);
        consulta->medicamento_alergia = strdup(getMedicamento);
        //DEBUG
        printf("%s\n", getMedicamento);
        printf("%d\n", aux);

    }


    //Historico de cancer
    printf("(SIM ou NAO) Possui histórico de câncer? ");
    scanf(" %s", getResposta);

    converteLetrasMaiusculo(getResposta);
    aux = verificaResposta(getResposta);
    //DEBUG
    printf("%d\n", aux);
    
    // if(aux == -1) abortaProcesso(consulta);
    consulta->historico_cancer = aux;
    

    //Pele
    printf("(I, II, III, IV, V, VI) Tipo de pele? ");
    scanf(" %s", getResposta);

    converteLetrasMaiusculo(getResposta);
    aux = verificaPele(getResposta);
    //DEBUG
    printf("%d\n", aux);

    // if(aux == -1) abortaProcesso(consulta);
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
        scanf(" %s", getResposta);
        //DEBUG
        printf("%s\n", getResposta);

        converteLetrasMaiusculo(getResposta);
        strcpy( consulta->lesao[id].diagnostico, getResposta );


        //Regiao
        printf("Região: ");
        scanf(" %s", getResposta);
        //DEBUG
        printf("%s\n", getResposta);

        converteLetrasMaiusculo(getResposta);
        strcpy( consulta->lesao[id].regiao, getResposta );


        //Tamanho
        printf("(mm) Tamanho: ");
        scanf(" %d\n", &consulta->lesao[id].tamanho);
        //DEBUG
        printf("%d\n", consulta->lesao[id].tamanho);


        //Cirurgia
        printf("(SIM ou NAO) Necessidade de cirurgia? ");
        scanf(" %s", getResposta);

        converteLetrasMaiusculo(getResposta);
        aux = verificaResposta(getResposta);
        //DEBUG
        printf("%d\n", aux);
        
        // if(aux == -1) abortaProcesso(consulta);
        consulta->lesao[id].cirurgia = aux;


        //Crioterapia
        printf("(SIM ou NAO) Necessidade de crioterapia? ");
        scanf(" %s", getResposta);

        converteLetrasMaiusculo(getResposta);
        aux = verificaResposta(getResposta);
        //DEBUG
        printf("%d\n", aux);
        
        // if(aux == -1) abortaProcesso(consulta);
        consulta->lesao[id].crioterapia = aux;


        //Mais lesoes?
        printf("(SIM ou NAO) Deseja cadastrar outra lesão? ");
        scanf(" %s", getResposta);

        converteLetrasMaiusculo(getResposta);
        aux = verificaResposta(getResposta);
        //DEBUG
        printf("%d\n", aux);
        
        // if(aux == -1) abortaProcesso(consulta);

        if(aux == 0) break;

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

    if(!strcmp(resposta, "I")) return 1;
    if(!strcmp(resposta, "II")) return 2;
    if(!strcmp(resposta, "III")) return 3;
    if(!strcmp(resposta, "IV")) return 4;
    if(!strcmp(resposta, "V")) return 5;
    if(!strcmp(resposta, "VI")) return 6;

    return -1;

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

    fscanf(file, "%d", &n_pacientes);

    for(int i=0; i<n_pacientes; i++){

        fscanf(file, " %[^\n]", linha);

        token = strtok(linha, ";");
        token = strtok(NULL, ";");

        //Se existir cartao, tambem exibe o nome e idade do paciente
        if(strcmp(cartao_sus, token) == 0){

            token = strtok(linha, ";");
            char* nome = strdup(token);

            token = strtok(NULL, ";");
            token = strtok(NULL, ";");
            char* getIdade = strdup(token);
            
            int dia, mes, ano;
            sscanf(getIdade, "%d/%d/%d", &dia, &mes, &ano);

            int idade = calculaIdade(dia, mes, ano);

            printf("NOME: %s\n", nome);
            printf("IDADE: %d\n\n", idade);

            free(nome);
            free(getIdade);
            fclose(file);

            return 1;

        }

    }

    fclose(file);

    return 0;

}



int calculaIdade(int dia_b, int mes_b, int ano_b){

    //data atual: 11/05/2023
    
    //tm_year -> number of years since 1900
    //tm_mon -> range 0 to 11

    int dia_a = 11, mes_a = 4, ano_a = (2023 - 1900);
    
    mes_b -= 1;
    ano_b -= 1900;

    struct tm data_atual, data_nascimento;

    data_atual.tm_mday = dia_a;
    data_atual.tm_mon = mes_a;
    data_atual.tm_year = ano_a;

    data_nascimento.tm_mday = dia_b;
    data_nascimento.tm_mon = mes_b;
    data_nascimento.tm_year = ano_b;

    time_t data_a = mktime(&data_atual);
    time_t data_b = mktime(&data_nascimento);

    double idade = difftime(data_a, data_b);

    //1 segundo = 3.1688×10^-8 anos

    int diferenca_dias = ( idade / (3.1688 * pow(10, -8)) );

    return diferenca_dias;

}



void liberaConsulta(Consulta* consulta){

    if(consulta->alergia == 1) free(consulta->medicamento_alergia);
    free(consulta->lesao);
    free(consulta);

}



void abortaProcesso(Consulta* consulta){

}



void gravaLog(Consulta* consulta){

    //Checa o indice do ultimo log
    FILE* checa_logs;
    int cont_logs = 1;

    while(1){

        char str[10] = "log_";
        sprintf(str, "%d", cont_logs);

        checa_logs = fopen(str, "r");
        cont_logs++;

        if(checa_logs == NULL) break;

        fclose(checa_logs);

    }

    fclose(checa_logs);

    //Grava novo arquivo log apos consulta
    char str[10] = "log_";
    sprintf(str, "%d", cont_logs);

    FILE* log = fopen(str, "w");



}



void printDebugConsulta(Consulta* consulta){

    printf("%d %d %d %d %d %d %d %d %d %s %s %s %s\n",  consulta->diabetes,
                                                        consulta->fumante,
                                                        consulta->historico_cancer,
                                                        consulta->alergia,
                                                        consulta->pele,
                                                        consulta->cont_lesao,
                                                        consulta->lesao->tamanho,
                                                        consulta->lesao->cirurgia,
                                                        consulta->lesao->crioterapia,
                                                        consulta->medicamento_alergia,
                                                        consulta->lesao->rotulo,
                                                        consulta->lesao->diagnostico,
                                                        consulta->lesao->regiao

    );

}