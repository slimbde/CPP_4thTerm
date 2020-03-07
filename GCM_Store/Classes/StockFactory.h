#pragma once
#include "Bowl.h"
using namespace System;
using namespace System::Collections;
using namespace System::Collections::Generic;


namespace GCMStore
{

	ref class StockFactory
	{

	public: property List<Type^>^ OilType;

	public: StockFactory()
	{
		OilType = gcnew List<Type^>();
		OilType->Add(Castrol::typeid);
		OilType->Add(Mobil::typeid);
		OilType->Add(Total::typeid);
		OilType->Add(Shell::typeid);
	}
	public: Generic::Stack<Bowl^>^ Create()
	{
		// случайным образом организованный склад
		auto rnd = gcnew Random();

		// заполнение склада бочками
		auto stock = gcnew Generic::Stack<Bowl^>();
		for (int i = 0; i < 50; ++i)
		{
			auto oil = (Oil^)Activator::CreateInstance(OilType[rnd->Next(OilType->Count)], gcnew array<Object^>{i < 30 ? 100 : 200});

			Bowl^ bowl = gcnew LargeBowl();
			if (oil->Quantity == 100)
				bowl = gcnew MediumBowl();

			bowl->PourWith(oil);
			stock->Push(bowl);
		}

		return stock;
	}
	public: Generic::Stack<Bowl^>^ CreateMore(int num)
	{
		// случайным образом организованный склад
		auto rnd = gcnew Random();

		// заполнение склада бочками
		auto stock = gcnew Generic::Stack<Bowl^>();
		for (int i = 0; i < num; ++i)
		{
			auto oil = (Oil^)Activator::CreateInstance(OilType[rnd->Next(OilType->Count)], gcnew array<Object^>{i < (num * 2 / 3) ? 100 : 200});

			Bowl^ bowl = gcnew LargeBowl();
			if (oil->Quantity == 100)
				bowl = gcnew MediumBowl();

			bowl->PourWith(oil);
			stock->Push(bowl);
		}

		return stock;
	}

	};

}