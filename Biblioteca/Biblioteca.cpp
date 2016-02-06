#include "Biblioteca.h"
#include "Libro.h"
#include "Lector.h"
#include "Sancion.h"
#include "Prestamo.h"
#include <string>
#include <ctime>
#include <sstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <wx/msgdlg.h>
#include "Utils.h"



Biblioteca::Biblioteca(){
	CargarLibrosDesdeArchivo();
	CargarLectoresDesdeArchivo();
	CargarPrestamosDesdeArchivo();
	CargarSancionesDesdeArchivo();
}

Biblioteca::~Biblioteca(){ Guardar();}	

void Biblioteca::AgregarLibro(string titulo, string autores, string editorial, string isbn, string edicion, string tipo){
	Libro unLibro(titulo, autores, editorial, isbn, edicion, cantLibros(),tipo, "Disponible");
	vLibros.push_back(unLibro);				
};

void Biblioteca::AgregarLector(string nombre, string apellido, string dni, string domicilio, string tel){
	Lector unLector(nombre, apellido, dni, domicilio, tel, cantLectores());
	vLectores.push_back(unLector);		
};	

bool Biblioteca::AgregarPrestamo(int numeroLector, int codigoLibro){
	if (VerLibro(codigoLibro).EstaDisponible()){
		Prestamo unPrestamo(numeroLector, codigoLibro);	
		vPrestamos.push_back(unPrestamo);		
		//poner prestado el libro
		vLibros[codigoLibro].EstadoPrestado();	
		return true;
	}
	return false;
}

void Biblioteca::AgregarSancion(int codigoLector, string motivo, int cantDias){
	Sancion unaSancion(codigoLector, motivo, cantDias);
	vSanciones.push_back(unaSancion);
}

int Biblioteca::EliminarPrestamo(int codigoLibro){	
	int devolucionATiempo;	//si es mayor a 0, muestra los dias que se sobrepaso
	vLibros[codigoLibro].EstadoDisponible(); //pongo el libro "disponible"		
	for(int i=0;i<cantPrestamos();i++) { 
		if (codigoLibro == vPrestamos[i].VerCodigoLibroPrestamo()){
			devolucionATiempo = vPrestamos[i].VerificarEntregaATiempo();
			vPrestamos.erase(vPrestamos.begin()+i);
			break;
		}
	}
	return devolucionATiempo;
}

//*****GUARDADO DE DATOS AL ARCHIVO*****
bool Biblioteca::Guardar() const {
	//Guardar libros	
	ofstream archivoLibros(directorioLibros.c_str(),ios::binary|ios::trunc);
	if (!archivoLibros.is_open()) return false;
	for (int i=0;i<cantLibros();i++){
		registro_libro reg_libro;
		strcpy(reg_libro.titulo, vLibros[i].VerTitulo().c_str());
		strcpy(reg_libro.autores, vLibros[i].VerAutores().c_str());
		strcpy(reg_libro.editorial, vLibros[i].VerEditorial().c_str());
		strcpy(reg_libro.isbn, vLibros[i].VerISBN().c_str());
		strcpy(reg_libro.edicion, vLibros[i].VerEdicion().c_str());
		reg_libro.codigoLibro = vLibros[i].VerCodigoLibro();
		strcpy(reg_libro.tipo, vLibros[i].VerTipo().c_str());
		strcpy(reg_libro.estado, vLibros[i].VerEstado().c_str());
		archivoLibros.write((char*)&reg_libro, sizeof(reg_libro));		
	}
	archivoLibros.close();
	
	//Guardar lectores
	ofstream archivoLectores(directorioLectores.c_str(),ios::binary|ios::trunc);
	if (!archivoLectores.is_open()) return false;
	for (int i=0;i<cantLectores();i++){
		registro_lector reg_lector;
		strcpy(reg_lector.nombre, vLectores[i].VerNombre().c_str());
		strcpy(reg_lector.apellido, vLectores[i].VerApellido().c_str());
		strcpy(reg_lector.dni, vLectores[i].VerDNI().c_str());
		strcpy(reg_lector.domicilio, vLectores[i].VerDomicilio().c_str());
		strcpy(reg_lector.tel, vLectores[i].VerTel().c_str());
		reg_lector.numeroLector = vLectores[i].VerNumeroLector();
		archivoLectores.write((char*)&reg_lector, sizeof(reg_lector));	
	}
	archivoLectores.close();
	
	//Guardar prestamos
	ofstream archivoPrestamos(directorioPrestamos.c_str(),ios::binary|ios::trunc);
	if (!archivoPrestamos.is_open()) return false;
	for (int i=0;i<cantPrestamos();i++){
		registro_prestamo reg_prestamo;
		reg_prestamo.numeroLector = vPrestamos[i].VerNumeroLectorPrestamo();
		reg_prestamo.codigoLibro = vPrestamos[i].VerCodigoLibroPrestamo();
		reg_prestamo.fechaDesde_t = vPrestamos[i].VerFechaDesde_T();
		reg_prestamo.fechaHasta_t = vPrestamos[i].VerFechaHasta_T();
		archivoPrestamos.write((char*)&reg_prestamo, sizeof(reg_prestamo));	
	}
	archivoPrestamos.close();
	
	//Guardar sanciones
	ofstream archivoSanciones(directorioSanciones.c_str(),ios::binary|ios::trunc);
	if (!archivoSanciones.is_open()) return false;
	for (int i=0;i<cantSanciones();i++){
		registro_sancion reg_sancion;
		reg_sancion.numeroLector = vSanciones[i].VerNumeroLector();
		reg_sancion.fechaSancion_t = vSanciones[i].VerFechaSancion_T();
		strcpy(reg_sancion.motivo, vSanciones[i].VerMotivo().c_str());
		archivoSanciones.write((char*)&reg_sancion, sizeof(reg_sancion));	
	}
	archivoSanciones.close();
}
		

