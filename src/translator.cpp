#include "translator.h"

#define __DEBUG2__

int translator (list <Token> & tokenlist, char * s){
	list<Token>::iterator it;
	ofstream nasmfile( s, ios_base::app);  //opens NASM file in output mode - always writes at end (append)
	if (nasmfile.is_open())
		nasmfile << "global      _start" << endl;
	else{
		cout << "Falha na criação ou abertura do arquivo." << endl;
		exit(EXIT_FAILURE);
	}
	nasmfile.close();

	for (it = tokenlist.begin();it != tokenlist.end(); it++){	//scans whole file
		switch (it->type){
			case TT_MNEMONIC:		//check OPCODE table
				#ifdef __DEBUG2__
				cout << "foi-mnemonic - " << it->str << endl;
				#endif
				transl_mnemonic(it, s);
			break;

			case TT_LABEL:
				#ifdef __DEBUG2__
				cout << "foi-label - " << it->str << endl;
				#endif
				transl_label(it, s);
			break;

			case TT_DIRECTIVE:
				#ifdef __DEBUG2__
				cout << "foi-directive - " << it->str << endl;
				#endif
				transl_directive(it, s);
			break;
			case TT_OPERAND          	:
			case TT_CONST        		:
			case TT_COMMA_OPERATOR   	:
			case TT_PLUS_OPERATOR		:
			case TT_AMPERSAND_OPERATOR 	:
				#ifdef __DEBUG2__
				cout << "foi-outro - " << it->str << endl;
				#endif
			break;
			default:
				cerr << "Parser: unknowm token type (" << it->str << ")." << endl;
				it++;
			break;
		}
	}
	return 0;
}

list<Token>::iterator transl_mnemonic(list<Token>::iterator it, char * s){
	ofstream nasmfile( s, ios::out | ios::app);  //opens NASM file in output mode - always writes at end (append)
	switch (it->addit_info){
		 case OP_ADD      :
			if (nasmfile.is_open()){
			 	nasmfile << "add eax, ";
				it++;
				nasmfile << it->str << endl;
				it++;
			}else{
		 		cout << "Falha na criação ou abertura do arquivo." << endl;
		 		exit(EXIT_FAILURE);
			}
		 break;
		 case OP_SUB      :
		 if (nasmfile.is_open()){
			nasmfile << "sub eax, ";
			it++;
			nasmfile << it->str << endl;
			it++;
		}else{
			cout << "Falha na criação ou abertura do arquivo." << endl;
			exit(EXIT_FAILURE);
		}
		 break;
		 case OP_MULT     :

		 break;
		 case OP_DIV      :

		 break;
		 case OP_JMP      :

		 break;
		 case OP_JMPN     :

		 break;
		 case OP_JMPP     :

		 break;
		 case OP_JMPZ     :

		 break;
		 case OP_COPY     :

		 break;
		 case OP_LOAD     :


		 break;
		 case OP_STORE    :


		 break;
		 case OP_INPUT    :


		 break;
		 case OP_OUTPUT   :


		 break;
		 case OP_C_INPUT  :


		 break;
		 case OP_C_OUTPUT :


		 break;
		 case OP_S_INPUT  :


		 break;
		 case OP_S_OUTPUT :


		 break;
		 case OP_STOP     :


		 break;
		 case OP_BASIC_OP :      //"+, -, /, *, %"

		 break;

		 default:
			 cerr << "Parser: unknowm token type (" << it->str << ")." << endl;
			 it++;
		 break;
	}
	nasmfile.close();
	return it;
}

list<Token>::iterator transl_label(list<Token>::iterator it, char * s){
	ofstream nasmfile( s, ios::out | ios::app);  //opens NASM file in output mode - always writes at end (append)
	if (nasmfile.is_open())
		nasmfile << it->str << " ";
	else{
		cout << "Falha na criação ou abertura do arquivo." << endl;
		exit(EXIT_FAILURE);
	}
	it ++;
	nasmfile.close();
	return it;
}

list<Token>::iterator transl_directive(list<Token>::iterator it, char * s){
	ofstream nasmfile( s, ios::out | ios::app);  //opens NASM file in output mode - always writes at end (append)
	switch (it->addit_info){
		case DIR_SECTION :
			if (nasmfile.is_open())
				nasmfile << "section ";
			else{
				cout << "Falha na criação ou abertura do arquivo." << endl;
				exit(EXIT_FAILURE);
			}
			it ++;
		break;
		case DIR_SPACE :

		break;
		case DIR_CONST :

		break;
		case DIR_EQU :

		break;
		case DIR_IF :

		break;
		case DIR_MACRO :

		break;
		case DIR_ENDMACRO :

		break;
		case DIR_TEXT :
			if (nasmfile.is_open())
				nasmfile << ".text" << endl << "_start: ";
			else{
				cout << "Falha na criação ou abertura do arquivo." << endl;
				exit(EXIT_FAILURE);
			}
			it ++;
		break;
		case DIR_DATA :
			if (nasmfile.is_open())
				nasmfile << ".data" << endl;
			else{
				cout << "Falha na criação ou abertura do arquivo." << endl;
				exit(EXIT_FAILURE);
			}
			it ++;
		break;
		case DIR_BEGIN :

		break;
		case DIR_END :

		break;
		case DIR_EXTERN :

		break;
		case DIR_PUBLIC :

		break;
		case DIR_BSS :
			if (nasmfile.is_open())
				nasmfile << ".bss" << endl;
			else{
				cout << "Falha na criação ou abertura do arquivo." << endl;
				exit(EXIT_FAILURE);
			}
			it ++;
		break;

		default:
			cerr << "Parser: unknowm token type (" << it->str << ")." << endl;
			it++;
		break;
		}
		nasmfile.close();
	return it;
}
