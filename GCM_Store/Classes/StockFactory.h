#pragma once
#include "Barrel.h"
using namespace System;
using namespace System::Collections;
using namespace System::Collections::Generic;


namespace GCMStore
{

	ref class StockFactory
	{

	public: property List<Type^>^ OilType;

	public: Generic::Stack<Barrel^>^ Create()
	{
		// ��������� ������� �������������� �����
		auto rnd = gcnew Random();

		// ���������� ������ �������
		auto stock = gcnew Generic::Stack<Barrel^>();
		for (int i = 0; i < 50; ++i)
		{
			auto oil = (Oil^)Activator::CreateInstance(OilType[rnd->Next(OilType->Count)], gcnew array<Object^>{i < 30 ? 100 : 200});

			Barrel^ barrel = gcnew LargeBarrel();
			if (oil->Quantity == 100)
				barrel = gcnew MediumBarrel();

			barrel->PourWith(oil);
			stock->Push(barrel);
		}

		return stock;
	}
	public: Generic::Stack<Barrel^>^ CreateMore(int num)
	{
		// ��������� ������� �������������� �����
		auto rnd = gcnew Random();

		// ���������� ������ �������
		auto stock = gcnew Generic::Stack<Barrel^>();
		for (int i = 0; i < num; ++i)
		{
			auto oil = (Oil^)Activator::CreateInstance(OilType[rnd->Next(OilType->Count)], gcnew array<Object^>{i < (num * 2 / 3) ? 100 : 200});

			Barrel^ barrel = gcnew LargeBarrel();
			if (oil->Quantity == 100)
				barrel = gcnew MediumBarrel();

			barrel->PourWith(oil);
			stock->Push(barrel);
		}

		return stock;
	}

	};

}