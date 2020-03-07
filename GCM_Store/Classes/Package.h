#pragma once
#include "Bowl.h"
using namespace System;
using namespace System::Collections;
using namespace System::Collections::Generic;


namespace GCMStore
{

	ref class Package
	{

	public: property int Id {int get() { return id; } private: void set(int value) { } }
	public: property Generic::Stack<Bowl^>^ Items;

	public: Package() { Items = gcnew Generic::Stack<Bowl^>(); }
	public: void SetId(int num) { id = num; }
	public: String^ ToString() override
	{
		String^ result = String::Concat("\n---------------------------------------------\nЗаказ: ", id, "\n");
		for each (auto item in Items)
			result += String::Concat(item, "\n");

		return String::Concat(result, "\n");
	}

	private: int id;
	};

}