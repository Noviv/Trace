#ifndef GUI_H
#define GUI_H

#define __WXMSW__
#include <wx/wx.h>

class MyApp : public wxApp {
public:
	virtual bool OnInit();
};

class TraceFrame : public wxFrame {
public:
	TraceFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
private:
	wxMenu* fileMenu;
	wxMenu* aboutMenu;
	wxMenuBar* menuBar;

	wxTextCtrl* console;

	void OnExit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);	
	wxDECLARE_EVENT_TABLE();
};

enum {
	ID_EXIT = wxID_EXIT,
	ID_ABOUT = wxID_ABOUT,
	ID_CONSOLE = wxID_HIGHEST + 1
};

#endif