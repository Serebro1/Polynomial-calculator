#pragma once
#include <stdlib.h>
#include "../TasksList/Model.h"

namespace Visual {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ PolinomCalculator
	/// </summary>
	public ref class PolinomCalculator sealed : public System::Windows::Forms::Form
	{
	private:
		static PolinomCalculator^ instance = nullptr;
		std::vector<Polinom>* buffer;
		PolinomCalculator(void)
		{
			InitializeComponent();
			buffer = new std::vector<Polinom>(Model::getInstance().getPolinoms());

		}
	public:
		static property PolinomCalculator^ Instance {
			PolinomCalculator^ get() {
				if (instance == nullptr || instance->IsDisposed)
					instance = gcnew PolinomCalculator();
				return instance;
			}
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~PolinomCalculator()
		{
			if (buffer != nullptr) {
				delete buffer;
				buffer = nullptr;
			}
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnAttach;
	private: System::Windows::Forms::Button^ btnCancel;
	private: System::Windows::Forms::Button^ btnSave;
	private: System::Windows::Forms::TextBox^ calculTBox;
	private: System::Windows::Forms::Button^ btnEnter;
	private: System::Windows::Forms::Button^ btnBack;


	private: System::Windows::Forms::Button^ btnClear;

	private: System::Windows::Forms::Button^ btnZero;
	private: System::Windows::Forms::Button^ btnPlus;


	private: System::Windows::Forms::Button^ btnThree;

	private: System::Windows::Forms::Button^ btnTwo;

	private: System::Windows::Forms::Button^ btnOne;
	private: System::Windows::Forms::Button^ btnMinus;


	private: System::Windows::Forms::Button^ btnSix;

	private: System::Windows::Forms::Button^ btnFive;

	private: System::Windows::Forms::Button^ btnFour;
	private: System::Windows::Forms::Button^ btnMult;


	private: System::Windows::Forms::Button^ btnNine;

	private: System::Windows::Forms::Button^ btnEight;

	private: System::Windows::Forms::Button^ btnSeven;

	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->btnEnter = (gcnew System::Windows::Forms::Button());
			this->btnBack = (gcnew System::Windows::Forms::Button());
			this->btnClear = (gcnew System::Windows::Forms::Button());
			this->btnZero = (gcnew System::Windows::Forms::Button());
			this->btnPlus = (gcnew System::Windows::Forms::Button());
			this->btnThree = (gcnew System::Windows::Forms::Button());
			this->btnTwo = (gcnew System::Windows::Forms::Button());
			this->btnOne = (gcnew System::Windows::Forms::Button());
			this->btnMinus = (gcnew System::Windows::Forms::Button());
			this->btnSix = (gcnew System::Windows::Forms::Button());
			this->btnFive = (gcnew System::Windows::Forms::Button());
			this->btnFour = (gcnew System::Windows::Forms::Button());
			this->btnMult = (gcnew System::Windows::Forms::Button());
			this->btnNine = (gcnew System::Windows::Forms::Button());
			this->btnEight = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnAttach = (gcnew System::Windows::Forms::Button());
			this->calculTBox = (gcnew System::Windows::Forms::TextBox());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->btnSave = (gcnew System::Windows::Forms::Button());
			this->btnSeven = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->BackColor = System::Drawing::Color::Gainsboro;
			this->tableLayoutPanel1->ColumnCount = 4;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel1->Controls->Add(this->btnEnter, 3, 5);
			this->tableLayoutPanel1->Controls->Add(this->btnBack, 2, 5);
			this->tableLayoutPanel1->Controls->Add(this->btnClear, 1, 5);
			this->tableLayoutPanel1->Controls->Add(this->btnZero, 0, 5);
			this->tableLayoutPanel1->Controls->Add(this->btnPlus, 3, 4);
			this->tableLayoutPanel1->Controls->Add(this->btnThree, 2, 4);
			this->tableLayoutPanel1->Controls->Add(this->btnTwo, 1, 4);
			this->tableLayoutPanel1->Controls->Add(this->btnOne, 0, 4);
			this->tableLayoutPanel1->Controls->Add(this->btnMinus, 3, 3);
			this->tableLayoutPanel1->Controls->Add(this->btnSix, 2, 3);
			this->tableLayoutPanel1->Controls->Add(this->btnFive, 1, 3);
			this->tableLayoutPanel1->Controls->Add(this->btnFour, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->btnMult, 3, 2);
			this->tableLayoutPanel1->Controls->Add(this->btnNine, 2, 2);
			this->tableLayoutPanel1->Controls->Add(this->btnEight, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->btnAttach, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->calculTBox, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->btnCancel, 0, 6);
			this->tableLayoutPanel1->Controls->Add(this->btnSave, 2, 6);
			this->tableLayoutPanel1->Controls->Add(this->btnSeven, 0, 2);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 7;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 14.28571F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 14.28571F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 14.28571F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 14.28571F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 14.28571F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 14.28571F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 14.28571F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(312, 421);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// btnEnter
			// 
			this->btnEnter->BackColor = System::Drawing::Color::Azure;
			this->btnEnter->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnEnter->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold));
			this->btnEnter->Location = System::Drawing::Point(237, 303);
			this->btnEnter->Name = L"btnEnter";
			this->btnEnter->Size = System::Drawing::Size(72, 54);
			this->btnEnter->TabIndex = 20;
			this->btnEnter->Text = L"=";
			this->btnEnter->UseVisualStyleBackColor = false;
			this->btnEnter->Click += gcnew System::EventHandler(this, &PolinomCalculator::btnEnter_Click);
			// 
			// btnBack
			// 
			this->btnBack->BackColor = System::Drawing::Color::Azure;
			this->btnBack->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnBack->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold));
			this->btnBack->Location = System::Drawing::Point(159, 303);
			this->btnBack->Name = L"btnBack";
			this->btnBack->Size = System::Drawing::Size(72, 54);
			this->btnBack->TabIndex = 19;
			this->btnBack->Text = L"<";
			this->btnBack->UseVisualStyleBackColor = false;
			this->btnBack->Click += gcnew System::EventHandler(this, &PolinomCalculator::btnBack_Click);
			// 
			// btnClear
			// 
			this->btnClear->BackColor = System::Drawing::Color::Azure;
			this->btnClear->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnClear->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold));
			this->btnClear->Location = System::Drawing::Point(81, 303);
			this->btnClear->Name = L"btnClear";
			this->btnClear->Size = System::Drawing::Size(72, 54);
			this->btnClear->TabIndex = 18;
			this->btnClear->Text = L"C";
			this->btnClear->UseVisualStyleBackColor = false;
			this->btnClear->Click += gcnew System::EventHandler(this, &PolinomCalculator::btnClear_Click);
			// 
			// btnZero
			// 
			this->btnZero->BackColor = System::Drawing::Color::LightBlue;
			this->btnZero->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnZero->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold));
			this->btnZero->Location = System::Drawing::Point(3, 303);
			this->btnZero->Name = L"btnZero";
			this->btnZero->Size = System::Drawing::Size(72, 54);
			this->btnZero->TabIndex = 17;
			this->btnZero->Text = L"0";
			this->btnZero->UseVisualStyleBackColor = false;
			this->btnZero->Click += gcnew System::EventHandler(this, &PolinomCalculator::btnCalc_Click);
			// 
			// btnPlus
			// 
			this->btnPlus->BackColor = System::Drawing::Color::Azure;
			this->btnPlus->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnPlus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold));
			this->btnPlus->Location = System::Drawing::Point(237, 243);
			this->btnPlus->Name = L"btnPlus";
			this->btnPlus->Size = System::Drawing::Size(72, 54);
			this->btnPlus->TabIndex = 16;
			this->btnPlus->Text = L"+";
			this->btnPlus->UseVisualStyleBackColor = false;
			this->btnPlus->Click += gcnew System::EventHandler(this, &PolinomCalculator::btnCalc_Click);
			// 
			// btnThree
			// 
			this->btnThree->BackColor = System::Drawing::Color::LightBlue;
			this->btnThree->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnThree->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold));
			this->btnThree->Location = System::Drawing::Point(159, 243);
			this->btnThree->Name = L"btnThree";
			this->btnThree->Size = System::Drawing::Size(72, 54);
			this->btnThree->TabIndex = 15;
			this->btnThree->Text = L"3";
			this->btnThree->UseVisualStyleBackColor = false;
			this->btnThree->Click += gcnew System::EventHandler(this, &PolinomCalculator::btnCalc_Click);
			// 
			// btnTwo
			// 
			this->btnTwo->BackColor = System::Drawing::Color::LightBlue;
			this->btnTwo->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnTwo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold));
			this->btnTwo->Location = System::Drawing::Point(81, 243);
			this->btnTwo->Name = L"btnTwo";
			this->btnTwo->Size = System::Drawing::Size(72, 54);
			this->btnTwo->TabIndex = 14;
			this->btnTwo->Text = L"2";
			this->btnTwo->UseVisualStyleBackColor = false;
			this->btnTwo->Click += gcnew System::EventHandler(this, &PolinomCalculator::btnCalc_Click);
			// 
			// btnOne
			// 
			this->btnOne->BackColor = System::Drawing::Color::LightBlue;
			this->btnOne->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnOne->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold));
			this->btnOne->Location = System::Drawing::Point(3, 243);
			this->btnOne->Name = L"btnOne";
			this->btnOne->Size = System::Drawing::Size(72, 54);
			this->btnOne->TabIndex = 13;
			this->btnOne->Text = L"1";
			this->btnOne->UseVisualStyleBackColor = false;
			this->btnOne->Click += gcnew System::EventHandler(this, &PolinomCalculator::btnCalc_Click);
			// 
			// btnMinus
			// 
			this->btnMinus->BackColor = System::Drawing::Color::Azure;
			this->btnMinus->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnMinus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold));
			this->btnMinus->Location = System::Drawing::Point(237, 183);
			this->btnMinus->Name = L"btnMinus";
			this->btnMinus->Size = System::Drawing::Size(72, 54);
			this->btnMinus->TabIndex = 12;
			this->btnMinus->Text = L"-";
			this->btnMinus->UseVisualStyleBackColor = false;
			this->btnMinus->Click += gcnew System::EventHandler(this, &PolinomCalculator::btnCalc_Click);
			// 
			// btnSix
			// 
			this->btnSix->BackColor = System::Drawing::Color::LightBlue;
			this->btnSix->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnSix->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold));
			this->btnSix->Location = System::Drawing::Point(159, 183);
			this->btnSix->Name = L"btnSix";
			this->btnSix->Size = System::Drawing::Size(72, 54);
			this->btnSix->TabIndex = 11;
			this->btnSix->Text = L"6";
			this->btnSix->UseVisualStyleBackColor = false;
			this->btnSix->Click += gcnew System::EventHandler(this, &PolinomCalculator::btnCalc_Click);
			// 
			// btnFive
			// 
			this->btnFive->BackColor = System::Drawing::Color::LightBlue;
			this->btnFive->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnFive->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold));
			this->btnFive->Location = System::Drawing::Point(81, 183);
			this->btnFive->Name = L"btnFive";
			this->btnFive->Size = System::Drawing::Size(72, 54);
			this->btnFive->TabIndex = 10;
			this->btnFive->Text = L"5";
			this->btnFive->UseVisualStyleBackColor = false;
			this->btnFive->Click += gcnew System::EventHandler(this, &PolinomCalculator::btnCalc_Click);
			// 
			// btnFour
			// 
			this->btnFour->BackColor = System::Drawing::Color::LightBlue;
			this->btnFour->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnFour->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold));
			this->btnFour->Location = System::Drawing::Point(3, 183);
			this->btnFour->Name = L"btnFour";
			this->btnFour->Size = System::Drawing::Size(72, 54);
			this->btnFour->TabIndex = 9;
			this->btnFour->Text = L"4";
			this->btnFour->UseVisualStyleBackColor = false;
			this->btnFour->Click += gcnew System::EventHandler(this, &PolinomCalculator::btnCalc_Click);
			// 
			// btnMult
			// 
			this->btnMult->BackColor = System::Drawing::Color::Azure;
			this->btnMult->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnMult->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold));
			this->btnMult->Location = System::Drawing::Point(237, 123);
			this->btnMult->Name = L"btnMult";
			this->btnMult->Size = System::Drawing::Size(72, 54);
			this->btnMult->TabIndex = 8;
			this->btnMult->Text = L"*";
			this->btnMult->UseVisualStyleBackColor = false;
			this->btnMult->Click += gcnew System::EventHandler(this, &PolinomCalculator::btnCalc_Click);
			// 
			// btnNine
			// 
			this->btnNine->BackColor = System::Drawing::Color::LightBlue;
			this->btnNine->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnNine->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold));
			this->btnNine->Location = System::Drawing::Point(159, 123);
			this->btnNine->Name = L"btnNine";
			this->btnNine->Size = System::Drawing::Size(72, 54);
			this->btnNine->TabIndex = 7;
			this->btnNine->Text = L"9";
			this->btnNine->UseVisualStyleBackColor = false;
			this->btnNine->Click += gcnew System::EventHandler(this, &PolinomCalculator::btnCalc_Click);
			// 
			// btnEight
			// 
			this->btnEight->BackColor = System::Drawing::Color::LightBlue;
			this->btnEight->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnEight->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold));
			this->btnEight->Location = System::Drawing::Point(81, 123);
			this->btnEight->Name = L"btnEight";
			this->btnEight->Size = System::Drawing::Size(72, 54);
			this->btnEight->TabIndex = 6;
			this->btnEight->Text = L"8";
			this->btnEight->UseVisualStyleBackColor = false;
			this->btnEight->Click += gcnew System::EventHandler(this, &PolinomCalculator::btnCalc_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->tableLayoutPanel1->SetColumnSpan(this->label1, 2);
			this->label1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold));
			this->label1->Location = System::Drawing::Point(3, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(150, 60);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Calculator";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// btnAttach
			// 
			this->btnAttach->BackColor = System::Drawing::Color::PeachPuff;
			this->tableLayoutPanel1->SetColumnSpan(this->btnAttach, 2);
			this->btnAttach->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnAttach->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->btnAttach->Location = System::Drawing::Point(159, 3);
			this->btnAttach->Name = L"btnAttach";
			this->btnAttach->Size = System::Drawing::Size(150, 54);
			this->btnAttach->TabIndex = 1;
			this->btnAttach->Text = L"Detach";
			this->btnAttach->UseVisualStyleBackColor = false;
			this->btnAttach->Click += gcnew System::EventHandler(this, &PolinomCalculator::btnAttach_Click);
			// 
			// calculTBox
			// 
			this->calculTBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->calculTBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tableLayoutPanel1->SetColumnSpan(this->calculTBox, 4);
			this->calculTBox->Font = (gcnew System::Drawing::Font(L"Arial", 10));
			this->calculTBox->Location = System::Drawing::Point(3, 76);
			this->calculTBox->Name = L"calculTBox";
			this->calculTBox->ReadOnly = true;
			this->calculTBox->Size = System::Drawing::Size(306, 27);
			this->calculTBox->TabIndex = 4;
			// 
			// btnCancel
			// 
			this->btnCancel->BackColor = System::Drawing::Color::Pink;
			this->tableLayoutPanel1->SetColumnSpan(this->btnCancel, 2);
			this->btnCancel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnCancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->btnCancel->Location = System::Drawing::Point(3, 363);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(150, 55);
			this->btnCancel->TabIndex = 2;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = false;
			this->btnCancel->Click += gcnew System::EventHandler(this, &PolinomCalculator::btnCancel_Click);
			// 
			// btnSave
			// 
			this->btnSave->BackColor = System::Drawing::Color::PaleGreen;
			this->tableLayoutPanel1->SetColumnSpan(this->btnSave, 2);
			this->btnSave->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnSave->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->btnSave->Location = System::Drawing::Point(159, 363);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(150, 55);
			this->btnSave->TabIndex = 3;
			this->btnSave->Text = L"Save";
			this->btnSave->UseVisualStyleBackColor = false;
			this->btnSave->Click += gcnew System::EventHandler(this, &PolinomCalculator::btnSave_Click);
			// 
			// btnSeven
			// 
			this->btnSeven->BackColor = System::Drawing::Color::LightBlue;
			this->btnSeven->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnSeven->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold));
			this->btnSeven->Location = System::Drawing::Point(3, 123);
			this->btnSeven->Name = L"btnSeven";
			this->btnSeven->Size = System::Drawing::Size(72, 54);
			this->btnSeven->TabIndex = 5;
			this->btnSeven->Text = L"7";
			this->btnSeven->UseVisualStyleBackColor = false;
			this->btnSeven->Click += gcnew System::EventHandler(this, &PolinomCalculator::btnCalc_Click);
			// 
			// PolinomCalculator
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(312, 421);
			this->Controls->Add(this->tableLayoutPanel1);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::SizableToolWindow;
			this->KeyPreview = true;
			this->MinimumSize = System::Drawing::Size(330, 439);
			this->Name = L"PolinomCalculator";
			this->Text = L"PolinomCalculator";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &PolinomCalculator::PolinomCalculator_FormClosed);
			this->LocationChanged += gcnew System::EventHandler(this, &PolinomCalculator::PolinomCalculator_LocationChanged);
			this->SizeChanged += gcnew System::EventHandler(this, &PolinomCalculator::PolinomCalculator_SizeChanged);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &PolinomCalculator::PolinomCalculator_KeyDown);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &PolinomCalculator::PolinomCalculator_MouseDown);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private:
		static const int MY_WM_ENTERSIZEMOVE = 0x0231;
		static const int MY_WM_MOVING = 0x0216;
		bool isAttached = false;
		Form^ parentForm = nullptr;

	protected:
		virtual void WndProc(Message% m) override;
	public:
		void Attach(Form^ parent);
		void Detach();
	private:
		void UpdateLBWithBuffer();

		void UpdatePosition();
		void PolinomCalculator_MouseDown(Object^ sender, MouseEventArgs^ e);
		void PolinomCalculator_SizeChanged(Object^ sender, EventArgs^ e);
		void PolinomCalculator_LocationChanged(Object^ sender, EventArgs^ e);
		void parentForm_LocationChanged(Object^ sender, EventArgs^ e);
		void parentForm_SizeChanged(Object^ sender, EventArgs^ e);
		void CheckForSmartDocking();

		System::Void btnAttach_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btnSave_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void PolinomCalculator_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);
		System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e);

		System::Void btnCalc_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btnEnter_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btnBack_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btnClear_Click(System::Object^ sender, System::EventArgs^ e);

		System::Void PolinomCalculator_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e);
		void HandleDigitKey(KeyEventArgs^ e);
		void HandleBackSpaceKey();
		void CalculatePolinoms();
};
}
