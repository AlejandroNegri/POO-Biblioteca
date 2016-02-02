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

string TimeT_a_String(long t){
	stringstream ss;
	long long t_l = (long long)t;	
	string t_s;	
	ss << t_l;
	ss >> t_s;
	return ss.str();
}

long String_a_TimeT(string s){
	long t = atol(s.c_str());
	return t;
}

string TimeT_a_FormatoFecha(long t1){
	time_t t = (time_t)t1;
	tm *fecha_tm = localtime( &t );
	stringstream ssFecha;
	ssFecha << fecha_tm->tm_mday << "/" << fecha_tm->tm_mon+1 << "/" << fecha_tm->tm_year+1900 << " "
		<< fecha_tm->tm_hour << ":" << fecha_tm->tm_min << ":" << fecha_tm->tm_sec <<"hs";
	return ssFecha.str();
}

long CalcularFecha(int cantDias){	
	//segundos en un dia (24*60*60)
	int dia_t = 86400;	
	//calculo los segundos hasta ahora y le sumo la cant de dias extra
	time_t fecha_t = time(NULL) +(cantDias * dia_t);		
	//si no es la fecha de hoy cambio los minutos
	if (cantDias>0){
		//meto el time_t en un tm para modificarle los min y seg
		tm *fecha_tm = localtime( &fecha_t );
		//le seteo la hora de entrega hasta las 23:59:59
		fecha_tm->tm_hour = 23;
		fecha_tm->tm_min = 59;
		fecha_tm->tm_sec = 59;		
		//mktime vuelve el tm a formato time_t
		fecha_t = mktime(fecha_tm);
	}	
	return fecha_t;
}

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

void Biblioteca::AgregarSancion(int codigoLector, string motivo){
	Sancion unaSancion(codigoLector, motivo);
	vSanciones.push_back(unaSancion);
}

bool Biblioteca::Guardar() const {
	ofstream archivoLibros("./datos/libros.txt",ios::trunc);
	ofstream archivoLectores("./datos/lectores.txt",ios::trunc);
	ofstream archivoPrestamos("./datos/prestamos.txt",ios::trunc);
	ofstream archivoSanciones("./datos/sanciones.txt",ios::trunc);
	//Guardar libros
	if (!archivoLibros.is_open()) return false;
	for(const Libro l:vLibros) {
		archivoLibros 	<< l.VerTitulo() << endl 
			<< l.VerAutores() << endl 
			<< l.VerEditorial() << endl 
			<< l.VerISBN() << endl 
			<< l.VerEdicion() << endl 
			<< l.VerCodigoLibro() << endl 
			<< l.VerTipo() << endl 
			<< l.VerEstado() << endl<<endl;
	}
	//Guardar lectores
	if (!archivoLectores.is_open()) return false;
	for(const Lector l:vLectores) {
		archivoLectores << l.VerNombre() << endl 
			<< l.VerApellido() << endl 
			<< l.VerDNI() << endl 				
			<< l.VerDomicilio() << endl 
			<< l.VerTel() << endl 
			<< l.VerNumeroLector() << endl<<endl;
	}
	//Guardar prestamos
	if (!archivoPrestamos.is_open()) return false;
	for(const Prestamo p:vPrestamos) {				
		archivoPrestamos << p.VerNumeroLectorPrestamo() << endl
			<< p.VerCodigoLibroPrestamo()<< endl 
			<< p.VerFechaDesde_T() << endl 
			<< p.VerFechaHasta_T()<<endl<<endl; 
	}
	return true;
	//Guardar sanciones
	if (!archivoSanciones.is_open()) return false;
	for(const Sancion s:vSanciones) {
		archivoPrestamos << s.VerNumeroLector() << endl
			<< s.VerFechaSancion_T() << endl 
			<< s.VerMotivo()<< endl<<endl; 
	}
	return true;
}

