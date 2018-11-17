#ifndef TRANSLATOR_H_
#define TRANSLATOR_H_

#include "scanner.h"
#include "parser.h"

int translate (char * s, std::list<Token> & tokenlist);


#endif /* TRANSLATOR_H_ */
