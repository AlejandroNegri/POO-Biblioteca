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
#define NO_SE_ENCUENTRA -1

using namespace std;

class Biblioteca{
	vector<Libro> vLibros;
	vector<Lector> vLectores;
	vector<Prestamo> vPrestamos;
	vector<Sancion> vSanciones;	
	string directorioLibros = "./datos/libros.dat";
	string directorioLectores = "./datos/lectores.dat";
	string directorioPrestamos = "./datos/prestamos.dat";
	string directorioSanciones = "./datos/sanciones.dat";
public:
	Biblioteca();	
	~Biblioteca();
	
	void AgregarLibro(string titulo, string autores, string editorial, string isbn, string edicion, string tipo);	
	void AgregarLector(string nombre, string apellido, string dni, string domicilio, string tel);	
	bool AgregarPrestamo(int numeroLector, int codigoLibro);
	void AgregarSancion(int codigoLector, string motivo, int cantDias);
	int EliminarPrestamo(int codigoLibro);
	
	bool EstaSancionado(int numLector);
	
	bool Guardar() const;
	
	void CargarLibrosDesdeArchivo();	
	void CargarLectoresDesdeArchivo();	
	void CargarPrestamosDesdeArchivo();	
	void CargarSancionesDesdeArchivo();
	
	int BuscarTitulo(string parte, int pos_desde);
	
	int cantLibros()const;	
	int cantLectores()const;	
	int cantPrestamos()const;	
	int cantSanciones()const;
	
	Libro VerLibro (int i) const;	
	Lector VerLector (int i) const;	
	Prestamo VerPrestamo (int i) const;	
	Sancion VerSancion (int i) const;
};
#endif
