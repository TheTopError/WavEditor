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

	wxButton* button1 = nullptr;
	wxButton* button2 = nullptr;

	wxStaticText* textbox = nullptr;

	void OnButtonClicked(wxCommandEvent& evt);

	wxDECLARE_EVENT_TABLE();


};

