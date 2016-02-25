#ifndef VMODIFICARLIBRO_H
#define VMODIFICARLIBRO_H
#include "Ventanas.h"
using std::string;

class vModificarLibro : public VentanaAgregarLibro {
protected:
	void bCancelarAgregarLibro( wxCommandEvent& event ) ;
	void ClickAgregarLibroNuevo( wxCommandEvent& event ) ;
	
public:
	vModificarLibro(wxWindow *parent=NULL);
	~vModificarLibro();	
	static int codLibro;
	string ValidarDatos();
};

#endif

