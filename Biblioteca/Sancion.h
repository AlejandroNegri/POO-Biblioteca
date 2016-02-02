#ifndef SANCION_H
#define SANCION_H
#include <ctime>
#include <string>
#include "Biblioteca.h"
using namespace std;

class Sancion{
	int NumeroLector;
	time_t FechaSancion_T;
	string Motivo;
public:
	Sancion(int p_numeroLector, string p_motivo);
	
	Sancion(int p_numeroLector, time_t p_fechaSancion_T, string p_motivo);
	
	int VerNumeroLector()const;
	
	string VerFechaSancion()const;
	
	time_t VerFechaSancion_T()const;
	
	string VerMotivo()const;	
};
#endif
