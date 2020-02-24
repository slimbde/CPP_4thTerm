#pragma once
#include "Oil.h"
using namespace System;
using namespace System::Collections::Generic;


namespace GSMStore
{

	ref class Order
	{

	public: property int Id {int get() { return id; } private: void set(int value) { } }
	public: property List<Oil^>^ Scroll;

	public: Order() { Scroll = gcnew List<Oil^>(); }
	public: void SetId(int num) { id = num; }
	public: void Add(Oil^ oil) { Scroll->Add(oil); }

	private: int id;
	};

}