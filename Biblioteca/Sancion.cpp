#include <algorithm>
#include "Biblioteca.h"
#include "Sancion.h"
#include "Singleton.h"
#include "Utils.h"
	
Sancion::Sancion(int p_numeroLector, long p_fechaSancion_T, string p_motivo)
: NumeroLector(p_numeroLector), FechaSancion_T(p_fechaSancion_T), Motivo(p_motivo){}

void Sancion::ProlongarSancion(long cantDias, string p_motivo){
	FechaSancion_T = FechaSancion_T + Dias_a_TimeT(cantDias);
	Motivo +=", " + p_motivo;
}
	
int Sancion::VerNumeroLector()const{ return NumeroLector;}
	
string Sancion::VerFechaSancion()const{ return TimeT_a_FormatoFecha(FechaSancion_T);}

long Sancion::VerFechaSancion_T()const{ return FechaSancion_T;}
	
string Sancion::VerMotivo()const{ return Motivo;}	
