#include "Paciente.h"

struct cadastro{

    Paciente** lista_pacientes;
    int qtd_pacientes;

};

struct paciente{

    char* nome;
    char cartao_sus[19];        //formato: 000-0000-0000-0000
    char data_nascimento[11];   //seria muito hype se eu conseguisse pedir pro usuario completar __/__/____ nos espacinhos tlg
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

    char nome_aux[50];

    scanf("%[^\n]", nome_aux);
    
    nome_aux[strlen(nome_aux)] = '\0';          //Remove \n

    paciente->nome = strdup(nome_aux);              

    scanf(" %s", paciente->cartao_sus);           

    

    //Checa repetição de cartão sus

    FILE* file = fopen("banco_pacientes", "r");            //mudar aqui pra ao inves de ler do arquivo, ele comparar pelos vetores mesmo
    
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

        if(strcmp(paciente->cartao_sus, token) == 0){

            fclose(file);

            printf("Esse número de cartão já existe. Por favor refaça o cadastro.\n");

            free(paciente->nome);
            free(paciente);

            paciente = NULL;

            return cadastro;

        }

    }

    fclose(file);

    //Continua leitura

    scanf(" %s", paciente->data_nascimento);
    scanf(" %s", paciente->telefone);
    scanf(" %s", paciente->genero);

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

    cadastro->lista_pacientes = (Paciente**)realloc(cadastro->lista_pacientes, sizeof(Paciente*) * (cadastro->qtd_pacientes + 1));
    cadastro->lista_pacientes[cadastro->qtd_pacientes] = paciente;
    cadastro->qtd_pacientes++;

    return cadastro;
}



// void gravaPaciente(Cadastro* cadastro){

//     FILE* file = fopen("banco_pacientes", "r+");

//     if(file == NULL){
//         printf("Erro na abertura do arquivo 'banco_pacientes'\n");
//         exit(1);
//     }

//     int n_pacientes = 0;

//     //Reescreve numero de pacientes

//     fscanf(file, "%d", &n_pacientes);

//     fseek(file, 0, SEEK_SET);

//     fprintf(file, "%d", (n_pacientes + 1));

//     //Grava em formato csv

//     fseek(file, 0, SEEK_END);

//     fprintf(file, "\n%s;%s;%s;%s;%s",   paciente->nome, 
//                                         paciente->cartao_sus, 
//                                         paciente->data_nascimento, 
//                                         paciente->telefone, 
//                                         paciente->genero);


//     fclose(file);

// }


void liberaPacientes(Cadastro* cadastro){

    for(int i=0; i<cadastro->qtd_pacientes; i++){
        free(cadastro->lista_pacientes[i]->nome);
        free(cadastro->lista_pacientes[i]);
    }

    free(cadastro->lista_pacientes);
    free(cadastro);

}



void printDebugPaciente(Cadastro* cadastro){

    printf("%s %s %s %s %s\n", cadastro->lista_pacientes[0]->nome, 
    cadastro->lista_pacientes[0]->cartao_sus, 
    cadastro->lista_pacientes[0]->data_nascimento, 
    cadastro->lista_pacientes[0]->telefone, 
    cadastro->lista_pacientes[0]->genero);
    
}



void reiniciaBancoPacientes(){

    FILE* file = fopen("banco_pacientes", "w");

    if(file == NULL){
        printf("Erro na abertura do arquivo 'banco_pacientes'\n");
        exit(1);
    }

    fprintf(file, "%d", 0);

    fclose(file);

}