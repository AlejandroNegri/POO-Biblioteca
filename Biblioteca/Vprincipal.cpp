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
#include "icono.xpm"
#include <wx/icon.h>

Vprincipal::Vprincipal(wxWindow *parent) : VentanaPrincipal(parent) {	
	SetIcon(wxIcon(icono));
	RefrescarGrillas();
}

Vprincipal::~Vprincipal(){}

//********DIBUJAR GRILLAS POR PESTAÑA********
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
		CargarFilaLectores(i);
		if (Singleton::ObtenerInstancia()->VerLector(i).EstaOculto()){ gLectores->SetRowSize(i,0);}		
	}
	gLectores->SetSelectionMode(wxGrid::wxGridSelectRows);
}

void Vprincipal::DibujarPestaniaPrestamos(){
	gPrestamos->DeleteRows(0,gPrestamos->GetNumberRows(), true);
	int cant_prestamos = Singleton::ObtenerInstancia()->cantPrestamos();
	gPrestamos->AppendRows(cant_prestamos);	
	for (int i=0;i<cant_prestamos;i++){ CargarFilaPrestamos(i); }
	gPrestamos->SetSelectionMode(wxGrid::wxGridSelectRows);
}

void Vprincipal::DibujarPestaniaSanciones(){
	gSanciones->DeleteRows(0,gSanciones->GetNumberRows(), true);
	int cant_sanciones = Singleton::ObtenerInstancia()->cantSanciones();
	gSanciones->AppendRows(cant_sanciones);	
	for (int i=0;i<cant_sanciones;i++){ CargarFilaSanciones(i); }
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
	gLibros->SetCellValue(i,5,IntToString(l.VerCodigoLibro()));
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
	gLectores->SetCellValue(i,5,IntToString(l.VerNumeroLector()));
}
//				PRESTAMOS
void Vprincipal::CargarFilaPrestamos(int i) {
	Prestamo p 	= Singleton::ObtenerInstancia()->VerPrestamo(i);
	Lector le	= Singleton::ObtenerInstancia()->VerLector(p.VerNumeroLectorPrestamo());
	Libro li	= Singleton::ObtenerInstancia()->VerLibro(p.VerCodigoLibroPrestamo());	
	gPrestamos->SetCellValue(i,1,li.VerTitulo());
	gPrestamos->SetCellValue(i,0,le.VerApellido() + ", " + le.VerNombre());
	gPrestamos->SetCellValue(i,3,p.VerFechaDesde());
	gPrestamos->SetCellValue(i,4,p.VerFechaHasta());
	gPrestamos->SetCellValue(i,2,IntToString(li.VerCodigoLibro()));
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
	if (nueva_ventana.ShowModal()==1){ RefrescarGrillas(); }
}
//MENU LIBRO: MODIFICAR
void Vprincipal::ClickModificarLibroMenu() {	
	vModificarLibro::codLibro=indice;
	vModificarLibro nueva_ventana(this);	
	if (nueva_ventana.ShowModal()==1){ RefrescarGrillas(); }
}

//		ELIMINAR
void Vprincipal::ClickEliminarLibroMenu()  {
	if(!Singleton::ObtenerInstancia()->VerLibro(indice).EstaDisponible()){
		wxMessageBox("¡No se pueden eliminar libros en préstamo!","Error",wxOK|wxICON_ERROR,this);
		return;
	}		
	wxMessageDialog dial(NULL, wxT("¿Eliminar el libro " + Singleton::ObtenerInstancia()->VerLibro(indice).VerTitulo() 
								   + "? "),wxT("Question"), wxYES_NO | wxNO_DEFAULT | wxICON_QUESTION);
	if (dial.ShowModal() ==  wxID_YES){	
		Singleton::ObtenerInstancia()->OcultarLibro(indice);
		wxMessageBox("¡El libro ha sido eliminado!");
		RefrescarGrillas();
	}	
	return;
}

//MENU LECTOR: AGREGAR
void Vprincipal::ClickAgregarLectorMenu( wxCommandEvent& event )  {
	VagregarLector nueva_ventana(this);
	if (nueva_ventana.ShowModal()==1){ 
		RefrescarGrillas(); 
	}
}
//MENU LECTOR: MODIFICAR
void Vprincipal::ClickModificarLectorMenu() {	
	vModificarLector::numLector=indice;
	vModificarLector nueva_ventana(this);	
	if (nueva_ventana.ShowModal()==1){ RefrescarGrillas(); }
}

