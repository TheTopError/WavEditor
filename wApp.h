#pragma once

#include "wx/wx.h";
#include "wMain.h"
#include <memory>

class wApp : public wxApp //Launcher
{
public:
	wApp();
	~wApp();

private:
	wMain* frame1;

public:
	virtual bool OnInit();

};