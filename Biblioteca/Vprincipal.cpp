#include "Vprincipal.h"
#include "Libro.h"
#include "Biblioteca.h"
#include "VagregarLibro.h"
#include "Singleton.h"
#include "VagregarLector.h"
#include "Prestamo.h"
#include "Lector.h"
#include <wx/textdlg.h>
#include <wx/msgdlg.h>
#include <wx/string.h>


//constructor
Vprincipal::Vprincipal(wxWindow *parent) : VentanaPrincipal(parent) {	
	RefrescarGrillas();
}

//destructor
Vprincipal::~Vprincipal(){}



//********DIBUJAR GRILLAS POR PESTAÑA********

void Vprincipal::DibujarPestaniaLibros(){
	gLibros->DeleteRows(0,gLibros->GetNumberRows(), true);
	int cant_libros = Singleton::ObtenerInstancia()->cantLibros();	
	gLibros->AppendRows(cant_libros); // agregar tantas filas como libros	
	for (int i=0;i<cant_libros;i++) {
		CargarFilaLibros(i);// cargar todos los datos
	}
	gLibros->SetSelectionMode(wxGrid::wxGridSelectRows);
	Show();
}

void Vprincipal::DibujarPestaniaLectores(){
	gLectores->DeleteRows(0,gLectores->GetNumberRows(), true);
	int cant_lectores = Singleton::ObtenerInstancia()->cantLectores();
	gLectores->AppendRows(cant_lectores);	
	for (int i=0;i<cant_lectores;i++) {
		CargarFilaLectores(i);// cargar todos los datos
	}
	gLectores->SetSelectionMode(wxGrid::wxGridSelectRows);
	Show();
}

void Vprincipal::DibujarPestaniaPrestamos(){
	gPrestamos->DeleteRows(0,gPrestamos->GetNumberRows(), true);
	int cant_prestamos = Singleton::ObtenerInstancia()->cantPrestamos();
	gPrestamos->AppendRows(cant_prestamos);	
	for (int i=0;i<cant_prestamos;i++) {
		CargarFilaPrestamos(i);// cargar todos los datos
	}
	gPrestamos->SetSelectionMode(wxGrid::wxGridSelectRows);
	Show();
}

void Vprincipal::RefrescarGrillas(){
	Vprincipal::DibujarPestaniaLibros();
	Vprincipal::DibujarPestaniaLectores();
	Vprincipal::DibujarPestaniaPrestamos();
}



//********CARGA DE DATOS EN LAS GRILLAS********

//				LIBROS
void Vprincipal::CargarFilaLibros(int i) {
	Libro l= Singleton::ObtenerInstancia()->VerLibro(i);
	gLibros->SetCellValue(i,0,l.VerTitulo());
	gLibros->SetCellValue(i,1,l.VerAutores());
	gLibros->SetCellValue(i,2,l.VerEditorial());
	gLibros->SetCellValue(i,3,l.VerISBN());
	gLibros->SetCellValue(i,4,l.VerEdicion());	
	wxString cod;
	cod << l.VerCodigoLibro();	
	gLibros->SetCellValue(i,5,cod);
	gLibros->SetCellValue(i,6,l.VerTipo());
	gLibros->SetCellValue(i,7,l.VerEstado());
}
//				LECTORES
void Vprincipal::CargarFilaLectores(int i) {
	Lector l= Singleton::ObtenerInstancia()->VerLector(i);
	gLectores->SetCellValue(i,0,l.VerApellido());
	gLectores->SetCellValue(i,1,l.VerNombre());
	gLectores->SetCellValue(i,2,l.VerDNI());
	gLectores->SetCellValue(i,3,l.VerDomicilio());
	gLectores->SetCellValue(i,4,l.VerTel());	
	wxString numLector;
	numLector << l.VerNumeroLector();	
	gLectores->SetCellValue(i,5,numLector);
}
//				PRESTAMOS
void Vprincipal::CargarFilaPrestamos(int i) {
	Prestamo p = Singleton::ObtenerInstancia()->VerPrestamo(i);
	Lector le = Singleton::ObtenerInstancia()->VerLector(p.VerNumeroLectorPrestamo());
	Libro li= Singleton::ObtenerInstancia()->VerLibro(p.VerCodigoLibroPrestamo());	
	
	gPrestamos->SetCellValue(i,0,le.VerApellido() + ", " + le.VerNombre());
	gPrestamos->SetCellValue(i,1,li.VerTitulo());
	gPrestamos->SetCellValue(i,2,p.VerFechaDesde());
	gPrestamos->SetCellValue(i,3,p.VerFechaHasta());
}



//********EVENTOS DEL MENU********

//MENU LIBRO: AGREGAR
void Vprincipal::ClickAgregarLibroMenu( wxCommandEvent& event ) {
	VagregarLibro nueva_ventana(this); // crear la ventana
	if (nueva_ventana.ShowModal()==1) { // mostrar y esperar
		gLibros->AppendRows(1); // agregar el lugar en la grilla
		CargarFilaLibros(Singleton::ObtenerInstancia()->cantLibros()-1); // copiar en la grilla
		Show();
	}
}

