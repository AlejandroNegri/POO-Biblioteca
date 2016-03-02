/**
* @brief Ventana buscar lector para prestamo
**/
#ifndef VBUSCARLECTOR_H
#define VBUSCARLECTOR_H
#include "Ventanas.h"
#include <string>

class vBuscarLector : public VentanaBuscarLector {
protected:
	/// Busca por nombre segun la cadena ingresada 
	void ClickBusquedaPorNombre( wxCommandEvent& event ) ;
	
	/// Guarda el nuevo dato y cierra la ventana (boton "Aceptar");
	void DClickAceptarLectorPrestamo( wxGridEvent& event );
public:
	vBuscarLector(wxWindow *parent=NULL);
	~vBuscarLector();	
	
	/// Carga los datos en la grilla
	void CargarFilaLectores(int i);
};

#endif

