#pragma once


namespace Task1
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Collections::Generic;


	public ref class EvenSimple : public System::Windows::Forms::Form
	{
		HashSet<int>^ even;
		HashSet<int>^ simple;

	public:
		EvenSimple(void)
		{
			InitializeComponent();

			lbInitial->Items->AddRange(gcnew array<int^> {
				2, 3, 45, 21, 984, 4426, 82, 452, 777, 655, 5, 81, (int^)0, 23}
			);

			even = gcnew HashSet<int>();
			simple = gcnew HashSet<int>();
		}

	protected:
		~EvenSimple()
		{
			if (components)
			{
				delete components;
			}
		}

#pragma region Windows Form Designer generated code
	private: System::Windows::Forms::ListBox^ lbInitial;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ListBox^ lbEven;
	private: System::Windows::Forms::ListBox^ lbSimple;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label33;

	private: System::Windows::Forms::Button^ bCheck;
	private: System::Windows::Forms::Button^ bAppend;
	private: System::Windows::Forms::Button^ bRemove;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::StatusStrip^ statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabel1;


	private:
		System::ComponentModel::Container^ components;

		void InitializeComponent(void)
		{
			this->lbInitial = (gcnew System::Windows::Forms::ListBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lbEven = (gcnew System::Windows::Forms::ListBox());
			this->lbSimple = (gcnew System::Windows::Forms::ListBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->bCheck = (gcnew System::Windows::Forms::Button());
			this->bAppend = (gcnew System::Windows::Forms::Button());
			this->bRemove = (gcnew System::Windows::Forms::Button());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->statusStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// lbInitial
			// 
			this->lbInitial->FormattingEnabled = true;
			this->lbInitial->Location = System::Drawing::Point(12, 25);
			this->lbInitial->Name = L"lbInitial";
			this->lbInitial->Size = System::Drawing::Size(111, 160);
			this->lbInitial->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(111, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Исходный ряд чисел";
			// 
			// lbEven
			// 
			this->lbEven->FormattingEnabled = true;
			this->lbEven->Location = System::Drawing::Point(131, 25);
			this->lbEven->Name = L"lbEven";
			this->lbEven->Size = System::Drawing::Size(111, 95);
			this->lbEven->TabIndex = 0;
			// 
			// lbSimple
			// 
			this->lbSimple->FormattingEnabled = true;
			this->lbSimple->Location = System::Drawing::Point(248, 25);
			this->lbSimple->Name = L"lbSimple";
			this->lbSimple->Size = System::Drawing::Size(111, 95);
			this->lbSimple->TabIndex = 0;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(131, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(46, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Четные";
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Location = System::Drawing::Point(245, 9);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(52, 13);
			this->label33->TabIndex = 1;
			this->label33->Text = L"Простые";
			// 
			// bCheck
			// 
			this->bCheck->Location = System::Drawing::Point(131, 165);
			this->bCheck->Name = L"bCheck";
			this->bCheck->Size = System::Drawing::Size(228, 23);
			this->bCheck->TabIndex = 2;
			this->bCheck->Text = L"Проверить";
			this->bCheck->UseVisualStyleBackColor = true;
			this->bCheck->Click += gcnew System::EventHandler(this, &EvenSimple::bCheck_Click);
			// 
			// bAppend
			// 
			this->bAppend->Location = System::Drawing::Point(131, 136);
			this->bAppend->Name = L"bAppend";
			this->bAppend->Size = System::Drawing::Size(75, 23);
			this->bAppend->TabIndex = 2;
			this->bAppend->Text = L"< Добавить";
			this->bAppend->UseVisualStyleBackColor = true;
			this->bAppend->Click += gcnew System::EventHandler(this, &EvenSimple::bAppend_Click);
			// 
			// bRemove
			// 
			this->bRemove->Location = System::Drawing::Point(284, 136);
			this->bRemove->Name = L"bRemove";
			this->bRemove->Size = System::Drawing::Size(75, 23);
			this->bRemove->TabIndex = 2;
			this->bRemove->Text = L"Удалить >";
			this->bRemove->UseVisualStyleBackColor = true;
			this->bRemove->Click += gcnew System::EventHandler(this, &EvenSimple::bRemove_Click);
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(212, 136);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 9999, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(66, 20);
			this->numericUpDown1->TabIndex = 3;
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripStatusLabel1 });
			this->statusStrip1->Location = System::Drawing::Point(0, 195);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(371, 22);
			this->statusStrip1->SizingGrip = false;
			this->statusStrip1->TabIndex = 4;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(0, 17);
			// 
			// EvenSimple
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(371, 217);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->bRemove);
			this->Controls->Add(this->bAppend);
			this->Controls->Add(this->bCheck);
			this->Controls->Add(this->label33);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->lbSimple);
			this->Controls->Add(this->lbEven);
			this->Controls->Add(this->lbInitial);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"EvenSimple";
			this->Text = L"EvenSimple";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void bAppend_Click(System::Object^ sender, System::EventArgs^ e)
	{
		auto val = Convert::ToInt32(numericUpDown1->Text);

		toolStripStatusLabel1->Text = "";
		if (!lbInitial->Items->Contains(val))
		{
			lbInitial->Items->Add(val);
			lbInitial->SelectedIndex = lbInitial->Items->Count - 1;
			toolStripStatusLabel1->Text = "Число " + val + " добавлено в коллекцию заданных чисел";
		}
	}
	private: System::Void bRemove_Click(System::Object^ sender, System::EventArgs^ e)
	{
		auto val = Convert::ToInt32(numericUpDown1->Text);

		toolStripStatusLabel1->Text = "";
		if (lbInitial->Items->Contains(val))
		{
			lbInitial->Items->Remove(val);
			toolStripStatusLabel1->Text = "Число " + val + " удалено из коллекции заданных чисел";
		}
	}
	private: System::Void bCheck_Click(System::Object^ sender, System::EventArgs^ e)
	{
		even->Clear();
		simple->Clear();
		lbEven->Items->Clear();
		lbSimple->Items->Clear();

		for each (int item in lbInitial->Items)
		{
			if (item % 2 == 0)
			{
				even->Add(item);
				lbEven->Items->Add(item);
			}

			auto isSimple = true;
			for (int i = 2; i < item / 2; ++i)
				if (item % i == 0)
				{
					isSimple = !isSimple;
					break;
				}

			if (!isSimple)
				continue;

			simple->Add(item);
			lbSimple->Items->Add(item);
		}
	}
	};
}
