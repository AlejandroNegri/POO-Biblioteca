/**
* @file Biblioteca.h
* @brief Declaraciones de todo lo necesario para trabajar con la clase Biblioteca
*
* Este archivo define la clase Biblioteca, la constante que se usa en los 
* argumentos de sus metodos, los vectores que se usan para guardar 
* las distintas instancias y las rutas relativas de los datos y el log
**/
#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include "Libro.h"
#include "Lector.h"
#include "Prestamo.h"
#include "Sancion.h"
#include <string>
#include <vector>
using std::vector;
using std::string;

/// @brief constante para indicar que falló una búsqueda
#define NO_SE_ENCUENTRA -1

/**
* @brief Clase contenedora que administra la Biblioteca. La misma será utilizada
* mediante un Singleton para evitar múltiples instancias
*
* Contiene la lista de libros, lectores, préstamos y sanciones, y los metodos 
* para guardarlos y buscarlos en sus respectivas pestañas. 
* Tambíen contiene los métodos para agregar, modificar y eliminar elementos.
* Los datos estan siempre en memoria, y al realizar alguna operación se debe
* llamar al metodo Guardar para persistir los cambios en los archivos.
**/
class Biblioteca{
private:
	/// @brief Vectores STL donde guardaremos las instancias
	vector<Libro> vLibros; ///< vector de libros
	vector<Lector> vLectores; ///< vector de lectores
	vector<Prestamo> vPrestamos; ///< vector de prestamos
	vector<Sancion> vSanciones;	///< vector de sanciones
	
	/// @brief Ruta de los archivos binarios donde guardaremos los datos
	string directorioLibros 		= "./datos/libros.dat";
	string directorioLectores 		= "./datos/lectores.dat";
	string directorioPrestamos 		= "./datos/prestamos.dat";
	string directorioSanciones 		= "./datos/sanciones.dat";
	
	/// @brief Ruta del archivo log.txt
	string directorioLog = "./datos/log.txt";
	
public:
	/// @brief Crea el objeto, carga los datos desde los archivos y elimina sanciones viejas
	Biblioteca();	
	/// @brief Destructor, guarda todos los cambios antes de cerrar
	~Biblioteca();
	
	//ABM LIBROS
	/// @brief Agregar un libro	
	void AgregarLibro(string titulo, string autores, string editorial, string isbn, string edicion, string tipo, int codLibro, string estado);		
	/// @brief Modificar un libro
	void ModificarLibro(string titulo, string autores, string editorial, string isbn, string edicion, string tipo, int codLibro, string estado);		
	/// @brief Oculta un libro de la grilla, funciona como "eliminar" para el usuario
	void OcultarLibro(int i);	
	
	//ABM LIBROS
	/// @brief Agregar un lector
	void AgregarLector(string nombre, string apellido, string dni, string domicilio, string tel, int numLector);	
	/// @brief Modificar un libro
	void ModificarLector(string nombre, string apellido, string dni, string domicilio, string tel, int numLector);	
	/// @brief Oculta un lector de la grilla, funciona como "eliminar" para el usuario
	void OcultarLector(int i);
	
	//ABM PRÉSTAMOS
	/// @brief Agregar un préstamo
	void AgregarPrestamo(int numeroLector, int codigoLibro);	
	/// @brief Eliminar un préstamo mediante una devolución
	int EliminarPrestamo(int codigoLibro);
	/// @brief Verifica si un lector tiene préstamos activos
	bool TienePrestamosActivos (int numLector);
	
	//ABM SANCIONES
	/// @brief Agregar una sanción
	void AgregarSancion(int numeroLector, string motivo, int cantDias);
	/// @brief Chequea las sanciones al inicio y elimina las que caducaron
	void EliminarSancionesCumplidas();
	/// @brief Verifica si un lector esta sancionado
	bool EstaSancionado(int numLector);
	
	//GUARDAR
	/// @brief Guarda el contenido de los vectores en los archivos
	bool Guardar() const;	
	/// @brief Guarda en un txt un mensaje con fecha acerca de los eventos ocurridos
	void EscribirLog(string mensaje);
	
	//CARGAR
	/// @brief Carga los libros desde el archivo
	void CargarLibrosDesdeArchivo();	
	/// @brief Carga los lectores desde el archivo
	void CargarLectoresDesdeArchivo();	
	/// @brief Carga los préstamos desde el archivo
	void CargarPrestamosDesdeArchivo();	
	/// @brief Carga las sanciones desde el archivo
	void CargarSancionesDesdeArchivo();
	
	//BÚSQUEDA
	/// @brief Busqueda por título en la grilla
	int BuscarTitulo(string parte, int pos_desde);
	/// @brief Busqueda por apellido y nombre en la grilla
	int BuscarApellidoYNombre(string parte, int pos_desde);
	/// @brief Busqueda por título, apellido y nombre en la grilla
	int BuscarApellidoNombreOTitulo(string parte, int pos_desde);
	
	//VER CANTIDADES
	int cantLibros()const; ///< Devuelve la cantidad de libros en vLibros	
	int cantLibrosActivos()const; ///< Devuelve la cantidad de libros activos en vLibros
	int cantLectores()const; ///< Devuelve la cantidad de lectores en vLectores	 
	int cantPrestamos()const; ///< Devuelve la cantidad de préstamos en vPrestamos	
	int cantSanciones()const; ///< Devuelve la cantidad de sanciones en vSanciones
	
	//VER OBJETOS
	Libro VerLibro (int i) const;	///< Devuelve un Libro de vLibros	
	Lector VerLector (int i) const;	///< Devuelve un lector de vLectores	
	Prestamo VerPrestamo (int i) const;	///< Devuelve un préstamo de vPrestamos	
	Sancion	VerSancion (int i) const; ///< Devuelve una sanción de vSanciones	
};
#endif