//MENU LECTOR: AGREGAR
void Vprincipal::ClickAgregarLectorMenu( wxCommandEvent& event )  {
	VagregarLector nueva_ventana(this); // crear la ventana
	if (nueva_ventana.ShowModal()==1) { // mostrar y esperar
		gLectores->AppendRows(1); // agregar el lugar en la grilla
		CargarFilaLectores(Singleton::ObtenerInstancia()->cantLectores()-1); // copiar en la grilla
		Show();
	}
}

//MENU PRESTAMO: PRESTAR
void Vprincipal::ClickAgregarPrestamoMenu( wxCommandEvent& event )  {	
	wxString numLector = wxGetTextFromUser("Ingrese el número de lector","Nuevo Préstamo","",this);	
	if (atoi(numLector)>= (Singleton::ObtenerInstancia()->cantLectores())){
		wxMessageBox("Número de lector incorrecto!","Error",wxOK|wxICON_ERROR,this);
		return;
	}
	Lector unLector = Singleton::ObtenerInstancia()->VerLector(atoi(numLector.c_str()));
	if (numLector==""){
		wxMessageBox("Número de lector incorrecto!","Error",wxOK|wxICON_ERROR,this);
		return;
	}else if(Singleton::ObtenerInstancia()->EstaSancionado(atoi(numLector))){
		wxMessageBox("Ese lector esta sancionado!","Error",wxOK|wxICON_ERROR,this);
		return;
	}	
	wxString codLibro = wxGetTextFromUser("Ingrese el código del libro","Nuevo Préstamo","",this);
	if (atoi(codLibro)>= (Singleton::ObtenerInstancia()->cantLibros())){
		wxMessageBox("Código de libro incorrecto!","Error",wxOK|wxICON_ERROR,this);
		return;
	}
	Libro unLibro = Singleton::ObtenerInstancia()->VerLibro(atoi(codLibro.c_str()));
	if (codLibro==""){
		wxMessageBox("Código de libro incorrecto!","Error",wxOK|wxICON_ERROR,this);
		return;
	}else if(!unLibro.EstaDisponible()){
		wxMessageBox("Ese libro esta prestado!","Error",wxOK|wxICON_ERROR,this);
		return;
	}	
	wxMessageDialog dial(NULL, wxT("El usuario: " + unLector.VerApellido()  + ", " + unLector.VerNombre() + " llevará el libro: " + unLibro.VerTitulo()
								   + ". ¿Confirmar préstamo?"), wxT("Question"), wxYES_NO | wxNO_DEFAULT | wxICON_QUESTION);
	if (dial.ShowModal() ==  wxID_YES){		
		Singleton::ObtenerInstancia()->AgregarPrestamo(unLector.VerNumeroLector(), unLibro.VerCodigoLibro());
		Singleton::ObtenerInstancia()->Guardar(); // actualizar el archivo	
		RefrescarGrillas();
		wxMessageBox("Préstamo Agregado!");
	}else{
		wxMessageBox("Préstamo Cancelado!");
		return;
	}	
	return;
}

//MENU PRESTAMO: DEVOLVER
void Vprincipal::ClickAgregarDevolucionMenu( wxCommandEvent& event )  {
	wxString codLibro = wxGetTextFromUser("Ingrese el código del libro","Nuevo Préstamo","",this);
	if (atoi(codLibro)>= (Singleton::ObtenerInstancia()->cantLibros())){
		wxMessageBox("Código de libro incorrecto!","Error",wxOK|wxICON_ERROR,this);
		return;
	}
	Libro unLibro = Singleton::ObtenerInstancia()->VerLibro(atoi(codLibro.c_str()));
	if (codLibro==""){
		wxMessageBox("Código de libro incorrecto!","Error",wxOK|wxICON_ERROR,this);
		return;
	}else if(unLibro.EstaDisponible()){
		wxMessageBox("Ese libro no estaba prestado!","Error",wxOK|wxICON_ERROR,this);
		return;
	}
	wxMessageDialog dial(NULL, wxT("¿Confirmar devolución de: " + unLibro.VerTitulo()+ "?"), wxT("Question"), wxYES_NO | wxNO_DEFAULT | wxICON_QUESTION);
	if (dial.ShowModal()){		
		int diasAtrasados = Singleton::ObtenerInstancia()->EliminarPrestamo(unLibro.VerCodigoLibro());		
		Singleton::ObtenerInstancia()->Guardar(); // actualizar el archivo	
		RefrescarGrillas();
		
		wxString diasAtrasados_s;
		diasAtrasados_s << diasAtrasados;	
		
		
		wxMessageBox("Devolución Agregada! " + diasAtrasados_s + " días tarde!" );
	}else{
		wxMessageBox("Devolución Cancelada!");
		return;
	}	
	return;
}


//eventos
void Vprincipal::ClickPestaniaLibros( wxMouseEvent& event )  {
	Vprincipal::DibujarPestaniaLibros();
	event.Skip();
}

void Vprincipal::ClickPestaniaLectores( wxMouseEvent& event )  {
	Vprincipal::DibujarPestaniaLectores();
	event.Skip();
}

void Vprincipal::ClickPestaniaPrestamos( wxMouseEvent& event )  {
	Vprincipal::DibujarPestaniaPrestamos();
	event.Skip();
}


