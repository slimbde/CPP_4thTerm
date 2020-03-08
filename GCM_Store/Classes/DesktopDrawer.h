#pragma once
using namespace System;
using namespace System::Drawing;
using namespace System::Runtime::InteropServices;

namespace GCMStore
{

	ref class DesktopDrawer
	{
		[DllImport("User32.dll")]
		static IntPtr GetDC(IntPtr hwnd);

		[DllImport("User32.dll")]
		static int ReleaseDC(IntPtr hwnd, IntPtr dc);


	public: static void DrawFace()
	{
		auto desktop = GetDC(IntPtr::Zero);
		auto g = Graphics::FromHdc(desktop);
		auto font = gcnew Drawing::Font("Consolas", 10);

		auto face = gcnew array<String^>
		{
			"____________________����������� ",
				"_______________�������������������� ",
				"____________��������1111111111�������� ",
				"__________�����11111111111111111111������ ",
				"________�����1111111111111111111111111����� ",
				"_______����11111111111111111111111111111���� ",
				"_____����1111���1111111111111111111���111���� ",
				"____����11111���1111111111111111111���11111��� ",
				"___���1111111���1111111111111111111���111111��� ",
				"__����1111������1111111111111111111������1111��� ",
				"__���111��������1111111111111111111��������111��� ",
				"_���111����___���11111111111111111���___����11��� ",
				"_���11���____�����1111111111111111����____���11�� ",
				"_��11���_____������11111111111111�����_____��11��� ",
				"���11���_____��������11111111111������_____���1��� ",
				"���11���_____�������������������������_____��111�� ",
				"���111���____�������������������������____���111�� ",
				"���111����___����������11111����������___���111��� ",
				"���1111����___��������111111���������___����111��� ",
				"_��111111������������111111111������������11111��� ",
				"_���1111111��������1111111111111��������1111111��______________________________________________________________________��___ ",
				"_���111111111111111111111111111111111111111111���______������__������__��____��__�������___���____������__��____��__��____�� ",
				"__���1111111111111111���������111111111111111���_______��______��__��__��___���__��______��___��__��__��__��___���__��___��� ",
				"___���11111111111111�����������11111111111111���_______��______������__��_��_��__��______��___��__������__��_��_��__��_��_�� ",
				"____���11111111111����1111111����11111111111���________��______��______���___��__��______��___��__��______���___��__���___�� ",
				"____����1111111111���111111111���111111111����_________��______��______��____��__��________���____��______��____��__��____�� ",
				"______����1111111111111111111111111111111����_________________________________________________________��___ ",
				"_______����1111111111111111111111111111����______________����____���_______����__������__��____��__��____�� ",
				"_________�����11111111111111111111111�����______________�__��__��___��____�__��__��______��___���__��___��� ",
				"___________������11111111111111111������_______________��__��__��___��___��__��__��______��_��_��__��_��_��  ",
				"_____________����������1111����������_________________��___��__��___��__��___��__��______���___��__���___�� ",
				"_________________����������������____________________���������___���___��____��__��______��____��__��____�� "
		};

		for (int k = 0; k < 5; ++k)
		{
			for (int i = 0; i < face->Length; ++i)
				g->DrawString(face[i], font, Brushes::Red, 200, 100 + (float)i * 12);

			System::Threading::Thread::Sleep(1000);
		}

		ReleaseDC(IntPtr::Zero, desktop);
	}
	};

}