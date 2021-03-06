///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "Ventanas.h"

///////////////////////////////////////////////////////////////////////////

VentanaPrincipal::VentanaPrincipal( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	m_menubar2 = new wxMenuBar( 0 );
	m_menu2 = new wxMenu();
	wxMenuItem* mAgregarLibro;
	mAgregarLibro = new wxMenuItem( m_menu2, wxID_ANY, wxString( wxT("Libro...") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu2->Append( mAgregarLibro );
	
	wxMenuItem* mAgregarLector;
	mAgregarLector = new wxMenuItem( m_menu2, wxID_ANY, wxString( wxT("Lector...") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu2->Append( mAgregarLector );
	
	m_menubar2->Append( m_menu2, wxT("Agregar") ); 
	
	this->SetMenuBar( m_menubar2 );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer21;
	bSizer21 = new wxBoxSizer( wxVERTICAL );
	
	m_notebook2 = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	pGrillaLibros = new wxPanel( m_notebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* sizerLibros;
	sizerLibros = new wxBoxSizer( wxVERTICAL );
	
	gLibros = new wxGrid( pGrillaLibros, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	gLibros->CreateGrid( 0, 8 );
	gLibros->EnableEditing( false );
	gLibros->EnableGridLines( true );
	gLibros->EnableDragGridSize( false );
	gLibros->SetMargins( 0, 0 );
	
	// Columns
	gLibros->SetColSize( 0, 159 );
	gLibros->SetColSize( 1, 102 );
	gLibros->SetColSize( 2, 106 );
	gLibros->SetColSize( 3, 94 );
	gLibros->SetColSize( 4, 146 );
	gLibros->SetColSize( 5, 50 );
	gLibros->SetColSize( 6, 56 );
	gLibros->SetColSize( 7, 58 );
	gLibros->EnableDragColMove( false );
	gLibros->EnableDragColSize( true );
	gLibros->SetColLabelSize( 30 );
	gLibros->SetColLabelValue( 0, wxT("T�tulo") );
	gLibros->SetColLabelValue( 1, wxT("Autor") );
	gLibros->SetColLabelValue( 2, wxT("Editorial") );
	gLibros->SetColLabelValue( 3, wxT("ISBN") );
	gLibros->SetColLabelValue( 4, wxT("Edici�n") );
	gLibros->SetColLabelValue( 5, wxT("C�digo") );
	gLibros->SetColLabelValue( 6, wxT("Tipo") );
	gLibros->SetColLabelValue( 7, wxT("Estado") );
	gLibros->SetColLabelValue( 8, wxEmptyString );
	gLibros->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	gLibros->EnableDragRowSize( true );
	gLibros->SetRowLabelSize( 0 );
	gLibros->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	gLibros->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	sizerLibros->Add( gLibros, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer24;
	bSizer24 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText2 = new wxStaticText( pGrillaLibros, wxID_ANY, wxT("Busqueda por T�tulo: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer24->Add( m_staticText2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	tBusquedaTitulo = new wxTextCtrl( pGrillaLibros, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer24->Add( tBusquedaTitulo, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bBusquedaTitulo = new wxButton( pGrillaLibros, wxID_ANY, wxT("Buscar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer24->Add( bBusquedaTitulo, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sizerLibros->Add( bSizer24, 0, wxEXPAND, 5 );
	
	
	pGrillaLibros->SetSizer( sizerLibros );
	pGrillaLibros->Layout();
	sizerLibros->Fit( pGrillaLibros );
	m_notebook2->AddPage( pGrillaLibros, wxT("Libros"), true );
	pGrillaLectores = new wxPanel( m_notebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* sizerLectores;
	sizerLectores = new wxBoxSizer( wxVERTICAL );
	
	gLectores = new wxGrid( pGrillaLectores, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	gLectores->CreateGrid( 0, 6 );
	gLectores->EnableEditing( false );
	gLectores->EnableGridLines( true );
	gLectores->EnableDragGridSize( false );
	gLectores->SetMargins( 0, 0 );
	
	// Columns
	gLectores->SetColSize( 0, 140 );
	gLectores->SetColSize( 1, 100 );
	gLectores->SetColSize( 2, 80 );
	gLectores->SetColSize( 3, 152 );
	gLectores->SetColSize( 4, 80 );
	gLectores->SetColSize( 5, 68 );
	gLectores->EnableDragColMove( false );
	gLectores->EnableDragColSize( true );
	gLectores->SetColLabelSize( 30 );
	gLectores->SetColLabelValue( 0, wxT("Apellido") );
	gLectores->SetColLabelValue( 1, wxT("Nombre") );
	gLectores->SetColLabelValue( 2, wxT("DNI") );
	gLectores->SetColLabelValue( 3, wxT("Domicilio") );
	gLectores->SetColLabelValue( 4, wxT("Tel�fono") );
	gLectores->SetColLabelValue( 5, wxT("N� Lector") );
	gLectores->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	gLectores->EnableDragRowSize( true );
	gLectores->SetRowLabelSize( 0 );
	gLectores->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	gLectores->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	sizerLectores->Add( gLectores, 1, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxBoxSizer* bSizer241;
	bSizer241 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText21 = new wxStaticText( pGrillaLectores, wxID_ANY, wxT("Busqueda por Nombre y Apellido: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText21->Wrap( -1 );
	bSizer241->Add( m_staticText21, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	tBusquedaNombre = new wxTextCtrl( pGrillaLectores, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer241->Add( tBusquedaNombre, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bBusquedaNombre = new wxButton( pGrillaLectores, wxID_ANY, wxT("Buscar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer241->Add( bBusquedaNombre, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sizerLectores->Add( bSizer241, 0, wxEXPAND, 5 );
	
	
	pGrillaLectores->SetSizer( sizerLectores );
	pGrillaLectores->Layout();
	sizerLectores->Fit( pGrillaLectores );
	m_notebook2->AddPage( pGrillaLectores, wxT("Lectores"), false );
	pGrillaPrestamos = new wxPanel( m_notebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* sizerPrestamos;
	sizerPrestamos = new wxBoxSizer( wxVERTICAL );
	
	gPrestamos = new wxGrid( pGrillaPrestamos, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	gPrestamos->CreateGrid( 0, 5 );
	gPrestamos->EnableEditing( false );
	gPrestamos->EnableGridLines( true );
	gPrestamos->EnableDragGridSize( false );
	gPrestamos->SetMargins( 0, 0 );
	
	// Columns
	gPrestamos->SetColSize( 0, 188 );
	gPrestamos->SetColSize( 1, 149 );
	gPrestamos->SetColSize( 2, 99 );
	gPrestamos->SetColSize( 3, 122 );
	gPrestamos->SetColSize( 4, 115 );
	gPrestamos->EnableDragColMove( false );
	gPrestamos->EnableDragColSize( true );
	gPrestamos->SetColLabelSize( 30 );
	gPrestamos->SetColLabelValue( 0, wxT("Lector") );
	gPrestamos->SetColLabelValue( 1, wxT("Libro") );
	gPrestamos->SetColLabelValue( 2, wxT("C�digo (Libro)") );
	gPrestamos->SetColLabelValue( 3, wxT("Fecha Entrega") );
	gPrestamos->SetColLabelValue( 4, wxT("Pr�stamo Hasta") );
	gPrestamos->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	gPrestamos->EnableDragRowSize( true );
	gPrestamos->SetRowLabelSize( 0 );
	gPrestamos->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	gPrestamos->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	sizerPrestamos->Add( gPrestamos, 1, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxBoxSizer* bSizer242;
	bSizer242 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText22 = new wxStaticText( pGrillaPrestamos, wxID_ANY, wxT("Busqueda por Nombre, Apellido o Libro: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText22->Wrap( -1 );
	bSizer242->Add( m_staticText22, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	tBusquedaPrestamo = new wxTextCtrl( pGrillaPrestamos, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer242->Add( tBusquedaPrestamo, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bBusquedaPrestamo = new wxButton( pGrillaPrestamos, wxID_ANY, wxT("Buscar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer242->Add( bBusquedaPrestamo, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sizerPrestamos->Add( bSizer242, 0, wxEXPAND, 5 );
	
	
	pGrillaPrestamos->SetSizer( sizerPrestamos );
	pGrillaPrestamos->Layout();
	sizerPrestamos->Fit( pGrillaPrestamos );
	m_notebook2->AddPage( pGrillaPrestamos, wxT("Pr�stamos"), false );
	pGrillaSanciones = new wxPanel( m_notebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* sizerSanciones;
	sizerSanciones = new wxBoxSizer( wxHORIZONTAL );
	
	gSanciones = new wxGrid( pGrillaSanciones, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	gSanciones->CreateGrid( 0, 3 );
	gSanciones->EnableEditing( false );
	gSanciones->EnableGridLines( true );
	gSanciones->EnableDragGridSize( false );
	gSanciones->SetMargins( 0, 0 );
	
	// Columns
	gSanciones->SetColSize( 0, 180 );
	gSanciones->SetColSize( 1, 149 );
	gSanciones->SetColSize( 2, 120 );
	gSanciones->SetColSize( 3, 114 );
	gSanciones->EnableDragColMove( false );
	gSanciones->EnableDragColSize( true );
	gSanciones->SetColLabelSize( 30 );
	gSanciones->SetColLabelValue( 0, wxT("Lector") );
	gSanciones->SetColLabelValue( 1, wxT("Sanci�n Hasta") );
	gSanciones->SetColLabelValue( 2, wxT("Motivo") );
	gSanciones->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	gSanciones->EnableDragRowSize( true );
	gSanciones->SetRowLabelSize( 0 );
	gSanciones->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	gSanciones->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	sizerSanciones->Add( gSanciones, 1, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	pGrillaSanciones->SetSizer( sizerSanciones );
	pGrillaSanciones->Layout();
	sizerSanciones->Fit( pGrillaSanciones );
	m_notebook2->AddPage( pGrillaSanciones, wxT("Sanciones"), false );
	
	bSizer21->Add( m_notebook2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bSizer2->Add( bSizer21, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	this->SetSizer( bSizer2 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( mAgregarLibro->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( VentanaPrincipal::ClickAgregarLibroMenu ) );
	this->Connect( mAgregarLector->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( VentanaPrincipal::ClickAgregarLectorMenu ) );
	pGrillaLibros->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( VentanaPrincipal::ClickPestaniaLibros ), NULL, this );
	gLibros->Connect( wxEVT_GRID_CELL_RIGHT_CLICK, wxGridEventHandler( VentanaPrincipal::ClickDerechoGrillaLibro ), NULL, this );
	bBusquedaTitulo->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaPrincipal::ClickBusquedaPorTitulo ), NULL, this );
	pGrillaLectores->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( VentanaPrincipal::ClickPestaniaLectores ), NULL, this );
	gLectores->Connect( wxEVT_GRID_CELL_RIGHT_CLICK, wxGridEventHandler( VentanaPrincipal::ClickDerechoGrillaLectores ), NULL, this );
	bBusquedaNombre->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaPrincipal::ClickBusquedaPorNombre ), NULL, this );
	pGrillaPrestamos->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( VentanaPrincipal::ClickPestaniaPrestamos ), NULL, this );
	gPrestamos->Connect( wxEVT_GRID_CELL_RIGHT_CLICK, wxGridEventHandler( VentanaPrincipal::ClickDerechoGrillaPrestamo ), NULL, this );
	bBusquedaPrestamo->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaPrincipal::ClickBusquedaPrestamo ), NULL, this );
	pGrillaSanciones->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( VentanaPrincipal::ClickPestaniaSanciones ), NULL, this );
}

VentanaPrincipal::~VentanaPrincipal()
{
	// Disconnect Events
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( VentanaPrincipal::ClickAgregarLibroMenu ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( VentanaPrincipal::ClickAgregarLectorMenu ) );
	pGrillaLibros->Disconnect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( VentanaPrincipal::ClickPestaniaLibros ), NULL, this );
	gLibros->Disconnect( wxEVT_GRID_CELL_RIGHT_CLICK, wxGridEventHandler( VentanaPrincipal::ClickDerechoGrillaLibro ), NULL, this );
	bBusquedaTitulo->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaPrincipal::ClickBusquedaPorTitulo ), NULL, this );
	pGrillaLectores->Disconnect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( VentanaPrincipal::ClickPestaniaLectores ), NULL, this );
	gLectores->Disconnect( wxEVT_GRID_CELL_RIGHT_CLICK, wxGridEventHandler( VentanaPrincipal::ClickDerechoGrillaLectores ), NULL, this );
	bBusquedaNombre->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaPrincipal::ClickBusquedaPorNombre ), NULL, this );
	pGrillaPrestamos->Disconnect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( VentanaPrincipal::ClickPestaniaPrestamos ), NULL, this );
	gPrestamos->Disconnect( wxEVT_GRID_CELL_RIGHT_CLICK, wxGridEventHandler( VentanaPrincipal::ClickDerechoGrillaPrestamo ), NULL, this );
	bBusquedaPrestamo->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaPrincipal::ClickBusquedaPrestamo ), NULL, this );
	pGrillaSanciones->Disconnect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( VentanaPrincipal::ClickPestaniaSanciones ), NULL, this );
	
}

VentanaAgregarLibro::VentanaAgregarLibro( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText13 = new wxStaticText( this, wxID_ANY, wxT("T�tulo: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	bSizer13->Add( m_staticText13, 0, wxALL, 5 );
	
	tTitulo = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( tTitulo, 1, wxALL, 5 );
	
	
	bSizer12->Add( bSizer13, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText14 = new wxStaticText( this, wxID_ANY, wxT("Autor: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText14->Wrap( -1 );
	bSizer14->Add( m_staticText14, 0, wxALL, 5 );
	
	tAutor = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14->Add( tAutor, 1, wxALL, 5 );
	
	
	bSizer12->Add( bSizer14, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText15 = new wxStaticText( this, wxID_ANY, wxT("Editorial: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15->Wrap( -1 );
	bSizer15->Add( m_staticText15, 0, wxALL, 5 );
	
	tEditorial = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer15->Add( tEditorial, 1, wxALL, 5 );
	
	
	bSizer12->Add( bSizer15, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText16 = new wxStaticText( this, wxID_ANY, wxT("ISBN: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText16->Wrap( -1 );
	bSizer17->Add( m_staticText16, 0, wxALL, 5 );
	
	tISBN = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer17->Add( tISBN, 1, wxALL, 5 );
	
	
	bSizer12->Add( bSizer17, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText17 = new wxStaticText( this, wxID_ANY, wxT("Edici�n: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText17->Wrap( -1 );
	bSizer18->Add( m_staticText17, 0, wxALL, 5 );
	
	tEdicion = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer18->Add( tEdicion, 1, wxALL, 5 );
	
	
	bSizer12->Add( bSizer18, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer19;
	bSizer19 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText18 = new wxStaticText( this, wxID_ANY, wxT("Tipo: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText18->Wrap( -1 );
	bSizer19->Add( m_staticText18, 0, wxALL, 5 );
	
	tTipo = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer19->Add( tTipo, 1, wxALL, 5 );
	
	
	bSizer12->Add( bSizer19, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer20;
	bSizer20 = new wxBoxSizer( wxHORIZONTAL );
	
	bCancelar = new wxButton( this, wxID_ANY, wxT("Cancelar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer20->Add( bCancelar, 0, wxALL, 5 );
	
	bAgregarLibro = new wxButton( this, wxID_ANY, wxT("Aceptar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer20->Add( bAgregarLibro, 0, wxALL, 5 );
	
	
	bSizer12->Add( bSizer20, 0, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer12 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	bCancelar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAgregarLibro::bCancelarAgregarLibro ), NULL, this );
	bAgregarLibro->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAgregarLibro::ClickAgregarLibroNuevo ), NULL, this );
}

VentanaAgregarLibro::~VentanaAgregarLibro()
{
	// Disconnect Events
	bCancelar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAgregarLibro::bCancelarAgregarLibro ), NULL, this );
	bAgregarLibro->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAgregarLibro::ClickAgregarLibroNuevo ), NULL, this );
	
}

VentanaAgregarLector::VentanaAgregarLector( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText13 = new wxStaticText( this, wxID_ANY, wxT("Nombre:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	bSizer13->Add( m_staticText13, 0, wxALL, 5 );
	
	tNombre = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( tNombre, 1, wxALL, 5 );
	
	
	bSizer12->Add( bSizer13, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText14 = new wxStaticText( this, wxID_ANY, wxT("Apellido:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText14->Wrap( -1 );
	bSizer14->Add( m_staticText14, 0, wxALL, 5 );
	
	tApellido = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer14->Add( tApellido, 1, wxALL, 5 );
	
	
	bSizer12->Add( bSizer14, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText15 = new wxStaticText( this, wxID_ANY, wxT("DNI:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15->Wrap( -1 );
	bSizer15->Add( m_staticText15, 0, wxALL, 5 );
	
	tDNI = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer15->Add( tDNI, 1, wxALL, 5 );
	
	
	bSizer12->Add( bSizer15, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText16 = new wxStaticText( this, wxID_ANY, wxT("Domicilio:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText16->Wrap( -1 );
	bSizer17->Add( m_staticText16, 0, wxALL, 5 );
	
	tDomicilio = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer17->Add( tDomicilio, 1, wxALL, 5 );
	
	
	bSizer12->Add( bSizer17, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText17 = new wxStaticText( this, wxID_ANY, wxT("Tel�fono:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText17->Wrap( -1 );
	bSizer18->Add( m_staticText17, 0, wxALL, 5 );
	
	tTelefono = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer18->Add( tTelefono, 1, wxALL, 5 );
	
	
	bSizer12->Add( bSizer18, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer20;
	bSizer20 = new wxBoxSizer( wxHORIZONTAL );
	
	bCancelar = new wxButton( this, wxID_ANY, wxT("Cancelar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer20->Add( bCancelar, 0, wxALL, 5 );
	
	bAgregarLector = new wxButton( this, wxID_ANY, wxT("Aceptar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer20->Add( bAgregarLector, 0, wxALL, 5 );
	
	
	bSizer12->Add( bSizer20, 0, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer12 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	bCancelar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAgregarLector::bCancelarAgregarLector ), NULL, this );
	bAgregarLector->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAgregarLector::ClickAgregarLectorNuevo ), NULL, this );
}

VentanaAgregarLector::~VentanaAgregarLector()
{
	// Disconnect Events
	bCancelar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAgregarLector::bCancelarAgregarLector ), NULL, this );
	bAgregarLector->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAgregarLector::ClickAgregarLectorNuevo ), NULL, this );
	
}

VentanaAgregarPrestamo::VentanaAgregarPrestamo( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer64;
	bSizer64 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer65;
	bSizer65 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText39 = new wxStaticText( this, wxID_ANY, wxT("Libro:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText39->Wrap( -1 );
	bSizer65->Add( m_staticText39, 0, wxALL, 5 );
	
	lLibro = new wxStaticText( this, wxID_ANY, wxT("-"), wxDefaultPosition, wxDefaultSize, 0 );
	lLibro->Wrap( -1 );
	bSizer65->Add( lLibro, 0, wxALL, 5 );
	
	
	bSizer65->Add( 0, 0, 1, wxEXPAND, 5 );
	
	bBuscarLibro = new wxButton( this, wxID_ANY, wxT("Buscar..."), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer65->Add( bBuscarLibro, 0, wxALL, 5 );
	
	
	bSizer64->Add( bSizer65, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer66;
	bSizer66 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText391 = new wxStaticText( this, wxID_ANY, wxT("Lector:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText391->Wrap( -1 );
	bSizer66->Add( m_staticText391, 0, wxALL, 5 );
	
	lLector = new wxStaticText( this, wxID_ANY, wxT("-"), wxDefaultPosition, wxDefaultSize, 0 );
	lLector->Wrap( -1 );
	bSizer66->Add( lLector, 0, wxALL, 5 );
	
	
	bSizer66->Add( 0, 0, 1, wxEXPAND, 5 );
	
	bBuscarLector = new wxButton( this, wxID_ANY, wxT("Buscar..."), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer66->Add( bBuscarLector, 0, wxALL, 5 );
	
	
	bSizer64->Add( bSizer66, 1, wxEXPAND, 5 );
	
	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer64->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer74;
	bSizer74 = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizer74->Add( 0, 0, 1, wxEXPAND, 5 );
	
	bCancelar = new wxButton( this, wxID_ANY, wxT("Cancelar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer74->Add( bCancelar, 0, wxALL, 5 );
	
	bConfirmarPrestamo = new wxButton( this, wxID_ANY, wxT("Aceptar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer74->Add( bConfirmarPrestamo, 0, wxALL, 5 );
	
	
	bSizer64->Add( bSizer74, 0, wxEXPAND|wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer64 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	bBuscarLibro->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAgregarPrestamo::ClickBuscarLibro ), NULL, this );
	bBuscarLector->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAgregarPrestamo::ClickBuscarLector ), NULL, this );
	bCancelar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAgregarPrestamo::ClickCancelar ), NULL, this );
	bConfirmarPrestamo->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAgregarPrestamo::ClickAceptarPrestamo ), NULL, this );
}

VentanaAgregarPrestamo::~VentanaAgregarPrestamo()
{
	// Disconnect Events
	bBuscarLibro->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAgregarPrestamo::ClickBuscarLibro ), NULL, this );
	bBuscarLector->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAgregarPrestamo::ClickBuscarLector ), NULL, this );
	bCancelar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAgregarPrestamo::ClickCancelar ), NULL, this );
	bConfirmarPrestamo->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaAgregarPrestamo::ClickAceptarPrestamo ), NULL, this );
	
}

VentanaBuscarLector::VentanaBuscarLector( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer52;
	bSizer52 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer24;
	bSizer24 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("B�squeda por nombre y apellido: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer24->Add( m_staticText2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	tBusquedaNombre = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer24->Add( tBusquedaNombre, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bBusquedaNombre = new wxButton( this, wxID_ANY, wxT("Buscar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer24->Add( bBusquedaNombre, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer52->Add( bSizer24, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer61;
	bSizer61 = new wxBoxSizer( wxVERTICAL );
	
	pGrillaLectores = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* sizerLibros;
	sizerLibros = new wxBoxSizer( wxVERTICAL );
	
	gLectoresPrestamo = new wxGrid( pGrillaLectores, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	gLectoresPrestamo->CreateGrid( 0, 6 );
	gLectoresPrestamo->EnableEditing( false );
	gLectoresPrestamo->EnableGridLines( true );
	gLectoresPrestamo->EnableDragGridSize( false );
	gLectoresPrestamo->SetMargins( 0, 0 );
	
	// Columns
	gLectoresPrestamo->SetColSize( 0, 164 );
	gLectoresPrestamo->SetColSize( 1, 155 );
	gLectoresPrestamo->SetColSize( 2, 137 );
	gLectoresPrestamo->SetColSize( 3, 182 );
	gLectoresPrestamo->SetColSize( 4, 80 );
	gLectoresPrestamo->SetColSize( 5, 80 );
	gLectoresPrestamo->EnableDragColMove( false );
	gLectoresPrestamo->EnableDragColSize( true );
	gLectoresPrestamo->SetColLabelSize( 30 );
	gLectoresPrestamo->SetColLabelValue( 0, wxT("Apellido") );
	gLectoresPrestamo->SetColLabelValue( 1, wxT("Nombre") );
	gLectoresPrestamo->SetColLabelValue( 2, wxT("DNI") );
	gLectoresPrestamo->SetColLabelValue( 3, wxT("Domicilio") );
	gLectoresPrestamo->SetColLabelValue( 4, wxT("Tel�fono") );
	gLectoresPrestamo->SetColLabelValue( 5, wxT("N� Lector") );
	gLectoresPrestamo->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	gLectoresPrestamo->EnableDragRowSize( true );
	gLectoresPrestamo->SetRowLabelSize( 0 );
	gLectoresPrestamo->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	gLectoresPrestamo->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	sizerLibros->Add( gLectoresPrestamo, 1, wxALL|wxEXPAND, 5 );
	
	
	pGrillaLectores->SetSizer( sizerLibros );
	pGrillaLectores->Layout();
	sizerLibros->Fit( pGrillaLectores );
	bSizer61->Add( pGrillaLectores, 1, wxEXPAND | wxALL, 5 );
	
	
	bSizer52->Add( bSizer61, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer52 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	bBusquedaNombre->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaBuscarLector::ClickBusquedaPorNombre ), NULL, this );
	gLectoresPrestamo->Connect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( VentanaBuscarLector::DClickAceptarLectorPrestamo ), NULL, this );
}

VentanaBuscarLector::~VentanaBuscarLector()
{
	// Disconnect Events
	bBusquedaNombre->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaBuscarLector::ClickBusquedaPorNombre ), NULL, this );
	gLectoresPrestamo->Disconnect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( VentanaBuscarLector::DClickAceptarLectorPrestamo ), NULL, this );
	
}

VentanaBuscarLibro::VentanaBuscarLibro( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer52;
	bSizer52 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer24;
	bSizer24 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("B�squeda por t�tulo: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer24->Add( m_staticText2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	tBusquedaTitulo = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer24->Add( tBusquedaTitulo, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	bBusquedaTitulo = new wxButton( this, wxID_ANY, wxT("Buscar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer24->Add( bBusquedaTitulo, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer52->Add( bSizer24, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer61;
	bSizer61 = new wxBoxSizer( wxVERTICAL );
	
	pGrillaLibros = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* sizerLibros;
	sizerLibros = new wxBoxSizer( wxVERTICAL );
	
	gLibrosPrestamo = new wxGrid( pGrillaLibros, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	gLibrosPrestamo->CreateGrid( 0, 8 );
	gLibrosPrestamo->EnableEditing( false );
	gLibrosPrestamo->EnableGridLines( true );
	gLibrosPrestamo->EnableDragGridSize( false );
	gLibrosPrestamo->SetMargins( 0, 0 );
	
	// Columns
	gLibrosPrestamo->SetColSize( 0, 164 );
	gLibrosPrestamo->SetColSize( 1, 80 );
	gLibrosPrestamo->SetColSize( 2, 80 );
	gLibrosPrestamo->SetColSize( 3, 80 );
	gLibrosPrestamo->SetColSize( 4, 80 );
	gLibrosPrestamo->SetColSize( 5, 80 );
	gLibrosPrestamo->SetColSize( 6, 80 );
	gLibrosPrestamo->SetColSize( 7, 87 );
	gLibrosPrestamo->EnableDragColMove( false );
	gLibrosPrestamo->EnableDragColSize( true );
	gLibrosPrestamo->SetColLabelSize( 30 );
	gLibrosPrestamo->SetColLabelValue( 0, wxT("T�tulo") );
	gLibrosPrestamo->SetColLabelValue( 1, wxT("Autor") );
	gLibrosPrestamo->SetColLabelValue( 2, wxT("Editorial") );
	gLibrosPrestamo->SetColLabelValue( 3, wxT("ISBN") );
	gLibrosPrestamo->SetColLabelValue( 4, wxT("Edici�n") );
	gLibrosPrestamo->SetColLabelValue( 5, wxT("C�digo") );
	gLibrosPrestamo->SetColLabelValue( 6, wxT("Tipo") );
	gLibrosPrestamo->SetColLabelValue( 7, wxT("Estado") );
	gLibrosPrestamo->SetColLabelValue( 8, wxEmptyString );
	gLibrosPrestamo->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	gLibrosPrestamo->EnableDragRowSize( true );
	gLibrosPrestamo->SetRowLabelSize( 0 );
	gLibrosPrestamo->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	gLibrosPrestamo->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	sizerLibros->Add( gLibrosPrestamo, 1, wxALL|wxEXPAND, 5 );
	
	
	pGrillaLibros->SetSizer( sizerLibros );
	pGrillaLibros->Layout();
	sizerLibros->Fit( pGrillaLibros );
	bSizer61->Add( pGrillaLibros, 1, wxEXPAND | wxALL, 5 );
	
	
	bSizer52->Add( bSizer61, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer52 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	bBusquedaTitulo->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaBuscarLibro::ClickBusquedaPorTitulo ), NULL, this );
	gLibrosPrestamo->Connect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( VentanaBuscarLibro::DClickAceptarLibroPrestamo ), NULL, this );
}

VentanaBuscarLibro::~VentanaBuscarLibro()
{
	// Disconnect Events
	bBusquedaTitulo->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaBuscarLibro::ClickBusquedaPorTitulo ), NULL, this );
	gLibrosPrestamo->Disconnect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( VentanaBuscarLibro::DClickAceptarLibroPrestamo ), NULL, this );
	
}
