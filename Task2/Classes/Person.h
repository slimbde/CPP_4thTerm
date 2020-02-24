#pragma once


namespace Task2
{

	using namespace System;



	ref class Person
	{

	public:
		property int Id {
			int get() { return id; }
		}
		property String^ FullName {
			String^ get() { return fullName; }
			void set(String^ value) { fullName = value; }
		}
		property String^ Company {
			String^ get() { return company; }
			void set(String^ value) { company = value; }
		}
		property String^ WorkDomain {
			String^ get() { return workDomain; }
			void set(String^ value) { workDomain = value; }
		}
		property String^ Fancies {
			String^ get() { return fancies; }
			void set(String^ value) { fancies = value; }
		}

		Person(String^ info)
		{
			auto strokes = info->Split('#');

			this->id = Convert::ToInt32(strokes[0]);
			this->fullName = strokes[1] + " " + strokes[2] + " " + strokes[3];
			this->company = strokes[4];
			this->workDomain = strokes[5];
			this->fancies = strokes[6];
		}


	private:
		int id;
		String^ fullName;
		String^ company;
		String^ workDomain;
		String^ fancies;
	};

}