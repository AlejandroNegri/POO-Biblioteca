#include "vBuscarLector.h"
#include "Singleton.h"
#include "vAgregarPrestamo.h"
#include <wx/string.h>

//constructor
vBuscarLector::vBuscarLector(wxWindow *parent) : VentanaBuscarLector(parent) {
	gLectoresPrestamo->SetRowMinimalAcceptableHeight(0);
	gLectoresPrestamo->DeleteRows(0,gLectoresPrestamo->GetNumberRows(), true);
	int cant_lectores = Singleton::ObtenerInstancia()->cantLectores();
	gLectoresPrestamo->AppendRows(cant_lectores);	
	for (int i=0;i<cant_lectores;i++) {
		CargarFilaLectores(i);// cargar todos los datos
		if (Singleton::ObtenerInstancia()->VerLector(i).EstaOculto()){
			gLectoresPrestamo->SetRowSize(i,0);			
		}		
	}
	gLectoresPrestamo->SetSelectionMode(wxGrid::wxGridSelectRows);
	Show();
}

//destructor
vBuscarLector::~vBuscarLector() {}


void vBuscarLector::CargarFilaLectores(int i) {
	Lector l= Singleton::ObtenerInstancia()->VerLector(i);
	gLectoresPrestamo->SetCellValue(i,0,l.VerApellido());
	gLectoresPrestamo->SetCellValue(i,1,l.VerNombre());
	gLectoresPrestamo->SetCellValue(i,2,l.VerDNI());
	gLectoresPrestamo->SetCellValue(i,3,l.VerDomicilio());
	gLectoresPrestamo->SetCellValue(i,4,l.VerTel());	
	wxString numLector;
	numLector << l.VerNumeroLector();	
	gLectoresPrestamo->SetCellValue(i,5,numLector);
}

//busqueda
void vBuscarLector::ClickBusquedaPorNombreDesdeLibro( wxCommandEvent& event )  {
	event.Skip();
}

//ACEPTAR Y CANCELAR
void vBuscarLector::DClickAceptarLectorPrestamo( wxGridEvent& event )  {
	vAgregarPrestamo::numLector = event.GetRow();
	EndModal(1);
}

void vBuscarLector::ClickCancelar( wxCommandEvent& event )  {
	EndModal(0);
}