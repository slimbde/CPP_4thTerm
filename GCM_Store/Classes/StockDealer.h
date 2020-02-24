#pragma once
#include "Order.h"
#include "Package.h"
#include "Bowl.h"
using namespace System;
using namespace System::Collections::Generic;


namespace GSMStore
{

	ref class StockDealer
	{

	public:
		StockDealer(Queue<Bowl^>^ stock)
		{
			this->stock = stock;
			orders = gcnew Queue<Order^>();
			packages = gcnew Dictionary<int, Package^>();
			errors = gcnew Dictionary<int, String^>();
		}
		int ApplyOrder(Order^ order)
		{
			order->SetId(++count);
			orders->Enqueue(order);

			return count;
		}
		void ProcessOrders()
		{
			auto ordersCount = orders->Count;
			for (int o = 0; o < ordersCount; ++o)
			{
				auto order = orders->Dequeue();

				auto package = gcnew Package();
				package->SetId(order->Id);

				int combineError = 0;

				for each (auto orderOil in order->Scroll)
				{
					bool oilOk = false;

					auto stockCount = stock->Count;
					for (int s = 0; s < stockCount; ++s)
					{
						// pull a bowl
						auto stockBowl = stock->Dequeue();

						if (stockBowl->ContentType == orderOil->GetType() && orderOil->Quantity >= stockBowl->Capacity)
						{
							package->List->Push(stockBowl);
							orderOil->Quantity -= stockBowl->Capacity;

							if (orderOil->Quantity <= 0)
							{
								oilOk = true;
								break;
							}
						}
						else
							stock->Enqueue(stockBowl); // place it back
					}

					if (!oilOk)
					{
						--combineError;

						auto message = String::Concat("Не удалось собрать ", orderOil);
						if (!errors->ContainsKey(order->Id))
							errors->Add(order->Id, message);
						else
							errors[order->Id] = message;

						break;
					}
				}

				if (combineError == 0)
					packages->Add(package->Id, package);
				else
					orders->Enqueue(order);
			}
		}
		Package^ RetrievePackage(int id)
		{
			if (packages->ContainsKey(id))
				return packages[id];

			return nullptr;
		}
		String^ GetOrderStatus(int id)
		{
			String^ result = String::Concat("Заказ ", id, ": ");

			if (errors->ContainsKey(id))
				return String::Concat(result, errors[id]);

			return String::Concat(result, "Нет ошибок сборки");
		}

	private:
		Queue<Bowl^>^ stock;
		Queue<Order^>^ orders;
		Dictionary<int, Package^>^ packages;
		Dictionary<int, String^>^ errors;
		static int count = 0;
	};

}