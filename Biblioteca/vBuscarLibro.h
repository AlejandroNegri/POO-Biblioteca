/**
* @brief Ventana buscar libro para prestamo
**/
#ifndef VBUSCARLIBRO_H
#define VBUSCARLIBRO_H
#include "Ventanas.h"

class vBuscarLibro : public VentanaBuscarLibro {
protected:
	/// Elige un libro y cierra la ventana (doble click)
	void DClickAceptarLibroPrestamo( wxGridEvent& event ) ;
	
	/// Busca por titulo segun la cadena ingresada 
	void ClickBusquedaPorTitulo( wxCommandEvent& event ) ;
	
public:
	vBuscarLibro(wxWindow *parent=NULL);
	~vBuscarLibro();
	
	/// Carga los datos en la grilla
	void CargarFilaLibros(int i);
};

#endif

