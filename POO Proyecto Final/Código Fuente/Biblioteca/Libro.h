/**
* @file Libro.h
* @brief Declaraciones de todo lo necesario para trabajar con la clase Libro
*
* Este archivo define la clase Libro, las funciones auxiliares para ocultarlos
* y ver si estan ocultos, y el struct que hace de intermediario para guardar y 
* leer en archivo binarios.
**/
#ifndef LIBRO_H
#define LIBRO_H
#include <string>
using std::string;

/**
* @brief Estructura auxiliar para usar con archivos binarios
*
* En este struct se guardan los datos para poder llevar strings al archivo
**/
struct registro_libro {
	char	titulo[256];
	char 	autores[256];
	char 	editorial[256];
	char 	isbn[256];
	char	edicion[256];
	int 	codigoLibro;
	char 	tipo[256];
	char 	estado[256];
	bool 	oculto;
};

/**
* @brief Clase que representa a un Libro. 
*
* Contiene los atributos que se guardan de cada libro,  metodos para verlos y 
* métodos para ocultar y ver si estan ocultos
**/
class Libro {
	string 	Titulo; ///< título del Libro
	string 	Autores; ///< autores del Libro
	string 	Editorial; ///< editorial del Libro
	string 	ISBN; ///< ISBN del Libro
	string 	Edicion; ///< edicióndel Libro
	int 	CodigoLibro; ///< código del Libro
	string 	Tipo;  ///< tipo de Libro	
	string 	Estado; ///< estado del libro (Prestado o Disponible)
	bool 	Oculto; ///< bool que indica si esta oculto/eliminado
public: 
	Libro(string p_titulo, string p_autores, string p_editorial, string p_isbn, string p_edicion, int p_codigoLibro, string p_tipo, string p_Estado);	
	Libro(string p_titulo, string p_autores, string p_editorial, string p_isbn, string p_edicion, int p_codigoLibro, string p_tipo, string p_Estado, bool p_oculto);	
	void 	EstadoPrestado(); ///< cambiar el estado a "Prestado"	
	void 	EstadoDisponible(); ///< cambiar el estado a "Disponible"
	void 	Ocultar(); ///< ocultar/eliminar lector	
	string	VerTitulo() const; ///< devuelve el titulo del Libro
	string 	VerAutores() const; ///< devuelve los autores del Libro
	string 	VerEditorial() const; ///< devuelve la editorial del Libro
	string 	VerISBN() const; ///< devuelve el ISBN del Libro
	string 	VerEdicion() const;	 ///< devuelve la edición del Libro
	int 	VerCodigoLibro() const; ///< devuelve el código del Libro
	string 	VerTipo() const; ///< devuelve el tipo de Libro
	string 	VerEstado() const; ///< devuelve el estado del libro (Prestado o Disponible)
	bool 	EstaDisponible() const;  ///< bool que indica si esta Disponible 
	bool 	EstaOculto() const; ///< bool que devuelve si esta oculto/eliminado
};
#endif
