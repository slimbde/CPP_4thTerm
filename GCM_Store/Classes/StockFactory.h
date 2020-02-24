#pragma once
#include "Bowl.h"
using namespace System;
using namespace System::Collections::Generic;


namespace GSMStore
{

	ref class StockFactory
	{

	public: Queue<Bowl^>^ Create()
	{
		// случайным образом организованный склад
		auto oilType = gcnew List<Type^>();
		oilType->Add(Castrol::typeid);
		oilType->Add(Mobil::typeid);
		oilType->Add(Total::typeid);
		oilType->Add(Shell::typeid);

		auto rnd = gcnew Random();

		// заполнение склада бочками
		auto stock = gcnew Queue<Bowl^>();
		for (int i = 0; i < 50; ++i)
		{
			auto oil = (Oil^)Activator::CreateInstance(oilType[rnd->Next(4)], gcnew array<Object^>{i < 30 ? 100 : 200});

			Bowl^ bowl = gcnew LargeBowl();
			if (oil->Quantity == 100)
				bowl = gcnew MediumBowl();

			bowl->PourWith(oil);
			stock->Enqueue(bowl);
		}

		return stock;
	}

	};

}