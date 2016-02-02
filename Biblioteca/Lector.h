#ifndef LECTOR_H
#define LECTOR_H
#include <string>
using namespace std;

class Lector {	
	string Nombre;
	string Apellido;
	string DNI;
	string Domicilio;
	string Tel;
	int NumeroLector;
public: 
	Lector(string p_nombre, string p_apellido, string p_dni, string p_domicilio, string p_tel, int p_numeroLector);
		string VerNombre()const;	
		string VerApellido()const;	
		string VerDNI() const;	
		string VerDomicilio() const;	
		string VerTel() const;	
		int VerNumeroLector() const; 
};
#endif
