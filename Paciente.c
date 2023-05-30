#include "Paciente.h"

struct paciente{

    char* nome;
    char cartao_sus[19];        //formato: 000-0000-0000-0000
    char data_nascimento[11];   //seria muito hype se eu conseguisse pedir pro usuario completar __/__/____ nos espacinhos tlg
    char telefone[15];          //formato: (00)00000-0000
    char genero[10];            //masculino, feminino, outros

};

//Pré-Cadastro

//O cartão do SUS é o identificador único do paciente. Portanto, o sistema deve garantir que não seja possível 
//cadastrar mais de um paciente com o mesmo número do SUS. Se houver tentativa de realizar a operação, 
//o sistema deve informar o usuário que não é possível pois já existe paciente cadastrado com o mesmo número.

Paciente* preCadastroPaciente(){

    Paciente* paciente = (Paciente*) malloc(sizeof(Paciente));

    char nome_aux[50];

    fgets(nome_aux, 49, stdin);

    paciente->nome = strdup(nome_aux);

    fgets(paciente->cartao_sus, 19, stdin);
    fgets(paciente->data_nascimento, 11, stdin);
    fgets(paciente->telefone, 15, stdin);
    fgets(paciente->genero, 10, stdin);

    return paciente;
}



void LiberaPacientes(Paciente* paciente){

    free(paciente->nome);
    free(paciente);

}



void printDebug(Paciente* paciente){

    puts(paciente->nome);
    puts(paciente->cartao_sus);
    puts(paciente->data_nascimento);
    puts(paciente->genero);
    puts(paciente->telefone);

    //printf("%s %s %s %s %s\n", paciente->nome, paciente->cartao_sus, paciente->data_nascimento, paciente->telefone, paciente->genero);
    
}