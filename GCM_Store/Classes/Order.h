#pragma once
#include "Oil.h"
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;


namespace GCMStore
{

	ref class Order : TextBox
	{

	public: property int Id { int get() { return id; } private: void set(int value) { } }
	public: property List<Oil^>^ Items;

	// показывает собран заказ или нет
	public: property bool Complete {
		bool get()
		{
			for each (auto item in Items)
				if (item->Quantity > 0)
					return false;

			return true;
		}
	}

	public: Order() { Items = gcnew List<Oil^>(); }
	public: Order(Order^ other)
	{
		Items = other->Items;
		id = other->id;
		

		BackColor = other->BackColor;
		BorderStyle = other->BorderStyle;
		Cursor = other->Cursor;
		Location = other->Location;
		Multiline = other->Multiline;
		Name = other->Name;
		ReadOnly = other->ReadOnly;
		Size = other->Size;
		Lines = other->Lines;
	}
	public: void SetId(int num) { id = num; }
	public: void Add(Oil^ oil) { Items->Add(oil); }
	public: String^ GetRest()
	{
		String^ result = "";

		for each (auto item in Items)
			if (item->Quantity > 0)
				result = String::Concat(result, item, "; ");

		return result;
	}

	private: int id;
	};

}