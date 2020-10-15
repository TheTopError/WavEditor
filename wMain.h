#pragma once

#include "wx/wx.h";

#include "Wav.h"


class wMain : public wxFrame //GUI implementation
{

public:
	wMain();
	~wMain();

public:
	Wav* wav;

	wxMenuBar* menuBar;
	wxMenu* fileMenu;
	void OnMenuFileOpen(wxCommandEvent& event);
	void OnMenuFileSave(wxCommandEvent& event);
	void OnMenuFileSaveAs(wxCommandEvent& event);
	void OnMenuFileQuit(wxCommandEvent& event);

	wxFileDialog* openDialog;


	wxButton* button1 = nullptr;
	wxButton* button2 = nullptr;


	wxStaticText* textbox = nullptr;

	void OnButtonClicked(wxCommandEvent& evt);

	enum
	{
		//IDs: wxIDS_HIGHEST +1
	};

	wxDECLARE_EVENT_TABLE();




};

