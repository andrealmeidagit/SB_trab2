#ifndef TRANSLATOR_H_
#define TRANSLATOR_H_

#include "scanner.h"

using namespace std;

int translator(list <Token> & tokenlist, list <Token> & labellist);
list<Token>::iterator translator_mnemonic(list <Token> & tokenlist, list<Token>::iterator it);
list<Token>::iterator translator_directive(list <Token> & tokenlist, list<Token>::iterator it);
list<Token>::iterator translator_operand(list <Token> & tokenlist, list<Token>::iterator it);
list<Token>::iterator translator_const(list <Token> & tokenlist, list<Token>::iterator it);
list<Token>::iterator translator_ampersand(list <Token> & tokenlist, list<Token>::iterator it);
list<Token>::iterator translator_label(list <Token> & tokenlist, list<Token>::iterator it);

extern int pre_error;

#endif /* translator_H_ */
