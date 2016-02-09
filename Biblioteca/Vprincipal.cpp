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
#include "Utils.h"
#include <cstdlib>


//constructor
Vprincipal::Vprincipal(wxWindow *parent) : VentanaPrincipal(parent) {	
	RefrescarGrillas();
}

//destructor
Vprincipal::~Vprincipal(){}



//********DIBUJAR GRILLAS POR PESTA�A********

void Vprincipal::DibujarPestaniaLibros(){
	gLibros->DeleteRows(0,gLibros->GetNumberRows(), true);
	int cant_libros_activos = Singleton::ObtenerInstancia()->cantLibrosActivos();	
	int cant_libros = Singleton::ObtenerInstancia()->cantLibros();	
	gLibros->AppendRows(cant_libros_activos); // agregar tantas filas como libros activos
	int fila_a_llenar = 0;
	for (int i=0;i<cant_libros;i++) {		
		if (!( Singleton::ObtenerInstancia()->VerLibro(i).EstaOculto())){
			int cod = Singleton::ObtenerInstancia()->VerLibro(i).VerCodigoLibro();
			CargarFilaLibros(fila_a_llenar, cod);// cargar todos los datos
			fila_a_llenar++;
		}		
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


void Vprincipal::DibujarPestaniaSanciones(){
	gSanciones->DeleteRows(0,gSanciones->GetNumberRows(), true);
	int cant_sanciones = Singleton::ObtenerInstancia()->cantSanciones();
	gSanciones->AppendRows(cant_sanciones);	
	for (int i=0;i<cant_sanciones;i++) {
		CargarFilaSanciones(i);// cargar todos los datos
	}
	gSanciones->SetSelectionMode(wxGrid::wxGridSelectRows);
	Show();
}

void Vprincipal::RefrescarGrillas(){
	Vprincipal::DibujarPestaniaLibros();
	Vprincipal::DibujarPestaniaLectores();
	Vprincipal::DibujarPestaniaPrestamos();
	Vprincipal::DibujarPestaniaSanciones();
}



//********CARGA DE DATOS EN LAS GRILLAS********

//				LIBROS
void Vprincipal::CargarFilaLibros(int fila_a_llenar, int codL) {
	Libro l= Singleton::ObtenerInstancia()->VerLibro(codL);
	gLibros->SetCellValue(fila_a_llenar,0,l.VerTitulo());
	gLibros->SetCellValue(fila_a_llenar,1,l.VerAutores());
	gLibros->SetCellValue(fila_a_llenar,2,l.VerEditorial());
	gLibros->SetCellValue(fila_a_llenar,3,l.VerISBN());
	gLibros->SetCellValue(fila_a_llenar,4,l.VerEdicion());	
	wxString cod;
	cod << l.VerCodigoLibro();	
	gLibros->SetCellValue(fila_a_llenar,5,cod);
	gLibros->SetCellValue(fila_a_llenar,6,l.VerTipo());
	gLibros->SetCellValue(fila_a_llenar,7,l.VerEstado());
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
//				SANCIONES
void Vprincipal::CargarFilaSanciones(int i) {
	Sancion s = Singleton::ObtenerInstancia()->VerSancion(i);
	Lector le = Singleton::ObtenerInstancia()->VerLector(s.VerNumeroLector());
	
	gSanciones->SetCellValue(i,0,le.VerApellido() + ", " + le.VerNombre());
	gSanciones->SetCellValue(i,1,s.VerFechaSancion());
	gSanciones->SetCellValue(i,2,s.VerMotivo());
}



//********EVENTOS DEL MENU********

//MENU LIBRO: AGREGAR
void Vprincipal::ClickAgregarLibroMenu( wxCommandEvent& event ) {
	VagregarLibro nueva_ventana(this); // crear la ventana
	if (nueva_ventana.ShowModal()==1) { // mostrar y esperar
		RefrescarGrillas();
		Show();
	}
}

//MENU LECTOR: AGREGAR
void Vprincipal::ClickAgregarLectorMenu( wxCommandEvent& event )  {
	VagregarLector nueva_ventana(this); // crear la ventana
	if (nueva_ventana.ShowModal()==1) { // mostrar y esperar
		RefrescarGrillas(); 
	}
}

//MENU PRESTAMO: PRESTAR
void Vprincipal::ClickAgregarPrestamoMenu( wxCommandEvent& event )  {	
	wxString numLector = wxGetTextFromUser("Ingrese el n�mero de lector","Nuevo Pr�stamo","",this);	
	if (atoi(numLector)>= (Singleton::ObtenerInstancia()->cantLectores())){
		wxMessageBox("N�mero de lector incorrecto!","Error",wxOK|wxICON_ERROR,this);
		return;
	}
	Lector unLector = Singleton::ObtenerInstancia()->VerLector(atoi(numLector.c_str()));
	if (numLector==""){
		wxMessageBox("N�mero de lector incorrecto!","Error",wxOK|wxICON_ERROR,this);
		return;
	}else if(Singleton::ObtenerInstancia()->EstaSancionado(atoi(numLector))){
		wxMessageBox("Ese lector esta sancionado!","Error",wxOK|wxICON_ERROR,this);
		return;
	}	
	wxString codLibro = wxGetTextFromUser("Ingrese el c�digo del libro","Nuevo Pr�stamo","",this);
	if (atoi(codLibro)>= (Singleton::ObtenerInstancia()->cantLibros())){
		wxMessageBox("C�digo de libro incorrecto!","Error",wxOK|wxICON_ERROR,this);
		return;
	}
	Libro unLibro = Singleton::ObtenerInstancia()->VerLibro(atoi(codLibro.c_str()));
	if (codLibro==""){
		wxMessageBox("C�digo de libro incorrecto!","Error",wxOK|wxICON_ERROR,this);
		return;
	}else if(!unLibro.EstaDisponible()){
		wxMessageBox("Ese libro esta prestado!","Error",wxOK|wxICON_ERROR,this);
		return;
	}	
	wxMessageDialog dial(NULL, wxT("El usuario: " + unLector.VerApellido()  + ", " + unLector.VerNombre() + " llevar� el libro: " + unLibro.VerTitulo()
								   + ". �Confirmar pr�stamo?"), wxT("Question"), wxYES_NO | wxNO_DEFAULT | wxICON_QUESTION);
	if (dial.ShowModal() ==  wxID_YES){		
		Singleton::ObtenerInstancia()->AgregarPrestamo(unLector.VerNumeroLector(), unLibro.VerCodigoLibro());
		Singleton::ObtenerInstancia()->Guardar(); // actualizar el archivo	
		RefrescarGrillas();
		wxMessageBox("Pr�stamo Agregado!");
	}else{
		wxMessageBox("Pr�stamo Cancelado!");
		return;
	}	
	return;
}

//MENU PRESTAMO: DEVOLVER
void Vprincipal::ClickAgregarDevolucionMenu( wxCommandEvent& event )  {
	wxString codLibro = wxGetTextFromUser("Ingrese el c�digo del libro","Nuevo Pr�stamo","",this);
	if (atoi(codLibro)>= (Singleton::ObtenerInstancia()->cantLibros())){
		wxMessageBox("C�digo de libro incorrecto!","Error",wxOK|wxICON_ERROR,this);
		return;
	}
	Libro unLibro = Singleton::ObtenerInstancia()->VerLibro(atoi(codLibro.c_str()));
	if (codLibro==""){
		wxMessageBox("C�digo de libro incorrecto!","Error",wxOK|wxICON_ERROR,this);
		return;
	}else if(unLibro.EstaDisponible()){
		wxMessageBox("Ese libro no estaba prestado!","Error",wxOK|wxICON_ERROR,this);
		return;
	}
	wxMessageDialog dial(NULL, wxT("�Confirmar devoluci�n de: " + unLibro.VerTitulo()+ "?"), wxT("Question"), wxYES_NO | wxNO_DEFAULT | wxICON_QUESTION);
	if (dial.ShowModal() ==  wxID_YES){		
		int diasAtrasados = Singleton::ObtenerInstancia()->EliminarPrestamo(unLibro.VerCodigoLibro());		
		Singleton::ObtenerInstancia()->Guardar(); // actualizar el archivo	
		RefrescarGrillas();
		
		wxString diasAtrasados_s;
		diasAtrasados_s << diasAtrasados;	
		
		
		wxMessageBox("Devoluci�n Agregada! " + diasAtrasados_s + " d�as tarde!" );
	}else{
		wxMessageBox("Devoluci�n Cancelada!");
		return;
	}	
	return;
}

//MENU SANCION: AGREGAR
void Vprincipal::ClickAgregarSancionMenu( wxCommandEvent& event )  {
	
	wxString numLector = wxGetTextFromUser("Ingrese el n�mero de lector","Nueva Sanci�n","",this);	
	if (atoi(numLector)>= (Singleton::ObtenerInstancia()->cantLectores())){
		wxMessageBox("N�mero de lector incorrecto!","Error",wxOK|wxICON_ERROR,this);
		return;
	}
	Lector unLector = Singleton::ObtenerInstancia()->VerLector(atoi(numLector.c_str()));
	if (numLector==""){
		wxMessageBox("N�mero de lector incorrecto!","Error",wxOK|wxICON_ERROR,this);
		return;
//	}else if(Singleton::ObtenerInstancia()->EstaSancionado(atoi(numLector))){
//		wxMessageBox("Ese lector esta sancionado!","Error",wxOK|wxICON_ERROR,this);
//		return;
	}	
	
	wxString cantDias_s = wxGetTextFromUser("Cantidad de d�as a sancionar:","Nueva Sanci�n","",this);
	if (cantDias_s==""){
		wxMessageBox("Cantidad incorrecta incorrecto!","Error",wxOK|wxICON_ERROR,this);
		return;
	}
	int cantDias = atoi(cantDias_s);
	
	wxString motivo = wxGetTextFromUser("Motivo de Sanci�n:","Nueva Sanci�n","",this);
	if (motivo==""){
		wxMessageBox("Agregue un motivo de sanci�n!","Error",wxOK|wxICON_ERROR,this);
		return;
	}
	
	wxMessageDialog dial(NULL, wxT("El usuario: " + unLector.VerApellido()  + ", " + unLector.VerNombre() + " ser� sancionado " + cantDias_s
								   + " d�as por "+ motivo +". �Confirmar sanci�n?"), wxT("Question"), wxYES_NO | wxNO_DEFAULT | wxICON_QUESTION);
	if (dial.ShowModal() ==  wxID_YES){		
		Singleton::ObtenerInstancia()->AgregarSancion(unLector.VerNumeroLector(), motivo.c_str(), cantDias);
		Singleton::ObtenerInstancia()->Guardar(); // actualizar el archivo	
		RefrescarGrillas();
		wxMessageBox("Sanci�n Agregada!");
	}else{
		wxMessageBox("Sanci�n Cancelada!");
		return;
	}	
	return;
}


//           EVENTOS DE PESTA�AS
void Vprincipal::ClickPestaniaLibros( wxMouseEvent& event )  {
	Vprincipal::DibujarPestaniaLibros();
}

void Vprincipal::ClickPestaniaLectores( wxMouseEvent& event )  {
	Vprincipal::DibujarPestaniaLectores();
	event.Skip();
}

void Vprincipal::ClickPestaniaPrestamos( wxMouseEvent& event )  {
	Vprincipal::DibujarPestaniaPrestamos();
	event.Skip();
}


void Vprincipal::ClickPestaniaSanciones( wxMouseEvent& event )  {
	Vprincipal::DibujarPestaniaSanciones();
	event.Skip();
}



void Vprincipal::ClickBusquedaPorTitulo( wxCommandEvent& event )  {
	int fila_actual = gLibros->GetGridCursorRow();
	int res = Singleton::ObtenerInstancia()->BuscarTitulo(tBusquedaTitulo->GetValue().c_str(),fila_actual+1);
	if (res==NO_SE_ENCUENTRA) 
		res=Singleton::ObtenerInstancia()->BuscarTitulo(tBusquedaTitulo->GetValue().c_str(),0);
	if (res==-1)
		wxMessageBox("No se encontraron mas coincidencias");
	else {
		gLibros->SetGridCursor(res,0); // seleccionar celda
		gLibros->SelectRow(res); // marcar toda la fila
		//gLibros->MakeCellVisible(res,0); // asegurarse de que se ve
	}	
}

void Vprincipal::ClickEliminarLibroMenu( wxCommandEvent& event )  {
	wxString codLibro = wxGetTextFromUser("Ingrese el c�digo del libro","Eliminar Libro","",this);
	if (atoi(codLibro)>= (Singleton::ObtenerInstancia()->cantLibros())){
		wxMessageBox("C�digo de libro incorrecto!","Error",wxOK|wxICON_ERROR,this);
		return;
	}
	if (codLibro==""){
		wxMessageBox("C�digo de libro incorrecto!","Error",wxOK|wxICON_ERROR,this);
		return;
	}else if(!Singleton::ObtenerInstancia()->VerLibro(atoi(codLibro.c_str())).EstaDisponible()){
		wxMessageBox("Ese libro esta prestado o eliminado!","Error",wxOK|wxICON_ERROR,this);
		return;
	}		
	wxMessageDialog dial(NULL, wxT("�Eliminar el libro " + Singleton::ObtenerInstancia()->VerLibro(atoi(codLibro.c_str())).VerTitulo()  
								   + " (" + Singleton::ObtenerInstancia()->VerLibro(atoi(codLibro.c_str())).EstaDisponible() 
								   + ") ? "),wxT("Question"), wxYES_NO | wxNO_DEFAULT | wxICON_QUESTION);
	if (dial.ShowModal() ==  wxID_YES){	
		int num = atoi(codLibro);
		Singleton::ObtenerInstancia()->OcultarLibro(num);		
		Singleton::ObtenerInstancia()->Guardar(); // actualizar el archivo	
		wxMessageBox("�El libro ha sido eliminado!");
		RefrescarGrillas();
	}else{
		wxMessageBox("�El libro no ha sido eliminado!");
		return;
	}	
	return;
}


//doble click en libro
void Vprincipal::DClickGrillaLibro( wxGridEvent& event )  {
	event.Skip();
}