void Vprincipal::ClickEliminarLectorMenu()  {
	if(Singleton::ObtenerInstancia()->TienePrestamosActivos(indice))	{
		wxMessageBox("¡No se pueden eliminar lectores con préstamos activos!","Error",wxOK|wxICON_ERROR,this);
		return;
	}	
	wxMessageDialog dial(NULL, wxT("¿Eliminar el lector " + Singleton::ObtenerInstancia()->VerLector(indice).VerApellidoYNombre() 
								   + "? "),wxT("Question"), wxYES_NO | wxNO_DEFAULT | wxICON_QUESTION);
	if (dial.ShowModal() ==  wxID_YES)	{	
		Singleton::ObtenerInstancia()->OcultarLector(indice);		
		wxMessageBox("¡El lector ha sido eliminado!");
		RefrescarGrillas();
	}
	return;
}

//PRESTAMO: AGREGAR:
void Vprincipal::ClickAgregarPrestamoMenu(){	
	vAgregarPrestamo ventana_prestamo(this);			
	if (ventana_prestamo.ShowModal()==1){ RefrescarGrillas(); }	
}

//MENU PRESTAMO: DEVOLVER
void Vprincipal::ClickAgregarDevolucionMenu()  {	
	int codLibro = Singleton::ObtenerInstancia()->VerPrestamo(indice).VerCodigoLibroPrestamo();
	int numLector = Singleton::ObtenerInstancia()->VerPrestamo(indice).VerNumeroLectorPrestamo();
	wxMessageDialog dial(NULL, wxT("¿Confirmar devolución de: " + Singleton::ObtenerInstancia()-> VerLibro(codLibro).VerTitulo()+ "?"), 
						 wxT("Question"), wxYES_NO | wxNO_DEFAULT | wxICON_QUESTION);
	if (dial.ShowModal() ==  wxID_YES){				
		int diasAtrasados = Singleton::ObtenerInstancia()->EliminarPrestamo(Singleton::ObtenerInstancia()->VerLibro(codLibro).VerCodigoLibro());					
		if (diasAtrasados == 0){ 
			wxMessageBox("Devolución a tiempo! " );
		}else{
			wxString diasAtrasados_s;
			diasAtrasados_s << diasAtrasados;			
			wxMessageDialog dial2(NULL, wxT("Devolución Agregada! " + diasAtrasados_s + " días tarde! ¿Desea aplicar una sanción?"), 
								  wxT("Question"), wxYES_NO | wxNO_DEFAULT | wxICON_QUESTION);
			if (dial2.ShowModal() ==  wxID_YES){ ClickAgregarSancionMenu(numLector); }				
		}
	}	
	RefrescarGrillas();
	return;
}
//MENU SANCION: AGREGAR
void Vprincipal::ClickAgregarSancionMenu(int numLector)  {
	wxString cantDias_s = wxGetTextFromUser("Cantidad de días a sancionar:","Nueva Sanción","",this);
	if (cantDias_s==""){
		wxMessageBox("Cantidad incorrecta incorrecto!","Error",wxOK|wxICON_ERROR,this);
		return;
	}
	int cantDias = atoi(cantDias_s);	
	wxString motivo = wxGetTextFromUser("Motivo de Sanción:","Nueva Sanción","",this);
	if (motivo==""){
		wxMessageBox("Agregue un motivo de sanción!","Error",wxOK|wxICON_ERROR,this);
		return;
	}
	wxMessageDialog dial(NULL, wxT("El usuario: " + Singleton::ObtenerInstancia()->VerLector(numLector).VerApellidoYNombre() + " será sancionado " + cantDias_s
								   + " días por "+ motivo +". ¿Confirmar sanción?"), wxT("Question"), wxYES_NO | wxNO_DEFAULT | wxICON_QUESTION);
	if (dial.ShowModal() ==  wxID_YES){		
		Singleton::ObtenerInstancia()->AgregarSancion(numLector, motivo.c_str(), cantDias);	
		wxMessageBox("Sanción Agregada!");		
	}
	RefrescarGrillas();
	return;
}

