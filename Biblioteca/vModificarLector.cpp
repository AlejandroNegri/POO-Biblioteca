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
	string errores = ValidarDatos();
	if(errores.size()){
		wxMessageBox(errores); // mostrar errores		
	}else{
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
}

void vModificarLector::bCancelarAgregarLector( wxCommandEvent& event )  {
	EndModal(0);
}

string vModificarLector::ValidarDatos() {
	string errores;
	if (tNombre->GetValue().Length()==0) errores+="El nombre no puede estar vacio\n";
	if (tNombre->GetValue().Length()>256) errores+="El nombre es demasiado largo\n";
	if (tApellido->GetValue().Length()==0) errores+="El apellido no puede estar vacio\n";
	if (tApellido->GetValue().Length()>256) errores+="El apellido es demasiado largo\n";
	if (tDNI->GetValue().Length()==0) errores+="El DNI no puede estar vacio\n";
	if (tDNI->GetValue().Length()>256) errores+="El DNI es demasiado largo\n";
	if (tDomicilio->GetValue().Length()==0) errores+="El domicilio no puede estar vacio\n";
	if (tDomicilio->GetValue().Length()>256) errores+="El domicilio es demasiado largo\n";
	if (tTelefono->GetValue().Length()==0) errores+="El teléfono no puede estar vacio\n";
	if (tTelefono->GetValue().Length()>256) errores+="El teléfono es demasiado largo\n";
	return errores;
}

