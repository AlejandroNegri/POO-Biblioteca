/**
* @file Sancion.h
* @brief Declaraciones de todo lo necesario para trabajar con la clase Sancion
*
* Este archivo define la clase Sancion, las funciones auxiliares para prolongar 
* el tiempo de la sanción y el struct que hace de intermediario para guardar y 
* leer en archivo binarios.
**/
#ifndef SANCION_H
#define SANCION_H
#include <string>

/**
* @brief Estructura auxiliar para usar con archivos binarios
*
* En este struct se guardan los datos para poder llevar strings al archivo
**/
struct registro_sancion {
	int 	numeroLector;
	long 	fechaSancion_t;
	char 	motivo[256];	
};

/**
* @brief Clase que representa a una Sancion. 
*
* Contiene los atributos que se guardan de cada Sancion,  metodos para verlos y 
* métodos para prolongar el tiempo de sanción
**/
class Sancion{
	int 	NumeroLector; ///< número del Lector
	long 	FechaSancion_T; ///< fecha time_t hasta la cual el lector esta sancionado
	string 	Motivo; ///< motivo por el cual el lector fue sancionado
public:	
	Sancion(int p_numeroLector, long p_fechaSancion_T, string p_motivo);	
	void	ProlongarSancion(long cantDias, string p_motivo);	 ///< prolonga la sancion
	int 	VerNumeroLector()const; ///< devuelve el número de Lector
	string 	VerFechaSancion()const; ///< devuelve la fecha hasta la cual el lector esta sancionado	
	long 	VerFechaSancion_T()const; ///< devuelve la fecha time_t hasta la cual el lector esta sancionado		
	string 	VerMotivo()const; ///< devuelve el motivo por el cual el lector fue sancionado
};
#endif
