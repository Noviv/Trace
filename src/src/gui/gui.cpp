#include "gui/gui.h"

wxBEGIN_EVENT_TABLE(TraceFrame, wxFrame)
EVT_MENU(ID_EXIT, TraceFrame::OnExit)
EVT_MENU(ID_ABOUT, TraceFrame::OnAbout)
wxEND_EVENT_TABLE()
DECLARE_APP(MyApp)
IMPLEMENT_APP_NO_MAIN(MyApp)

bool MyApp::OnInit() {
	TraceFrame* frame = new TraceFrame("Trace", wxPoint(100, 100), wxSize(800, 600));
	return true;
}

TraceFrame::TraceFrame(const wxString& title, const wxPoint& pos, const wxSize& size) : wxFrame(NULL, wxID_ANY, title, pos, size) {
	//trace menu
	fileMenu = new wxMenu;
	fileMenu->Append(wxID_EXIT);

	//about menu
	aboutMenu = new wxMenu;
	aboutMenu->Append(wxID_ABOUT);

	//menu bar
	menuBar = new wxMenuBar;
	menuBar->Append(fileMenu, "&Trace");
	menuBar->Append(aboutMenu, "&About");

	//console
	console = new wxTextCtrl(this, ID_CONSOLE, wxT(""), wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_RICH);

	//init
	SetMenuBar(menuBar);
	CreateStatusBar();

	//finalize window
	SetStatusText("Welcome to Trace!");
	Show(true);

	for (int i = 0; i < 100; i++) {
		console->AppendText(wxString::Format(wxT("%d\n"), i));
	}
}

void TraceFrame::OnAbout(wxCommandEvent& event) {
	wxMessageBox("Trace is a network sniffing application.", "About Trace", wxOK | wxICON_INFORMATION);
}

void TraceFrame::OnExit(wxCommandEvent& event) {
	Close(true);
	exit(0);
}