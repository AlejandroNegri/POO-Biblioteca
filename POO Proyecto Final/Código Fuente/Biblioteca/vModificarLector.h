#ifndef VMODIFICARLECTOR_H
#define VMODIFICARLECTOR_H
#include "Ventanas.h"
using std::string;

/**
* @brief Ventana para modificar los datos de un lector
**/
class vModificarLector : public VentanaAgregarLector {
protected:
	/// Cierra la ventana sin modificar (boton "Cancelar")
	void bCancelarAgregarLector( wxCommandEvent& event ) ;
	
	/// Cierra la ventana modificando los datos (boton "Cancelar")
	void ClickAgregarLectorNuevo( wxCommandEvent& event ) ;
	
public:
	vModificarLector(wxWindow *parent=NULL);
	~vModificarLector();	
	
	static int numLector; ///< variable estatica del número del lector
	
	/// Valida los datos ingresados
	string ValidarDatos();
};

#endif

