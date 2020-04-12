#pragma once
#include "Classes/People.h"
#include "Classes/Frames.h"


namespace Task2
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::IO;
	using namespace System::Drawing;


	public ref class InvitationApp : public System::Windows::Forms::Form
	{
		People^ people;

	public:
		InvitationApp(void)
		{
			InitializeComponent();

			cbFrame->Items->AddRange(gcnew array<String^> {	"Шарики", "Цветочки", "Дети", "Узор" });
			cbFrame->SelectedIndex = 0;
		}

	protected:
		~InvitationApp()
		{
			if (components)
			{
				delete components;
			}
		}

#pragma region Windows Form Designer generated code

	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ bReadFromFile;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ fullName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ company;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ workDomain;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ fancies;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^ pick;
	private: System::Windows::Forms::TextBox^ tbSurname;
	private: System::Windows::Forms::TextBox^ tbName;
	private: System::Windows::Forms::TextBox^ tbPatronic;
	private: System::Windows::Forms::TextBox^ tbCompany;
	private: System::Windows::Forms::TextBox^ tbWorkDomain;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ tbFancies;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ bAlter;
	private: System::Windows::Forms::Button^ bAppend;
	private: System::Windows::Forms::Button^ bRemove;
	private: System::Windows::Forms::Button^ bClear;
	private: System::Windows::Forms::StatusStrip^ statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabel1;
	private: System::Windows::Forms::ComboBox^ cbFrame;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ tbEventName;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ bSend;
	private: System::Windows::Forms::Button^ bPreview;
	private:
		System::ComponentModel::Container^ components;

		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->fullName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->company = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->workDomain = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->fancies = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->pick = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->bReadFromFile = (gcnew System::Windows::Forms::Button());
			this->tbSurname = (gcnew System::Windows::Forms::TextBox());
			this->tbName = (gcnew System::Windows::Forms::TextBox());
			this->tbPatronic = (gcnew System::Windows::Forms::TextBox());
			this->tbCompany = (gcnew System::Windows::Forms::TextBox());
			this->tbWorkDomain = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tbFancies = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->bAlter = (gcnew System::Windows::Forms::Button());
			this->bAppend = (gcnew System::Windows::Forms::Button());
			this->bRemove = (gcnew System::Windows::Forms::Button());
			this->bClear = (gcnew System::Windows::Forms::Button());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->cbFrame = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->tbEventName = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->bSend = (gcnew System::Windows::Forms::Button());
			this->bPreview = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->statusStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::LightSlateGray;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
																		System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6)
			{
				this->id, this->fullName,
					this->company, this->workDomain, this->fancies, this->pick
			});
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::Info;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
																		System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle3;
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Left;
			this->dataGridView1->EditMode = System::Windows::Forms::DataGridViewEditMode::EditOnKeystroke;
			this->dataGridView1->Location = System::Drawing::Point(0, 0);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle4->BackColor = System::Drawing::Color::LightSlateGray;
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
																		static_cast<System::Byte>(204)));
			dataGridViewCellStyle4->ForeColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle4->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle4->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle4->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->RowHeadersDefaultCellStyle = dataGridViewCellStyle4;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::AutoSizeToDisplayedHeaders;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->Size = System::Drawing::Size(711, 490);
			this->dataGridView1->TabIndex = 4;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &InvitationApp::dataGridView1_CellContentClick);
			// 
			// id
			// 
			this->id->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::DisplayedCells;
			dataGridViewCellStyle2->BackColor = System::Drawing::Color::White;
			this->id->DefaultCellStyle = dataGridViewCellStyle2;
			this->id->HeaderText = L"Id";
			this->id->Name = L"id";
			this->id->ReadOnly = true;
			this->id->Width = 41;
			// 
			// fullName
			// 
			this->fullName->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::DisplayedCells;
			this->fullName->HeaderText = L"Имя";
			this->fullName->Name = L"fullName";
			this->fullName->ReadOnly = true;
			this->fullName->Width = 54;
			// 
			// company
			// 
			this->company->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::DisplayedCells;
			this->company->HeaderText = L"Фирма";
			this->company->Name = L"company";
			this->company->ReadOnly = true;
			this->company->Width = 69;
			// 
			// workDomain
			// 
			this->workDomain->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::DisplayedCells;
			this->workDomain->HeaderText = L"Сфера деятельности";
			this->workDomain->Name = L"workDomain";
			this->workDomain->ReadOnly = true;
			this->workDomain->Width = 126;
			// 
			// fancies
			// 
			this->fancies->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::DisplayedCells;
			this->fancies->HeaderText = L"Круг интересов";
			this->fancies->Name = L"fancies";
			this->fancies->ReadOnly = true;
			this->fancies->Width = 102;
			// 
			// pick
			// 
			this->pick->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->pick->HeaderText = L"";
			this->pick->Name = L"pick";
			this->pick->ReadOnly = true;
			// 
			// bReadFromFile
			// 
			this->bReadFromFile->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->bReadFromFile->AutoSize = true;
			this->bReadFromFile->Location = System::Drawing::Point(822, 12);
			this->bReadFromFile->Name = L"bReadFromFile";
			this->bReadFromFile->Size = System::Drawing::Size(89, 23);
			this->bReadFromFile->TabIndex = 1;
			this->bReadFromFile->Text = L"Прочитать БД";
			this->bReadFromFile->UseVisualStyleBackColor = true;
			this->bReadFromFile->Click += gcnew System::EventHandler(this, &InvitationApp::bReadFromFile_Click);
			// 
			// tbSurname
			// 
			this->tbSurname->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->tbSurname->Location = System::Drawing::Point(719, 70);
			this->tbSurname->Margin = System::Windows::Forms::Padding(5);
			this->tbSurname->Name = L"tbSurname";
			this->tbSurname->Size = System::Drawing::Size(190, 20);
			this->tbSurname->TabIndex = 2;
			// 
			// tbName
			// 
			this->tbName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->tbName->Location = System::Drawing::Point(719, 96);
			this->tbName->Name = L"tbName";
			this->tbName->Size = System::Drawing::Size(190, 20);
			this->tbName->TabIndex = 2;
			// 
			// tbPatronic
			// 
			this->tbPatronic->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->tbPatronic->Location = System::Drawing::Point(719, 122);
			this->tbPatronic->Name = L"tbPatronic";
			this->tbPatronic->Size = System::Drawing::Size(190, 20);
			this->tbPatronic->TabIndex = 2;
			// 
			// tbCompany
			// 
			this->tbCompany->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->tbCompany->Location = System::Drawing::Point(719, 165);
			this->tbCompany->Name = L"tbCompany";
			this->tbCompany->Size = System::Drawing::Size(190, 20);
			this->tbCompany->TabIndex = 2;
			// 
			// tbWorkDomain
			// 
			this->tbWorkDomain->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->tbWorkDomain->Location = System::Drawing::Point(719, 204);
			this->tbWorkDomain->Name = L"tbWorkDomain";
			this->tbWorkDomain->Size = System::Drawing::Size(190, 20);
			this->tbWorkDomain->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(876, 52);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(34, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"ФИО";
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(866, 149);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(44, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Фирма";
			// 
			// label3
			// 
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(798, 188);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(113, 13);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Сфера деятельности";
			// 
			// tbFancies
			// 
			this->tbFancies->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->tbFancies->Location = System::Drawing::Point(719, 243);
			this->tbFancies->Name = L"tbFancies";
			this->tbFancies->Size = System::Drawing::Size(190, 20);
			this->tbFancies->TabIndex = 2;
			// 
			// label4
			// 
			this->label4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(824, 227);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(86, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Круг интересов";
			// 
			// bAlter
			// 
			this->bAlter->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->bAlter->AutoSize = true;
			this->bAlter->Location = System::Drawing::Point(719, 298);
			this->bAlter->Name = L"bAlter";
			this->bAlter->Size = System::Drawing::Size(89, 23);
			this->bAlter->TabIndex = 1;
			this->bAlter->Text = L"< Изменить*";
			this->bAlter->UseVisualStyleBackColor = true;
			this->bAlter->Click += gcnew System::EventHandler(this, &InvitationApp::bAlter_Click);
			// 
			// bAppend
			// 
			this->bAppend->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->bAppend->AutoSize = true;
			this->bAppend->Location = System::Drawing::Point(719, 269);
			this->bAppend->Name = L"bAppend";
			this->bAppend->Size = System::Drawing::Size(89, 23);
			this->bAppend->TabIndex = 1;
			this->bAppend->Text = L"< Добавить";
			this->bAppend->UseVisualStyleBackColor = true;
			this->bAppend->Click += gcnew System::EventHandler(this, &InvitationApp::bAppend_Click);
			// 
			// bRemove
			// 
			this->bRemove->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->bRemove->AutoSize = true;
			this->bRemove->Location = System::Drawing::Point(822, 298);
			this->bRemove->Name = L"bRemove";
			this->bRemove->Size = System::Drawing::Size(89, 23);
			this->bRemove->TabIndex = 1;
			this->bRemove->Text = L"Удалить >";
			this->bRemove->UseVisualStyleBackColor = true;
			this->bRemove->Click += gcnew System::EventHandler(this, &InvitationApp::bRemove_Click);
			// 
			// bClear
			// 
			this->bClear->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->bClear->AutoSize = true;
			this->bClear->Location = System::Drawing::Point(822, 269);
			this->bClear->Name = L"bClear";
			this->bClear->Size = System::Drawing::Size(89, 23);
			this->bClear->TabIndex = 1;
			this->bClear->Text = L"Х";
			this->bClear->UseVisualStyleBackColor = true;
			this->bClear->Click += gcnew System::EventHandler(this, &InvitationApp::bClear_Click);
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripStatusLabel1 });
			this->statusStrip1->Location = System::Drawing::Point(0, 490);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(923, 22);
			this->statusStrip1->SizingGrip = false;
			this->statusStrip1->TabIndex = 0;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(0, 17);
			// 
			// cbFrame
			// 
			this->cbFrame->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->cbFrame->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cbFrame->FormattingEnabled = true;
			this->cbFrame->Location = System::Drawing::Point(768, 358);
			this->cbFrame->Name = L"cbFrame";
			this->cbFrame->Size = System::Drawing::Size(141, 21);
			this->cbFrame->TabIndex = 5;
			// 
			// label5
			// 
			this->label5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(795, 342);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(114, 13);
			this->label5->TabIndex = 3;
			this->label5->Text = L"Форма приглашения";
			// 
			// tbEventName
			// 
			this->tbEventName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->tbEventName->Location = System::Drawing::Point(720, 405);
			this->tbEventName->Name = L"tbEventName";
			this->tbEventName->Size = System::Drawing::Size(190, 20);
			this->tbEventName->TabIndex = 2;
			// 
			// label6
			// 
			this->label6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(783, 389);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(127, 13);
			this->label6->TabIndex = 3;
			this->label6->Text = L"Название мероприятия";
			// 
			// bSend
			// 
			this->bSend->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->bSend->AutoSize = true;
			this->bSend->Location = System::Drawing::Point(811, 464);
			this->bSend->Name = L"bSend";
			this->bSend->Size = System::Drawing::Size(100, 23);
			this->bSend->TabIndex = 1;
			this->bSend->Text = L"Отправить всем";
			this->bSend->UseVisualStyleBackColor = true;
			this->bSend->Click += gcnew System::EventHandler(this, &InvitationApp::bSend_Click);
			// 
			// bPreview
			// 
			this->bPreview->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->bPreview->AutoSize = true;
			this->bPreview->Location = System::Drawing::Point(819, 435);
			this->bPreview->Name = L"bPreview";
			this->bPreview->Size = System::Drawing::Size(92, 23);
			this->bPreview->TabIndex = 1;
			this->bPreview->Text = L"Предпросмотр";
			this->bPreview->UseVisualStyleBackColor = true;
			this->bPreview->Click += gcnew System::EventHandler(this, &InvitationApp::bPreview_Click);
			// 
			// InvitationApp
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(923, 512);
			this->Controls->Add(this->cbFrame);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->tbEventName);
			this->Controls->Add(this->tbFancies);
			this->Controls->Add(this->tbWorkDomain);
			this->Controls->Add(this->tbCompany);
			this->Controls->Add(this->tbPatronic);
			this->Controls->Add(this->tbName);
			this->Controls->Add(this->tbSurname);
			this->Controls->Add(this->bAppend);
			this->Controls->Add(this->bClear);
			this->Controls->Add(this->bRemove);
			this->Controls->Add(this->bAlter);
			this->Controls->Add(this->bPreview);
			this->Controls->Add(this->bSend);
			this->Controls->Add(this->bReadFromFile);
			this->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"InvitationApp";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"InvitationApp";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion

	private: void fillDataGrid()
	{
		dataGridView1->Rows->Clear();

		for each (auto one in people)
		{
			auto person = ((KeyValuePair<int, Person^>)one).Value;

			dataGridView1->Rows->Add(
				person->Id,
				person->FullName,
				person->Company,
				person->WorkDomain,
				person->Fancies
			);
		}
	}
	private: void fillForm()
	{
		auto row = dataGridView1->SelectedRows[0];

		auto credentials = row->Cells[1]->Value->ToString()->Split(' ');
		tbSurname->Text = credentials[0];
		tbName->Text = credentials[1];
		tbPatronic->Text = credentials[2];

		tbCompany->Text = row->Cells[2]->Value->ToString();
		tbWorkDomain->Text = row->Cells[3]->Value->ToString();
		tbFancies->Text = row->Cells[4]->Value->ToString();
	}
	private: void switchRow(DataGridViewRow^ row)
	{
		auto val = Convert::ToBoolean(row->Cells[5]->Value);

		row->Cells[5]->Value = !val;
		row->DefaultCellStyle->BackColor = SystemColors::Info;
		row->DefaultCellStyle->ForeColor = Color::Black;

		if (!val)
		{
			row->DefaultCellStyle->BackColor = SystemColors::Highlight;
			row->DefaultCellStyle->ForeColor = Color::White;
		}
	}
	private: bool formCompleted()
	{
		if (tbSurname->Text == "" || tbName->Text == "" || tbPatronic->Text == "" || tbCompany->Text == "" || tbWorkDomain->Text == "" || tbFancies->Text == "")
		{
			MessageBox::Show("Заполните все поля формы!");
			return false;
		}

		return true;
	}
	private: int SelectedRow()
	{
		int result = -1;

		for each (DataGridViewRow ^ row in dataGridView1->Rows)
		{
			if (Convert::ToBoolean(row->Cells[5]->Value))
				if (result != -1)
					return -1;
				else
					result = Convert::ToInt32(row->Cells[0]->Value);
		}

		return result;
	}
	private: Frame^ getFrame(String^ fullName)
	{
		Frame^ form;

		auto pick = cbFrame->SelectedItem;
		if (pick == "Шарики")
			form = gcnew BaloonFrame();
		else if (pick == "Цветочки")
			form = gcnew FlowerFrame();
		else if (pick == "Дети")
			form = gcnew KidsFrame();
		else
			form = gcnew PatternFrame();

		form->StartPosition = FormStartPosition::CenterParent;
		form->MaximizeBox = false;
		form->FormBorderStyle = Windows::Forms::FormBorderStyle::FixedSingle;

		form->SetPerson(fullName);
		form->SetEvent(tbEventName->Text);

		form->Paint += gcnew PaintEventHandler(form, &Frame::DrawContent);

		return form;
	}

	private: System::Void bReadFromFile_Click(System::Object^ sender, System::EventArgs^ e)
	{
		try
		{
			auto db = File::ReadAllLines("db/dbPeople.txt");
			people = gcnew People();

			for each (auto personInfo in db)
				people->Add(gcnew Person(personInfo));

			fillDataGrid();
			toolStripStatusLabel1->Text = "Данные прочитаны из dbPeople.txt";
		}
		catch (Exception ^ ex)
		{
			MessageBox::Show(ex->Message);
		}
	}
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
	{
		if (e->RowIndex > 0)
		{
			auto row = dataGridView1->Rows[e->RowIndex];

			switchRow(row);
			fillForm();
		}
	}
	private: System::Void bClear_Click(System::Object^ sender, System::EventArgs^ e)
	{
		tbSurname->Text = "";
		tbName->Text = "";
		tbPatronic->Text = "";

		tbCompany->Text = "";
		tbWorkDomain->Text = "";
		tbFancies->Text = "";
	}
	private: System::Void bAlter_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (dataGridView1->Rows->Count == 0)
			return;

		if (formCompleted())
		{
			auto id = dataGridView1->SelectedRows[0]->Cells[0]->Value->ToString();
			auto str = gcnew array<String^> {
				id,
					tbSurname->Text,
					tbName->Text,
					tbPatronic->Text,
					tbCompany->Text,
					tbWorkDomain->Text,
					tbFancies->Text
			};
			auto info = String::Join("#", str);

			auto refinedPerson = gcnew Person(info);
			people->Alter(refinedPerson);

			auto row = dataGridView1->SelectedRows[0];
			row->Cells[0]->Value = id;
			row->Cells[1]->Value = String::Join(" ", gcnew array<String^>{tbSurname->Text, tbName->Text, tbPatronic->Text});
			row->Cells[2]->Value = tbCompany->Text;
			row->Cells[3]->Value = tbWorkDomain->Text;
			row->Cells[4]->Value = tbFancies->Text;

			toolStripStatusLabel1->Text = "Изменена запись № " + id;
		}
	}
	private: System::Void bAppend_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (formCompleted())
		{
			auto id = people->GetNextIndex().ToString();
			auto str = gcnew array<String^> {
				id,
					tbSurname->Text,
					tbName->Text,
					tbPatronic->Text,
					tbCompany->Text,
					tbWorkDomain->Text,
					tbFancies->Text
			};
			auto info = String::Join("#", str);

			auto newPerson = gcnew Person(info);
			people->Add(newPerson);

			auto row = gcnew DataGridViewRow();
			dataGridView1->Rows->Add(
				id,
				String::Join(" ", gcnew array<String^>{tbSurname->Text, tbName->Text, tbPatronic->Text}),
				tbCompany->Text,
				tbWorkDomain->Text,
				tbFancies->Text
			);

			auto rowIdx = dataGridView1->Rows->Count - 1;
			dataGridView1->CurrentCell = dataGridView1->Rows[rowIdx]->Cells[1];

			toolStripStatusLabel1->Text = "Добавлена запись № " + id;
		}
	}
	private: System::Void bRemove_Click(System::Object^ sender, System::EventArgs^ e)
	{
		auto deleteRowIdx = SelectedRow();

		if (deleteRowIdx == -1)
		{
			MessageBox::Show("Неверно выбраны записи. Выберите один чекбокс");
			return;
		}

		people->RemoveAt(deleteRowIdx);
		for (int i = 0; i < dataGridView1->Rows->Count; ++i)
		{
			if (Convert::ToInt32(dataGridView1->Rows[i]->Cells[0]->Value) == deleteRowIdx)
			{
				dataGridView1->Rows->RemoveAt(i);
				break;
			}
		}

		toolStripStatusLabel1->Text = "Удалена запись № " + deleteRowIdx;
	}
	private: System::Void bSend_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (tbEventName->Text == "")
			MessageBox::Show("Заполните поле \"мероприятие\"");
		else
		{
			auto list = gcnew Generic::Stack<Frame^>();
			auto count = 0;

			for each (DataGridViewRow ^ row in dataGridView1->Rows)
			{
				if (Convert::ToBoolean(row->Cells[5]->Value))
				{
					++count;
					list->Push(getFrame(row->Cells[1]->Value->ToString()));
					list->Peek()->Show();
				}
			}

			if (count == 0)
				MessageBox::Show("Выберите получателей сообщений");
			else
				MessageBox::Show(String::Concat("Отправлено ", count, " приглашений"));
		}
	}
	private: System::Void bPreview_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (tbEventName->Text == "")
			MessageBox::Show("Заполните поле \"мероприятие\"");
		else
			if (formCompleted())
			{
				auto fullName = String::Concat(tbSurname->Text, " ", tbName->Text, " ", tbPatronic->Text);
				auto form = getFrame(fullName);
				form->ShowDialog();
			}
	}
	};
}
