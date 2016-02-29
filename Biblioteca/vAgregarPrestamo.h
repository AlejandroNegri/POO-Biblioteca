/**
* @brief Ventana cargar los datos de un nuevo Prestamo
**/
#ifndef VAGREGARPRESTAMO_H
#define VAGREGARPRESTAMO_H
#include "Ventanas.h"

class vAgregarPrestamo : public VentanaAgregarPrestamo {	
protected:
	/// Guarda el nuevo dato y cierra la ventana (boton "Aceptar");
	void ClickAceptarPrestamo( wxCommandEvent& event ) ;
	
	/// Cierra la ventana sin agregar el nuevo dato (boton "Cancelar")
	void ClickCancelar( wxCommandEvent& event ) ;
	
	/// Abre una ventana para elegir el lector del prestamo
	void ClickBuscarLector( wxCommandEvent& event ) ;
	
	/// Abre una ventana para elegir el libro del prestamo
	void ClickBuscarLibro( wxCommandEvent& event ) ;
	
public:
	
	static int codLibro; ///< variable estatica del codigo del libro
	static int numLector; ///< variable estatica del numero del lector
	
	vAgregarPrestamo(wxWindow *parent=NULL);
	~vAgregarPrestamo();	

	/// Chequea que se elija un libro y que no este prestado
	bool ValidarLibro();
	
	/// Chequea que se elija un lector y que no este sancionado
	bool ValidarLector();
	
	/// Actualiza el label del libro una vez elegido
	void ActualizarLabelLibro();
	
	/// Actualiza el label del lector una vez elegido
	void ActualizarLabelLector();	
};
#endif

