/**
* @file Utils.h
* @brief Declaraciones de todo lo necesario para trabajar con la clase Sancion
*
* Este archivo define la clase Sancion, las funciones auxiliares para prolongar 
* el tiempo de la sanci�n y el struct que hace de intermediario para guardar y 
* leer en archivo binarios.
**/
#include "Utils.h"
#include <sstream>
#include <ctime>
#include <cstdlib>
using std::string;
using std::stringstream;

void pasar_a_minusculas(string &s) {
	int i,c=s.size();
	for (i=0;i<c;i++)
		s[i]=tolower(s[i]);
}

string TimeT_a_FormatoFecha(long t1){
	time_t t = (time_t)t1;
	tm *fecha_tm = localtime( &t );
	stringstream ssFecha;
	ssFecha << fecha_tm->tm_mday << "/" << fecha_tm->tm_mon+1 << "/" << fecha_tm->tm_year+1900 << " "
		<< fecha_tm->tm_hour << ":" << fecha_tm->tm_min << ":" << fecha_tm->tm_sec <<"hs";
	return ssFecha.str();
}

long Dias_a_TimeT(int cantDias){	
	//segundos en un dia (24*60*60)
	int dia_t = 86400;		
	return cantDias * dia_t;
}

long CalcularFechaLimite(int cantDias){	
	//segundos en un dia (24*60*60)
	int dia_t = 86400;	
	//calculo los segundos hasta ahora y le sumo la cant de dias extra
	time_t fecha_t = time(NULL) +(cantDias * dia_t);		
	//si no es la fecha de hoy cambio los minutos
	if (cantDias>0){
		//meto el time_t en un tm para modificarle los min y seg
		tm *fecha_tm = localtime( &fecha_t );
		//le seteo la hora de entrega hasta las 23:59:59
		fecha_tm->tm_hour	= 23;
		fecha_tm->tm_min	= 59;
		fecha_tm->tm_sec 	= 59;		
		//mktime vuelve el tm a formato time_t
		fecha_t = mktime(fecha_tm);
	}	
	return fecha_t;
}

bool NoEstaOculto_Funcion(Libro l) { 
	return !(l.EstaOculto()); 
}

string IntToString(int num){
	stringstream ss;
	ss << num;
	return ss.str();	
}
