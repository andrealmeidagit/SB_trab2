# Software Básico - Trabalho 2 - 2/2018


## Objetivo

Fixar o funcionamento de um processo de ligação e formato de arquivos.

## Especificação

Deve ser implementado um tradutor que converta um programa da linguagem assembly hipotética didática de sala de aula para IA-32.
Não é necessária a detecção de erros.

### Entradas

Arquivo texto "arquivo.asm" com o programa em assembly didático.

### Saídas

Arquivo texto "arquivo.s" contendo o programa traduzido para IA-32.

### Requisitos de sistema

O programa traduzido deve ser compilável em ambiente Linux 32bits, com montador NASM.
O programa tradutor deve ser feito em C/C++ e deve ser chamado "tradutor.c".
