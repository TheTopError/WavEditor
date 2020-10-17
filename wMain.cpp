#include "wMain.h"

wxBEGIN_EVENT_TABLE(wMain, wxFrame) //

EVT_MENU(wxID_OPEN, wMain::OnMenuFileOpen)
EVT_MENU(wxID_SAVE, wMain::OnMenuFileSave)
EVT_MENU(wxID_EXIT, wMain::OnMenuFileQuit)
EVT_MENU(wxID_SAVEAS, wMain::OnMenuFileSaveAs)

EVT_SIZE(wMain::OnResize)

EVT_PAINT(wMain::OnPaint)


EVT_BUTTON(1, OnButtonClicked)

wxEND_EVENT_TABLE()

//ZWEI MAP NEW WAV, WEIL EINS DIE GEÄNDERTE VERSION IST!

wMain::wMain() : wxFrame(nullptr, wxID_ANY, "WavEdit", wxPoint(0,0), wxSize(1245,700))
{
	SetBackgroundColour(wxColour(*wxWHITE));


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

	CreateStatusBar(4);

	sizer = new wxBoxSizer(wxHORIZONTAL);


	sizer->Add(new wxPanel(this, 23894, wxPoint(0, 0), wxSize(0, 0)));

	wxSize size;
	size.x = 100;
	size.y = 300;

	sizer->Add(new wxPanel(this, 11111, wxDefaultPosition, size));
	sizer->Show(true);

	





	button1 = new wxButton(this, 1, "Click me", wxPoint(500, 400), wxSize(100, 50));
	button2 = new wxButton(this, wxID_ANY, "Click me 2", wxPoint(600, 400), wxSize(100, 50));

}


void wMain::OnMenuFileOpen(wxCommandEvent& event)
{
	//TODO: ASK IF HE WANTS TO SAVE!


	openDialog = new wxFileDialog(this, "Choose a file to open", wxEmptyString, wxEmptyString, _T("wav file (*.wav)|*.wav"), wxFD_OPEN);

	if (openDialog->ShowModal() == wxID_OK) //Pressed Open
	{
		
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

}

void wMain::OnPaint(wxPaintEvent& event)
{
	wxPaintDC dc(this);

	//----Boundries of Function----

	//STATT EINES RECHTECKS EIN NEUES PANEL!!
	wxPoint start;
	start.x = dc.GetSize().x / 10;
	start.y = dc.GetSize().y / 2;

	wxPoint end; //Misleading: Steht für Bottom right!!!
	end.x = dc.GetSize().x - start.x;
	end.y = dc.GetSize().y - dc.GetSize().y / 20;

	dc.DrawRectangle(wxRect(start, end));

	//Draw Wav Curve
	dc.SetPen(*wxBLUE_PEN);
	dc.SetBrush(*wxBLACK_BRUSH);
	
	int pixelSize = 1;
	
	wxPoint pos;
	for (double i = 0; i < 100; i+=0.2) //Index als 0.1 schritt sehen, nicht als 1 x
	{
		
		//ALS ENDWERT FÜR i ENDWERT DES PANELS NUTZEN

		pos.x = start.x + i;
		pos.y = start.y + (i * i)/10;

		if (pos.x < start.x || pos.x + pixelSize > end.x || pos.y < start.y || pos.y + pixelSize > end.y) continue;
		dc.DrawRectangle(wxRect(pos, wxPoint(pos.x + pixelSize, pos.y + pixelSize)));
		
	}
	


}

void wMain::OnResize(wxSizeEvent& event)
{
	this->Refresh();
	this->Update();
}







wMain::~wMain()
{
}