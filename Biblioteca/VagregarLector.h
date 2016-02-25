#ifndef VAGREGARLECTOR_H
#define VAGREGARLECTOR_H
#include "Ventanas.h"
using std::string;

class VagregarLector : public VentanaAgregarLector {
protected:
	void bCancelarAgregarLector( wxCommandEvent& event ) ; // 
	void ClickAgregarLectorNuevo( wxCommandEvent& event ) ; //
	
public:
	//constructor
	VagregarLector(wxWindow *parent=NULL);
	//destructor
	~VagregarLector();
	string ValidarDatos();
};

#endif

