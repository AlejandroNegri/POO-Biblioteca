#ifndef LIBRO_H
#define LIBRO_H
#include <string>
using std::string;

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

class Libro {
	std::string 	Titulo;
	std::string 	Autores;
	std::string 	Editorial;
	std::string 	ISBN;
	std::string 	Edicion;
	int 			CodigoLibro;
	std::string 	Tipo;	
	std::string 	Estado; //Disponible o Prestado
	bool 	Oculto;
public: 
	Libro(string p_titulo, string p_autores, string p_editorial, string p_isbn, string p_edicion, int p_codigoLibro, string p_tipo, string p_Estado);	
	Libro(string p_titulo, string p_autores, string p_editorial, string p_isbn, string p_edicion, int p_codigoLibro, string p_tipo, string p_Estado, bool p_oculto);	
	void 	EstadoPrestado();
	void 	EstadoDisponible();
	void 	Ocultar();
	string	VerTitulo() const;
	string 	VerAutores() const;
	string 	VerEditorial() const;
	string 	VerISBN() const;
	string 	VerEdicion() const;	
	int 	VerCodigoLibro() const;
	string 	VerTipo() const;	
	string 	VerEstado() const;
	bool 	EstaDisponible() const;
	bool 	EstaOculto() const;
	

};
#endif
