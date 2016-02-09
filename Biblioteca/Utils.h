#ifndef UTILS_H
#define UTILS_H
#include <string>
#include "Libro.h"
using namespace std;

void pasar_a_minusculas(string &s);

string TimeT_a_String(long t);

long String_a_TimeT(string s);

string TimeT_a_FormatoFecha(long t);

long CalcularFecha(int cantDias);

bool NoEstaOculto_Funcion(Libro l);


#endif
