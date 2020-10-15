#include "wMain.h"

wxBEGIN_EVENT_TABLE(wMain, wxFrame) //

EVT_MENU(wxID_OPEN, wMain::OnMenuFileOpen)
EVT_MENU(wxID_SAVE, wMain::OnMenuFileSave)
EVT_MENU(wxID_EXIT, wMain::OnMenuFileQuit)
EVT_MENU(wxID_SAVEAS, wMain::OnMenuFileSaveAs)


EVT_BUTTON(1, OnButtonClicked)

wxEND_EVENT_TABLE()

//ZWEI MAP NEW WAV, WEIL EINS DIE GEÄNDERTE VERSION IST!

wMain::wMain() : wxFrame(nullptr, wxID_ANY, "WavEdit", wxPoint(30,30), wxSize(800,600))
{
	SetBackgroundColour(wxColour(*wxWHITE));
	wav = new Wav();
	wav->ReadFromFile();

	//Menubar
	menuBar = new wxMenuBar();
	fileMenu = new wxMenu();

	fileMenu->Append(wxID_OPEN, _T("&Open"), _T("Open a Wav file"));
	fileMenu->Append(wxID_SAVE, _T("&Save"), _T("Save the Wav file"));
	fileMenu->Append(wxID_SAVEAS, _T("&Save as"), _T("Save current Wav file with a different name"));
	fileMenu->AppendSeparator();
	fileMenu->Append(wxID_EXIT, _T("&Quit"));

	menuBar->Append(fileMenu, _T("&File"));
	SetMenuBar(menuBar);



	CreateStatusBar(2);



	wxClientDC d(this);
	d.DrawRectangle(wxRect(100, 100, 100, 100));


	std::string wavValues =  wav->GetValues();
	
	

	textbox = new wxStaticText(this, 2, wavValues, wxPoint(10, 10), wxSize(200, 400));

	button1 = new wxButton(this, 1, "Click me", wxPoint(500, 400), wxSize(100, 50));
	button2 = new wxButton(this, wxID_ANY, "Click me 2", wxPoint(600, 400), wxSize(100, 50));

}


void wMain::OnMenuFileOpen(wxCommandEvent& event)
{
	//TODO: ASK IF HE WANTS TO SAVE!


	openDialog = new wxFileDialog(this, "Choose a file to open", wxEmptyString, wxEmptyString, _T("wav file (*.wav)|*.wav"), wxFD_OPEN);

	if (openDialog->ShowModal() == wxID_OK) //Pressed Open
	{
		wav->Clear();
		wav->ReadFromFile(openDialog->GetPath());
		//SetTitle("Edit - " << wav->path)
	}

	openDialog->Destroy();
	event.Skip(true);
}

void wMain::OnMenuFileSave(wxCommandEvent& event)
{

}

void wMain::OnMenuFileSaveAs(wxCommandEvent& event)
{

}

void wMain::OnMenuFileQuit(wxCommandEvent& event)
{

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