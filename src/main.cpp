/*
Universidade de Brasilia - 02/2018
CIC 116432 - Software Basico - Turma B
Professor Bruno Macchiavello
Trabalho Pratico 2 - Tradutor

Alunos: Andre Abreu Rodrigues de Almeida    12/0007100
        Alvaro Queiroz dos Reis Silva       15/0155280
*/


#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <list>
#include "scanner.h"
using namespace std;

#define __DEBUG__

int error_found;


int main (){
    list<Token> tokenlist;
    list<Token>::iterator it, aux;
    char s[] = "arquivo.asm";

    identify_tokens(s , tokenlist);

    #ifdef __DEBUG__
        print_list (tokenlist);
    #endif

    return 0;
}
