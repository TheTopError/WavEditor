#pragma once

#include "wx/wx.h";



class wMain : public wxFrame //GUI implementation
{

public:
	wMain();
	~wMain();

public:

	wxMenuBar* menuBar;
	wxMenu* fileMenu;
	void OnMenuFileOpen(wxCommandEvent& event);
	void OnMenuFileSave(wxCommandEvent& event);
	void OnMenuFileSaveAs(wxCommandEvent& event);
	void OnMenuFileQuit(wxCommandEvent& event);

	wxFileDialog* openDialog;

	wxBoxSizer* sizer;
	wxPanel* wavePanel;


	wxButton* button1 = nullptr;
	wxButton* button2 = nullptr;


	wxStaticText* textbox = nullptr;

	void OnButtonClicked(wxCommandEvent& evt);

	void OnPaint(wxPaintEvent& event);
	void OnResize(wxSizeEvent& event);


	enum
	{
		//IDs: wxIDS_HIGHEST +1
	};

	wxDECLARE_EVENT_TABLE();




};

