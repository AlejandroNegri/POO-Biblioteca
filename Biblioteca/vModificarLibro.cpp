#include "vModificarLibro.h"
#include "Singleton.h"
#include <wx/msgdlg.h>

int vModificarLibro::codLibro = -1;

vModificarLibro::vModificarLibro(wxWindow *parent) : VentanaAgregarLibro(parent) {
	SetTitle("Modificar Libro");
	tTitulo->	SetLabel( Singleton::ObtenerInstancia()->VerLibro(vModificarLibro::codLibro).VerTitulo());
	tAutor->	SetLabel( Singleton::ObtenerInstancia()->VerLibro(vModificarLibro::codLibro).VerAutores());
	tEditorial->SetLabel( Singleton::ObtenerInstancia()->VerLibro(vModificarLibro::codLibro).VerEditorial());
	tISBN->		SetLabel( Singleton::ObtenerInstancia()->VerLibro(vModificarLibro::codLibro).VerISBN());
	tEdicion->	SetLabel( Singleton::ObtenerInstancia()->VerLibro(vModificarLibro::codLibro).VerEdicion());
	tTipo->		SetLabel( Singleton::ObtenerInstancia()->VerLibro(vModificarLibro::codLibro).VerTipo());
}

vModificarLibro::~vModificarLibro() {}

void vModificarLibro::ClickAgregarLibroNuevo( wxCommandEvent& event )  {
	string errores = ValidarDatos();
	if(errores.size()){
		wxMessageBox(errores); // mostrar errores		
	}else{
		Singleton::ObtenerInstancia()->ModificarLibro(	
													  tTitulo->GetValue().c_str(),
													  tAutor->GetValue().c_str(),
													  tEditorial->GetValue().c_str(),
													  tISBN->GetValue().c_str(),
													  tEdicion->GetValue().c_str(),
													  tTipo->GetValue().c_str(),
													  codLibro,												
													  Singleton::ObtenerInstancia()->VerLibro(codLibro).VerEstado());
		wxMessageBox("¡Libro Modificado!");	
		EndModal(1);
	}
}

void vModificarLibro::bCancelarAgregarLibro( wxCommandEvent& event )  {
	EndModal(0);
}

string vModificarLibro::ValidarDatos() {
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
