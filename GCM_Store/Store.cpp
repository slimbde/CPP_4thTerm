#include "Store.h"
#include "Classes/Oil.h"
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
	factory->OilType = gcnew List<Type^>();
	factory->OilType->Add(Castrol::typeid);
	factory->OilType->Add(Mobil::typeid);
	factory->OilType->Add(Total::typeid);
	factory->OilType->Add(Shell::typeid);

	auto dealer = gcnew StockDealer(factory);

	Application::Run(gcnew GCMStore::Store(dealer));

	return 0;
}