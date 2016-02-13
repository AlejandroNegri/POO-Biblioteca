#ifndef VPRINCIPAL_H
#define VPRINCIPAL_H
#include "Ventanas.h"
#include "Biblioteca.h"
#include "Singleton.h"
using namespace std;



class Vprincipal : public VentanaPrincipal {
	int indiceGrilla;
public:
	Vprincipal(wxWindow *parent=NULL);	
	~Vprincipal();	
	
	void ClickDerechoGrillaLectores( wxGridEvent& event ) ;
	void ClickDerechoGrillaLibro( wxGridEvent& event ) ;
	
	
	void ClickBusquedaPorTitulo( wxCommandEvent& event ) ;
	void ClickBusquedaPorNombre( wxCommandEvent& event ) ;
	void ClickAgregarSancionMenu( wxCommandEvent& event ) ;
	void PopupClickDerechoLibro(wxCommandEvent &event);
	void PopupClickDerechoLector(wxCommandEvent &event);


	void ClickAgregarLibroMenu( wxCommandEvent& event );	
	void ClickModificarLibroMenu() ;
	void ClickEliminarLibroMenu() ;
	
	void ClickAgregarLectorMenu( wxCommandEvent& event ) ;
	void ClickModificarLectorMenu() ;
	void ClickEliminarLectorMenu() ;
	
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

