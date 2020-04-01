#pragma once
#include "Barrel.h"
using namespace System;
using namespace System::Collections;
using namespace System::Collections::Generic;


namespace GCMStore
{

	ref class Package
	{

	public: property int Id {int get() { return id; } private: void set(int value) { } }
	public: property Generic::Stack<Barrel^>^ Items;

	public: Package() { Items = gcnew Generic::Stack<Barrel^>(); }
	public: void SetId(int num) { id = num; }
	public: String^ ToString() override
	{
		String^ result = String::Concat("Заказ: ", id, "\n");
		double price = 0.0;

		for each (auto item in Items)
		{
			result += String::Concat(item, "\n");
			price += item->Cost;
		}
		result += String::Concat("Стоимость: ", price, " у.е.");

		return String::Concat(result, "\n");
	}

	private: int id;
	};

}