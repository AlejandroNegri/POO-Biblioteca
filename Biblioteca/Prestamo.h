#ifndef PRESTAMO_H
#define PRESTAMO_H
#include <string>
#include <ctime>
#include <sstream>
using namespace std;

struct registro_prestamo {
	int numeroLector;
	int codigoLibro;
	long fechaDesde_t;
	long fechaHasta_t;

};

class Prestamo {
	int 	NumeroLector;
	int 	CodigoLibro;	
	long	FechaDesde_T;
	long 	FechaHasta_T;
public: 	
	Prestamo(int p_numeroLector,int p_CodigoLibro);	
	Prestamo(int p_numeroLector,int p_CodigoLibro, long p_FechaDesde_TimeT , long p_FechaHasta_TimeT);
	int 	VerNumeroLectorPrestamo()const;	
	int 	VerCodigoLibroPrestamo()const;	
	string	VerFechaDesde()const;	
	string 	VerFechaHasta()const;	
	long 	VerFechaDesde_T()const;	
	long 	VerFechaHasta_T()const;	
	int 	VerificarEntregaATiempo()const;
};
#endif
