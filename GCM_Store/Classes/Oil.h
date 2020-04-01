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
			return String::Concat("����� Castrol: ", quantity, " ������ >> ", Price, " �./����");
		}
	};


	ref class Mobil : Oil
	{

	public:
		Mobil(int quantity) : Oil(quantity) { }
		property double Price { double get() override { return 1800.3; }}


		virtual String^ ToString() override
		{
			return String::Concat("����� Mobil: ", quantity, " ������ >> ", Price, " �./����");
		}
	};


	ref class Total : Oil
	{

	public:
		Total(int quantity) : Oil(quantity) { }
		property double Price { double get() override { return 980.4; }}


		virtual String^ ToString() override
		{
			return String::Concat("����� Total: ", quantity, " ������ >> ", Price, " �./����");
		}
	};


	ref class Shell : Oil
	{

	public:
		Shell(int quantity) : Oil(quantity) { }
		property double Price { double get() override { return 1017.5; }}


		virtual String^ ToString() override
		{
			return String::Concat("����� Shell: ", quantity, " ������ >> ", Price, " �./����");
		}
	};

}