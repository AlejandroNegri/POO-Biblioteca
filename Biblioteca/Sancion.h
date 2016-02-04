#ifndef SANCION_H
#define SANCION_H
#include <ctime>
#include <string>
#include "Biblioteca.h"
using namespace std;

class Sancion{
	int NumeroLector;
	long FechaSancion_T;
	string Motivo;
public:
	Sancion(int p_numeroLector, string p_motivo, int cant_dias);
	
	Sancion(int p_numeroLector, long p_fechaSancion_T, string p_motivo);
	
	int VerNumeroLector()const;
	
	string VerFechaSancion()const;
	
	long VerFechaSancion_T()const;
	
	string VerMotivo()const;	
};
#endif
