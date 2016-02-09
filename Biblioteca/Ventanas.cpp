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
	m_menu1 = new wxMenu();
	m_menubar2->Append( m_menu1, wxT("Archivo") ); 
	
	m_menu2 = new wxMenu();
	wxMenuItem* mAgregarLibro;
	mAgregarLibro = new wxMenuItem( m_menu2, wxID_ANY, wxString( wxT("Agregar...") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu2->Append( mAgregarLibro );
	
	wxMenuItem* mModificarLibro;
	mModificarLibro = new wxMenuItem( m_menu2, wxID_ANY, wxString( wxT("MyMenuItem") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu2->Append( mModificarLibro );
	
	wxMenuItem* mEliminarLibro;
	mEliminarLibro = new wxMenuItem( m_menu2, wxID_ANY, wxString( wxT("Eliminar...") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu2->Append( mEliminarLibro );
	
	m_menubar2->Append( m_menu2, wxT("Libro") ); 
	
	m_menu3 = new wxMenu();
	wxMenuItem* mAgregarLector;
	mAgregarLector = new wxMenuItem( m_menu3, wxID_ANY, wxString( wxT("Agregar...") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu3->Append( mAgregarLector );
	
	m_menubar2->Append( m_menu3, wxT("Lector") ); 
	
	m_menu4 = new wxMenu();
	wxMenuItem* mAgregarPrestamo;
	mAgregarPrestamo = new wxMenuItem( m_menu4, wxID_ANY, wxString( wxT("Prestar...") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu4->Append( mAgregarPrestamo );
	
	wxMenuItem* mAgregarDevolucion;
	mAgregarDevolucion = new wxMenuItem( m_menu4, wxID_ANY, wxString( wxT("Devolver...") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu4->Append( mAgregarDevolucion );
	
	m_menubar2->Append( m_menu4, wxT("Préstamo") ); 
	
	m_menu7 = new wxMenu();
	wxMenuItem* mAgregarSancion;
	mAgregarSancion = new wxMenuItem( m_menu7, wxID_ANY, wxString( wxT("Agregar...") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu7->Append( mAgregarSancion );
	
	m_menubar2->Append( m_menu7, wxT("Sanción") ); 
	
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
	gLibros->SetColSize( 0, 164 );
	gLibros->SetColSize( 1, 80 );
	gLibros->SetColSize( 2, 80 );
	gLibros->SetColSize( 3, 80 );
	gLibros->SetColSize( 4, 80 );
	gLibros->SetColSize( 5, 80 );
	gLibros->SetColSize( 6, 80 );
	gLibros->SetColSize( 7, 87 );
	gLibros->EnableDragColMove( false );
	gLibros->EnableDragColSize( true );
	gLibros->SetColLabelSize( 30 );
	gLibros->SetColLabelValue( 0, wxT("Título") );
	gLibros->SetColLabelValue( 1, wxT("Autor") );
	gLibros->SetColLabelValue( 2, wxT("Editorial") );
	gLibros->SetColLabelValue( 3, wxT("ISBN") );
	gLibros->SetColLabelValue( 4, wxT("Edición") );
	gLibros->SetColLabelValue( 5, wxT("Código") );
	gLibros->SetColLabelValue( 6, wxT("Tipo") );
	gLibros->SetColLabelValue( 7, wxT("Estado") );
	gLibros->SetColLabelValue( 8, wxEmptyString );
	gLibros->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	gLibros->EnableDragRowSize( true );
	gLibros->SetRowLabelSize( 1 );
	gLibros->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	gLibros->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	sizerLibros->Add( gLibros, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer24;
	bSizer24 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText2 = new wxStaticText( pGrillaLibros, wxID_ANY, wxT("Busqueda por Título: "), wxDefaultPosition, wxDefaultSize, 0 );
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
	sizerLectores = new wxBoxSizer( wxHORIZONTAL );
	
	gLectores = new wxGrid( pGrillaLectores, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	gLectores->CreateGrid( 0, 6 );
	gLectores->EnableEditing( false );
	gLectores->EnableGridLines( true );
	gLectores->EnableDragGridSize( false );
	gLectores->SetMargins( 0, 0 );
	
	// Columns
	gLectores->SetColSize( 0, 164 );
	gLectores->SetColSize( 1, 80 );
	gLectores->SetColSize( 2, 80 );
	gLectores->SetColSize( 3, 80 );
	gLectores->SetColSize( 4, 80 );
	gLectores->SetColSize( 5, 80 );
	gLectores->SetColSize( 6, 80 );
	gLectores->SetColSize( 7, 80 );
	gLectores->EnableDragColMove( false );
	gLectores->EnableDragColSize( true );
	gLectores->SetColLabelSize( 30 );
	gLectores->SetColLabelValue( 0, wxT("Apellido") );
	gLectores->SetColLabelValue( 1, wxT("Nombre") );
	gLectores->SetColLabelValue( 2, wxT("DNI") );
	gLectores->SetColLabelValue( 3, wxT("Domicilio") );
	gLectores->SetColLabelValue( 4, wxT("Teléfono") );
	gLectores->SetColLabelValue( 5, wxT("Nº Lector") );
	gLectores->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	gLectores->EnableDragRowSize( true );
	gLectores->SetRowLabelSize( 0 );
	gLectores->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	gLectores->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	sizerLectores->Add( gLectores, 1, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	pGrillaLectores->SetSizer( sizerLectores );
	pGrillaLectores->Layout();
	sizerLectores->Fit( pGrillaLectores );
	m_notebook2->AddPage( pGrillaLectores, wxT("Lectores"), false );
	pGrillaPrestamos = new wxPanel( m_notebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* sizerPrestamos;
	sizerPrestamos = new wxBoxSizer( wxHORIZONTAL );
	
	gPrestamos = new wxGrid( pGrillaPrestamos, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	gPrestamos->CreateGrid( 0, 4 );
	gPrestamos->EnableEditing( false );
	gPrestamos->EnableGridLines( true );
	gPrestamos->EnableDragGridSize( false );
	gPrestamos->SetMargins( 0, 0 );
	
	// Columns
	gPrestamos->SetColSize( 0, 180 );
	gPrestamos->SetColSize( 1, 149 );
	gPrestamos->SetColSize( 2, 120 );
	gPrestamos->SetColSize( 3, 114 );
	gPrestamos->EnableDragColMove( false );
	gPrestamos->EnableDragColSize( true );
	gPrestamos->SetColLabelSize( 30 );
	gPrestamos->SetColLabelValue( 0, wxT("Libro") );
	gPrestamos->SetColLabelValue( 1, wxT("Lector") );
	gPrestamos->SetColLabelValue( 2, wxT("Fecha Entrega") );
	gPrestamos->SetColLabelValue( 3, wxT("Préstamo Hasta") );
	gPrestamos->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	gPrestamos->EnableDragRowSize( true );
	gPrestamos->SetRowLabelSize( 0 );
	gPrestamos->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	gPrestamos->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	sizerPrestamos->Add( gPrestamos, 1, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	pGrillaPrestamos->SetSizer( sizerPrestamos );
	pGrillaPrestamos->Layout();
	sizerPrestamos->Fit( pGrillaPrestamos );
	m_notebook2->AddPage( pGrillaPrestamos, wxT("Préstamos"), false );
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
	gSanciones->SetColLabelValue( 1, wxT("Sanción Hasta") );
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
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );
	
	bPrestamo = new wxButton( this, wxID_ANY, wxT("+ Préstamo"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( bPrestamo, 0, wxALL, 5 );
	
	bDevolucion = new wxButton( this, wxID_ANY, wxT("+ Devolución"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( bDevolucion, 0, wxALL, 5 );
	
	bSancion = new wxButton( this, wxID_ANY, wxT("+ Sanción"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( bSancion, 0, wxALL, 5 );
	
	
	bSizer2->Add( bSizer5, 0, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer2 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( mAgregarLibro->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( VentanaPrincipal::ClickAgregarLibroMenu ) );
	this->Connect( mEliminarLibro->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( VentanaPrincipal::ClickEliminarLibroMenu ) );
	this->Connect( mAgregarLector->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( VentanaPrincipal::ClickAgregarLectorMenu ) );
	this->Connect( mAgregarPrestamo->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( VentanaPrincipal::ClickAgregarPrestamoMenu ) );
	this->Connect( mAgregarDevolucion->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( VentanaPrincipal::ClickAgregarDevolucionMenu ) );
	this->Connect( mAgregarSancion->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( VentanaPrincipal::ClickAgregarSancionMenu ) );
	pGrillaLibros->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( VentanaPrincipal::ClickPestaniaLibros ), NULL, this );
	gLibros->Connect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( VentanaPrincipal::DClickGrillaLibro ), NULL, this );
	bBusquedaTitulo->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaPrincipal::ClickBusquedaPorTitulo ), NULL, this );
	pGrillaLectores->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( VentanaPrincipal::ClickPestaniaLectores ), NULL, this );
	pGrillaPrestamos->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( VentanaPrincipal::ClickPestaniaPrestamos ), NULL, this );
	pGrillaSanciones->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( VentanaPrincipal::ClickPestaniaSanciones ), NULL, this );
	bPrestamo->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaPrincipal::ClickAgregarPrestamoMenu ), NULL, this );
	bDevolucion->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaPrincipal::ClickAgregarDevolucionMenu ), NULL, this );
	bSancion->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaPrincipal::ClickAgregarSancionMenu ), NULL, this );
}

VentanaPrincipal::~VentanaPrincipal()
{
	// Disconnect Events
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( VentanaPrincipal::ClickAgregarLibroMenu ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( VentanaPrincipal::ClickEliminarLibroMenu ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( VentanaPrincipal::ClickAgregarLectorMenu ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( VentanaPrincipal::ClickAgregarPrestamoMenu ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( VentanaPrincipal::ClickAgregarDevolucionMenu ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( VentanaPrincipal::ClickAgregarSancionMenu ) );
	pGrillaLibros->Disconnect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( VentanaPrincipal::ClickPestaniaLibros ), NULL, this );
	gLibros->Disconnect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( VentanaPrincipal::DClickGrillaLibro ), NULL, this );
	bBusquedaTitulo->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaPrincipal::ClickBusquedaPorTitulo ), NULL, this );
	pGrillaLectores->Disconnect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( VentanaPrincipal::ClickPestaniaLectores ), NULL, this );
	pGrillaPrestamos->Disconnect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( VentanaPrincipal::ClickPestaniaPrestamos ), NULL, this );
	pGrillaSanciones->Disconnect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( VentanaPrincipal::ClickPestaniaSanciones ), NULL, this );
	bPrestamo->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaPrincipal::ClickAgregarPrestamoMenu ), NULL, this );
	bDevolucion->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaPrincipal::ClickAgregarDevolucionMenu ), NULL, this );
	bSancion->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VentanaPrincipal::ClickAgregarSancionMenu ), NULL, this );
	
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
	
	m_staticText17 = new wxStaticText( this, wxID_ANY, wxT("Teléfono:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText17->Wrap( -1 );
	bSizer18->Add( m_staticText17, 0, wxALL, 5 );
	
	tTelefono = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer18->Add( tTelefono, 1, wxALL, 5 );
	
	
	bSizer12->Add( bSizer18, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer20;
	bSizer20 = new wxBoxSizer( wxHORIZONTAL );
	
	bCancelar = new wxButton( this, wxID_ANY, wxT("Cancelar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer20->Add( bCancelar, 0, wxALL, 5 );
	
	bAgregarLector = new wxButton( this, wxID_ANY, wxT("Agregar"), wxDefaultPosition, wxDefaultSize, 0 );
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

VentanaAgregarLibro::VentanaAgregarLibro( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText13 = new wxStaticText( this, wxID_ANY, wxT("Título: "), wxDefaultPosition, wxDefaultSize, 0 );
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
	
	m_staticText17 = new wxStaticText( this, wxID_ANY, wxT("Edición: "), wxDefaultPosition, wxDefaultSize, 0 );
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
	
	bAgregarLibro = new wxButton( this, wxID_ANY, wxT("Agregar"), wxDefaultPosition, wxDefaultSize, 0 );
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
