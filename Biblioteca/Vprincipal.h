#ifndef VPRINCIPAL_H
#define VPRINCIPAL_H
#include "Ventanas.h"
#include "Biblioteca.h"
#include "Singleton.h"
using namespace std;

class Vprincipal : public VentanaPrincipal {

protected:
	void ClickBusquedaPorTitulo( wxCommandEvent& event ) ;
	void ClickAgregarSancionMenu( wxCommandEvent& event ) ;

public:
	Vprincipal(wxWindow *parent=NULL);	
	~Vprincipal();	
	void ClickAgregarLibroMenu( wxCommandEvent& event );	
	void ClickAgregarLectorMenu( wxCommandEvent& event ) ;
	void ClickAgregarPrestamoMenu( wxCommandEvent& event ) ;
	void ClickAgregarDevolucionMenu( wxCommandEvent& event ) ;
	
	void ClickPestaniaLibros( wxMouseEvent& event ) ;
	void ClickPestaniaLectores( wxMouseEvent& event ) ;
	void ClickPestaniaPrestamos( wxMouseEvent& event ) ;
	void ClickPestaniaSanciones( wxMouseEvent& event ) ;
	
	void CargarFilaLibros(int i);	
	void CargarFilaLectores(int i);
	void CargarFilaPrestamos(int i);	
	void CargarFilaSanciones(int i);	
	
	void DibujarPestaniaLibros();
	void DibujarPestaniaLectores();
	void DibujarPestaniaPrestamos();
	void DibujarPestaniaSanciones();
	void RefrescarGrillas();
};

#endif

