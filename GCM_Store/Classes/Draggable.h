#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;

namespace GCMStore
{

	static ref class ControlExtension
	{
		// TKey is control to drag, TValue is a flag used while dragging
	private: static Dictionary<Control^, bool>^ draggables = gcnew Dictionary<Control^, bool>();
	private: static System::Drawing::Size mouseOffset;

		   /// <summary>
		   /// Enabling/disabling dragging for control
		   /// </summary>
	public: static void Draggable(this Control^ control, bool Enable)
	{
		if (Enable)
		{
			// enable drag feature
			if (draggables->ContainsKey(control))
			{   // return if control is already draggable
				return;
			}
			// 'false' - initial state is 'not dragging'
			draggables->Add(control, false);

			// assign required event handlersnnn
			control->MouseDown += gcnew MouseEventHandler(control_MouseDown);
			control->MouseUp += gcnew MouseEventHandler(control_MouseUp);
			control->MouseMove += gcnew MouseEventHandler(control_MouseMove);
		}
		else
		{
			// disable drag feature
			if (!draggables->ContainsKey(control))
			{  // return if control is not draggable
				return;
			}
			// remove event handlers
			control->MouseDown -= gcnew MouseEventHandler(control_MouseDown);
			control->MouseUp -= gcnew MouseEventHandler(control_MouseUp);
			control->MouseMove -= gcnew MouseEventHandler(control_MouseMove);
			draggables->Remove(control);
		}
	}
	private: static void control_MouseDown(Object^ sender, MouseEventArgs^ e)
	{
		mouseOffset = System::Drawing::Size(e->Location);
		// turning on dragging
		draggables[(Control^)sender] = true;
	}
	private: static void control_MouseUp(Object^ sender, MouseEventArgs^ e)
	{
		// turning off dragging
		draggables[(Control^)sender] = false;
	}
	private: static void control_MouseMove(Object^ sender, MouseEventArgs^ e)
	{
		// only if dragging is turned on
		if (draggables[(Control^)sender] == true)
		{
			// calculations of control's new position
			System::Drawing::Point^ newLocationOffset = e->Location - mouseOffset;
			((Control^)sender)->Left += newLocationOffset->X;
			((Control^)sender)->Top += newLocationOffset->Y;
		}
	}
	};

}