#include "Biblioteca.h"
#include "Libro.h"
#include "Lector.h"
#include "Sancion.h"
#include "Prestamo.h"
#include "Utils.h"
#include <string>
#include <ctime>
#include <sstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <wx/msgdlg.h>
#include "Vprincipal.h"



Biblioteca::Biblioteca(){
	CargarLibrosDesdeArchivo();
	CargarLectoresDesdeArchivo();
	CargarPrestamosDesdeArchivo();
	CargarSancionesDesdeArchivo();
	EliminarSancionesCumplidas();
}

Biblioteca::~Biblioteca(){ Guardar();}	

// ABM LIBRO
void Biblioteca::AgregarLibro(string titulo, string autores, string editorial, string isbn, string edicion, string tipo, int codLibro, string estado){
	Libro unLibro(titulo, autores, editorial, isbn, edicion, codLibro,tipo, estado);
	vLibros.push_back(unLibro);		
	Guardar();
	EscribirLog("Se agregó el libro: \" " + titulo + "\" - Código: " + IntToString(codLibro));	
};

void Biblioteca::ModificarLibro(string titulo, string autores, string editorial, string isbn, string edicion, string tipo, int codLibro, string estado){
	Libro unLibro(titulo, autores, editorial, isbn, edicion, codLibro,tipo, estado);
	vLibros[codLibro]= unLibro;	
	Guardar();
	EscribirLog("Se modificó el libro: \"" + titulo + "\" - Código: " + IntToString(codLibro));
};

void Biblioteca::OcultarLibro(int i){
	vLibros[i].Ocultar();
	Guardar();
	EscribirLog("Se eliminó el libro: \"" + VerLibro(i).VerTitulo()+ "\" - Código: " + IntToString(VerLibro(i).VerCodigoLibro()));	
}

// ABM LECTOR
void Biblioteca::AgregarLector(string nombre, string apellido, string dni, string domicilio, string tel, int numLector){
	Lector unLector(nombre, apellido, dni, domicilio, tel, numLector);
	vLectores.push_back(unLector);		
	Guardar();
	EscribirLog("Se agregó el lector: \"" + apellido + ", "+ nombre + "\" - Núm. lector: " + IntToString(numLector));
};	

void Biblioteca::ModificarLector(string nombre, string apellido, string dni, string domicilio, string tel, int numLector){
	Lector unLector(nombre, apellido, dni, domicilio, tel, numLector);
	vLectores[numLector] = unLector;		
	Guardar();	
	EscribirLog("Se modificó el lector: \"" + apellido + ", "+ nombre + "\" - Núm. lector: " + IntToString(numLector));
};	

void Biblioteca::OcultarLector(int i){
	vLectores[i].Ocultar();
	Guardar();
	EscribirLog("Se eliminó el lector: \"" + VerLector(i).VerApellidoYNombre() + "\" - Núm. Lector: " + IntToString(i));
}

// ABM PRESTAMOS
void Biblioteca::AgregarPrestamo(int numeroLector, int codigoLibro){
	Prestamo unPrestamo(numeroLector, codigoLibro);	
	vPrestamos.push_back(unPrestamo);		
	vLibros[codigoLibro].EstadoPrestado();
	Guardar();
	EscribirLog("Se prestó el libro: \"" + VerLibro(codigoLibro).VerTitulo() + "\"("+IntToString(codigoLibro)+") "+
				"al lector: \""+VerLector(numeroLector).VerApellidoYNombre() + "\"("+IntToString(numeroLector)+")");
}

int Biblioteca::EliminarPrestamo(int codigoLibro){	
	int devolucionATiempo;	//si es mayor a 0, muestra los dias que se sobrepaso
	vLibros[codigoLibro].EstadoDisponible(); //pongo el libro "disponible"		
	for(int i=0;i<cantPrestamos();i++){
		if (codigoLibro == vPrestamos[i].VerCodigoLibroPrestamo()){
			devolucionATiempo = vPrestamos[i].VerificarEntregaATiempo();
			vPrestamos.erase(vPrestamos.begin()+i);
			break;
		}
	}
	Guardar();
	EscribirLog("Se devolvió el libro: \"" + VerLibro(codigoLibro).VerTitulo() + "\"("+IntToString(codigoLibro)+") "+
				IntToString(devolucionATiempo) + " días tarde");
	return devolucionATiempo;
}


// ABM SANCIONES
//si está sancionado, le agrego dias y motivos a la sancion. Sino, la creo
void Biblioteca::AgregarSancion(int numeroLector, string motivo, int cantDias){	
	if(EstaSancionado(numeroLector)){
		for(int i=0;i<cantSanciones();i++) {
			if( vSanciones[i].VerNumeroLector() == numeroLector){ 
				vSanciones[i].ProlongarSancion(cantDias, motivo);
			}			
		}				
	}else{	
		Sancion unaSancion(numeroLector, CalcularFechaLimite(cantDias), motivo);
		vSanciones.push_back(unaSancion);
	}
	Guardar();
	EscribirLog("Se sancionó " + IntToString(cantDias) + " días al lector \"" + VerLector(numeroLector).VerApellidoYNombre() + "\"(" + IntToString(numeroLector) +") por "+ motivo);
}

