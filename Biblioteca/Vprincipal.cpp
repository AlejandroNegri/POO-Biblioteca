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
#include <wx/grid.h>
#include "vAgregarPrestamo.h"
#include "vModificarLibro.h"
#include "vModificarLector.h"


//constructor
Vprincipal::Vprincipal(wxWindow *parent) : VentanaPrincipal(parent) {	
	RefrescarGrillas();
}

//destructor
Vprincipal::~Vprincipal(){}

//********DIBUJAR GRILLAS POR PESTA�A********
void Vprincipal::DibujarPestaniaLibros(){
	gLibros->SetRowMinimalAcceptableHeight(0);
	gLibros->DeleteRows(0,gLibros->GetNumberRows(), true);	
	int cant_libros = Singleton::ObtenerInstancia()->cantLibros();	
	gLibros->AppendRows(cant_libros); // agregar tantas filas como libros activos
	for (int i=0;i<cant_libros;i++) {		
		CargarFilaLibros(i);// cargar todos los datos
		if (Singleton::ObtenerInstancia()->VerLibro(i).EstaOculto()){
			gLibros->SetRowSize(i,0);			
		}		
	}
	gLibros->SetSelectionMode(wxGrid::wxGridSelectRows);
}

void Vprincipal::DibujarPestaniaLectores(){
	gLectores->SetRowMinimalAcceptableHeight(0);
	gLectores->DeleteRows(0,gLectores->GetNumberRows(), true);
	int cant_lectores = Singleton::ObtenerInstancia()->cantLectores();
	gLectores->AppendRows(cant_lectores);	
	for (int i=0;i<cant_lectores;i++) {
		CargarFilaLectores(i);// cargar todos los datos
		if (Singleton::ObtenerInstancia()->VerLector(i).EstaOculto()){
			gLectores->SetRowSize(i,0);			
		}		
	}
	gLectores->SetSelectionMode(wxGrid::wxGridSelectRows);
}

void Vprincipal::DibujarPestaniaPrestamos(){
	gPrestamos->DeleteRows(0,gPrestamos->GetNumberRows(), true);
	int cant_prestamos = Singleton::ObtenerInstancia()->cantPrestamos();
	gPrestamos->AppendRows(cant_prestamos);	
	for (int i=0;i<cant_prestamos;i++) {
		CargarFilaPrestamos(i);// cargar todos los datos
	}
	gPrestamos->SetSelectionMode(wxGrid::wxGridSelectRows);
}

void Vprincipal::DibujarPestaniaSanciones(){
	gSanciones->DeleteRows(0,gSanciones->GetNumberRows(), true);
	int cant_sanciones = Singleton::ObtenerInstancia()->cantSanciones();
	gSanciones->AppendRows(cant_sanciones);	
	for (int i=0;i<cant_sanciones;i++) {
		CargarFilaSanciones(i);// cargar todos los datos
	}
	gSanciones->SetSelectionMode(wxGrid::wxGridSelectRows);
}

void Vprincipal::RefrescarGrillas(){	
	Vprincipal::DibujarPestaniaLibros();
	Vprincipal::DibujarPestaniaLectores();
	Vprincipal::DibujarPestaniaPrestamos();
	Vprincipal::DibujarPestaniaSanciones();	
}

//********CARGA DE DATOS EN LAS GRILLAS********

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
	
	gPrestamos->SetCellValue(i,0,li.VerTitulo());
	gPrestamos->SetCellValue(i,1,le.VerApellido() + ", " + le.VerNombre());
	gPrestamos->SetCellValue(i,2,p.VerFechaDesde());
	gPrestamos->SetCellValue(i,3,p.VerFechaHasta());
}
//				SANCIONES
void Vprincipal::CargarFilaSanciones(int i) {
	Sancion s = Singleton::ObtenerInstancia()->VerSancion(i);
	Lector le = Singleton::ObtenerInstancia()->VerLector(s.VerNumeroLector());
	
	gSanciones->SetCellValue(i,0,le.VerApellidoYNombre());
	gSanciones->SetCellValue(i,1,s.VerFechaSancion());
	gSanciones->SetCellValue(i,2,s.VerMotivo());
}

