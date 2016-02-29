/**
* @brief Ventana cargar los datos de un nuevo Lector
**/
#ifndef VAGREGARLECTOR_H
#define VAGREGARLECTOR_H
#include "Ventanas.h"
using std::string;

class VagregarLector : public VentanaAgregarLector {
protected:	
	/// Guarda el nuevo dato y cierra la ventana (boton "Aceptar");
	void ClickAgregarLectorNuevo( wxCommandEvent& event ) ;
	
	/// Cierra la ventana sin agregar el nuevo dato (boton "Cancelar")
	void bCancelarAgregarLector( wxCommandEvent& event ) ; 	
	
public:
	VagregarLector(wxWindow *parent=NULL);
	~VagregarLector();
	
	/// Valida los datos ingresados
	string ValidarDatos();
};

#endif

