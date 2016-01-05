#include "gui/gui.h"

wxBEGIN_EVENT_TABLE(TraceFrame, wxFrame)
EVT_MENU(wxID_EXIT, TraceFrame::OnExit)
EVT_MENU(wxID_ABOUT, TraceFrame::OnAbout)
wxEND_EVENT_TABLE()
DECLARE_APP(MyApp)
IMPLEMENT_APP_NO_MAIN(MyApp)

bool MyApp::OnInit() {
	TraceFrame *frame = new TraceFrame("Trace", wxPoint(50, 50), wxSize(800, 600));
	return true;
}

TraceFrame::TraceFrame(const wxString& title, const wxPoint& pos, const wxSize& size) : wxFrame(NULL, wxID_ANY, title, pos, size) {
	//file
	wxMenu *menuFile = new wxMenu;
	menuFile->Append(wxID_EXIT);

	//help
	wxMenu *menuHelp = new wxMenu;
	menuHelp->Append(wxID_ABOUT);

	//menu bar
	wxMenuBar *menuBar = new wxMenuBar;
	menuBar->Append(menuFile, "&Trace");
	menuBar->Append(menuHelp, "&Help");

	//init
	SetMenuBar(menuBar);
	CreateStatusBar();
	SetStatusText("Welcome to Trace!");
	Show(true);
}

void TraceFrame::OnExit(wxCommandEvent& event) {
	Close(true);
	exit(0);
}

void TraceFrame::OnAbout(wxCommandEvent& event) {
	wxMessageBox("Trace is a network sniffing application.", "About Trace", wxOK | wxICON_INFORMATION);
}