//********EVENTOS DEL MENU********

//MENU LIBRO: AGREGAR
void Vprincipal::ClickAgregarLibroMenu( wxCommandEvent& event ) {
	VagregarLibro nueva_ventana(this);
	if (nueva_ventana.ShowModal()==1) {
		RefrescarGrillas();
	}
}
//MENU LIBRO: MODIFICAR
void Vprincipal::ClickModificarLibroMenu() {	
	vModificarLibro::codLibro=indiceGrilla;
	vModificarLibro nueva_ventana(this);	
	if (nueva_ventana.ShowModal()==1) {
		RefrescarGrillas();
	}
}

//		ELIMINAR
void Vprincipal::ClickEliminarLibroMenu()  {
	if(!Singleton::ObtenerInstancia()->VerLibro(indiceGrilla).EstaDisponible()){
		wxMessageBox("�No se pueden eliminar libros en pr�stamo!","Error",wxOK|wxICON_ERROR,this);
		return;
	}		
	wxMessageDialog dial(NULL, wxT("�Eliminar el libro " + Singleton::ObtenerInstancia()->VerLibro(indiceGrilla).VerTitulo() 
								   + "? "),wxT("Question"), wxYES_NO | wxNO_DEFAULT | wxICON_QUESTION);
	if (dial.ShowModal() ==  wxID_YES){	
		Singleton::ObtenerInstancia()->OcultarLibro(indiceGrilla);		
		Singleton::ObtenerInstancia()->Guardar(); // actualizar el archivo	
		wxMessageBox("�El libro ha sido eliminado!");
		RefrescarGrillas();
	}	
	return;
}

//MENU LECTOR: AGREGAR
void Vprincipal::ClickAgregarLectorMenu( wxCommandEvent& event )  {
	VagregarLector nueva_ventana(this); // crear la ventana
	if (nueva_ventana.ShowModal()==1) { // mostrar y esperar
		RefrescarGrillas(); 
	}
}
//MENU LECTOR: MODIFICAR
void Vprincipal::ClickModificarLectorMenu() {	
	vModificarLector::numLector=indiceGrilla;
	vModificarLector nueva_ventana(this);	
	if (nueva_ventana.ShowModal()==1) {
		RefrescarGrillas();
	}
}

void Vprincipal::ClickEliminarLectorMenu()  {
	if(Singleton::ObtenerInstancia()->TienePrestamosActivos(indiceGrilla)){
		wxMessageBox("�No se pueden eliminar lectores con pr�stamos activos!","Error",wxOK|wxICON_ERROR,this);
		return;
	}	
	wxMessageDialog dial(NULL, wxT("�Eliminar el lector " + Singleton::ObtenerInstancia()->VerLector(indiceGrilla).VerApellidoYNombre() 
								   + "? "),wxT("Question"), wxYES_NO | wxNO_DEFAULT | wxICON_QUESTION);
	if (dial.ShowModal() ==  wxID_YES){	
		Singleton::ObtenerInstancia()->OcultarLector(indiceGrilla);		
		Singleton::ObtenerInstancia()->Guardar(); // actualizar el archivo	
		wxMessageBox("�El lector ha sido eliminado!");
		RefrescarGrillas();
	}
	return;
}

//PRESTAMO: AGREGAR:
void Vprincipal::ClickAgregarPrestamoMenu(){	
	vAgregarPrestamo ventana_prestamo(this);			
	if (ventana_prestamo.ShowModal()==1) { // mostrar y esperar
		RefrescarGrillas();
	}	
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
	}else if(unLector.EstaOculto()){
		wxMessageBox("Ese lector fu� eliminado!","Error",wxOK|wxICON_ERROR,this);
		return;
	}

