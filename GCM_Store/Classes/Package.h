#pragma once
#include "Bowl.h"
using namespace System;
using namespace System::Collections::Generic;


namespace GSMStore
{

	ref class Package
	{

	public: property int Id {int get() { return id; } private: void set(int value) { } }
	public: property Stack<Bowl^>^ List;

	public: Package() { List = gcnew Stack<Bowl^>(); }
	public: void SetId(int num) { id = num; }
	public: String^ ToString() override
	{
		String^ result = String::Concat("\n---------------------------------------------\nЗаказ: ", id, "\n");
		for each (auto item in List)
			result += String::Concat(item, "\n");

		return String::Concat(result, "\n");
	}

		  int id;
	};

}