//*****CARGA DE DATOS DESDE ARCHIVO*****
void Biblioteca::CargarLibrosDesdeArchivo(){
	ifstream archivo(directorioLibros.c_str(),ios::binary|ios::ate);
	if (archivo.is_open()) {
		int tamanio_archivo = archivo.tellg();
		int cantLibros = tamanio_archivo/sizeof(registro_libro);
		//vLibros.resize(cantLibros);
		archivo.seekg(0,ios::beg);
		for (int i=0;i<cantLibros;i++){
			registro_libro reg;
			archivo.read((char*)&reg,sizeof(reg));		
			Libro unLibro(reg.titulo, reg.autores, reg.editorial, reg.isbn, reg.edicion, reg.codigoLibro ,reg.tipo, reg.estado);
			vLibros.push_back(unLibro);				
		}		
		archivo.close();
	}	
}

void Biblioteca::CargarLectoresDesdeArchivo(){
	ifstream archivo(directorioLectores.c_str(),ios::binary|ios::ate);
	if (archivo.is_open()) {
		int tamanio_archivo = archivo.tellg();
		int cantLectores = tamanio_archivo/sizeof(registro_lector);
		//vLibros.resize(cantLibros);
		archivo.seekg(0,ios::beg);
		for (int i=0;i<cantLectores;i++){
			registro_lector reg;
			archivo.read((char*)&reg,sizeof(reg));		
			Lector unLector(reg.nombre, reg.apellido, reg.dni, reg.domicilio, reg.tel, reg.numeroLector );
			vLectores.push_back(unLector);				
		}		
		archivo.close();
	}	
}

void Biblioteca::CargarPrestamosDesdeArchivo(){
	ifstream archivo(directorioPrestamos.c_str(),ios::binary|ios::ate);
	if (archivo.is_open()) {
		int tamanio_archivo = archivo.tellg();
		int cantPrestamos = tamanio_archivo/sizeof(registro_prestamo);
		//vLibros.resize(cantLibros);
		archivo.seekg(0,ios::beg);
		for (int i=0;i<cantPrestamos;i++){
			registro_prestamo reg;
			archivo.read((char*)&reg,sizeof(reg));		
			Prestamo unPrestamo(reg.numeroLector, reg.codigoLibro, reg.fechaDesde_t, reg.fechaHasta_t);
			vPrestamos.push_back(unPrestamo);				
		}		
		archivo.close();
	}	
}

void Biblioteca::CargarSancionesDesdeArchivo(){
	ifstream archivo("./datos/sanciones.txt");
	string NumeroLector;
	string FechaSancion_T;
	string Motivo;
	string LineaVacia;
	
	while(getline(archivo,NumeroLector) && getline(archivo, FechaSancion_T) && 
		  getline(archivo, Motivo) && getline(archivo, LineaVacia)){
		Sancion unaSancion(atoi(NumeroLector.c_str()), String_a_TimeT(FechaSancion_T), Motivo);
		vSanciones.push_back(unaSancion);	
	}
}

bool Biblioteca::EstaSancionado(int numLector){
	for( Sancion x : vSanciones) {
		if( x.VerNumeroLector() == numLector){ return true; }
	}
	return false;
}

int Biblioteca::BuscarTitulo(string parte, int pos_desde) {
	pasar_a_minusculas(parte);
	for (int i=pos_desde;i<cantLibros();i++) {
		Libro l = vLibros[i];
		string cadena_a_buscar = l.VerTitulo();
		pasar_a_minusculas(cadena_a_buscar);
		if (cadena_a_buscar.find(parte,0)!=string::npos)
			return i;
	}
	return NO_SE_ENCUENTRA;
}

int Biblioteca::cantLibros()const{ return vLibros.size();}

int Biblioteca::cantLectores()const{ return vLectores.size();}

int Biblioteca::cantPrestamos()const{ return vPrestamos.size();}

int Biblioteca:: cantSanciones()const{ return vSanciones.size();}

Libro Biblioteca::VerLibro (int i) const { return vLibros[i]; }	

Lector Biblioteca::VerLector (int i) const { return vLectores[i]; }

Prestamo Biblioteca::VerPrestamo (int i) const { return vPrestamos[i]; }

Sancion Biblioteca::VerSancion (int i) const { return vSanciones[i]; }



