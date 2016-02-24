#ifndef SANCION_H
#define SANCION_H
#include <ctime>
#include <string>
#include "Biblioteca.h"
using namespace std;

struct registro_sancion {
	int 	numeroLector;
	long 	fechaSancion_t;
	char 	motivo[256];	
};

class Sancion{
	int 	NumeroLector;
	long 	FechaSancion_T;
	string 	Motivo;
public:
	
	Sancion(int p_numeroLector, long p_fechaSancion_T, string p_motivo);	
	void	ProlongarSancion(long cantDias, string p_motivo);	
	int 	VerNumeroLector()const;	
	string 	VerFechaSancion()const;	
	long 	VerFechaSancion_T()const;	
	string 	VerMotivo()const;	
};
#endif
