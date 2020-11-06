#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "std_lib_facilities(1).h"
#include "variable.h"
#include "token.h"

double expression();
double primary();
double term();
double declaration(Token let_or_const);
double statement();
void clean_up_mess();
void printHelp();
void calculate();

#endif // FUNCTIONS_H
