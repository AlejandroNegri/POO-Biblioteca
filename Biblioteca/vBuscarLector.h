#ifndef VBUSCARLECTOR_H
#define VBUSCARLECTOR_H
#include "Ventanas.h"
#include <string>

class vBuscarLector : public VentanaBuscarLector {
protected:
	//eventos
	void ClickBusquedaPorNombre( wxCommandEvent& event ) ;
	void DClickAceptarLectorPrestamo( wxGridEvent& event );
public:
	vBuscarLector(wxWindow *parent=NULL);
	~vBuscarLector();	
	void CargarFilaLectores(int i);
};

#endif

