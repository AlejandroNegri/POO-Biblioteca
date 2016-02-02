#ifndef VPRINCIPAL_H
#define VPRINCIPAL_H
#include "Ventanas.h"
#include "Biblioteca.h"
#include "Singleton.h"
using namespace std;

class Vprincipal : public VentanaPrincipal {
protected:
	void ClickAgregarDevolucionMenu( wxCommandEvent& event ) ;
	void ClickAgregarPrestamoMenu( wxCommandEvent& event ) ;
	void ClickPestaniaPrestamos( wxMouseEvent& event ) ;
	void ClickPestaniaLibros( wxMouseEvent& event ) ;
	void ClickPestaniaLectores( wxMouseEvent& event ) ;
	void ClickAgregarLectorMenu( wxCommandEvent& event ) ;

public:
	Vprincipal(wxWindow *parent=NULL);	
	~Vprincipal();	
	void CargarFilaLibros(int i);	
	void CargarFilaLectores(int i);
	void CargarFilaPrestamos(int i);	
	void ClickAgregarLibroMenu( wxCommandEvent& event );	
	void DibujarPestaniaLibros();
	void DibujarPestaniaLectores();
	void DibujarPestaniaPrestamos();
	void RefrescarGrillas();
};

#endif

