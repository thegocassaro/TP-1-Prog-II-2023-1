#include "Paciente.h"

struct paciente{

    char* nome;
    char cartao_sus[19];        //formato: 000-0000-0000-0000
    char data_nascimento[11];   //seria muito hype se eu conseguisse pedir pro usuario completar __/__/____ nos espacinhos tlg
    char telefone[15];          //formato: (00)00000-0000
    char genero[10];            //masculino, feminino, outros

};

//Pré-Cadastro


//Retorna um paciente caso acorra tudo certo / NULL se cartão já houver sido cadastrado

Paciente* preCadastroPaciente(){

    Paciente* paciente = (Paciente*) malloc(sizeof(Paciente));

    char nome_aux[50];

    scanf("%[^\n]\n", nome_aux);
    
    nome_aux[strlen(nome_aux) - 1] = '\0';          //Remove \n

    paciente->nome = strdup(nome_aux);              

    scanf(" %s\n", paciente->cartao_sus);           

    

    //Checa repetição de cartão sus

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

        if(strcmp(paciente->cartao_sus, token) == 0){

            fclose(file);

            printf("Esse número de cartão já existe. Por favor refaça o cadastro.\n");

            free(paciente->nome);
            free(paciente);

            paciente = NULL;

            return paciente;

        }

    }

    fclose(file);



    //Continua leitura

    scanf(" %s\n", paciente->data_nascimento);
    scanf(" %s\n", paciente->telefone);
    scanf(" %s\n", paciente->genero);

    //nao to entendendo pq ta guardando errado o primeiro caractere de cada string. 
    //nao pode ser problema do \n pq eu to engolindo todos com o scanf (se eu tiro todos dá errado igual)
    //ta guardando o telefone no genero e nada em telefone

    // fgets(paciente->cartao_sus, 19, stdin);
    // scanf("%*c");
    // fgets(paciente->data_nascimento, 11, stdin);
    // scanf("%*c");
    // fgets(paciente->telefone, 15, stdin);
    // scanf("%*c");
    // fgets(paciente->genero, 10, stdin);
    // scanf("%*c");

    return paciente;
}



void gravaPaciente(Paciente* paciente){

    FILE* file = fopen("banco_pacientes", "r+");

    if(file == NULL){
        printf("Erro na abertura do arquivo 'banco_pacientes'\n");
        exit(1);
    }

    int n_pacientes = 0;

    //Reescreve numero de pacientes

    fscanf(file, "%d", &n_pacientes);

    fseek(file, 0, SEEK_SET);

    fprintf(file, "%d", (n_pacientes + 1));

    //Grava em formato csv

    fseek(file, 0, SEEK_END);

    fprintf(file, "\n%s;%s;%s;%s;%s",   paciente->nome, 
                                        paciente->cartao_sus, 
                                        paciente->data_nascimento, 
                                        paciente->telefone, 
                                        paciente->genero);


    fclose(file);

}


void LiberaPacientes(Paciente* paciente){

    free(paciente->nome);
    free(paciente);

}



void printDebug(Paciente* paciente){

    printf("%s %s %s %s %s\n", paciente->nome, paciente->cartao_sus, paciente->data_nascimento, paciente->telefone, paciente->genero);
    
}