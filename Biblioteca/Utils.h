#ifndef UTILS_H
#define UTILS_H
#include <string>
#include "Libro.h"
using namespace std;

void 	pasar_a_minusculas(string &s);
string	TimeT_a_FormatoFecha(long t);
long 	Dias_a_TimeT(int cantDias);
long 	CalcularFechaLimite(int cantDias);
bool 	NoEstaOculto_Funcion(Libro l);
string 	IntToString(int num);


#endif