//*****CARGA DE DATOS DESDE ARCHIVO*****
void Biblioteca::CargarLibrosDesdeArchivo(){
	ifstream archivo("./datos/libros.txt");
	string Titulo;
	string Autores;
	string Editorial;
	string ISBN;
	string Edicion;
	string CodigoLibro;
	string Tipo;	
	string Estado; //Disponible o Prestado	
	string LineaVacia;
	
	while(getline(archivo,Titulo) && getline(archivo, Autores) && 
		  getline(archivo, Editorial) && getline(archivo, ISBN) && 
		  getline(archivo, Edicion) && getline(archivo, CodigoLibro) && 
		  getline(archivo, Tipo) && getline(archivo, Estado) && getline(archivo, LineaVacia)){
		Libro unLibro(Titulo, Autores, Editorial, ISBN, Edicion, atoi( CodigoLibro.c_str() ) , Tipo, Estado);
		vLibros.push_back(unLibro);	
	}
}
void Biblioteca::CargarLectoresDesdeArchivo(){
	ifstream archivo("./datos/lectores.txt");
	string Nombre;
	string Apellido;
	string DNI;
	string Domicilio;
	string Tel;
	string NumeroLector;	
	string LineaVacia;
	
	while(getline(archivo,Nombre) && getline(archivo, Apellido) && 
		  getline(archivo, DNI) && getline(archivo, Domicilio) && 
		  getline(archivo, Tel) && getline(archivo, NumeroLector) && 
		  getline(archivo, LineaVacia)){
		Lector unLector(Nombre, Apellido, DNI, Domicilio, Tel, atoi( NumeroLector.c_str() ));
		vLectores.push_back(unLector);	
	}
}
void Biblioteca::CargarPrestamosDesdeArchivo(){
	ifstream archivo("./datos/prestamos.txt");
	string NumeroLector;
	string CodigoLibro;	
	string FechaDesde_TimeT;
	string FechaHasta_TimeT;		
	string LineaVacia;
	
	while(getline(archivo,NumeroLector) && getline(archivo, CodigoLibro) && 
		  getline(archivo, FechaDesde_TimeT) && getline(archivo, FechaHasta_TimeT) && 
		  getline(archivo, LineaVacia)){
		Prestamo unPrestamo(atoi(NumeroLector.c_str() ), atoi(CodigoLibro.c_str() ),String_a_TimeT(FechaDesde_TimeT) , String_a_TimeT(FechaHasta_TimeT));
		vPrestamos.push_back(unPrestamo);	
	}
}
void Biblioteca::CargarSancionesDesdeArchivo(){
	ifstream archivo("./datos/sanciones.txt");
	string NumeroLector;
	string FechaSancion_T;
	string Motivo;
	string LineaVacia;
	
	while(getline(archivo,NumeroLector) && getline(archivo, FechaSancion_T) && 
		  getline(archivo, FechaSancion_T) && getline(archivo, LineaVacia)){
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




int Biblioteca::cantLibros()const{ return vLibros.size();}

int Biblioteca::cantLectores()const{ return vLectores.size();}

int Biblioteca::cantPrestamos()const{ return vPrestamos.size();}

int Biblioteca:: cantSanciones()const{ return vSanciones.size();}

Libro Biblioteca::VerLibro (int i) const {
	return vLibros[i];
}	

Lector Biblioteca::VerLector (int i) const {
	return vLectores[i];
}

Prestamo Biblioteca::VerPrestamo (int i) const {
	return vPrestamos[i];
}

//consola
//void Biblioteca::mostrar(){		
//	cout <<"***LIBROS***"<<endl;
//	for( Libro x : vLibros) {			
//		cout << x.VerTitulo() << " "<< x.VerCodigoLibro()<< " " << x.VerEstado() << endl;
//	}	
//	cout <<"***LECTORES***"<<endl;
//	for( Lector x : vLectores) {
//		cout << x.VerNombre() << " "<< x.VerNumeroLector()<<endl;
//	}	
//	cout <<"***PRESTAMOS***"<<endl;
//	for( Prestamo x : vPrestamos) {
//		cout << x.VerNumeroLectorPrestamo() << " "<< x.VerCodigoLibroPrestamo()<<" "<< x.VerFechaDesde() << " " << x.VerFechaHasta()<<endl;
//	}
//	cout <<"***SANCIONES***"<<endl;
//	for( Sancion x : vSanciones) {
//		cout << x.VerNumeroLector() << " sancionado hasta "<< x.VerFechaSancion_S()<<" por "<< x.VerMotivo()<<endl;
//	}
//}	