//	}else if(Singleton::ObtenerInstancia()->EstaSancionado(atoi(numLector))){
//		wxMessageBox("Ese lector esta sancionado!","Error",wxOK|wxICON_ERROR,this);
//		return;
//	}	
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
void Vprincipal::ClickPestaniaLibros( wxMouseEvent& event )  { Vprincipal::DibujarPestaniaLibros(); }
void Vprincipal::ClickPestaniaLectores( wxMouseEvent& event )  { Vprincipal::DibujarPestaniaLectores(); }
void Vprincipal::ClickPestaniaPrestamos( wxMouseEvent& event )  { Vprincipal::DibujarPestaniaPrestamos(); }
void Vprincipal::ClickPestaniaSanciones( wxMouseEvent& event )  { Vprincipal::DibujarPestaniaSanciones(); }


// BUSQUEDA
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
	}	
}

void Vprincipal::ClickBusquedaPorNombre( wxCommandEvent& event )  {
	int fila_actual = gLectores->GetGridCursorRow();
	int res = Singleton::ObtenerInstancia()->BuscarApellidoYNombre(tBusquedaNombre->GetValue().c_str(),fila_actual+1);
	if (res==NO_SE_ENCUENTRA) 
		res=Singleton::ObtenerInstancia()->BuscarApellidoYNombre(tBusquedaNombre->GetValue().c_str(),0);
	if (res==-1)
		wxMessageBox("No se encontraron mas coincidencias");
	else {
		gLectores->SetGridCursor(res,0); // seleccionar celda
		gLectores->SelectRow(res); // marcar toda la fila
	}
}







//			CLICK DERECHO LIBRO
//MENU
void Vprincipal::ClickDerechoGrillaLibro( wxGridEvent& event )  {
	gLibros->SetGridCursor(event.GetRow(),0); // seleccionar celda
	gLibros->SelectRow(event.GetRow()); // marcar toda la fila
	
	ResetearIndices();	
	indiceGrilla = event.GetRow();	
	
	wxMenu menu(wxT(""));	
	menu.Append(0, wxT("Prestar"));
	menu.Append(1, wxT("Modificar"));
	menu.Append(2, wxT("Eliminar"));
	menu.Connect(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(Vprincipal::PopupClickDerechoLibro), NULL, this);
	PopupMenu(&menu);
}
//FUNCIONES
void Vprincipal::PopupClickDerechoLibro(wxCommandEvent &event){
	switch(event.GetId()) {		
		case 0:
		{	
			vAgregarPrestamo::codLibro = indiceGrilla;
			ClickAgregarPrestamoMenu();
			break;
		}
		case 1: 
		{
			ClickModificarLibroMenu();
			break;
		}	
		case 2:{
			ClickEliminarLibroMenu();
			break;
		}
	}
}

//			CLICK DERECHO LECTORES
//MENU
void Vprincipal::ClickDerechoGrillaLectores( wxGridEvent& event )  {
	gLectores->SetGridCursor(event.GetRow(),0); // seleccionar celda
	gLectores->SelectRow(event.GetRow()); // marcar toda la fila
	
	ResetearIndices();		
	indiceGrilla = event.GetRow();	
	
	wxMenu menu(wxT(""));	
	menu.Append(0, wxT("Prestar"));
	menu.Append(1, wxT("Modificar"));
	menu.Append(2, wxT("Eliminar"));
	menu.Connect(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(Vprincipal::PopupClickDerechoLector), NULL, this);
	PopupMenu(&menu);
}
//FUNCIONES
void Vprincipal::PopupClickDerechoLector(wxCommandEvent &event){
	switch(event.GetId()) {		
		case 0:
		{		
			vAgregarPrestamo::numLector = indiceGrilla;
			ClickAgregarPrestamoMenu();
			break;
		}
		case 1: 
		{
			ClickModificarLectorMenu();
			break;
		}	
		case 2:{
			ClickEliminarLectorMenu();
			break;
		}
	}
}

//resetea los indices buscadores
void Vprincipal::ResetearIndices(){
	vAgregarPrestamo::codLibro = -1;
	vAgregarPrestamo::numLector = -1;
	vModificarLibro::codLibro = -1;
	vModificarLector::numLector = -1;
	indiceGrilla = -1;
}














