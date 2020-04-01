#pragma once
#include "Classes/Order.h"
#include "Classes/StockDealer.h"
#include "Classes/DesktopDrawer.h"

namespace GCMStore
{

	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Data;
	using namespace System;
	using namespace System::Windows::Forms;

	delegate array<String^>^ arrayVoidDelegate();


	ref class Store : Form
	{
		Order^ order;						// жетон (заказ)
		Dictionary<Type^, Oil^>^ orderOils;	// словарь для хранения масел в заказе перед формированием заказа
		Dictionary<int, Order^>^ tokens;	// словарь для хранения жетонов
		Button^ blinkBtn;					// текущая подсвечиваемая кнопка

		StockDealer^ dealer;				// распорядитель склада

	public:
		Store(StockDealer^ dealer)
		{
			InitializeComponent();

			this->dealer = dealer;
			this->dealer->onOrderApplying += gcnew EventHandler(this, &Store::dealerUpdateStatus);
			this->dealer->onStopProcessing += gcnew EventHandler(this, &Store::dealerHandlingUpdate);
			this->dealer->onOrderRetrieving += gcnew EventHandler(this, &Store::dealerUpdateStatus);
			this->dealer->onReplentish += gcnew EventHandler(this, &Store::dealerUpdateStatus);
		}

	protected:
		~Store()
		{
			if (components)
			{
				delete components;
			}
		}

#pragma region Windows Form Designer generated code

	private: System::Windows::Forms::Button^ bAbout;
	private: System::Windows::Forms::GroupBox^ gbTotal;
	private: System::Windows::Forms::Timer^ tBlink;
	private: System::Windows::Forms::NumericUpDown^ nTotal;
	private: System::Windows::Forms::PictureBox^ pbTotal;
	private: System::Windows::Forms::GroupBox^ gbShell;
	private: System::Windows::Forms::NumericUpDown^ nShell;
	private: System::Windows::Forms::PictureBox^ pbShell;
	private: System::Windows::Forms::GroupBox^ gbMobil;
	private: System::Windows::Forms::NumericUpDown^ nMobil;
	private: System::Windows::Forms::PictureBox^ pbMobil;
	private: System::Windows::Forms::GroupBox^ gbCastrol;
	private: System::Windows::Forms::NumericUpDown^ nCastrol;
	private: System::Windows::Forms::PictureBox^ pbCastrol;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ bOrder;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Panel^ pOrder;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ bGet;
	private: System::Windows::Forms::Button^ bRegister;
	private: System::Windows::Forms::Panel^ pGet;
	private: System::Windows::Forms::Panel^ pRegister;
	private: System::Windows::Forms::Button^ bSafe;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Panel^ pSafe;
	private: System::Windows::Forms::NumericUpDown^ nSafe;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Panel^ panel7;
	private: System::Windows::Forms::RichTextBox^ rWarehouse;
	private: System::Windows::Forms::Panel^ panel8;
	private: System::Windows::Forms::Label^ lMessage;
	private: System::Windows::Forms::Button^ bRetrieve;
	private: System::Windows::Forms::Timer^ tMessage;
	private: System::Windows::Forms::ToolTip^ toolTip1;
	private: System::Windows::Forms::Button^ bSupply;
	private: System::ComponentModel::IContainer^ components;

	private:
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Store::typeid));
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->bSupply = (gcnew System::Windows::Forms::Button());
			this->gbTotal = (gcnew System::Windows::Forms::GroupBox());
			this->nTotal = (gcnew System::Windows::Forms::NumericUpDown());
			this->pbTotal = (gcnew System::Windows::Forms::PictureBox());
			this->gbShell = (gcnew System::Windows::Forms::GroupBox());
			this->nShell = (gcnew System::Windows::Forms::NumericUpDown());
			this->pbShell = (gcnew System::Windows::Forms::PictureBox());
			this->gbMobil = (gcnew System::Windows::Forms::GroupBox());
			this->nMobil = (gcnew System::Windows::Forms::NumericUpDown());
			this->pbMobil = (gcnew System::Windows::Forms::PictureBox());
			this->gbCastrol = (gcnew System::Windows::Forms::GroupBox());
			this->nCastrol = (gcnew System::Windows::Forms::NumericUpDown());
			this->pbCastrol = (gcnew System::Windows::Forms::PictureBox());
			this->bOrder = (gcnew System::Windows::Forms::Button());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->pOrder = (gcnew System::Windows::Forms::Panel());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->bAbout = (gcnew System::Windows::Forms::Button());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->rWarehouse = (gcnew System::Windows::Forms::RichTextBox());
			this->nSafe = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->bRetrieve = (gcnew System::Windows::Forms::Button());
			this->bSafe = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->bGet = (gcnew System::Windows::Forms::Button());
			this->bRegister = (gcnew System::Windows::Forms::Button());
			this->pGet = (gcnew System::Windows::Forms::Panel());
			this->pSafe = (gcnew System::Windows::Forms::Panel());
			this->pRegister = (gcnew System::Windows::Forms::Panel());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->lMessage = (gcnew System::Windows::Forms::Label());
			this->tMessage = (gcnew System::Windows::Forms::Timer(this->components));
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->tBlink = (gcnew System::Windows::Forms::Timer(this->components));
			this->groupBox1->SuspendLayout();
			this->gbTotal->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nTotal))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbTotal))->BeginInit();
			this->gbShell->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nShell))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbShell))->BeginInit();
			this->gbMobil->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nMobil))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbMobil))->BeginInit();
			this->gbCastrol->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nCastrol))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbCastrol))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->panel7->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nSafe))->BeginInit();
			this->panel8->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->bSupply);
			this->groupBox1->Controls->Add(this->gbTotal);
			this->groupBox1->Controls->Add(this->gbShell);
			this->groupBox1->Controls->Add(this->gbMobil);
			this->groupBox1->Controls->Add(this->gbCastrol);
			this->groupBox1->Controls->Add(this->bOrder);
			this->groupBox1->Controls->Add(this->panel3);
			this->groupBox1->Controls->Add(this->pOrder);
			this->groupBox1->Location = System::Drawing::Point(12, 32);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(5);
			this->groupBox1->Size = System::Drawing::Size(253, 310);
			this->groupBox1->TabIndex = 5;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"ЗАКАЗ";
			// 
			// bSupply
			// 
			this->bSupply->Location = System::Drawing::Point(170, 16);
			this->bSupply->Name = L"bSupply";
			this->bSupply->Size = System::Drawing::Size(75, 41);
			this->bSupply->TabIndex = 11;
			this->bSupply->Text = L"Пополнить склад";
			this->bSupply->UseVisualStyleBackColor = true;
			this->bSupply->Click += gcnew System::EventHandler(this, &Store::bSupply_Click);
			// 
			// gbTotal
			// 
			this->gbTotal->Controls->Add(this->nTotal);
			this->gbTotal->Controls->Add(this->pbTotal);
			this->gbTotal->ForeColor = System::Drawing::Color::Black;
			this->gbTotal->Location = System::Drawing::Point(8, 168);
			this->gbTotal->Name = L"gbTotal";
			this->gbTotal->Size = System::Drawing::Size(72, 134);
			this->gbTotal->TabIndex = 9;
			this->gbTotal->TabStop = false;
			this->gbTotal->Text = L"TOTAL";
			// 
			// nTotal
			// 
			this->nTotal->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			this->nTotal->Location = System::Drawing::Point(6, 105);
			this->nTotal->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->nTotal->Name = L"nTotal";
			this->nTotal->Size = System::Drawing::Size(60, 20);
			this->nTotal->TabIndex = 1;
			this->nTotal->ValueChanged += gcnew System::EventHandler(this, &Store::nTotal_ValueChanged);
			// 
			// pbTotal
			// 
			this->pbTotal->BackColor = System::Drawing::Color::Transparent;
			this->pbTotal->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbTotal.BackgroundImage")));
			this->pbTotal->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pbTotal->Location = System::Drawing::Point(6, 19);
			this->pbTotal->Name = L"pbTotal";
			this->pbTotal->Size = System::Drawing::Size(60, 80);
			this->pbTotal->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbTotal->TabIndex = 0;
			this->pbTotal->TabStop = false;
			// 
			// gbShell
			// 
			this->gbShell->Controls->Add(this->nShell);
			this->gbShell->Controls->Add(this->pbShell);
			this->gbShell->ForeColor = System::Drawing::Color::Black;
			this->gbShell->Location = System::Drawing::Point(86, 168);
			this->gbShell->Name = L"gbShell";
			this->gbShell->Size = System::Drawing::Size(72, 134);
			this->gbShell->TabIndex = 8;
			this->gbShell->TabStop = false;
			this->gbShell->Text = L"SHELL";
			// 
			// nShell
			// 
			this->nShell->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			this->nShell->Location = System::Drawing::Point(6, 105);
			this->nShell->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->nShell->Name = L"nShell";
			this->nShell->Size = System::Drawing::Size(60, 20);
			this->nShell->TabIndex = 1;
			this->nShell->ValueChanged += gcnew System::EventHandler(this, &Store::nShell_ValueChanged);
			// 
			// pbShell
			// 
			this->pbShell->BackColor = System::Drawing::Color::Transparent;
			this->pbShell->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbShell.BackgroundImage")));
			this->pbShell->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pbShell->Location = System::Drawing::Point(6, 19);
			this->pbShell->Name = L"pbShell";
			this->pbShell->Size = System::Drawing::Size(60, 80);
			this->pbShell->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbShell->TabIndex = 0;
			this->pbShell->TabStop = false;
			// 
			// gbMobil
			// 
			this->gbMobil->Controls->Add(this->nMobil);
			this->gbMobil->Controls->Add(this->pbMobil);
			this->gbMobil->ForeColor = System::Drawing::Color::Black;
			this->gbMobil->Location = System::Drawing::Point(86, 22);
			this->gbMobil->Name = L"gbMobil";
			this->gbMobil->Size = System::Drawing::Size(72, 134);
			this->gbMobil->TabIndex = 7;
			this->gbMobil->TabStop = false;
			this->gbMobil->Text = L"MOBIL";
			// 
			// nMobil
			// 
			this->nMobil->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			this->nMobil->Location = System::Drawing::Point(6, 105);
			this->nMobil->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->nMobil->Name = L"nMobil";
			this->nMobil->Size = System::Drawing::Size(60, 20);
			this->nMobil->TabIndex = 1;
			this->nMobil->ValueChanged += gcnew System::EventHandler(this, &Store::nMobil_ValueChanged);
			// 
			// pbMobil
			// 
			this->pbMobil->BackColor = System::Drawing::Color::Transparent;
			this->pbMobil->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbMobil.BackgroundImage")));
			this->pbMobil->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pbMobil->Location = System::Drawing::Point(6, 19);
			this->pbMobil->Name = L"pbMobil";
			this->pbMobil->Size = System::Drawing::Size(60, 80);
			this->pbMobil->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbMobil->TabIndex = 0;
			this->pbMobil->TabStop = false;
			// 
			// gbCastrol
			// 
			this->gbCastrol->Controls->Add(this->nCastrol);
			this->gbCastrol->Controls->Add(this->pbCastrol);
			this->gbCastrol->ForeColor = System::Drawing::Color::Black;
			this->gbCastrol->Location = System::Drawing::Point(8, 21);
			this->gbCastrol->Name = L"gbCastrol";
			this->gbCastrol->Size = System::Drawing::Size(72, 134);
			this->gbCastrol->TabIndex = 6;
			this->gbCastrol->TabStop = false;
			this->gbCastrol->Text = L"CASTROL";
			// 
			// nCastrol
			// 
			this->nCastrol->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			this->nCastrol->Location = System::Drawing::Point(6, 105);
			this->nCastrol->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4000, 0, 0, 0 });
			this->nCastrol->Name = L"nCastrol";
			this->nCastrol->Size = System::Drawing::Size(60, 20);
			this->nCastrol->TabIndex = 1;
			this->nCastrol->ValueChanged += gcnew System::EventHandler(this, &Store::nCastrol_ValueChanged);
			// 
			// pbCastrol
			// 
			this->pbCastrol->BackColor = System::Drawing::Color::Transparent;
			this->pbCastrol->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbCastrol.BackgroundImage")));
			this->pbCastrol->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pbCastrol->Location = System::Drawing::Point(6, 19);
			this->pbCastrol->Name = L"pbCastrol";
			this->pbCastrol->Size = System::Drawing::Size(60, 80);
			this->pbCastrol->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbCastrol->TabIndex = 0;
			this->pbCastrol->TabStop = false;
			// 
			// bOrder
			// 
			this->bOrder->BackColor = System::Drawing::SystemColors::ControlLight;
			this->bOrder->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bOrder.BackgroundImage")));
			this->bOrder->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->bOrder->Location = System::Drawing::Point(178, 209);
			this->bOrder->Name = L"bOrder";
			this->bOrder->Size = System::Drawing::Size(64, 41);
			this->bOrder->TabIndex = 5;
			this->toolTip1->SetToolTip(this->bOrder, L"Стрелка для получения жетона");
			this->bOrder->UseVisualStyleBackColor = false;
			this->bOrder->Click += gcnew System::EventHandler(this, &Store::bOrder_Click);
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::SlateGray;
			this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel3->Location = System::Drawing::Point(175, 103);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(70, 17);
			this->panel3->TabIndex = 1;
			// 
			// pOrder
			// 
			this->pOrder->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pOrder->Location = System::Drawing::Point(178, 116);
			this->pOrder->Name = L"pOrder";
			this->pOrder->Size = System::Drawing::Size(64, 87);
			this->pOrder->TabIndex = 4;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->bAbout);
			this->groupBox2->Controls->Add(this->panel7);
			this->groupBox2->Controls->Add(this->nSafe);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->bRetrieve);
			this->groupBox2->Controls->Add(this->bSafe);
			this->groupBox2->Controls->Add(this->textBox3);
			this->groupBox2->Controls->Add(this->textBox4);
			this->groupBox2->Controls->Add(this->textBox2);
			this->groupBox2->Controls->Add(this->bGet);
			this->groupBox2->Controls->Add(this->bRegister);
			this->groupBox2->Controls->Add(this->pGet);
			this->groupBox2->Controls->Add(this->pSafe);
			this->groupBox2->Controls->Add(this->pRegister);
			this->groupBox2->Location = System::Drawing::Point(280, 32);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(379, 310);
			this->groupBox2->TabIndex = 6;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"СКЛАД";
			// 
			// bAbout
			// 
			this->bAbout->Location = System::Drawing::Point(298, 279);
			this->bAbout->Name = L"bAbout";
			this->bAbout->Size = System::Drawing::Size(75, 25);
			this->bAbout->TabIndex = 11;
			this->bAbout->Text = L"about";
			this->bAbout->UseVisualStyleBackColor = true;
			this->bAbout->Click += gcnew System::EventHandler(this, &Store::bAbout_Click);
			// 
			// panel7
			// 
			this->panel7->BackColor = System::Drawing::Color::White;
			this->panel7->Controls->Add(this->rWarehouse);
			this->panel7->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel7->Location = System::Drawing::Point(3, 16);
			this->panel7->Name = L"panel7";
			this->panel7->Padding = System::Windows::Forms::Padding(8);
			this->panel7->Size = System::Drawing::Size(373, 136);
			this->panel7->TabIndex = 7;
			// 
			// rWarehouse
			// 
			this->rWarehouse->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->rWarehouse->Dock = System::Windows::Forms::DockStyle::Fill;
			this->rWarehouse->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
																  static_cast<System::Byte>(204)));
			this->rWarehouse->Location = System::Drawing::Point(8, 8);
			this->rWarehouse->Margin = System::Windows::Forms::Padding(2);
			this->rWarehouse->Name = L"rWarehouse";
			this->rWarehouse->Size = System::Drawing::Size(357, 120);
			this->rWarehouse->TabIndex = 0;
			this->rWarehouse->Text = L"";
			// 
			// nSafe
			// 
			this->nSafe->Location = System::Drawing::Point(299, 178);
			this->nSafe->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->nSafe->Name = L"nSafe";
			this->nSafe->Size = System::Drawing::Size(67, 20);
			this->nSafe->TabIndex = 1;
			this->nSafe->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(296, 162);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(51, 13);
			this->label2->TabIndex = 9;
			this->label2->Text = L"заказ №";
			// 
			// bRetrieve
			// 
			this->bRetrieve->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->bRetrieve->BackColor = System::Drawing::SystemColors::ControlLight;
			this->bRetrieve->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bRetrieve.BackgroundImage")));
			this->bRetrieve->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->bRetrieve->Location = System::Drawing::Point(299, 204);
			this->bRetrieve->Name = L"bRetrieve";
			this->bRetrieve->Size = System::Drawing::Size(67, 41);
			this->bRetrieve->TabIndex = 5;
			this->toolTip1->SetToolTip(this->bRetrieve, L"Стрелка для возврата жетона");
			this->bRetrieve->UseVisualStyleBackColor = false;
			this->bRetrieve->Click += gcnew System::EventHandler(this, &Store::bRetrieve_Click);
			// 
			// bSafe
			// 
			this->bSafe->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->bSafe->BackColor = System::Drawing::SystemColors::ControlLight;
			this->bSafe->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bSafe.BackgroundImage")));
			this->bSafe->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->bSafe->Location = System::Drawing::Point(221, 263);
			this->bSafe->Name = L"bSafe";
			this->bSafe->Size = System::Drawing::Size(64, 41);
			this->bSafe->TabIndex = 5;
			this->toolTip1->SetToolTip(this->bSafe, L"Стрелка для сохранения жетона");
			this->bSafe->UseVisualStyleBackColor = false;
			this->bSafe->Click += gcnew System::EventHandler(this, &Store::bSafe_Click);
			// 
			// textBox3
			// 
			this->textBox3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->textBox3->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->textBox3->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->textBox3->Location = System::Drawing::Point(85, 158);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(72, 20);
			this->textBox3->TabIndex = 6;
			this->textBox3->Text = L" ПОЛУЧИТЬ";
			// 
			// textBox4
			// 
			this->textBox4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->textBox4->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->textBox4->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->textBox4->Location = System::Drawing::Point(217, 158);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(72, 20);
			this->textBox4->TabIndex = 6;
			this->textBox4->Text = L"     СЕЙФ";
			// 
			// textBox2
			// 
			this->textBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->textBox2->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->textBox2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->textBox2->Location = System::Drawing::Point(6, 158);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(72, 20);
			this->textBox2->TabIndex = 6;
			this->textBox2->Text = L"  ЗАКАЗАТЬ";
			// 
			// bGet
			// 
			this->bGet->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->bGet->BackColor = System::Drawing::SystemColors::ControlLight;
			this->bGet->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bGet.BackgroundImage")));
			this->bGet->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->bGet->Location = System::Drawing::Point(89, 263);
			this->bGet->Name = L"bGet";
			this->bGet->Size = System::Drawing::Size(64, 41);
			this->bGet->TabIndex = 5;
			this->toolTip1->SetToolTip(this->bGet, L"Стрелка для получения заказа");
			this->bGet->UseVisualStyleBackColor = false;
			this->bGet->Click += gcnew System::EventHandler(this, &Store::bGet_Click);
			// 
			// bRegister
			// 
			this->bRegister->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->bRegister->BackColor = System::Drawing::SystemColors::ControlLight;
			this->bRegister->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bRegister.BackgroundImage")));
			this->bRegister->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->bRegister->Location = System::Drawing::Point(10, 263);
			this->bRegister->Name = L"bRegister";
			this->bRegister->Size = System::Drawing::Size(64, 41);
			this->bRegister->TabIndex = 5;
			this->toolTip1->SetToolTip(this->bRegister, L"Стрелка для регистрации заказа жетона");
			this->bRegister->UseVisualStyleBackColor = false;
			this->bRegister->Click += gcnew System::EventHandler(this, &Store::bRegister_Click);
			// 
			// pGet
			// 
			this->pGet->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->pGet->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pGet->Location = System::Drawing::Point(89, 171);
			this->pGet->Name = L"pGet";
			this->pGet->Size = System::Drawing::Size(64, 87);
			this->pGet->TabIndex = 5;
			// 
			// pSafe
			// 
			this->pSafe->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->pSafe->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pSafe->Location = System::Drawing::Point(221, 171);
			this->pSafe->Name = L"pSafe";
			this->pSafe->Size = System::Drawing::Size(64, 87);
			this->pSafe->TabIndex = 5;
			// 
			// pRegister
			// 
			this->pRegister->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->pRegister->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pRegister->Location = System::Drawing::Point(10, 171);
			this->pRegister->Name = L"pRegister";
			this->pRegister->Size = System::Drawing::Size(64, 87);
			this->pRegister->TabIndex = 5;
			// 
			// panel8
			// 
			this->panel8->BackColor = System::Drawing::Color::LightSlateGray;
			this->panel8->Controls->Add(this->lMessage);
			this->panel8->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel8->Location = System::Drawing::Point(0, 0);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(669, 22);
			this->panel8->TabIndex = 7;
			// 
			// lMessage
			// 
			this->lMessage->AutoSize = true;
			this->lMessage->BackColor = System::Drawing::Color::Transparent;
			this->lMessage->Font = (gcnew System::Drawing::Font(L"Consolas", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
																static_cast<System::Byte>(204)));
			this->lMessage->ForeColor = System::Drawing::Color::White;
			this->lMessage->Location = System::Drawing::Point(728, 4);
			this->lMessage->Name = L"lMessage";
			this->lMessage->Size = System::Drawing::Size(181, 13);
			this->lMessage->TabIndex = 0;
			this->lMessage->Text = L"НАЧНИТЕ С ФОРМИРОВАНИЯ ЗАКАЗА";
			// 
			// tMessage
			// 
			this->tMessage->Interval = 10;
			this->tMessage->Tick += gcnew System::EventHandler(this, &Store::tMessage_Tick);
			// 
			// tBlink
			// 
			this->tBlink->Interval = 500;
			this->tBlink->Tick += gcnew System::EventHandler(this, &Store::tBlink_Tick);
			// 
			// Store
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(669, 349);
			this->Controls->Add(this->panel8);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"Store";
			this->Text = L"Продажа ГСМ";
			this->Load += gcnew System::EventHandler(this, &Store::Store_Load);
			this->groupBox1->ResumeLayout(false);
			this->gbTotal->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nTotal))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbTotal))->EndInit();
			this->gbShell->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nShell))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbShell))->EndInit();
			this->gbMobil->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nMobil))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbMobil))->EndInit();
			this->gbCastrol->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nCastrol))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbCastrol))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->panel7->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nSafe))->EndInit();
			this->panel8->ResumeLayout(false);
			this->panel8->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	//-------------------------------------------- ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ -------------------------------------	
	private: void alterMessage(String^ text)
	{
		auto inv = gcnew Action<String^>(this, &Store::alterMessageInvoke);
		Invoke(inv, text);
	}
	private: void alterMessageInvoke(String^ text)
	{
		if (!lMessage->Text->Equals(text))
		{
			lMessage->Left = 728;
			lMessage->Text = text;
		}
	}
	private: void moveMessage()
	{
		auto inv = gcnew voidVoidDelegate(this, &Store::moveMessageInvoke);
		Invoke(inv);
	}
	private: void moveMessageInvoke()
	{
		if (lMessage->Right > 0)
			lMessage->Left -= 1;
		else
			lMessage->Left = 728;
	}

	// метод выдвигания карточки с заказом
	private: void pullOrder(IAsyncResult^ result)
	{
		try
		{
			auto order = (Order^)result->AsyncState;
			if (order->Id == 0)
				auto id = dealer->ApplyOrder(order);

			auto markOrder = gcnew Action<String^>(this, &Store::markOrderInvoke);
			Invoke(markOrder, Convert::ToString(order->Id));
		}
		catch (Exception^) { }

		auto pull = gcnew voidVoidDelegate(this, &Store::pullOrderInvoke);
		while (order->Top < 8)
		{
			Invoke(pull);
			System::Threading::Thread::Sleep(30);
		}
	}
	private: void markOrderInvoke(String^ num)
	{
		auto list = gcnew List<String^>(order->Lines);
		list->Add(String::Concat("  id: ", num));
		order->Lines = list->ToArray();
	}
	private: void pullOrderInvoke()
	{
		++order->Top;
	}

	// метод задвигания карточки с заказом	
	private: void pushOrder()
	{
		auto push = gcnew voidVoidDelegate(this, &Store::pushOrderInvoke);

		while (order->Top > -70)
		{
			Invoke(push);
			System::Threading::Thread::Sleep(30);
		}
	}
	private: void pushOrderInvoke()
	{
		--order->Top;
	}

	private: void pDragEnter(Object^ sender, DragEventArgs^ e)
	{
		e->Effect = DragDropEffects::Move;
	}
	private: void pDragDrop(Object^ sender, DragEventArgs^ e)
	{
		auto sdr = (Panel^)sender;
		auto tb = (Order^)(e->Data->GetData(Order::typeid));
		tb->Parent = sdr;
	}

	// набор масел в заказ
	private: void alterOrder(int value, Type^ oilType)
	{
		if (order == nullptr)
		{
			if (value > 0)
			{
				if (value % 100 > 0)
				{
					if (oilType->Equals(Castrol::typeid))
						nCastrol->Value = 0;
					else if (oilType->Equals(Mobil::typeid))
						nMobil->Value = 0;
					else if (oilType->Equals(Shell::typeid))
						nShell->Value = 0;
					else if (oilType->Equals(Total::typeid))
						nTotal->Value = 0;

					MessageBox::Show("Количество масла должно быть кратно 100");
					return;
				}

				if (orderOils->ContainsKey(oilType))
					orderOils[oilType]->Quantity = value;
				else
				{
					auto oil = (Oil^)Activator::CreateInstance(oilType, gcnew array<Object^>{value});
					orderOils[oilType] = oil;
				}
			}
			else
				if (orderOils->ContainsKey(oilType))
					orderOils->Remove(oilType);

			auto alterMsg = gcnew Action<String^>(this, &Store::alterMessage);
			alterMsg->BeginInvoke("ПОСЛЕ ОКОНЧАНИЯ ФОРМИРОВАНИЯ ЗАКАЗА НАЖМИТЕ НА СТРЕЛКУ ДЛЯ ПОЛУЧЕНИЯ ЖЕТОНА", nullptr, nullptr);

			blinkBtn = bOrder;
			tBlink->Enabled = true;
		}
	}

	// сохранение-выдача жетонов
	private: void saveTokenCallback(IAsyncResult^ result)
	{
		auto order = (Order^)result->AsyncState;
		auto copy = gcnew Order(order);
		tokens->Add(order->Id, copy);

		auto newOrder = gcnew voidVoidDelegate(this, &Store::saveTokenInvoke);
		Invoke(newOrder);

		alterMessage("ТЕПЕРЬ ВЫ МОЖЕТЕ СДЕЛАТЬ ЕЩЕ ОДИН ЗАКАЗ НЕ ДОЖИДАЯСЬ ГОТОВНОСТИ ТЕКУЩЕГО");
	}
	private: void retrieveTokenCallback(IAsyncResult^ result)
	{
		bRegister->BackColor = Drawing::SystemColors::ControlLight;
		blinkBtn = bGet;

		auto alterMessage = gcnew Action<String^>(this, &Store::alterMessage);
		alterMessage->BeginInvoke("ТЕПЕРЬ ВЫ МОЖЕТЕ ПОПРОБОВАТЬ ПОЛУЧИТЬ ЗАКАЗ ПО ЖЕТОНУ", nullptr, nullptr);
	}
	private: void getOrderCallback(IAsyncResult^ result)
	{
		MessageBox::Show(dealer->RetrievePackage(order->Id)->ToString(), "Магазин ГСМ");

		auto discardToken = gcnew voidVoidDelegate(this, &Store::saveTokenInvoke);
		Invoke(discardToken);
	}
	private: void saveTokenInvoke()
	{
		nCastrol->Value = 0;
		nMobil->Value = 0;
		nTotal->Value = 0;
		nShell->Value = 0;
		orderOils->Clear();

		nCastrol->Enabled = true;
		nMobil->Enabled = true;
		nTotal->Enabled = true;
		nShell->Enabled = true;

		blinkBtn->BackColor = Drawing::SystemColors::ControlLight;
		blinkBtn = bOrder;
		order = nullptr;
		bOrder_Click(this, EventArgs::Empty);
	}

	// методы отрисовки статуса склада
	private: void dealerUpdateStatus(System::Object^ sender, System::EventArgs^ e)
	{
		auto refresh = gcnew voidVoidDelegate(this, &Store::refreshTableInvoke);
		Invoke(refresh);
	}
	private: void dealerHandlingUpdate(System::Object^ sender, System::EventArgs^ e)
	{
		drawPercents();

		auto refresh = gcnew voidVoidDelegate(this, &Store::refreshTableInvoke);
		Invoke(refresh);
	}
	private: void refreshTableInvoke()
	{
		auto status = dealer->Status;
		auto board = gcnew Generic::Queue<String^>(rWarehouse->Lines);

		for each (auto line in status)
		{
			board->Enqueue(line);

			if (board->Count > 9)
				board->Dequeue();
		}

		rWarehouse->Lines = board->ToArray();
	}

	// отрисовка процентов
	private: void drawPercents()
	{
		auto getTable = gcnew arrayVoidDelegate(this, &Store::getTable);
		auto table = gcnew Generic::List<String^>((array<String^>^)Invoke(getTable));

		table->Add("");
		if (table->Count > 9)
			table->RemoveAt(0);

		for (int i = 0; i < 101; ++i)
		{
			table[table->Count - 1] = String::Concat("сборка заказов.. ", i, "%");

			auto alterPercent = gcnew Action<array<String^>^>(this, &Store::percentTableInvoke);
			Invoke(alterPercent, gcnew array<Object^>{table->ToArray()});

			System::Threading::Thread::Sleep(50);
		}

		auto clearCount = gcnew voidVoidDelegate(this, &Store::clearPercentInvoke);
		Invoke(clearCount);
	}
	private: array<String^>^ getTable()
	{
		return rWarehouse->Lines;
	}
	private: void percentTableInvoke(array<String^>^ brd)
	{
		rWarehouse->Lines = brd;
	}
	private: void clearPercentInvoke()
	{
		auto newArr = gcnew array<String^>(rWarehouse->Lines->Length - 1);
		Array::Copy(rWarehouse->Lines, newArr, rWarehouse->Lines->Length - 1);
		rWarehouse->Lines = newArr;
	}

	//-------------------------------------------- СОБЫТИЯ -----------------------------------------------------
	private: System::Void Store_Load(System::Object^ sender, System::EventArgs^ e)
	{
		tMessage->Enabled = true;

		pOrder->AllowDrop = true;
		pOrder->DragEnter += gcnew DragEventHandler(this, &Store::pDragEnter);
		pOrder->DragDrop += gcnew DragEventHandler(this, &Store::pDragDrop);

		pRegister->AllowDrop = true;
		pRegister->DragEnter += gcnew DragEventHandler(this, &Store::pDragEnter);
		pRegister->DragDrop += gcnew DragEventHandler(this, &Store::pDragDrop);

		pGet->AllowDrop = true;
		pGet->DragEnter += gcnew DragEventHandler(this, &Store::pDragEnter);
		pGet->DragDrop += gcnew DragEventHandler(this, &Store::pDragDrop);

		pSafe->AllowDrop = true;
		pSafe->DragEnter += gcnew DragEventHandler(this, &Store::pDragEnter);
		pSafe->DragDrop += gcnew DragEventHandler(this, &Store::pDragDrop);

		orderOils = gcnew Dictionary<Type^, Oil^>();
		tokens = gcnew Dictionary<int, Order^>();

		rWarehouse->Lines = dealer->Status->ToArray();
	}
	private: System::Void tMessage_Tick(System::Object^ sender, System::EventArgs^ e)
	{
		auto scroll = gcnew voidVoidDelegate(this, &Store::moveMessage);
		scroll->BeginInvoke(nullptr, nullptr);
	}
	private: System::Void tBlink_Tick(System::Object^ sender, System::EventArgs^ e)
	{
		if (blinkBtn->BackColor == Drawing::SystemColors::ControlLight)
			blinkBtn->BackColor = Drawing::SystemColors::ActiveCaption;
		else
			blinkBtn->BackColor = Drawing::SystemColors::ControlLight;
	}

	private: System::Void nCastrol_ValueChanged(System::Object^ sender, System::EventArgs^ e)
	{
		auto val = Convert::ToInt32(nCastrol->Value);
		alterOrder(val, Castrol::typeid);
	}
	private: System::Void nMobil_ValueChanged(System::Object^ sender, System::EventArgs^ e)
	{
		auto val = Convert::ToInt32(nMobil->Value);
		alterOrder(val, Mobil::typeid);
	}
	private: System::Void nTotal_ValueChanged(System::Object^ sender, System::EventArgs^ e)
	{
		auto val = Convert::ToInt32(nTotal->Value);
		alterOrder(val, Total::typeid);
	}
	private: System::Void nShell_ValueChanged(System::Object^ sender, System::EventArgs^ e)
	{
		auto val = Convert::ToInt32(nShell->Value);
		alterOrder(val, Shell::typeid);
	}

	private: System::Void bOrder_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (orderOils->Count != 0)
		{
			if (order == nullptr)
			{
				this->order = gcnew Order();
				this->order->BackColor = System::Drawing::SystemColors::Info;
				this->order->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				this->order->Cursor = System::Windows::Forms::Cursors::Default;
				this->order->Location = System::Drawing::Point(4, -70);
				this->order->Multiline = true;
				this->order->Name = L"order";
				this->order->ReadOnly = true;
				this->order->Size = System::Drawing::Size(55, 72);
				this->order->TabIndex = 0;
				this->order->Lines = gcnew array<String^>(2) { " ЖЕТОН", " ..." };
				this->order->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Store::order_MouseDown);
				this->pOrder->Controls->Add(this->order);

				auto pullOrderOut = gcnew Action<IAsyncResult^>(this, &Store::pullOrder);
				pullOrderOut->BeginInvoke(nullptr, nullptr, nullptr);

				for each (auto oil in orderOils->Values)
					order->Add(oil);

				orderOils->Clear();	// очищаем словарь масел в заказе после формирования заказа
			}

			auto alterMessage = gcnew Action<String^>(this, &Store::alterMessage);
			alterMessage->BeginInvoke("ТЕПЕРЬ ПЕРЕТАЩИТЕ ЖЕТОН НА ПОЛЕ РЕГИСТРАЦИИ И ЗАРЕГИСТРИРУЙТЕ ЗАКАЗ", nullptr, nullptr);

			blinkBtn->BackColor = Drawing::SystemColors::ControlLight;
			blinkBtn = bRegister;

			nCastrol->Enabled = false;
			nMobil->Enabled = false;
			nTotal->Enabled = false;
			nShell->Enabled = false;
		}
		else
		{
			if (order == nullptr)
			{
				auto alterMessage = gcnew Action<String^>(this, &Store::alterMessage);
				alterMessage->BeginInvoke("НАЧНИТЕ С ФОРМИРОВАНИЯ ЗАКАЗА", nullptr, nullptr);
			}
		}
	}
	private: System::Void order_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{
		if (order->Top == 8)
		{
			auto source = (TextBox^)sender;
			auto parent = source->Parent;

			parent->DoDragDrop(source, DragDropEffects::Move);
		}
	}
	private: System::Void bRegister_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (order != nullptr)
		{
			if (order->Parent == pRegister)
			{
				if (order->Id == 0)
				{
					auto regIn = gcnew voidVoidDelegate(this, &Store::pushOrder);
					auto callBack = gcnew AsyncCallback(this, &Store::pullOrder);
					regIn->BeginInvoke(callBack, order);

					bRegister->BackColor = Drawing::SystemColors::ControlLight;
					blinkBtn = bSafe;

					auto alterMessage = gcnew Action<String^>(this, &Store::alterMessage);
					alterMessage->BeginInvoke("ТЕПЕРЬ ВЫ МОЖЕТЕ СОХРАНИТЬ ЖЕТОН И СДЕЛАТЬ ЕЩЕ ОДИН ЗАКАЗ ЛИБО ДОЖДАТЬСЯ ГОТОВНОСТИ И ПОЛУЧИТЬ ЗАКАЗ", nullptr, nullptr);
				}
				else
					MessageBox::Show("Жетон уже зарегистрирован", "Магазин ГСМ");
			}
			else
				MessageBox::Show("Для регистрации жетона положите его на поле", "Магазин ГСМ");
		}
	}
	private: System::Void bGet_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (order != nullptr)
		{
			if (order->Parent == pGet)
			{
				if (order->Id != 0)
				{
					auto pullToken = gcnew AsyncCallback(this, &Store::pullOrder);
					if (dealer->CompleteOrder(order->Id))
						pullToken = gcnew AsyncCallback(this, &Store::getOrderCallback);

					auto handleToken = gcnew voidVoidDelegate(this, &Store::pushOrder);
					handleToken->BeginInvoke(pullToken, nullptr);
				}
				else
					MessageBox::Show("Зарегистрируйте жетон для сборки заказа", "Магазин ГСМ");
			}
			else
				MessageBox::Show("Для получения заказа положите жетон на поле", "Магазин ГСМ");
		}
	}
	private: System::Void bSafe_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (order != nullptr)
		{
			if (order->Parent == pSafe)
			{
				if (order->Id != 0)
				{
					auto push = gcnew voidVoidDelegate(this, &Store::pushOrder);
					auto callback = gcnew AsyncCallback(this, &Store::saveTokenCallback);
					push->BeginInvoke(callback, order);
				}
				else
					MessageBox::Show("Перед сохранением жетона его необходимо зарегистрировать", "Магазин ГСМ");
			}
			else
				MessageBox::Show("Для сохранения жетона положите его на поле", "Магазин ГСМ");
		}
	}
	private: System::Void bRetrieve_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (order == nullptr)
		{
			auto id = Convert::ToInt32(nSafe->Value);
			if (tokens->ContainsKey(id))
			{
				order = gcnew Order(tokens[id]);
				tokens->Remove(id);

				nCastrol->Enabled = false;
				nMobil->Enabled = false;
				nTotal->Enabled = false;
				nShell->Enabled = false;
				nCastrol->Value = 0;
				nMobil->Value = 0;
				nTotal->Value = 0;
				nShell->Value = 0;
				orderOils->Clear();
				orderOils->Clear();

				order->Parent = pSafe;
				order->MouseDown += gcnew MouseEventHandler(this, &Store::order_MouseDown);

				auto pull = gcnew Action<IAsyncResult^>(this, &Store::pullOrder);
				auto callback = gcnew AsyncCallback(this, &Store::retrieveTokenCallback);
				pull->BeginInvoke(nullptr, callback, nullptr);
			}
			else
				MessageBox::Show(String::Concat("Жетон с номером ", id, " не сохранялся"), "Магазин ГСМ");
		}
		else
			MessageBox::Show("Для выдачи сохраненного жетона сохраните-используйте активный жетон", "Магазин ГСМ");
	}
	private: System::Void bSupply_Click(System::Object^ sender, System::EventArgs^ e)
	{
		dealer->ReplenishWith(20);

		auto handle = gcnew voidVoidDelegate(dealer, &StockDealer::ProcessOrders);
		handle->BeginInvoke(nullptr, nullptr);
	}
	private: System::Void bAbout_Click(System::Object^ sender, System::EventArgs^ e)
	{
		MessageBox::Show("Разработчик:\nГригорий Долгий\nЗЭУ-271\n2020", "Об авторе");
		/*auto draw = gcnew voidVoidDelegate(DesktopDrawer::DrawFace);
		draw->BeginInvoke(nullptr, nullptr);*/
	}
	};
}
