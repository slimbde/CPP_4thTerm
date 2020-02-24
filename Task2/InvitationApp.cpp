#include "InvitationApp.h"
using namespace System;
using namespace System::Windows::Forms;


[STAThreadAttribute]
Int32 main(array<System::String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew Task2::InvitationApp());

	return 0;
}