//al iniciar el programa elimina las sanciones que ya cumplieron su tiempo
void Biblioteca::EliminarSancionesCumplidas(){
	time_t fechaHoy_t = time(NULL);
	for(int i=0;i<cantSanciones();i++){
		if( vSanciones[i].VerFechaSancion_T() < fechaHoy_t){ 			
			vSanciones.erase(vSanciones.begin()+i);
		}			
	}	
	Guardar();
}

//*****GUARDADO DE DATOS AL ARCHIVO*****
bool Biblioteca::Guardar() const {
	//Guardar libros	
	ofstream archivoLibros(directorioLibros.c_str(),ios::binary|ios::trunc);
	if (!archivoLibros.is_open())
		return false;
	for (int i=0;i<cantLibros();i++){
		registro_libro reg_libro;
		strcpy(reg_libro.titulo		, vLibros[i].VerTitulo().c_str());
		strcpy(reg_libro.autores	, vLibros[i].VerAutores().c_str());
		strcpy(reg_libro.editorial	, vLibros[i].VerEditorial().c_str());
		strcpy(reg_libro.isbn		, vLibros[i].VerISBN().c_str());
		strcpy(reg_libro.edicion	, vLibros[i].VerEdicion().c_str());		
		strcpy(reg_libro.tipo		, vLibros[i].VerTipo().c_str());
		strcpy(reg_libro.estado		, vLibros[i].VerEstado().c_str());
		reg_libro.codigoLibro 		= vLibros[i].VerCodigoLibro();
		reg_libro.oculto 			= vLibros[i].EstaOculto();
		archivoLibros.write((char*)&reg_libro, sizeof(reg_libro));		
	}
	archivoLibros.close();
	
	//Guardar lectores
	ofstream archivoLectores(directorioLectores.c_str(),ios::binary|ios::trunc);
	if (!archivoLectores.is_open()) return false;
	for (int i=0;i<cantLectores();i++){
		registro_lector reg_lector;
		strcpy(reg_lector.nombre	, vLectores[i].VerNombre().c_str());
		strcpy(reg_lector.apellido	, vLectores[i].VerApellido().c_str());
		strcpy(reg_lector.dni		, vLectores[i].VerDNI().c_str());
		strcpy(reg_lector.domicilio	, vLectores[i].VerDomicilio().c_str());
		strcpy(reg_lector.tel		, vLectores[i].VerTel().c_str());
		reg_lector.numeroLector 	= vLectores[i].VerNumeroLector();
		reg_lector.oculto 			= vLectores[i].EstaOculto();
		archivoLectores.write((char*)&reg_lector, sizeof(reg_lector));	
	}
	archivoLectores.close();
	
	//Guardar prestamos
	ofstream archivoPrestamos(directorioPrestamos.c_str(),ios::binary|ios::trunc);
	if (!archivoPrestamos.is_open()) return false;
	for (int i=0;i<cantPrestamos();i++){
		registro_prestamo reg_prestamo;
		reg_prestamo.numeroLector	= vPrestamos[i].VerNumeroLectorPrestamo();
		reg_prestamo.codigoLibro 	= vPrestamos[i].VerCodigoLibroPrestamo();
		reg_prestamo.fechaDesde_t 	= vPrestamos[i].VerFechaDesde_T();
		reg_prestamo.fechaHasta_t 	= vPrestamos[i].VerFechaHasta_T();
		archivoPrestamos.write((char*)&reg_prestamo, sizeof(reg_prestamo));	
	}
	archivoPrestamos.close();
	
	//Guardar sanciones
	ofstream archivoSanciones(directorioSanciones.c_str(),ios::binary|ios::trunc);
	if (!archivoSanciones.is_open()){ 
		return false; 
	}
	for (int i=0;i<cantSanciones();i++){
		registro_sancion reg_sancion;
		reg_sancion.numeroLector 	= vSanciones[i].VerNumeroLector();
		reg_sancion.fechaSancion_t 	= vSanciones[i].VerFechaSancion_T();
		strcpy(reg_sancion.motivo	, vSanciones[i].VerMotivo().c_str());
		archivoSanciones.write((char*)&reg_sancion, sizeof(reg_sancion));	
	}
	archivoSanciones.close();	
	return true;
}

