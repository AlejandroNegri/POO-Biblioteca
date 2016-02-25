///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __VENTANAS_H__
#define __VENTANAS_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/grid.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/notebook.h>
#include <wx/frame.h>
#include <wx/dialog.h>
#include <wx/statline.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class VentanaPrincipal
///////////////////////////////////////////////////////////////////////////////
class VentanaPrincipal : public wxFrame 
{
	private:
	
	protected:
		wxMenuBar* m_menubar2;
		wxMenu* m_menu2;
		wxNotebook* m_notebook2;
		wxPanel* pGrillaLibros;
		wxGrid* gLibros;
		wxStaticText* m_staticText2;
		wxTextCtrl* tBusquedaTitulo;
		wxButton* bBusquedaTitulo;
		wxPanel* pGrillaLectores;
		wxGrid* gLectores;
		wxStaticText* m_staticText21;
		wxTextCtrl* tBusquedaNombre;
		wxButton* bBusquedaNombre;
		wxPanel* pGrillaPrestamos;
		wxGrid* gPrestamos;
		wxStaticText* m_staticText22;
		wxTextCtrl* tBusquedaPrestamo;
		wxButton* bBusquedaPrestamo;
		wxPanel* pGrillaSanciones;
		wxGrid* gSanciones;
		
		// Virtual event handlers, overide them in your derived class
		virtual void ClickAgregarLibroMenu( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickAgregarLectorMenu( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickPestaniaLibros( wxMouseEvent& event ) { event.Skip(); }
		virtual void ClickDerechoGrillaLibro( wxGridEvent& event ) { event.Skip(); }
		virtual void ClickBusquedaPorTitulo( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickPestaniaLectores( wxMouseEvent& event ) { event.Skip(); }
		virtual void ClickDerechoGrillaLectores( wxGridEvent& event ) { event.Skip(); }
		virtual void ClickBusquedaPorNombre( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickPestaniaPrestamos( wxMouseEvent& event ) { event.Skip(); }
		virtual void ClickDerechoGrillaPrestamo( wxGridEvent& event ) { event.Skip(); }
		virtual void ClickBusquedaPrestamo( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickPestaniaSanciones( wxMouseEvent& event ) { event.Skip(); }
		
	
	public:
		
		VentanaPrincipal( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Corinthian"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 816,600 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~VentanaPrincipal();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class VentanaAgregarLibro
///////////////////////////////////////////////////////////////////////////////
class VentanaAgregarLibro : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText13;
		wxTextCtrl* tTitulo;
		wxStaticText* m_staticText14;
		wxTextCtrl* tAutor;
		wxStaticText* m_staticText15;
		wxTextCtrl* tEditorial;
		wxStaticText* m_staticText16;
		wxTextCtrl* tISBN;
		wxStaticText* m_staticText17;
		wxTextCtrl* tEdicion;
		wxStaticText* m_staticText18;
		wxTextCtrl* tTipo;
		wxButton* bCancelar;
		wxButton* bAgregarLibro;
		
		// Virtual event handlers, overide them in your derived class
		virtual void bCancelarAgregarLibro( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickAgregarLibroNuevo( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		VentanaAgregarLibro( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Libro"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 350,281 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~VentanaAgregarLibro();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class VentanaAgregarLector
///////////////////////////////////////////////////////////////////////////////
class VentanaAgregarLector : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText13;
		wxTextCtrl* tNombre;
		wxStaticText* m_staticText14;
		wxTextCtrl* tApellido;
		wxStaticText* m_staticText15;
		wxTextCtrl* tDNI;
		wxStaticText* m_staticText16;
		wxTextCtrl* tDomicilio;
		wxStaticText* m_staticText17;
		wxTextCtrl* tTelefono;
		wxButton* bCancelar;
		wxButton* bAgregarLector;
		
		// Virtual event handlers, overide them in your derived class
		virtual void bCancelarAgregarLector( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickAgregarLectorNuevo( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		VentanaAgregarLector( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Agregar Lector"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 350,281 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~VentanaAgregarLector();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class VentanaAgregarPrestamo
///////////////////////////////////////////////////////////////////////////////
class VentanaAgregarPrestamo : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText39;
		wxStaticText* lLibro;
		wxButton* bBuscarLibro;
		wxStaticText* m_staticText391;
		wxStaticText* lLector;
		wxButton* bBuscarLector;
		wxStaticLine* m_staticline1;
		wxButton* bCancelar;
		wxButton* bConfirmarPrestamo;
		
		// Virtual event handlers, overide them in your derived class
		virtual void ClickBuscarLibro( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBuscarLector( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickCancelar( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickAceptarPrestamo( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		VentanaAgregarPrestamo( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Agregar Préstamo"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 470,153 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~VentanaAgregarPrestamo();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class VentanaBuscarLector
///////////////////////////////////////////////////////////////////////////////
class VentanaBuscarLector : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText2;
		wxTextCtrl* tBusquedaNombre;
		wxButton* bBusquedaNombre;
		wxPanel* pGrillaLectores;
		wxGrid* gLectoresPrestamo;
		
		// Virtual event handlers, overide them in your derived class
		virtual void ClickBusquedaPorNombre( wxCommandEvent& event ) { event.Skip(); }
		virtual void DClickAceptarLectorPrestamo( wxGridEvent& event ) { event.Skip(); }
		
	
	public:
		
		VentanaBuscarLector( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Agregar Préstamo"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 904,563 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~VentanaBuscarLector();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class VentanaBuscarLibro
///////////////////////////////////////////////////////////////////////////////
class VentanaBuscarLibro : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText2;
		wxTextCtrl* tBusquedaTitulo;
		wxButton* bBusquedaTitulo;
		wxPanel* pGrillaLibros;
		wxGrid* gLibrosPrestamo;
		
		// Virtual event handlers, overide them in your derived class
		virtual void ClickBusquedaPorTitulo( wxCommandEvent& event ) { event.Skip(); }
		virtual void DClickAceptarLibroPrestamo( wxGridEvent& event ) { event.Skip(); }
		
	
	public:
		
		VentanaBuscarLibro( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Agregar Préstamo"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 904,563 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~VentanaBuscarLibro();
	
};

#endif //__VENTANAS_H__
