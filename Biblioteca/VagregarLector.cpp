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
	string errores = ValidarDatos();
	if(errores.size()){
		wxMessageBox(errores); // mostrar errores		
	}else{
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
}

void VagregarLector::bCancelarAgregarLector( wxCommandEvent& event )  {
	EndModal(0);
}

string VagregarLector::ValidarDatos() {
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
