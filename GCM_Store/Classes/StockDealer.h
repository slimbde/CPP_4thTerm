#pragma once
#include "Order.h"
#include "Package.h"
#include "Bowl.h"
#include "StockFactory.h"
using namespace System;
using namespace System::Collections::Generic;


namespace GCMStore
{
	delegate void voidVoidDelegate();


	ref class StockDealer
	{
	public: property Generic::List<String^>^ Status { Generic::List<String^>^ get() { return status; } }

	public:
		StockDealer(StockFactory^ stockFactory)
		{
			factory = stockFactory;

			auto factoryStock = factory->Create();
			stock = gcnew Generic::Queue<Bowl^>();

			while (factoryStock->Count)
				stock->Enqueue(factoryStock->Pop());

			orders = gcnew Generic::Queue<Order^>();
			packages = gcnew Dictionary<int, Package^>();
			assembles = gcnew Dictionary<int, Package^>();
			errors = gcnew Dictionary<int, String^>();

			status = gcnew List<String^>();
			status->Add("Содержимое склада:");
			for each (auto item in stock)
				status->Add(item->ToString());

			onBuild(this, EventArgs::Empty);
		}
		int ApplyOrder(Order^ order)
		{
			order->SetId(++count);
			orders->Enqueue(order);

			status = gcnew Generic::List<String^>();
			status->Add(String::Concat("Заказ зарегистрирован под номером: ", count));
			onOrderApplying(this, EventArgs::Empty);

			auto doWork = gcnew voidVoidDelegate(this, &StockDealer::ProcessOrders);
			doWork->BeginInvoke(nullptr, nullptr);

			return count;
		}
		void ProcessOrders()
		{
			System::Threading::Thread::Sleep(5000);

			auto initialOrdersCount = orders->Count;	// (*)
			for (int o = 0; o < initialOrdersCount; ++o)
			{
				auto order = orders->Dequeue();

				// retrieve half assembled package of the Id if exists
				Package^ package;
				if (assembles->ContainsKey(order->Id))
					package = assembles[order->Id];
				else
				{
					package = gcnew Package();
					package->SetId(order->Id);
				}

				auto initialStockCount = stock->Count;	// (*)
				for (int b = 0; b < initialStockCount; ++b)
				{
					auto stockBowl = stock->Dequeue();
					auto bowlUsed = false;

					for each (auto orderOil in order->Items)
					{
						if (orderOil->Quantity > 0)
						{
							if (stockBowl->ContentType == orderOil->GetType() && orderOil->Quantity >= stockBowl->Capacity)
							{
								package->Items->Push(stockBowl);			// (*)	when you withdraw a bowl, the stock bowls count decreases.
								orderOil->Quantity -= stockBowl->Capacity;	//		decreasing affects stock count of FOR cycle
								bowlUsed = true;
								break;
							}
						}
					}

					if (!bowlUsed)
						stock->Enqueue(stockBowl); // put the bowl back
				}

				if (order->Complete)
				{
					packages->Add(package->Id, package);

					// clear error entries
					if (errors->ContainsKey(package->Id))
						errors->Remove(package->Id);
				}
				else
				{
					// store half assembled package
					if (!assembles->ContainsKey(order->Id))
						assembles->Add(package->Id, package);
					else
						assembles[package->Id] = package;

					auto message = String::Concat("Не удалось собрать:\t", order->GetRest());

					// write error
					if (!errors->ContainsKey(order->Id))
						errors->Add(order->Id, message);
					else
						errors[order->Id] = message;

					orders->Enqueue(order); // put the order back in line
				}
			}

			//---------------------------------------------------------------- alter status ---------
			status = gcnew Generic::List<String^>();
			for each (auto package in packages)
			{
				String^ result = String::Concat("Заказ ", package.Key, ": ");

				if (errors->ContainsKey(package.Key))
					status->Add(String::Concat(result, errors[package.Key]));
				else
					status->Add(String::Concat(result, "готов к выдаче"));
			}

			onStopProcessing(this, EventArgs::Empty);
		}
		void ReplenishWith(int num)
		{
			auto extra = factory->CreateMore(num);

			while (extra->Count > 0)
				stock->Enqueue(extra->Pop());

			status = gcnew Generic::List<String^>();
			status->Add(String::Concat("Склад пополнен бочками в количестве: ", num, " шт."));
			onReplentish(this, EventArgs::Empty);
		}
		Package^ RetrievePackage(int id)
		{
			if (packages->ContainsKey(id))
				return packages[id];

			return nullptr;
		}

		event EventHandler^ onBuild;
		event EventHandler^ onOrderApplying;
		event EventHandler^ onStopProcessing;
		event EventHandler^ onReplentish;

	private:
		Generic::Queue<Bowl^>^ stock;
		Generic::Queue<Order^>^ orders;
		Dictionary<int, Package^>^ packages;
		Dictionary<int, Package^>^ assembles;
		Dictionary<int, String^>^ errors;
		StockFactory^ factory;
		Generic::List<String^>^ status;
		static int count = 0;
	};

}