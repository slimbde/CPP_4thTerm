#include "Store.h"
#include "Classes/StockDealer.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace GCMStore;


[STAThreadAttribute]
Int32 main(array<System::String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	auto factory = gcnew StockFactory();
	auto dealer = gcnew StockDealer(factory);

	Application::Run(gcnew GCMStore::Store(dealer));

	return 0;
}