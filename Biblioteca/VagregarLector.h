#ifndef VAGREGARLECTOR_H
#define VAGREGARLECTOR_H
#include "Ventanas.h"

class VagregarLector : public VentanaAgregarLector {
	
private:
	
protected:
	void bCancelarAgregarLector( wxCommandEvent& event ) ; // 
	void ClickAgregarLectorNuevo( wxCommandEvent& event ) ; //
	
public:
	//constructor
	VagregarLector(wxWindow *parent=NULL);
	//destructor
	~VagregarLector();
};

#endif

