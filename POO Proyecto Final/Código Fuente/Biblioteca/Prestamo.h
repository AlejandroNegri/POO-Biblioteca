/**
* @file Prestamo.h
* @brief Declaraciones de todo lo necesario para trabajar con la clase Prestamo
*
* Este archivo define la clase Prestamo, las funciones auxiliares para verificar las
* entregas a tiempo y el struct que hace de intermediario para guardar y 
* leer en archivo binarios.
**/
#ifndef PRESTAMO_H
#define PRESTAMO_H
#include <string>
using std::string;

/**
* @brief Estructura auxiliar para usar con archivos binarios
*
* En este struct se guardan los datos para poder llevar strings al archivo
**/
struct registro_prestamo {
	int numeroLector;
	int codigoLibro;
	long fechaDesde_t;
	long fechaHasta_t;
};

/**
* @brief Clase que representa a un Prestamo. 
*
* Contiene los atributos que se guardan de cada Prestamo,  metodos para verlos y 
* métodos para verificar las devoluciones a tiempo
**/
class Prestamo {
	int 	NumeroLector; ///< Número del Libro
	int 	CodigoLibro;  ///< 	Codigo del Libro
	long	FechaDesde_T; ///< Fecha time_t en la que se realiza el prestamo
	long 	FechaHasta_T; ///< Fecha limite time_t del plazo del prestamo
public: 	
	Prestamo(int p_numeroLector,int p_CodigoLibro);	
	Prestamo(int p_numeroLector,int p_CodigoLibro, long p_FechaDesde_TimeT , long p_FechaHasta_TimeT);
	int 	VerNumeroLectorPrestamo()const; ///< devuelve el numero del lector del préstamo
	int 	VerCodigoLibroPrestamo()const; ///< devuelve el código del libro del prestamo	
	string	VerFechaDesde()const; ///< devuelve la fecha en la que se realiza el prestamo 	
	string 	VerFechaHasta()const; ///< devuelve la fecha limite del plazo del prestamo	
	long 	VerFechaDesde_T()const;	///< devuelve la fecha time_t en la que se realiza el prestamo 
	long 	VerFechaHasta_T()const;	///< devuelve la fecha time_t limite del plazo del prestamo	
	int 	VerificarEntregaATiempo()const; ///< devuelve la cantidad de dias tarde que se devolvio el libro
};
#endif
