#include "Utils.h"
#include <sstream>
#include <ctime>
#include <cstdlib>

void pasar_a_minusculas(string &s) {
	int i,c=s.size();
	for (i=0;i<c;i++)
		s[i]=tolower(s[i]);
}

string TimeT_a_String(long t){
	stringstream ss;
	long long t_l = (long long)t;	
	string t_s;	
	ss << t_l;
	ss >> t_s;
	return ss.str();
}

long String_a_TimeT(string s){
	long t = atol(s.c_str());
	return t;
}

string TimeT_a_FormatoFecha(long t1){
	time_t t = (time_t)t1;
	tm *fecha_tm = localtime( &t );
	stringstream ssFecha;
	ssFecha << fecha_tm->tm_mday << "/" << fecha_tm->tm_mon+1 << "/" << fecha_tm->tm_year+1900 << " "
		<< fecha_tm->tm_hour << ":" << fecha_tm->tm_min << ":" << fecha_tm->tm_sec <<"hs";
	return ssFecha.str();
}

long CalcularFecha(int cantDias){	
	//segundos en un dia (24*60*60)
	int dia_t = 86400;	
	//calculo los segundos hasta ahora y le sumo la cant de dias extra
	time_t fecha_t = time(NULL) +(cantDias * dia_t);		
	//si no es la fecha de hoy cambio los minutos
	if (cantDias>0){
		//meto el time_t en un tm para modificarle los min y seg
		tm *fecha_tm = localtime( &fecha_t );
		//le seteo la hora de entrega hasta las 23:59:59
		fecha_tm->tm_hour = 23;
		fecha_tm->tm_min = 59;
		fecha_tm->tm_sec = 59;		
		//mktime vuelve el tm a formato time_t
		fecha_t = mktime(fecha_tm);
	}	
	return fecha_t;
}
