#ifndef VBUSCARLECTOR_H
#define VBUSCARLECTOR_H
#include "Ventanas.h"
#include <string>

class vBuscarLector : public VentanaBuscarLector {
	
private:
	
protected:
	//eventos
	void ClickBusquedaPorNombreDesdeLibro( wxCommandEvent& event ) ;
	void DClickAceptarLectorPrestamo( wxGridEvent& event );
	void ClickCancelar( wxCommandEvent& event ) ;
		
public:
	vBuscarLector(wxWindow *parent=NULL);
	~vBuscarLector();
	
	void CargarFilaLectores(int i);
};

#endif

