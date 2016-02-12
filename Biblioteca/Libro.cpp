#include <algorithm>
#include "Libro.h"
#include <cstring>
#include <fstream>

Libro::Libro(string p_titulo, string p_autores, string p_editorial, string p_isbn, string p_edicion, int p_codigoLibro, string p_tipo, string p_Estado)
	:Titulo(p_titulo), Autores(p_autores), Editorial(p_editorial), ISBN(p_isbn), Edicion(p_edicion), CodigoLibro(p_codigoLibro), Tipo(p_tipo), Estado(p_Estado), Oculto(false){}
	
//constructor de carga de archivo
Libro::Libro(string p_titulo, string p_autores, string p_editorial, string p_isbn, string p_edicion, int p_codigoLibro, string p_tipo, string p_Estado, bool p_oculto)
	:Titulo(p_titulo), Autores(p_autores), Editorial(p_editorial), ISBN(p_isbn), Edicion(p_edicion), CodigoLibro(p_codigoLibro), Tipo(p_tipo), Estado(p_Estado), Oculto(p_oculto){}
	
	
	
	
	
void Libro::EstadoPrestado(){ Estado = "Prestado"; }
void Libro::EstadoDisponible(){ Estado = "Disponible"; }
void Libro::Ocultar(){Oculto = true;}
string Libro::VerTitulo() const {return Titulo;}
string Libro::VerAutores() const { return Autores;}
string Libro::VerEditorial() const { return Editorial;}	
string Libro::VerISBN() const { return ISBN; }
string Libro::VerEdicion() const { return Edicion; }
int Libro::VerCodigoLibro() const { return CodigoLibro;}
string Libro::VerTipo() const { return Tipo; }
string Libro::VerEstado() const{ return Estado;}
bool Libro::EstaDisponible() const{ 
	if(Estado=="Disponible" && !Oculto){
		return true;
	}
	return false;
}
bool Libro::EstaOculto() const { return Oculto; }
