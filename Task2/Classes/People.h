#pragma once
#include "Person.h"


namespace Task2
{

	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;

	ref class People : Collections::ICollection
	{

	public:
		virtual property int Count {
			int get() { return people->Count; }
		}
		virtual property System::Object^ SyncRoot;
		virtual property bool IsSynchronized;


		People()
		{
			people = gcnew SortedDictionary<int, Person^>();
		}
		void Add(Person^ person)
		{
			people->Add(person->Id, person);
		}
		void RemoveAt(int id)
		{
			if (people->ContainsKey(id))
				people->Remove(id);
		}
		void Alter(Person^ person)
		{
			if (people->ContainsKey(person->Id))
			{
				RemoveAt(person->Id);
				Add(person);
			}
			else
				MessageBox::Show("Человек с id=" + person->Id + " не найден в базе");
		}
		int GetNextIndex()
		{
			if (people->Count == 0)
				return 1;

			int max = 0;
			for each (auto item in people)
			{
				if (item.Key > max)
					max = item.Key;
			}

			return max + 1;
		}

		// Inherited via ICollection
		virtual System::Collections::IEnumerator^ GetEnumerator()
		{
			return people->GetEnumerator();
		}
		virtual void CopyTo(System::Array^ array, int index)
		{
			throw gcnew NotImplementedException();
		}


	private:
		SortedDictionary<int, Person^>^ people;

	};

}