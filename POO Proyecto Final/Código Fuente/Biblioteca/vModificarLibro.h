#ifndef VMODIFICARLIBRO_H
#define VMODIFICARLIBRO_H
#include "Ventanas.h"
using std::string;

/**
* @brief Ventana para modificar los datos de un libro
**/
class vModificarLibro : public VentanaAgregarLibro {
protected:
	/// Cierra la ventana sin modificar (boton "Cancelar")
	void bCancelarAgregarLibro( wxCommandEvent& event ) ;
	
	/// Cierra la ventana modificando los datos (boton "Cancelar")
	void ClickAgregarLibroNuevo( wxCommandEvent& event ) ;
	
public:
	vModificarLibro(wxWindow *parent=NULL);
	~vModificarLibro();	
	
	static int codLibro; ///< variable estatica del codigo de libro
	
	/// Valida los datos ingresados
	string ValidarDatos();
};

#endif

