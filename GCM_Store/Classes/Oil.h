#pragma once
using namespace System;


namespace GCMStore
{

	ref class Oil abstract
	{

	public:
		property int Quantity {
			int get() { return quantity; }
			void set(int value) { quantity = value; }
		}
		virtual property double Price;

		Oil(int quantity) { this->quantity = quantity; }

	protected:
		int quantity;
	};



	ref class Castrol : Oil
	{

	public:
		Castrol(int quantity) : Oil(quantity) { }
		property double Price { double get() override { return 2000.5; }}


		virtual String^ ToString() override
		{
			return String::Concat("масло Castrol: ", quantity, " литров >> ", Price, " р./литр");
		}
	};


	ref class Mobil : Oil
	{

	public:
		Mobil(int quantity) : Oil(quantity) { }
		property double Price { double get() override { return 1800.3; }}


		virtual String^ ToString() override
		{
			return String::Concat("масло Mobil: ", quantity, " литров >> ", Price, " р./литр");
		}
	};


	ref class Total : Oil
	{

	public:
		Total(int quantity) : Oil(quantity) { }
		property double Price { double get() override { return 980.4; }}


		virtual String^ ToString() override
		{
			return String::Concat("масло Total: ", quantity, " литров >> ", Price, " р./литр");
		}
	};


	ref class Shell : Oil
	{

	public:
		Shell(int quantity) : Oil(quantity) { }
		property double Price { double get() override { return 1017.5; }}


		virtual String^ ToString() override
		{
			return String::Concat("масло Shell: ", quantity, " литров >> ", Price, " р./литр");
		}
	};

}