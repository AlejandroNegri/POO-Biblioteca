#ifndef LECTOR_H
#define LECTOR_H
#include <string>
using std::string;

struct registro_lector {
	char	nombre[256];
	char	apellido[256];
	char 	dni[256];
	char	domicilio[256];
	char 	tel[256];
	int		numeroLector;
	bool 	oculto;
};

class Lector {	
	string	Nombre;
	string 	Apellido;
	string 	DNI;
	string 	Domicilio;
	string 	Tel;
	int 	NumeroLector;
	bool 	Oculto;
public: 
	Lector(string p_nombre, string p_apellido, string p_dni, string p_domicilio, string p_tel, int p_numeroLector);
	Lector(string p_nombre, string p_apellido, string p_dni, string p_domicilio, string p_tel, int p_numeroLector, bool p_oculto);
	string 	VerNombre()const;	
	string 	VerApellido()const;	
	string	VerApellidoYNombre()const;
	string 	VerDNI() const;	
	string 	VerDomicilio() const;	
	string 	VerTel() const;	
	int 	VerNumeroLector() const; 
	bool 	EstaOculto() const;
	void	Ocultar();
};
#endif
