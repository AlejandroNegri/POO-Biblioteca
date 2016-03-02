/**
* @brief Ventana cargar los datos de un nuevo Libro
**/
#ifndef VAGREGARLIBRO_H
#define VAGREGARLIBRO_H
#include "Ventanas.h"
#include "Singleton.h"

class VagregarLibro : public VentanaAgregarLibro {	
protected:
	/// Guarda el nuevo dato y cierra la ventana (boton "Aceptar");
	void ClickAgregarLibroNuevo( wxCommandEvent& event ) ;
	
	/// Cierra la ventana sin agregar el nuevo dato (boton "Cancelar")
	void bCancelarAgregarLibro( wxCommandEvent& event ) ;	
public:
	VagregarLibro(wxWindow *parent=NULL);	
	~VagregarLibro();
	
	/// Valida los datos ingresados
	string ValidarDatos();
};

#endif

