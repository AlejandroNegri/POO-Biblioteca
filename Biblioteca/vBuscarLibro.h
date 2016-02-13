#ifndef VBUSCARLIBRO_H
#define VBUSCARLIBRO_H
#include "Ventanas.h"

class vBuscarLibro : public VentanaBuscarLibro {

protected:
	void DClickAceptarLibroPrestamo( wxGridEvent& event ) ;
	void ClickBusquedaPorTitulo( wxCommandEvent& event ) ;
	
public:
	vBuscarLibro(wxWindow *parent=NULL);
	~vBuscarLibro();
	void CargarFilaLibros(int i);
};

#endif

