#include "Store.h"
#include "Classes/Order.h"
#include "Classes/StockDealer.h"
#include "Classes/StockFactory.h"
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace GSMStore;


[STAThreadAttribute]
Int32 main(array<System::String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	//Application::Run(gcnew GCMStore::Store());

	auto factory = gcnew StockFactory();
	auto dealer = gcnew StockDealer(factory->Create());

	auto order1 = gcnew Order();
	order1->Add(gcnew Shell(500));
	order1->Add(gcnew Mobil(200));
	order1->Add(gcnew Total(500));

	auto order2 = gcnew Order();
	order2->Add(gcnew Castrol(100));
	order2->Add(gcnew Shell(200));
	order2->Add(gcnew Total(1300));

	auto numOrder1 = dealer->ApplyOrder(order1);
	auto numOrder2 = dealer->ApplyOrder(order2);

	dealer->ProcessOrders();

	Console::WriteLine(dealer->GetOrderStatus(numOrder1));
	Console::WriteLine(dealer->GetOrderStatus(numOrder2));

	auto package1 = dealer->RetrievePackage(numOrder1);
	auto package2 = dealer->RetrievePackage(numOrder2);

	Console::WriteLine(package1);
	Console::WriteLine(package2);

	Console::ReadKey();
	return 0;
}