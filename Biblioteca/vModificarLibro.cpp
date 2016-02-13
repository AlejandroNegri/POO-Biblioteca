#include "vModificarLibro.h"
#include "Singleton.h"
#include <wx/msgdlg.h>

int vModificarLibro::codLibro = -1;

vModificarLibro::vModificarLibro(wxWindow *parent) : VentanaAgregarLibro(parent) {
	SetTitle("Modificar Libro");
	tTitulo->SetLabel( Singleton::ObtenerInstancia()->VerLibro(vModificarLibro::codLibro).VerTitulo());
	tAutor->SetLabel( Singleton::ObtenerInstancia()->VerLibro(vModificarLibro::codLibro).VerAutores());
	tEditorial->SetLabel( Singleton::ObtenerInstancia()->VerLibro(vModificarLibro::codLibro).VerEditorial());
	tISBN->SetLabel( Singleton::ObtenerInstancia()->VerLibro(vModificarLibro::codLibro).VerISBN());
	tEdicion->SetLabel( Singleton::ObtenerInstancia()->VerLibro(vModificarLibro::codLibro).VerEdicion());
	tTipo->SetLabel( Singleton::ObtenerInstancia()->VerLibro(vModificarLibro::codLibro).VerTipo());
}

vModificarLibro::~vModificarLibro() {}

void vModificarLibro::ClickAgregarLibroNuevo( wxCommandEvent& event )  {
	Singleton::ObtenerInstancia()->ModificarLibro(	
												tTitulo->GetValue().c_str(),
												tAutor->GetValue().c_str(),
												tEditorial->GetValue().c_str(),
												tISBN->GetValue().c_str(),
												tEdicion->GetValue().c_str(),
												tTipo->GetValue().c_str(),
												codLibro,												
												Singleton::ObtenerInstancia()->VerLibro(codLibro).VerEstado()
												);	
	Singleton::ObtenerInstancia()->Guardar(); // actualizar el archivo	
	wxMessageBox("¡Libro Modificado!");
	EndModal(1);
}

void vModificarLibro::bCancelarAgregarLibro( wxCommandEvent& event )  {
	EndModal(0);
}

