#ifndef LIBRO_H
#define LIBRO_H
#include <string>
using namespace std;

struct registro_libro {
	char titulo[256];
	char autores[256];
	char editorial[256];
	char isbn[256];
	char edicion[256];
	int codigoLibro;
	char tipo[256];
	char estado[256];
};

class Libro {
	string Titulo;
	string Autores;
	string Editorial;
	string ISBN;
	string Edicion;
	int CodigoLibro;
	string Tipo;	
	string Estado; //Disponible o Prestado	
public: 
	Libro(string p_titulo, string p_autores, string p_editorial, string p_isbn, string p_edicion, int p_codigoLibro, string p_tipo, string p_Estado);	
	void EstadoPrestado();
	void EstadoDisponible();
	string VerTitulo() const;
	string VerAutores() const;
	string VerEditorial() const;
	string VerISBN() const;
	string VerEdicion() const;	
	int VerCodigoLibro() const;
	string VerTipo() const;	
	string VerEstado() const;
	bool EstaDisponible() const;

};
#endif
