#include "Application.h"
#include "Vprincipal.h"
#include <wx/image.h>

IMPLEMENT_APP(mxApplication)

bool mxApplication::OnInit() {
	wxInitAllImageHandlers();
	//new VPrincipal(NULL);

	Vprincipal *p = new Vprincipal(NULL);
	p->Show();
		
	return true;
}

