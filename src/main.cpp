/*
Universidade de Brasilia - 02/2018
CIC 116432 - Software Basico - Turma B
Professor Bruno Macchiavello
Trabalho Pratico 2 - Tradutor

Alunos: Andre Abreu Rodrigues de Almeida    12/0007100
        Alvaro Queiroz dos Reis Silva       15/0155280
*/


#include "scanner.h"
#include "translator.h"
using namespace std;

#define __DEBUG__

int error_found;


int main (){
    list<Token> tokenlist;
    list<Token>::iterator it, aux;
    char inp_filename[] = "arquivo.asm";       //defines input file name
    char out_filename[] = "arquivo.s";       //defines input file name

    identify_tokens(inp_filename , tokenlist);     //creates tokenlist with educational assembly code

    #ifdef __DEBUG__
        print_list (tokenlist);
    #endif

    translate(out_filename, tokenlist);     //creates NASM file based on tokenlist

    return 0;
}