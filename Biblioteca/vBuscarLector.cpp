#include "vBuscarLector.h"
#include "Singleton.h"
#include "vAgregarPrestamo.h"
#include <wx/string.h>
#include <wx/msgdlg.h>

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
}

//destructor
vBuscarLector::~vBuscarLector(){}


void vBuscarLector::CargarFilaLectores(int i) {
	Lector l= Singleton::ObtenerInstancia()->VerLector(i);
	gLectoresPrestamo->SetCellValue(i,0,l.VerApellido());
	gLectoresPrestamo->SetCellValue(i,1,l.VerNombre());
	gLectoresPrestamo->SetCellValue(i,2,l.VerDNI());
	gLectoresPrestamo->SetCellValue(i,3,l.VerDomicilio());
	gLectoresPrestamo->SetCellValue(i,4,l.VerTel());	
	gLectoresPrestamo->SetCellValue(i,5,IntToString(l.VerNumeroLector()));
}

//busqueda
void vBuscarLector::ClickBusquedaPorNombre( wxCommandEvent& event )  {
	int fila_actual	= gLectoresPrestamo->GetGridCursorRow();
	int res 		= Singleton::ObtenerInstancia()->BuscarApellidoYNombre(tBusquedaNombre->GetValue().c_str(),fila_actual+1);
	if (res==NO_SE_ENCUENTRA) 
		res=Singleton::ObtenerInstancia()->BuscarApellidoYNombre(tBusquedaNombre->GetValue().c_str(),0);
	if (res==-1)
		wxMessageBox("No se encontraron mas coincidencias");
	else {
		gLectoresPrestamo->SetGridCursor(res,0); // seleccionar celda
		gLectoresPrestamo->SelectRow(res); // marcar toda la fila
	}
	
}

//ACEPTAR Y CANCELAR
void vBuscarLector::DClickAceptarLectorPrestamo( wxGridEvent& event )  {
	vAgregarPrestamo::numLector = event.GetRow();
	EndModal(1);
}


