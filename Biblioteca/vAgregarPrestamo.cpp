#include "vAgregarPrestamo.h"
#include "vBuscarLector.h"
#include <wx/string.h>
#include <string>
#include "Singleton.h"
#include <wx/msgdlg.h>
#include "vBuscarLibro.h"

int vAgregarPrestamo::codLibro = -1 ;
int vAgregarPrestamo::numLector = -1 ;

vAgregarPrestamo::vAgregarPrestamo(wxWindow *parent) : VentanaAgregarPrestamo(parent) {	
	ActualizarLabelLibro();
	ActualizarLabelLector();
}

vAgregarPrestamo::~vAgregarPrestamo() {}

void vAgregarPrestamo::ClickBuscarLibro( wxCommandEvent& event )  {
	vBuscarLibro ventana_busqueda_lector(this); // crear la ventana	
	if (ventana_busqueda_lector.ShowModal()==1) { // mostrar y esperar
		ActualizarLabelLector();	
		ActualizarLabelLibro();
	}
	
}

void vAgregarPrestamo::ClickBuscarLector( wxCommandEvent& event )  {	
	vBuscarLector ventana_busqueda_lector(this); // crear la ventana	
	if (ventana_busqueda_lector.ShowModal()==1) { // mostrar y esperar
		ActualizarLabelLector();	
		ActualizarLabelLibro();
	}
}


//aceptar y cancelar
void vAgregarPrestamo::ClickAceptarPrestamo( wxCommandEvent& event )  {	
	if(ValidarLector() && ValidarLibro()){
		Singleton::ObtenerInstancia()->AgregarPrestamo(Singleton::ObtenerInstancia()->VerLector(vAgregarPrestamo::numLector).VerNumeroLector(), 
													   Singleton::ObtenerInstancia()->VerLibro(vAgregarPrestamo::codLibro).VerCodigoLibro() );
		Singleton::ObtenerInstancia()->Guardar(); // actualizar el archivo	
		wxMessageBox("¡Préstamo Agregado!");
		EndModal(1);		
	}	
}
void vAgregarPrestamo::ClickCancelar( wxCommandEvent& event )  { 
	EndModal(0); 
}


//ACTUALIZAR LABELS
void vAgregarPrestamo::ActualizarLabelLibro(){
	if(vAgregarPrestamo::codLibro != -1){
		lLibro->SetLabel(Singleton::ObtenerInstancia()->VerLibro(codLibro).VerTitulo());
	}else{ 
		lLibro->SetLabel("-"); 
	}
}

void vAgregarPrestamo::ActualizarLabelLector(){
	if(vAgregarPrestamo::numLector != -1){
		lLector->SetLabel(Singleton::ObtenerInstancia()->VerLector(numLector).VerApellidoYNombre());
	}else{
		lLector->SetLabel("-");
	}
}

//validarDatos
bool vAgregarPrestamo::ValidarLector(){
	if (vAgregarPrestamo::numLector==-1){
		wxMessageBox("¡Seleccione un lector!","Error",wxOK|wxICON_ERROR,this);
		return false;
	}else if(Singleton::ObtenerInstancia()->EstaSancionado(vAgregarPrestamo::numLector)){
		wxMessageBox("¡Ese lector esta sancionado!","Error",wxOK|wxICON_ERROR,this);
		return false;
	}
	return true;
}

bool vAgregarPrestamo::ValidarLibro(){
	if (vAgregarPrestamo::codLibro==-1){
		wxMessageBox("¡Seleccione un libro!","Error",wxOK|wxICON_ERROR,this);
		return false;
	}else if(!Singleton::ObtenerInstancia()->VerLibro(vAgregarPrestamo::codLibro).EstaDisponible()){
		wxMessageBox("¡Ese libro esta prestado!","Error",wxOK|wxICON_ERROR,this);
		return false;
	}
	return true;	
}

