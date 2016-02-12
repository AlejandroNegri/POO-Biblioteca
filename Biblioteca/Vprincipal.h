#ifndef VPRINCIPAL_H
#define VPRINCIPAL_H
#include "Ventanas.h"
#include "Biblioteca.h"
#include "Singleton.h"
using namespace std;



class Vprincipal : public VentanaPrincipal {
protected:
	void ClickDerechoGrillaLibro( wxGridEvent& event ) ;
	void ClickEliminarLectorMenu( wxCommandEvent& event ) ;
	void ClickEliminarLibroMenu( wxCommandEvent& event ) ;
	void ClickBusquedaPorTitulo( wxCommandEvent& event ) ;
	void ClickAgregarSancionMenu( wxCommandEvent& event ) ;
	void PopupClickDerechoLibro(wxCommandEvent &evt);

public:
	Vprincipal(wxWindow *parent=NULL);	
	~Vprincipal();	
	
	void ClickAgregarLibroMenu( wxCommandEvent& event );	
	void ClickModificarLibroMenu() ;
	void ClickAgregarLectorMenu( wxCommandEvent& event ) ;
	void ClickAgregarPrestamoMenu();
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
	
	void ResetearIndices();
};

#endif

