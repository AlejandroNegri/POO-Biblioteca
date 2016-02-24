#ifndef VAGREGARLIBRO_H
#define VAGREGARLIBRO_H
#include "Ventanas.h"
#include "Singleton.h"


class VagregarLibro : public VentanaAgregarLibro {	
protected:
	void bCancelarAgregarLibro( wxCommandEvent& event ) ;	
	void ClickAgregarLibroNuevo( wxCommandEvent& event ) ;

public:
	VagregarLibro(wxWindow *parent=NULL);	
	~VagregarLibro();
};

#endif