//*****CARGA DE DATOS DESDE ARCHIVO*****
void Biblioteca::CargarLibrosDesdeArchivo(){
	ifstream archivo(directorioLibros.c_str(),ios::binary|ios::ate);
	if (archivo.is_open()) 
	{
		int tamanio_archivo	= archivo.tellg();
		int cantLibros 		= tamanio_archivo/sizeof(registro_libro);
		archivo.seekg(0,ios::beg);
		for (int i=0;i<cantLibros;i++)
		{
			registro_libro reg;
			archivo.read((char*)&reg,sizeof(reg));		
			Libro unLibro(reg.titulo, reg.autores, reg.editorial, reg.isbn, reg.edicion, reg.codigoLibro ,reg.tipo, reg.estado, reg.oculto);
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
		archivo.seekg(0,ios::beg);
		for (int i=0;i<cantLectores;i++){
			registro_lector reg;
			archivo.read((char*)&reg,sizeof(reg));		
			Lector unLector(reg.nombre, reg.apellido, reg.dni, reg.domicilio, reg.tel, reg.numeroLector, reg.oculto);
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
	ifstream archivo(directorioSanciones.c_str(),ios::binary|ios::ate);
	if (archivo.is_open()) {
		int tamanio_archivo = archivo.tellg();
		int cantSanciones = tamanio_archivo/sizeof(registro_sancion);
		archivo.seekg(0,ios::beg);
		for (int i=0;i<cantSanciones;i++){
			registro_sancion reg;
			archivo.read((char*)&reg,sizeof(reg));		
			Sancion unaSancion(reg.numeroLector, reg.fechaSancion_t, reg.motivo);
			vSanciones.push_back(unaSancion);				
		}		
		archivo.close();
	}

}

bool Biblioteca::EstaSancionado(int numLector){
	for( Sancion x : vSanciones){
		if( x.VerNumeroLector() == numLector){ 
			return true; 
		}
	}
	return false;
}

bool Biblioteca::TienePrestamosActivos(int numLector){
	for( Prestamo x : vPrestamos) {
		if( x.VerNumeroLectorPrestamo() == numLector){ 
			return true; 
		}
	}
	return false;
}

//BUSQUEDAS
int Biblioteca::BuscarTitulo(string parte, int pos_desde) {
	pasar_a_minusculas(parte);
	for (int i=pos_desde;i<cantLibros();i++) {
		if (!VerLibro(i).EstaOculto()){
			string cadena_a_buscar = VerLibro(i).VerTitulo();
			pasar_a_minusculas(cadena_a_buscar);
			if (cadena_a_buscar.find(parte,0)!=string::npos)
				return i;
		}
	}
	return NO_SE_ENCUENTRA;
}

int Biblioteca::BuscarApellidoYNombre(string parte, int pos_desde) {
	pasar_a_minusculas(parte);
	for (int i=pos_desde;i<cantLectores();i++) {
		if (!VerLector(i).EstaOculto()){
			string cadena_a_buscar = VerLector(i).VerApellidoYNombre();
			pasar_a_minusculas(cadena_a_buscar);
			if (cadena_a_buscar.find(parte,0)!=string::npos){
				return i;
			}
		}
	}
	return NO_SE_ENCUENTRA;
}

int Biblioteca::BuscarApellidoNombreOTitulo(string parte, int pos_desde) {
	pasar_a_minusculas(parte);
	for (int i=pos_desde;i<cantPrestamos();i++) {		
			string cadena_a_buscar_libro 	= VerLibro(VerPrestamo(i).VerCodigoLibroPrestamo()).VerTitulo();
			string cadena_a_buscar_lector 	= VerLector(VerPrestamo(i).VerNumeroLectorPrestamo()).VerApellidoYNombre();
			pasar_a_minusculas(cadena_a_buscar_libro);			
			pasar_a_minusculas(cadena_a_buscar_lector);
			if (cadena_a_buscar_libro.find(parte,0)!=string::npos || cadena_a_buscar_lector.find(parte,0)!=string::npos)
				return i;			
	}	
	return NO_SE_ENCUENTRA;
}

void Biblioteca::EscribirLog(string mensaje){	
	ofstream archivoLog(directorioLog ,ios::app);	
	time_t fecha_t = time(NULL);	
	if (!archivoLog.is_open()) {
		return;
	}
	archivoLog 	<<"["<<TimeT_a_FormatoFecha(fecha_t)<<"]" << mensaje <<endl;
}	


int Biblioteca::cantLibros()const		{ return vLibros.size();}

int Biblioteca::cantLectores()const		{ return vLectores.size();}

int Biblioteca::cantPrestamos()const	{ return vPrestamos.size();}

int Biblioteca::cantSanciones()const	{ return vSanciones.size();}

int Biblioteca::cantLibrosActivos()const{
	int cant = count_if (vLibros.begin(), vLibros.end(),NoEstaOculto_Funcion);	
	return cant;
}

Libro Biblioteca::VerLibro (int i) const		{ return vLibros[i]; }

Lector Biblioteca::VerLector (int i) const 		{ return vLectores[i]; }

Prestamo Biblioteca::VerPrestamo (int i) const	{ return vPrestamos[i]; }

Sancion Biblioteca::VerSancion (int i) const	{ return vSanciones[i]; }
