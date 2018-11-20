#include "translator.h"

int translator (list <Token> & tokenlist, char * s){
	list<Token>::iterator it;

ofstream nasmfile( s );  //opens NASM file in write mode

	for (it = tokenlist.begin();it != tokenlist.end(); it++){	//scans whole file

		ofstream nasmfile( s );  //opens NASM file
		nasmfile << "global      _start\n_start:\n";
		nasmfile.close();

		switch (it->type){
			case TT_MNEMONIC:		//check OPCODE table
				it = transl_mnemonic(it, s);
			break;

			case TT_LABEL:
				it = transl_label(it, s);
			break;

			case TT_DIRECTIVE:
				it = transl_directive(it, s);
			break;
			case TT_OPERAND          	:
			case TT_CONST        		:
			case TT_COMMA_OPERATOR   	:
			case TT_PLUS_OPERATOR		:
			case TT_AMPERSAND_OPERATOR 	:
				it++;
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
	ofstream nasmfile( s );  //opens NASM file
	switch (it->addit_info){
		 case OP_ADD      :
		 	nasmfile << "add";
			it++;
			nasmfile << it->str << endl;
			it++;
		 break;
		 case OP_SUB      :
			 nasmfile << "sub";
			 it++;
			 nasmfile << it->str << endl;
			 it++;
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
	ofstream nasmfile( s );  //opens NASM file
	nasmfile << it->str << " ";
	it ++;
	nasmfile.close();
	return it;
}

list<Token>::iterator transl_directive(list<Token>::iterator it, char * s){
	ofstream nasmfile( s );  //opens NASM file
	switch (it->addit_info){
		case DIR_SECTION :
			nasmfile << "section ";
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
			nasmfile << ".text\n";
			it ++;
		break;
		case DIR_DATA :
			nasmfile << ".data\n";
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
			nasmfile << ".bss\n";
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
