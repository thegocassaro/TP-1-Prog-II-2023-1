#include <stdio.h>
#include <stdlib.h>
#include "Paciente.h"
#include "Consulta.h"
#include "Funcionalidades.h"
#include "Menu.h"

/*
Tentei colocar um miniSADE.h como header pra todos meus .c (paciente, consulta, etc).
Funcionava quando eu compilava pelo terminal do wsl, mas quando tentei executar pelo build task do vscode
(pra criar o trab1.exe, pra tentar usar o debugger do vscode na config padrão) não reconhecia os outros .c,
perdia a referência.
Qual a vantagem ou necessidade de ter um .h individual pra cada .c?

Colocando #include "Paciente.h" ou "Paciente.c" compila igual sem dar erro e o código funcionou, 
mas não posso dizer com certeza se na prática é a mesma coisa
*/

int main(){

    int opcao = 0;

    Cadastro* cadastro = criaCadastro();
    Atendimento* atendimento = criaAtendimento();
    
    while(opcao != -1){

        layoutMenu();

        opcao = selecionaOpcao();

        switch(opcao){

            case PRE_CADASTRO:
                cadastro = preCadastroPaciente(cadastro);
                break;

            case ATENDIMENTO:
                atendimento = iniciaConsulta(atendimento, cadastro);    
                break;

            case BUSCA:
                geraArquivoBusca(cadastro, atendimento);
                break;

            case RELATORIO:
                geraRelatorio(cadastro, atendimento);
                break;

            case FINALIZAR:
                liberaPacientes(cadastro);
                liberaConsultas(atendimento);
                opcao = -1;
                break;

        }

    }

    //Limpa arquivos
    //apagaRelatorio();
    //apagaLogs();

    return 0;

}
