#include "VagregarLibro.h"
#include "Vprincipal.h"
#include "Singleton.h"
#include <wx/msgdlg.h>
#include <string>


VagregarLibro::VagregarLibro(wxWindow *parent) : VentanaAgregarLibro(parent) {
	SetTitle("Agregar Libro");
}

VagregarLibro::~VagregarLibro() {}
void VagregarLibro::ClickAgregarLibroNuevo( wxCommandEvent& event ) {
	string errores = ValidarDatos();
	if(errores.size()){
		wxMessageBox(errores); // mostrar errores		
	}else{
		Singleton::ObtenerInstancia()->AgregarLibro(	
													tTitulo->GetValue().c_str(),
													tAutor->GetValue().c_str(),
													tEditorial->GetValue().c_str(),
													tISBN->GetValue().c_str(),
													tEdicion->GetValue().c_str(),
													tTipo->GetValue().c_str(),
													Singleton::ObtenerInstancia()->cantLibros(),
													"Disponible"
													);
		wxMessageBox("¡Libro Agregado!");	
		EndModal(1);
	}
}

void VagregarLibro::bCancelarAgregarLibro( wxCommandEvent& event )  {
	EndModal(0);
}

string VagregarLibro::ValidarDatos() {
	string errores;
	if (tTitulo->GetValue().Length()==0) errores+="El título no puede estar vacio\n";
	if (tTitulo->GetValue().Length()>256) errores+="El título es demasiado largo\n";
	if (tAutor->GetValue().Length()==0) errores+="El autor no puede estar vacio\n";
	if (tAutor->GetValue().Length()>256) errores+="El autor es demasiado largo\n";
	if (tEditorial->GetValue().Length()==0) errores+="La editorial no puede estar vacia\n";
	if (tEditorial->GetValue().Length()>256) errores+="La editorial es demasiado larga\n";
	if (tISBN->GetValue().Length()==0) errores+="El ISBN no puede estar vacio\n";
	if (tISBN->GetValue().Length()>256) errores+="El ISBN es demasiado largo\n";
	if (tEdicion->GetValue().Length()==0) errores+="La edición no puede estar vacia\n";
	if (tEdicion->GetValue().Length()>256) errores+="La edición es demasiado larga\n";
	if (tTipo->GetValue().Length()==0) errores+="El tipo no puede estar vacio\n";
	if (tTipo->GetValue().Length()>256) errores+="El tipo es demasiado largo\n";
	return errores;
}
