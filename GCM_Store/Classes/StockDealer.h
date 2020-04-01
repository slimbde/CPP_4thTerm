#pragma once
#include "Order.h"
#include "Package.h"
#include "Barrel.h"
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

			auto init = gcnew voidVoidDelegate(this, &StockDealer::buildStock);
			auto callback = gcnew AsyncCallback(this, &StockDealer::exposeContent);
			init->BeginInvoke(callback, nullptr);
		}
		int ApplyOrder(Order^ order)
		{
			order->SetId(++count);
			orders->Enqueue(order);

			double cost = 0.0;
			status = gcnew Generic::List<String^>();
			status->Add(String::Concat(String::Concat(DateTime::Now.ToShortTimeString(), " - зарегистрирован заказ id: ", count)));
			for each (auto oil in order->Items)
			{
				cost += oil->Price * oil->Quantity;
				status->Add(String::Concat(DateTime::Now.ToShortTimeString(), " - ", oil->ToString()));
			}
			status->Add(String::Concat("К оплате: ", cost, " р."));
			status->Add("");

			onOrderApplying(this, EventArgs::Empty);

			auto doWork = gcnew voidVoidDelegate(this, &StockDealer::ProcessOrders);
			doWork->BeginInvoke(nullptr, nullptr);

			return count;
		}
		void ProcessOrders()
		{
			System::Threading::Thread::Sleep(5000);

			// clear Status
			status = gcnew Generic::List<String^>();

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
					auto stockBarrel = stock->Dequeue();
					auto vatUsed = false;

					for each (auto orderOil in order->Items)
					{
						if (orderOil->Quantity > 0)
						{
							if (stockBarrel->ContentType == orderOil->GetType() && orderOil->Quantity >= stockBarrel->Capacity)
							{
								package->Items->Push(stockBarrel);			// (*)	when you withdraw a barrel, the stock vats count decreases.
								orderOil->Quantity -= stockBarrel->Capacity;	//		decreasing affects stock count of FOR cycle
								vatUsed = true;
								break;
							}
						}
					}

					if (!vatUsed)
						stock->Enqueue(stockBarrel); // put the barrel back
				}

				if (order->Complete)
				{
					packages->Add(package->Id, package);
					status->Add(String::Concat(String::Concat(DateTime::Now.ToShortTimeString(), " - заказ id: ", package->Id, ": ", "готов к выдаче")));
					status->Add("");

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

					auto message = String::Concat("не собрано: ", order->GetRest());

					// write error
					if (!errors->ContainsKey(order->Id))
						errors->Add(order->Id, message);
					else
						errors[order->Id] = message;

					status->Add(String::Concat(String::Concat(DateTime::Now.ToShortTimeString(), " - ", order->Id, ": ", errors[order->Id])));
					status->Add("необходимо пополнить склад");
					status->Add("");
					orders->Enqueue(order); // put the order back in line
				}
			}

			exposeContent(nullptr);
			onStopProcessing(this, EventArgs::Empty);
		}
		void ReplenishWith(int num)
		{
			auto extra = factory->CreateMore(num);

			while (extra->Count > 0)
				stock->Enqueue(extra->Pop());

			status = gcnew Generic::List<String^>();
			status->Add(String::Concat("Склад пополнен бочками в количестве: ", num, " шт."));
			status->Add("");
			exposeContent(nullptr);

			onReplentish(this, EventArgs::Empty);
		}
		bool CompleteOrder(int id)
		{
			return packages->ContainsKey(id);
		}
		Package^ RetrievePackage(int id)
		{
			if (packages->ContainsKey(id))
			{
				status = gcnew Generic::List<String^>();
				status->Add(String::Concat(String::Concat(DateTime::Now.ToShortTimeString(), "\tвыдан заказ id: ", id)));
				status->Add("");
				onOrderRetrieving(this, EventArgs::Empty);

				return packages[id];
			}

			return nullptr;
		}

		event EventHandler^ onOrderApplying;
		event EventHandler^ onStopProcessing;
		event EventHandler^ onOrderRetrieving;
		event EventHandler^ onReplentish;

	private:
		Generic::Queue<Barrel^>^ stock;
		Generic::Queue<Order^>^ orders;
		Dictionary<int, Package^>^ packages;
		Dictionary<int, Package^>^ assembles;
		Dictionary<int, String^>^ errors;
		StockFactory^ factory;
		Generic::List<String^>^ status;
		static int count = 0;

		void buildStock()
		{
			auto factoryStock = factory->Create();
			stock = gcnew Generic::Queue<Barrel^>();

			while (factoryStock->Count)
				stock->Enqueue(factoryStock->Pop());

			orders = gcnew Generic::Queue<Order^>();
			packages = gcnew Dictionary<int, Package^>();
			assembles = gcnew Dictionary<int, Package^>();
			errors = gcnew Dictionary<int, String^>();
		}
		void exposeContent(IAsyncResult^ result)
		{
			auto oils = gcnew Dictionary<Type^, Oil^>();

			for each (auto barrel in stock)
			{
				if (!oils->ContainsKey(barrel->ContentType))
					oils->Add(barrel->ContentType, (Oil^)Activator::CreateInstance(barrel->ContentType, gcnew array<Object^>{barrel->Capacity}));
				else
					oils[barrel->ContentType]->Quantity += barrel->Capacity;
			}

			if (status == nullptr)
				status = gcnew List<String^>();

			status->Add("остатки на складе:");
			for each (auto oil in oils)
				status->Add(String::Concat(DateTime::Now.ToShortTimeString(), " - ", oil.Value->ToString()));
			status->Add("");
		}
	};

}