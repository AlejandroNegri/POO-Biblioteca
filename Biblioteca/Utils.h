/**
* @file Utils.cpp
* @brief Funciones varias para simplificar tareas
*
* En este archivo van las funciones generales. Es decir, las que no son 
* particulares de ninguna clase.
**/
#ifndef UTILS_H
#define UTILS_H
#include <string>
#include "Libro.h"
using std::string;

/// Convierte una cadena a solo minusculas
void 	pasar_a_minusculas(string &s);

/// Convierte un long (time_t) a un string con formato fecha
string	TimeT_a_FormatoFecha(long t);

/// Convierte una cantidad de dias a time_t
long 	Dias_a_TimeT(int cantDias);

/// Calcula la fecha limite en la que se debe devolver un préstamo
long 	CalcularFechaLimite(int cantDias);

/// Bool que devuelve si un libro no esta oculto
bool 	NoEstaOculto_Funcion(Libro l);

/// Convierte un entero en string
string 	IntToString(int num);

#endif
