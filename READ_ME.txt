/*
Universidade de Brasilia - 02/2018
CIC 116432 - Software Basico - Turma B
Professor Bruno Macchiavello
Trabalho Pratico 2 - Tradutor

Alunos: Andre Abreu Rodrigues de Almeida    12/0007100
        Alvaro Queiroz dos Reis Silva       15/0155280
*/

*** INSTRUÇÕES DE COMPILAÇÃO***
O código para ser compilado DEVE ser compilado com um compilador capaz de usar os recursos do C++ versão 11.
Comandos de compilação usados:

*SO: Ubuntu 5.4.0-6ubuntu1~16.04.9
*Compilador: gcc 5.4.0 20160609
*comando: g++ -std=c++11 -Wall *.cpp
*obs: compilado na pasta /src.

*SO:OSX x86_64-apple-darwin17.5.0
*Compilador: CLANG -> Apple LLVM version 9.1.0 (clang-902.0.39.1)
*comando: clang++ -std=c++11 -Wall *.cpp
*obs: compilado na pasta /src.

*** INSTRUÇÕES DE USO***
O programa procura na pasta /src um arquivo "arquivo.asm" para traduzir. Como saída, ele coloca na mesma pasta um arquivo traduzido "arquivo.s" com o programa correspondente em IA-32 que pode ser montado com NASM.
