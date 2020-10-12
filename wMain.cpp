#include "wMain.h"

wxBEGIN_EVENT_TABLE(wMain, wxFrame) //

EVT_BUTTON(1, OnButtonClicked)


wxEND_EVENT_TABLE()

//ZWEI MAP NEW WAV, WEIL EINS DIE GEÄNDERTE VERSION IST!

wMain::wMain() : wxFrame(nullptr, wxID_ANY, "WavEdit", wxPoint(30,30), wxSize(800,600))
{
	SetBackgroundColour(wxColour(*wxWHITE));

	wav = new Wav();
	wav->ReadFromFile();

	std::string wavValues =  wav->GetValues();
	

	textbox = new wxStaticText(this, 2, wavValues, wxPoint(10, 10), wxSize(200, 400));


	button1 = new wxButton(this, 1, "Click me", wxPoint(500, 500), wxSize(100, 50));
	button2 = new wxButton(this, wxID_ANY, "Click me 2", wxPoint(600, 500), wxSize(100, 50));

}

void wMain::OnButtonClicked(wxCommandEvent &evt)
{
	button2->SetLabelText("Hello");
	evt.Skip();

}





wMain::~wMain()
{
	delete wav;
}