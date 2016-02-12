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


//constructor
Vprincipal::Vprincipal(wxWindow *parent) : VentanaPrincipal(parent) {	
	RefrescarGrillas();
}

//destructor
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
	vModificarLibro nueva_ventana(this);	
	if (nueva_ventana.ShowModal()==1) {
		RefrescarGrillas();
	}
}

//MENU LECTOR: AGREGAR
void Vprincipal::ClickAgregarLectorMenu( wxCommandEvent& event )  {
	VagregarLector nueva_ventana(this); // crear la ventana
	if (nueva_ventana.ShowModal()==1) { // mostrar y esperar
		RefrescarGrillas(); 
	}
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
	if (dial.ShowModal() ==  wxID_YES){		
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
//MENU SANCION: AGREGAR
void Vprincipal::ClickAgregarSancionMenu( wxCommandEvent& event )  {
	
	wxString numLector = wxGetTextFromUser("Ingrese el número de lector","Nueva Sanción","",this);	
	if (atoi(numLector)>= (Singleton::ObtenerInstancia()->cantLectores())){
		wxMessageBox("Número de lector incorrecto!","Error",wxOK|wxICON_ERROR,this);
		return;
	}
	Lector unLector = Singleton::ObtenerInstancia()->VerLector(atoi(numLector.c_str()));
	if (numLector==""){
		wxMessageBox("Número de lector incorrecto!","Error",wxOK|wxICON_ERROR,this);
		return;
	}else if(unLector.EstaOculto()){
		wxMessageBox("Ese lector fué eliminado!","Error",wxOK|wxICON_ERROR,this);
		return;
	}

//	}else if(Singleton::ObtenerInstancia()->EstaSancionado(atoi(numLector))){
//		wxMessageBox("Ese lector esta sancionado!","Error",wxOK|wxICON_ERROR,this);
//		return;
//	}	
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
	wxMessageDialog dial(NULL, wxT("El usuario: " + unLector.VerApellido()  + ", " + unLector.VerNombre() + " será sancionado " + cantDias_s
								   + " días por "+ motivo +". ¿Confirmar sanción?"), wxT("Question"), wxYES_NO | wxNO_DEFAULT | wxICON_QUESTION);
	if (dial.ShowModal() ==  wxID_YES){		
		Singleton::ObtenerInstancia()->AgregarSancion(unLector.VerNumeroLector(), motivo.c_str(), cantDias);
		Singleton::ObtenerInstancia()->Guardar(); // actualizar el archivo	
		RefrescarGrillas();
		wxMessageBox("Sanción Agregada!");
	}else{
		wxMessageBox("Sanción Cancelada!");
		return;
	}	
	return;
}

//           EVENTOS DE PESTAÑAS
void Vprincipal::ClickPestaniaLibros( wxMouseEvent& event )  { Vprincipal::DibujarPestaniaLibros(); }
void Vprincipal::ClickPestaniaLectores( wxMouseEvent& event )  { Vprincipal::DibujarPestaniaLectores(); }
void Vprincipal::ClickPestaniaPrestamos( wxMouseEvent& event )  { Vprincipal::DibujarPestaniaPrestamos(); }
void Vprincipal::ClickPestaniaSanciones( wxMouseEvent& event )  { Vprincipal::DibujarPestaniaSanciones(); }

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

//		ELIMINAR
void Vprincipal::ClickEliminarLibroMenu( wxCommandEvent& event )  {
	wxString codLibro = wxGetTextFromUser("Ingrese el código del libro","Eliminar Libro","",this);
	if (atoi(codLibro)>= (Singleton::ObtenerInstancia()->cantLibros())){
		wxMessageBox("Código de libro incorrecto!","Error",wxOK|wxICON_ERROR,this);
		return;
	}
	if (codLibro==""){
		wxMessageBox("Código de libro incorrecto!","Error",wxOK|wxICON_ERROR,this);
		return;
	}else if(!Singleton::ObtenerInstancia()->VerLibro(atoi(codLibro.c_str())).EstaDisponible()){
		wxMessageBox("Ese libro esta prestado o eliminado!","Error",wxOK|wxICON_ERROR,this);
		return;
	}		
	wxMessageDialog dial(NULL, wxT("¿Eliminar el libro " + Singleton::ObtenerInstancia()->VerLibro(atoi(codLibro.c_str())).VerTitulo() 
								   + ") ? "),wxT("Question"), wxYES_NO | wxNO_DEFAULT | wxICON_QUESTION);
	if (dial.ShowModal() ==  wxID_YES){	
		int num = atoi(codLibro);
		Singleton::ObtenerInstancia()->OcultarLibro(num);		
		Singleton::ObtenerInstancia()->Guardar(); // actualizar el archivo	
		wxMessageBox("¡El libro ha sido eliminado!");
		RefrescarGrillas();
	}else{
		wxMessageBox("¡El libro no ha sido eliminado!");
		return;
	}	
	return;
}

void Vprincipal::ClickEliminarLectorMenu( wxCommandEvent& event )  {
	wxString numLector = wxGetTextFromUser("Ingrese el número de lector","Eliminar Lector","",this);
	if (atoi(numLector)>= (Singleton::ObtenerInstancia()->cantLectores())){
		wxMessageBox("Número de lector incorrecto!","Error",wxOK|wxICON_ERROR,this);
		return;
	}
	if (numLector==""){
		wxMessageBox("Número de lector incorrecto!","Error",wxOK|wxICON_ERROR,this);
		return;
	}else if(Singleton::ObtenerInstancia()->VerLector(atoi(numLector.c_str())).EstaOculto()){
		wxMessageBox("Ese lector ya fué eliminado!","Error",wxOK|wxICON_ERROR,this);
		return;
	}		
	wxMessageDialog dial(NULL, wxT("¿Eliminar el lector " + Singleton::ObtenerInstancia()->VerLector(atoi(numLector.c_str())).VerApellido() 
								   + ", " + Singleton::ObtenerInstancia()->VerLector(atoi(numLector.c_str())).VerNombre()			   
								   +"? "),wxT("Question"), wxYES_NO | wxNO_DEFAULT | wxICON_QUESTION);
	if (dial.ShowModal() ==  wxID_YES){	
		int num = atoi(numLector);
		Singleton::ObtenerInstancia()->OcultarLector(num);		
		Singleton::ObtenerInstancia()->Guardar(); // actualizar el archivo	
		wxMessageBox("¡El lector ha sido eliminado!");
		RefrescarGrillas();
	}else{
		wxMessageBox("¡El lector no ha sido eliminado!");
		return;
	}	
	return;
}



//			CLICK DERECHO 
//MENU
void Vprincipal::ClickDerechoGrillaLibro( wxGridEvent& event )  {
	gLibros->SetGridCursor(event.GetRow(),0); // seleccionar celda
	gLibros->SelectRow(event.GetRow()); // marcar toda la fila
	
	ResetearIndices();
	vAgregarPrestamo::codLibro = event.GetRow();
	vModificarLibro::codLibro=event.GetRow();
	
	
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
		ClickAgregarPrestamoMenu();
		break;
	}
	case 1: 
	{
		ClickModificarLibroMenu();
		break;
	}	
	case 2: wxMessageBox("Eliminar");
	break;
	}
}


//resetea los indices buscadores
void Vprincipal::ResetearIndices(){
	vAgregarPrestamo::codLibro = -1;
	vAgregarPrestamo::numLector = -1;
	vModificarLibro::codLibro = -1;
}


