#ifndef VPRINCIPAL_H
#define VPRINCIPAL_H
#include "Ventanas.h"
#include "Biblioteca.h"
#include "Singleton.h"
using namespace std;



class Vprincipal : public VentanaPrincipal {
	int indice;
protected:
	

public:
	Vprincipal(wxWindow *parent=NULL);	
	~Vprincipal();	
	
	
	
	//click derechos y sus popups
	void ClickDerechoGrillaLectores( wxGridEvent& event ) ;
	void ClickDerechoGrillaLibro( wxGridEvent& event ) ;
	void ClickDerechoGrillaPrestamo(wxGridEvent& event) ;
	void PopupClickDerechoLibro(wxCommandEvent &event);
	void PopupClickDerechoLector(wxCommandEvent &event);
	void PopupClickDerechoPrestamo(wxCommandEvent &event);
	
	//busquedas
	void ClickBusquedaPorTitulo( wxCommandEvent& event ) ;
	void ClickBusquedaPorNombre( wxCommandEvent& event ) ;
	void ClickAgregarSancionMenu( wxCommandEvent& event ) ;

	//libro
	void ClickAgregarLibroMenu( wxCommandEvent& event );	
	void ClickModificarLibroMenu() ;
	void ClickEliminarLibroMenu() ;
	
	//lector
	void ClickAgregarLectorMenu( wxCommandEvent& event ) ;
	void ClickModificarLectorMenu() ;
	void ClickEliminarLectorMenu() ;
	
	//prestamo
	void ClickAgregarPrestamoMenu();
	void ClickAgregarDevolucionMenu() ;
	void ClickBusquedaPrestamo( wxCommandEvent& event ) ;
	
	//pestañas y carga de datos en ellas
	void DibujarPestaniaLibros();
	void DibujarPestaniaLectores();
	void DibujarPestaniaPrestamos();
	void DibujarPestaniaSanciones();
	void ClickPestaniaLibros( wxMouseEvent& event ) ;
	void ClickPestaniaLectores( wxMouseEvent& event ) ;
	void ClickPestaniaPrestamos( wxMouseEvent& event ) ;
	void ClickPestaniaSanciones( wxMouseEvent& event ) ;
	void CargarFilaLibros(int i);	
	void CargarFilaLectores(int i);
	void CargarFilaPrestamos(int i);	
	void CargarFilaSanciones(int i);	
	void RefrescarGrillas();
	
	
	void ResetearIndices();
};

#endif

