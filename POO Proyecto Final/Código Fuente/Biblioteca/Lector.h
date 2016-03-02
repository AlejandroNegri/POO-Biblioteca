/**
* @file Lector.h
* @brief Declaraciones de todo lo necesario para trabajar con la clase Lector
*
* Este archivo define la clase Lector, las funciones auxiliares para ocultarlos
* y ver si estan ocultos, y el struct que hace de intermediario para guardar y 
* leer en archivo binarios.
**/
#ifndef LECTOR_H
#define LECTOR_H
#include <string>
using std::string;

/**
* @brief Estructura auxiliar para usar con archivos binarios
*
* En este struct se guardan los datos para poder llevar strings al archivo
**/
struct registro_lector {
	char	nombre[256];
	char	apellido[256];
	char 	dni[256];
	char	domicilio[256];
	char 	tel[256];
	int		numeroLector;
	bool 	oculto;
};

/**
* @brief Clase que representa a un Lector. 
*
* Contiene los atributos que se guardan de cada lector,  metodos para verlos y 
* métodos para ocultar y ver si estan ocultos
**/
class Lector {	
	string	Nombre; ///< nombres del lector
	string 	Apellido; ///< apellidos del lector
	string 	DNI; ///< dni del lector
	string 	Domicilio; ///< domicilio del lector
	string 	Tel; ///< telefono del lector
	int 	NumeroLector; ///< número de lector
	bool 	Oculto; ///< bool que indica si esta oculto/eliminado
public: 
	Lector(string p_nombre, string p_apellido, string p_dni, string p_domicilio, string p_tel, int p_numeroLector);
	Lector(string p_nombre, string p_apellido, string p_dni, string p_domicilio, string p_tel, int p_numeroLector, bool p_oculto);
	string 	VerNombre()const; ///< devuelve los nombres del lector	 
	string 	VerApellido()const;	///< devuelve los apellidos del lector	
	string	VerApellidoYNombre()const; ///< devuelve el nombre y apellido del lector	
	string 	VerDNI() const;	///< devuelve el dni del lector	
	string 	VerDomicilio() const; ///< devuelve el domicilio del lector		
	string 	VerTel() const;	///< devuelve el telefono del lector	
	int 	VerNumeroLector() const; ///< devuelve el número del lector	
	bool 	EstaOculto() const; ///< bool que devuelve si esta oculto/eliminado
	void	Ocultar(); ///< ocultar/eliminar lector	
};
#endif
