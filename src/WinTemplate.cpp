// WinTemplate.cpp: Hauptprojektdatei.

#include "Form\FormMain.h"

using namespace Statistica;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Aktivieren visueller Effekte von Windows XP, bevor Steuerelemente erstellt werden
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Hauptfenster erstellen und ausführen
	Application::Run(gcnew FormMain());
	return 0;
}
