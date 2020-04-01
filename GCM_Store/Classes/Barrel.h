#pragma once
#include "Oil.h"
using namespace System;


namespace GCMStore
{

	ref class Barrel abstract
	{

	public: virtual property int Capacity;
	public:	virtual property Type^ ContentType { Type^ get() { return content->GetType(); }	protected: void set(Type^ value) { } }
	public: property int FreeSpace { int get() { if (content == nullptr) return 0; return Capacity - content->Quantity; }  private: void set(int value) { } }
	public: property double Cost { double get() { return content->Price * Capacity; } }

	public: void PourWith(Oil^ oil)
	{
		if (content == nullptr)
		{
			if (oil->Quantity <= Capacity)
				content = oil;

			return;
		}

		auto delta = Capacity - content->Quantity;
		if (delta > 0)
		{
			auto newDelta = delta - oil->Quantity;
			if (newDelta >= 0)
				if (content->GetType() == oil->GetType())
					content->Quantity += oil->Quantity;
		}
	}
	public: Oil^ PourOut(int quantity)
	{
		auto delta = content->Quantity - quantity;
		if (delta <= 0)
		{
			quantity = content->Quantity;
			content = nullptr;
		}
		else
			content->Quantity -= quantity;

		return (Oil^)Activator::CreateInstance(content->GetType(), gcnew array<Object^>{quantity});
	}

	protected:
		Oil^ content;
	};


	ref class MediumBarrel : Barrel
	{

	public: property int Capacity { int get() override { return 100; } }

	public: MediumBarrel() { Capacity = 100; }
	public: String^ ToString() override
	{
		String^ str = "Средняя бочка:\t";

		if (content == nullptr)
			return String::Concat(str, "пустая");

		return String::Concat(str, content);
	}

	};


	ref class LargeBarrel : Barrel
	{

	public: property int Capacity { int get() override { return 200; } }

	public: LargeBarrel() { Capacity = 200; }
	public: String^ ToString() override
	{
		String^ str = "Большая бочка:\t";

		if (content == nullptr)
			return String::Concat(str, "пустая");

		return String::Concat(str, content);
	}

	};
}