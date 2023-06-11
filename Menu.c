#include "Menu.h"

void layoutMenu(){

    printf("      ___                       ___                       ___           ___           ___           ___      \n");
    printf("     /\\__\\          ___        /\\__\\          ___        /\\  \\         /\\  \\         /\\  \\         /\\  \\     \n");
    printf("    /::|  |        /\\  \\      /::|  |        /\\  \\      /::\\  \\       /::\\  \\       /::\\  \\       /::\\  \\    \n");
    printf("   /:|:|  |        \\:\\  \\    /:|:|  |        \\:\\  \\    /:/\\ \\  \\     /:/\\:\\  \\     /:/\\:\\  \\     /:/\\:\\  \\   \n");
    printf("  /:/|:|__|__      /::\\__\\  /:/|:|  |__      /::\\__\\  _\\:\\~\\ \\  \\   /::\\~\\:\\  \\   /:/  \\:\\__\\   /::\\~\\:\\  \\  \n");
    printf(" /:/ |::::\\__\\  __/:/\\/__/ /:/ |:| /\\__\\  __/:/\\/__/ /\\ \\:\\ \\ \\__\\ /:/\\:\\ \\:\\__\\ /:/__/ \\:|__| /:/\\:\\ \\:\\__\\ \n");
    printf(" \\/__/~~/:/  / /\\/:/  /    \\/__|:|/:/  / /\\/:/  /    \\:\\ \\:\\ \\/__/ \\/__\\:\\/:/  / \\:\\  \\ /:/  / \\:\\~\\:\\ \\/__/ \n");
    printf("       /:/  /  \\::/__/         |:/:/  /  \\::/__/      \\:\\ \\:\\__\\        \\::/  /   \\:\\  /:/  /   \\:\\ \\:\\__\\   \n");
    printf("      /:/  /    \\:\\__\\         |::/  /    \\:\\__\\       \\:\\/:/  /        /:/  /     \\:\\/:/  /     \\:\\ \\/__/   \n");
    printf("     /:/  /      \\/__/         /:/  /      \\/__/        \\::/  /        /:/  /       \\::/__/       \\:\\__\\     \n");
    printf("     \\/__/                     \\/__/                     \\/__/         \\/__/         ~~            \\/__/     \n");

    printf("\nEscolha uma opcao:\n- Pre-cadastrar um paciente (P ou p)\n- Iniciar um atendimento (A ou a)\n");
    printf("- Buscar um paciente (B ou b)\n- Gerar relatorio (R ou r)\n- Finalizar programa (F ou f)\n\n");

}



int selecionaOpcao(){

    int opcao;
    char letra;

    scanf(" %c", &letra);

    switch(converteLetraMaiusculo(letra)){

        case 'P':
            return PRE_CADASTRO;
        case 'A':
            return ATENDIMENTO;
        case 'B':
            return BUSCA;
        case 'R':
            return RELATORIO;
        case 'F':
            return FINALIZAR;

    }

    return -1;

}



char converteLetraMaiusculo(char c){

    if(c >= 'a' && c <= 'z') c -= 32;

    return c;

}