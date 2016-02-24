#include "vModificarLector.h"
#include "Singleton.h"
#include <wx/msgdlg.h>

int vModificarLector::numLector = -1;

vModificarLector::vModificarLector(wxWindow *parent) : VentanaAgregarLector(parent) {
	SetTitle("Modificar Lector");
	tNombre->	SetLabel( Singleton::ObtenerInstancia()->VerLector(vModificarLector::numLector).VerNombre());
	tApellido->	SetLabel( Singleton::ObtenerInstancia()->VerLector(vModificarLector::numLector).VerApellido());
	tDNI->		SetLabel( Singleton::ObtenerInstancia()->VerLector(vModificarLector::numLector).VerDNI());
	tDomicilio->SetLabel( Singleton::ObtenerInstancia()->VerLector(vModificarLector::numLector).VerDomicilio());
	tTelefono->	SetLabel( Singleton::ObtenerInstancia()->VerLector(vModificarLector::numLector).VerTel());
}

vModificarLector::~vModificarLector() {}

void vModificarLector::ClickAgregarLectorNuevo( wxCommandEvent& event )  {
	Singleton::ObtenerInstancia()->ModificarLector(	
												  tNombre->GetValue().c_str(),
												  tApellido->GetValue().c_str(),
												  tDNI->GetValue().c_str(),
												  tDomicilio->GetValue().c_str(),
												  tTelefono->GetValue().c_str(),
												  numLector												
												);		
	wxMessageBox("¡Lector Modificado!");
	EndModal(1); // cerrar indicando que se agrego
}

void vModificarLector::bCancelarAgregarLector( wxCommandEvent& event )  {
	EndModal(0);
}


