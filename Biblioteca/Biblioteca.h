#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include "Libro.h"
#include "Lector.h"
#include "Prestamo.h"
#include "Sancion.h"
#include <string>
#include <ctime>
#include <sstream>
#include <vector>

using namespace std;

string TimeT_a_String(long t);

long String_a_TimeT(string s);

string TimeT_a_FormatoFecha(long t);

long CalcularFecha(int cantDias);

class Biblioteca{
	vector<Libro> vLibros;
	vector<Lector> vLectores;
	vector<Prestamo> vPrestamos;
	vector<Sancion> vSanciones;	
public:
	Biblioteca();
	
	~Biblioteca();
	
	void AgregarLibro(string titulo, string autores, string editorial, string isbn, string edicion, string tipo);
	
	void AgregarLector(string nombre, string apellido, string dni, string domicilio, string tel);
	
	bool AgregarPrestamo(int numeroLector, int codigoLibro);
	
	int EliminarPrestamo(int codigoLibro);
	
	void AgregarSancion(int codigoLector, string motivo);
	
	bool EstaSancionado(int numLector);
	
	bool Guardar() const;
	
	void CargarLibrosDesdeArchivo();
	
	void CargarLectoresDesdeArchivo();
	
	void CargarPrestamosDesdeArchivo();
	
	void CargarSancionesDesdeArchivo();
	
	int cantLibros()const;
	
	int cantLectores()const;
	
	int cantPrestamos()const;
	
	int cantSanciones()const;
	
	Libro VerLibro (int i) const;
	
	Lector VerLector (int i) const;
	
	Prestamo VerPrestamo (int i) const;
	
	//consola
	//void mostrar();
};
#endif
