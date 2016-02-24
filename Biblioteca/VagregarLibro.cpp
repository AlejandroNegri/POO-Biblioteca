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

void VagregarLibro::bCancelarAgregarLibro( wxCommandEvent& event )  {
	EndModal(0);
}