//           EVENTOS DE PESTAÑAS
void Vprincipal::ClickPestaniaLibros( wxMouseEvent& event )  	{ Vprincipal::DibujarPestaniaLibros(); }
void Vprincipal::ClickPestaniaLectores( wxMouseEvent& event )  	{ Vprincipal::DibujarPestaniaLectores(); }
void Vprincipal::ClickPestaniaPrestamos( wxMouseEvent& event )  { Vprincipal::DibujarPestaniaPrestamos(); }
void Vprincipal::ClickPestaniaSanciones( wxMouseEvent& event )  { Vprincipal::DibujarPestaniaSanciones(); }

// BUSQUEDA
void Vprincipal::ClickBusquedaPorTitulo( wxCommandEvent& event )  {
	int fila_actual = gLibros->GetGridCursorRow();
	int res 		= Singleton::ObtenerInstancia()->BuscarTitulo(tBusquedaTitulo->GetValue().c_str(),fila_actual+1);
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
	int res 		= Singleton::ObtenerInstancia()->BuscarApellidoYNombre(tBusquedaNombre->GetValue().c_str(),fila_actual+1);
	if (res==NO_SE_ENCUENTRA) 
		res=Singleton::ObtenerInstancia()->BuscarApellidoYNombre(tBusquedaNombre->GetValue().c_str(),0);
	if (res==-1)
		wxMessageBox("No se encontraron mas coincidencias");
	else {
		gLectores->SetGridCursor(res,0); // seleccionar celda
		gLectores->SelectRow(res); // marcar toda la fila
	}
}

void Vprincipal::ClickBusquedaPrestamo( wxCommandEvent& event )  {
	int fila_actual = gPrestamos->GetGridCursorRow();
	int res 		= Singleton::ObtenerInstancia()->BuscarApellidoNombreOTitulo(tBusquedaPrestamo->GetValue().c_str(),fila_actual+1);
	if (res==NO_SE_ENCUENTRA) 
		res=Singleton::ObtenerInstancia()->BuscarApellidoNombreOTitulo(tBusquedaPrestamo->GetValue().c_str(),0);
	if (res==-1) wxMessageBox("No se encontraron mas coincidencias");
	else {
		gPrestamos->SetGridCursor(res,0); // seleccionar celda
		gPrestamos->SelectRow(res); // marcar toda la fila
	}	
}

//			CLICK DERECHO LIBRO
//MENU
void Vprincipal::ClickDerechoGrillaLibro( wxGridEvent& event )  {
	gLibros->SetGridCursor(event.GetRow(),0); // seleccionar celda
	gLibros->SelectRow(event.GetRow()); // marcar toda la fila	
	ResetearIndices();	
	indice = event.GetRow();		
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
	case 0:{	
		vAgregarPrestamo::codLibro = indice;
		ClickAgregarPrestamoMenu();
		break;
		}
	case 1:{
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
	indice = event.GetRow();	
	wxMenu menu(wxT(""));	
	menu.Append(0, wxT("Prestar"));
	menu.Append(1, wxT("Modificar"));
	menu.Append(2, wxT("Eliminar"));
	menu.Append(3, wxT("Sancionar"));
	menu.Connect(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(Vprincipal::PopupClickDerechoLector), NULL, this);
	PopupMenu(&menu);
}
//FUNCIONES
void Vprincipal::PopupClickDerechoLector(wxCommandEvent &event){
	switch(event.GetId()) {		
	case 0:{		
		vAgregarPrestamo::numLector = indice;
		ClickAgregarPrestamoMenu();
		break;
		}
	case 1:{
		ClickModificarLectorMenu();
		break;
		}	
	case 2:{
		ClickEliminarLectorMenu();
		break;
		}
	case 3:{
		ClickAgregarSancionMenu(indice);
		break;
		}
					
	}
}

//			CLICK DERECHO PRESTAMOS
//MENU
void Vprincipal::ClickDerechoGrillaPrestamo(wxGridEvent& event){
	gPrestamos->SetGridCursor(event.GetRow(),0); // seleccionar celda
	gPrestamos->SelectRow(event.GetRow()); // marcar toda la fila
	
	ResetearIndices();		
	
	indice = event.GetRow();
	
	wxMenu menu(wxT(""));	
	menu.Append(0, wxT("Devolver"));
	menu.Connect(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(Vprincipal::PopupClickDerechoPrestamo), NULL, this);
	PopupMenu(&menu);
}
//FUNCIONES
void Vprincipal::PopupClickDerechoPrestamo(wxCommandEvent &event){
	switch(event.GetId()) {		
	case 0:{		
		ClickAgregarDevolucionMenu();
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
	indice = -1;
}

