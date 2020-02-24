#include "EvenSimple.h"
using namespace System;
using namespace System::Windows::Forms;


[STAThreadAttribute]
Int32 main(array<System::String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew Task1::EvenSimple());

	return 0;
}