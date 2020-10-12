#include "wApp.h";

wxIMPLEMENT_APP(wApp);

wApp::wApp()
{

}


bool wApp::OnInit()
{
	frame1 = new wMain();
	frame1->Show();


	return true;
}

wApp::~wApp()
{
}