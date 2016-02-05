#include <algorithm>
#include "Prestamo.h"
#include "Biblioteca.h"
#include <wx/msgdlg.h>
#include "Utils.h"

Prestamo::Prestamo(int p_numeroLector,int p_CodigoLibro)
	: NumeroLector(p_numeroLector), CodigoLibro (p_CodigoLibro) {
	FechaDesde_T = CalcularFecha(0);
	FechaHasta_T = CalcularFecha(7);

}

Prestamo::Prestamo(int p_numeroLector,int p_CodigoLibro, long p_FechaDesde_T, long p_FechaHasta_T)
	: NumeroLector(p_numeroLector), CodigoLibro(p_CodigoLibro), FechaDesde_T(p_FechaDesde_T), FechaHasta_T(p_FechaHasta_T){};
	
	int Prestamo::VerNumeroLectorPrestamo()const{ return NumeroLector;}
	
	int Prestamo::VerCodigoLibroPrestamo()const{ return CodigoLibro;}
	
	long Prestamo::VerFechaDesde_T()const{ return FechaDesde_T;}
	
	long Prestamo::VerFechaHasta_T()const{ return FechaHasta_T;}
	
	string Prestamo::VerFechaDesde()const{ return TimeT_a_FormatoFecha(FechaDesde_T);}
	
	string Prestamo::VerFechaHasta()const{ return TimeT_a_FormatoFecha(FechaHasta_T);}
		
	int Prestamo::VerificarEntregaATiempo()const{		
		int ATiempo;		
		long long hoy_T = CalcularFecha(0);		
		if (( hoy_T -  FechaHasta_T) <= 0){	
			ATiempo = 0;	
		}else{
			ATiempo = 1 + ((hoy_T- FechaHasta_T)/86400);
		}
		return ATiempo;		
	}	
