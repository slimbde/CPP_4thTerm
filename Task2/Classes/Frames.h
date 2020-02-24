#pragma once
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections;
using namespace System::Drawing;

namespace Task2
{
	ref class Frame abstract : Form
	{

	public:
		Frame()
		{
			this->BackgroundImageLayout = ImageLayout::Stretch;

			font = gcnew Drawing::Font("Times New Roman", 23, FontStyle::Italic);
			brush = Brushes::Black;
		}
		void SetEvent(String^ event) { this->event = event; }
		void SetPerson(String^ person) { this->person = person; }
		void DrawContent(Object^ sender, PaintEventArgs^ args)
		{
			auto fullName = person->Split(' ');
			auto name = String::Concat(fullName[1], " ", fullName[2]);

			String^ start = "Уважаемый\n";
			auto gender = fullName[1][fullName[1]->Length - 1];
			if (gender == 1072)
				start = "Уважаемая\n";

			auto text = event->Replace(" ", "\n");
			text = String::Concat(start, name, "!\nПриглашаем Вас\nна ", text, "\n\n23.05.2020\n\nКомпания\n\"Рога и копыта\"");

			easel->DrawString(text, font, brush, point);
		}

	protected:
		String^ event;
		String^ person;
		Graphics^ easel;
		Drawing::Font^ font;
		Drawing::Brush^ brush;
		PointF point;
	};



	ref class BaloonFrame : Frame
	{

	public:
		BaloonFrame()
		{
			this->Height = 600;
			this->Width = 800;
			this->BackgroundImage = Image::FromFile("Frames/baloons.jpg");
			easel = this->CreateGraphics();
			point = PointF(330, 80);
		}
	};


	ref class FlowerFrame : Frame
	{

	public:
		FlowerFrame()
		{
			this->Height = 800;
			this->Width = 600;
			this->BackgroundImage = Image::FromFile("Frames/flowers.jpg");
			easel = this->CreateGraphics();
			point = PointF(150, 100);
		}
	};


	ref class KidsFrame : Frame
	{

	public:
		KidsFrame()
		{
			this->Height = 700;
			this->Width = 800;
			this->BackgroundImage = Image::FromFile("Frames/kids.jpg");
			easel = this->CreateGraphics();
			point = PointF(150, 80);
		}
	};


	ref class PatternFrame : Frame
	{

	public:
		PatternFrame()
		{
			this->Height = 800;
			this->Width = 600;
			this->BackgroundImage = Image::FromFile("Frames/pattern.jpg");
			easel = this->CreateGraphics();
			point = PointF(150, 150);
		}
	};

}