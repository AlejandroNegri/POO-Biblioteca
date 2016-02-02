#include <algorithm>
#include "Biblioteca.h"
#include "Sancion.h"
#include "Singleton.h"



Sancion::Sancion(int p_numeroLector, string p_motivo){
	NumeroLector = p_numeroLector;
	FechaSancion_T = CalcularFecha(2);
	Motivo = p_motivo;
}
	
Sancion::Sancion(int p_numeroLector, time_t p_fechaSancion_T, string p_motivo)
: NumeroLector(p_numeroLector), FechaSancion_T(p_fechaSancion_T), Motivo(p_motivo){}
	
int Sancion::VerNumeroLector()const{ return NumeroLector;}
	
string Sancion::VerFechaSancion()const{ return TimeT_a_FormatoFecha(FechaSancion_T);}

time_t Sancion::VerFechaSancion_T()const{ return FechaSancion_T;}
	
string Sancion::VerMotivo()const{ return Motivo;}	
