#include "VagregarLector.h"
#include "Singleton.h"
#include <wx/msgdlg.h>

//constructor
VagregarLector::VagregarLector(wxWindow *parent) : VentanaAgregarLector(parent) {
	SetTitle("Agregar Lector");
}
//destructor
VagregarLector::~VagregarLector() {}

void VagregarLector::ClickAgregarLectorNuevo( wxCommandEvent& event )  {
	Singleton::ObtenerInstancia()->AgregarLector(	
												tNombre->GetValue().c_str(),
												tApellido->GetValue().c_str(),
												tDNI->GetValue().c_str(),
												tDomicilio->GetValue().c_str(),
												tTelefono->GetValue().c_str(),
												Singleton::ObtenerInstancia()->cantLectores());	
	wxMessageBox("Lector Agregado!");	
	EndModal(1); // cerrar indicando que se agrego
}

void VagregarLector::bCancelarAgregarLector( wxCommandEvent& event )  {
	EndModal(0);
}
