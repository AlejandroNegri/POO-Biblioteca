#ifndef VMODIFICARLIBRO_H
#define VMODIFICARLIBRO_H
#include "Ventanas.h"

class vModificarLibro : public VentanaAgregarLibro {
	
		
protected:
	void bCancelarAgregarLibro( wxCommandEvent& event ) ;
	void ClickAgregarLibroNuevo( wxCommandEvent& event ) ;
	
public:
	vModificarLibro(wxWindow *parent=NULL);
	~vModificarLibro();
	
	static int codLibro;
};

#endif

