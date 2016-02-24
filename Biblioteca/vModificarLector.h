#ifndef VMODIFICARLECTOR_H
#define VMODIFICARLECTOR_H
#include "Ventanas.h"

class vModificarLector : public VentanaAgregarLector {
protected:
	void bCancelarAgregarLector( wxCommandEvent& event ) ;
	void ClickAgregarLectorNuevo( wxCommandEvent& event ) ;
	
public:
	vModificarLector(wxWindow *parent=NULL);
	~vModificarLector();	
	static int numLector;
};

#endif

