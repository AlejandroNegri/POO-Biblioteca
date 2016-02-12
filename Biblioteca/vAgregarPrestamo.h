#ifndef VAGREGARPRESTAMO_H
#define VAGREGARPRESTAMO_H
#include "Ventanas.h"



class vAgregarPrestamo : public VentanaAgregarPrestamo {
	
protected:
	void ClickAceptarPrestamo( wxCommandEvent& event ) ;
	void ClickBuscarLector( wxCommandEvent& event ) ;
	void ClickBuscarLibro( wxCommandEvent& event ) ;
	void ClickCancelar( wxCommandEvent& event ) ;
	
public:
	vAgregarPrestamo(wxWindow *parent=NULL);
	~vAgregarPrestamo();
	
	bool ValidarLibro();
	bool ValidarLector();
	void ActualizarLabelLibro();
	void ActualizarLabelLector();
	
	static int codLibro ;
	static int numLector ;
	
	
	
	
};



#endif

