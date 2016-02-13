#include "vBuscarLibro.h"
#include "Singleton.h"
#include <wx/msgdlg.h>
#include "vAgregarPrestamo.h"

vBuscarLibro::vBuscarLibro(wxWindow *parent) : VentanaBuscarLibro(parent) {
	gLibrosPrestamo->SetRowMinimalAcceptableHeight(0);
	gLibrosPrestamo->DeleteRows(0,gLibrosPrestamo->GetNumberRows(), true);	
	int cant_libros = Singleton::ObtenerInstancia()->cantLibros();	
	gLibrosPrestamo->AppendRows(cant_libros); // agregar tantas filas como libros activos
	for (int i=0;i<cant_libros;i++) {		
		CargarFilaLibros(i);// cargar todos los datos
		if (Singleton::ObtenerInstancia()->VerLibro(i).EstaOculto()){
			gLibrosPrestamo->SetRowSize(i,0);			
		}		
	}
	gLibrosPrestamo->SetSelectionMode(wxGrid::wxGridSelectRows);
}

vBuscarLibro::~vBuscarLibro() {}

void vBuscarLibro::CargarFilaLibros(int i) {
	Libro l= Singleton::ObtenerInstancia()->VerLibro(i);
	gLibrosPrestamo->SetCellValue(i,0,l.VerTitulo());
	gLibrosPrestamo->SetCellValue(i,1,l.VerAutores());
	gLibrosPrestamo->SetCellValue(i,2,l.VerEditorial());
	gLibrosPrestamo->SetCellValue(i,3,l.VerISBN());
	gLibrosPrestamo->SetCellValue(i,4,l.VerEdicion());	
	wxString cod;
	cod << l.VerCodigoLibro();	
	gLibrosPrestamo->SetCellValue(i,5,cod);
	gLibrosPrestamo->SetCellValue(i,6,l.VerTipo());
	gLibrosPrestamo->SetCellValue(i,7,l.VerEstado());
}


void vBuscarLibro::ClickBusquedaPorTitulo( wxCommandEvent& event )  {
	int fila_actual = gLibrosPrestamo->GetGridCursorRow();
	int res = Singleton::ObtenerInstancia()->BuscarTitulo(tBusquedaTitulo->GetValue().c_str(),fila_actual+1);
	if (res==NO_SE_ENCUENTRA) 
		res=Singleton::ObtenerInstancia()->BuscarTitulo(tBusquedaTitulo->GetValue().c_str(),0);
	if (res==-1)
		wxMessageBox("No se encontraron mas coincidencias");
	else {
		gLibrosPrestamo->SetGridCursor(res,0); // seleccionar celda
		gLibrosPrestamo->SelectRow(res); // marcar toda la fila
	}	
}

void vBuscarLibro::DClickAceptarLibroPrestamo( wxGridEvent& event )  {
	vAgregarPrestamo::codLibro = event.GetRow();
	EndModal(1);
}

