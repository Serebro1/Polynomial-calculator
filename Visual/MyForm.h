#pragma once
#include <msclr/marshal_cppstd.h>
#include "../TasksList/Model.h"

namespace Visual {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		Model& model;
		static MyForm^ _instance = nullptr;
		void UpdateListBox();
		Polinom parsePolinom(const std::string& input);
	private: System::Windows::Forms::ContextMenuStrip^ polinomCMStrip;

	private: System::Windows::Forms::ToolStripMenuItem^ copyPolyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ deletePolyToolStripMenuItem;
		   
	public:
		static property MyForm^ Instance {
			MyForm^ get() { return _instance; }
		}
		MyForm(void): model(Model::getInstance())
		{
			
			InitializeComponent();
			_instance = this;
			
			//
			//TODO: добавьте код конструктора
			//
		}
		property System::Windows::Forms::ListBox^ MainListBox {
			System::Windows::Forms::ListBox^ get() { return this->polinomListBox; }
		}

		void RefreshListBox() {
			UpdateListBox();
		}
	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	protected:
	private: System::Windows::Forms::SplitContainer^ splitContainer1;
	private: System::Windows::Forms::SplitContainer^ splitContainer2;


	private: System::Windows::Forms::GroupBox^ historyGBox;


	private: System::Windows::Forms::ListBox^ polinomListBox;




	private: System::Windows::Forms::TableLayoutPanel^ monomTLPanel;
	private: System::Windows::Forms::Label^ monomLabel;



	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ coeffTBox;
	private: System::Windows::Forms::TextBox^ xTBox;
	private: System::Windows::Forms::TextBox^ yTBox;
	private: System::Windows::Forms::TextBox^ zTBox;




	private: System::Windows::Forms::Button^ addMonomButton;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TableLayoutPanel^ polinomTLPanel;
	private: System::Windows::Forms::Label^ polinomLabel;
	private: System::Windows::Forms::TextBox^ polinomTBox;


	private: System::Windows::Forms::Button^ addPolinombutton;

	private: System::Windows::Forms::Button^ calculatorButton;
	private: System::ComponentModel::IContainer^ components;







	protected:



	protected:



	protected:






	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->monomTLPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->monomLabel = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->coeffTBox = (gcnew System::Windows::Forms::TextBox());
			this->xTBox = (gcnew System::Windows::Forms::TextBox());
			this->yTBox = (gcnew System::Windows::Forms::TextBox());
			this->zTBox = (gcnew System::Windows::Forms::TextBox());
			this->addMonomButton = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->splitContainer2 = (gcnew System::Windows::Forms::SplitContainer());
			this->polinomTLPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->polinomLabel = (gcnew System::Windows::Forms::Label());
			this->polinomTBox = (gcnew System::Windows::Forms::TextBox());
			this->addPolinombutton = (gcnew System::Windows::Forms::Button());
			this->calculatorButton = (gcnew System::Windows::Forms::Button());
			this->historyGBox = (gcnew System::Windows::Forms::GroupBox());
			this->polinomListBox = (gcnew System::Windows::Forms::ListBox());
			this->polinomCMStrip = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->copyPolyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deletePolyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->monomTLPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->BeginInit();
			this->splitContainer2->Panel1->SuspendLayout();
			this->splitContainer2->Panel2->SuspendLayout();
			this->splitContainer2->SuspendLayout();
			this->polinomTLPanel->SuspendLayout();
			this->historyGBox->SuspendLayout();
			this->polinomCMStrip->SuspendLayout();
			this->SuspendLayout();
			// 
			// splitContainer1
			// 
			this->splitContainer1->BackColor = System::Drawing::SystemColors::Control;
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->splitContainer1->Location = System::Drawing::Point(0, 595);
			this->splitContainer1->Margin = System::Windows::Forms::Padding(4);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->monomTLPanel);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->splitContainer2);
			this->splitContainer1->Size = System::Drawing::Size(539, 185);
			this->splitContainer1->SplitterDistance = 174;
			this->splitContainer1->SplitterWidth = 5;
			this->splitContainer1->TabIndex = 1;
			// 
			// monomTLPanel
			// 
			this->monomTLPanel->BackColor = System::Drawing::Color::Gainsboro;
			this->monomTLPanel->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Single;
			this->monomTLPanel->ColumnCount = 2;
			this->monomTLPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->monomTLPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->monomTLPanel->Controls->Add(this->monomLabel, 0, 0);
			this->monomTLPanel->Controls->Add(this->label1, 0, 1);
			this->monomTLPanel->Controls->Add(this->coeffTBox, 1, 1);
			this->monomTLPanel->Controls->Add(this->xTBox, 1, 2);
			this->monomTLPanel->Controls->Add(this->yTBox, 1, 3);
			this->monomTLPanel->Controls->Add(this->zTBox, 1, 4);
			this->monomTLPanel->Controls->Add(this->addMonomButton, 0, 5);
			this->monomTLPanel->Controls->Add(this->label2, 0, 2);
			this->monomTLPanel->Controls->Add(this->label3, 0, 3);
			this->monomTLPanel->Controls->Add(this->label4, 0, 4);
			this->monomTLPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->monomTLPanel->Location = System::Drawing::Point(0, 0);
			this->monomTLPanel->Margin = System::Windows::Forms::Padding(4);
			this->monomTLPanel->Name = L"monomTLPanel";
			this->monomTLPanel->RowCount = 6;
			this->monomTLPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.32653F)));
			this->monomTLPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.32653F)));
			this->monomTLPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.32653F)));
			this->monomTLPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.32653F)));
			this->monomTLPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.32653F)));
			this->monomTLPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 18.36735F)));
			this->monomTLPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 25)));
			this->monomTLPanel->Size = System::Drawing::Size(174, 185);
			this->monomTLPanel->TabIndex = 0;
			// 
			// monomLabel
			// 
			this->monomLabel->AutoSize = true;
			this->monomTLPanel->SetColumnSpan(this->monomLabel, 2);
			this->monomLabel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->monomLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->monomLabel->Location = System::Drawing::Point(5, 1);
			this->monomLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->monomLabel->Name = L"monomLabel";
			this->monomLabel->Size = System::Drawing::Size(164, 29);
			this->monomLabel->TabIndex = 0;
			this->monomLabel->Text = L"Monomial";
			this->monomLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label1->Location = System::Drawing::Point(5, 31);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(77, 29);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Coefficient";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// coeffTBox
			// 
			this->coeffTBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->coeffTBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->coeffTBox->Font = (gcnew System::Drawing::Font(L"Arial", 7.8F));
			this->coeffTBox->Location = System::Drawing::Point(91, 35);
			this->coeffTBox->Margin = System::Windows::Forms::Padding(4);
			this->coeffTBox->Multiline = true;
			this->coeffTBox->Name = L"coeffTBox";
			this->coeffTBox->Size = System::Drawing::Size(78, 21);
			this->coeffTBox->TabIndex = 2;
			// 
			// xTBox
			// 
			this->xTBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->xTBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->xTBox->Font = (gcnew System::Drawing::Font(L"Arial", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->xTBox->Location = System::Drawing::Point(91, 65);
			this->xTBox->Margin = System::Windows::Forms::Padding(4);
			this->xTBox->Multiline = true;
			this->xTBox->Name = L"xTBox";
			this->xTBox->Size = System::Drawing::Size(78, 21);
			this->xTBox->TabIndex = 3;
			// 
			// yTBox
			// 
			this->yTBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->yTBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->yTBox->Font = (gcnew System::Drawing::Font(L"Arial", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->yTBox->Location = System::Drawing::Point(91, 95);
			this->yTBox->Margin = System::Windows::Forms::Padding(4);
			this->yTBox->Multiline = true;
			this->yTBox->Name = L"yTBox";
			this->yTBox->Size = System::Drawing::Size(78, 21);
			this->yTBox->TabIndex = 4;
			// 
			// zTBox
			// 
			this->zTBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->zTBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->zTBox->Font = (gcnew System::Drawing::Font(L"Arial", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->zTBox->Location = System::Drawing::Point(91, 125);
			this->zTBox->Margin = System::Windows::Forms::Padding(4);
			this->zTBox->Multiline = true;
			this->zTBox->Name = L"zTBox";
			this->zTBox->Size = System::Drawing::Size(78, 21);
			this->zTBox->TabIndex = 5;
			// 
			// addMonomButton
			// 
			this->addMonomButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->addMonomButton->AutoSize = true;
			this->addMonomButton->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->addMonomButton->BackColor = System::Drawing::Color::AliceBlue;
			this->monomTLPanel->SetColumnSpan(this->addMonomButton, 2);
			this->addMonomButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->addMonomButton->Location = System::Drawing::Point(5, 155);
			this->addMonomButton->Margin = System::Windows::Forms::Padding(4);
			this->addMonomButton->Name = L"addMonomButton";
			this->addMonomButton->Size = System::Drawing::Size(164, 25);
			this->addMonomButton->TabIndex = 6;
			this->addMonomButton->Text = L"Add";
			this->addMonomButton->UseVisualStyleBackColor = false;
			this->addMonomButton->Click += gcnew System::EventHandler(this, &MyForm::addMonomButton_Click);
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label2->Location = System::Drawing::Point(5, 65);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(77, 20);
			this->label2->TabIndex = 7;
			this->label2->Text = L"X";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label3
			// 
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label3->Location = System::Drawing::Point(5, 95);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(77, 20);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Y";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label4->Location = System::Drawing::Point(5, 121);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(77, 29);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Z";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// splitContainer2
			// 
			this->splitContainer2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer2->Location = System::Drawing::Point(0, 0);
			this->splitContainer2->Margin = System::Windows::Forms::Padding(4);
			this->splitContainer2->Name = L"splitContainer2";
			// 
			// splitContainer2.Panel1
			// 
			this->splitContainer2->Panel1->BackColor = System::Drawing::SystemColors::Control;
			this->splitContainer2->Panel1->Controls->Add(this->polinomTLPanel);
			// 
			// splitContainer2.Panel2
			// 
			this->splitContainer2->Panel2->Controls->Add(this->calculatorButton);
			this->splitContainer2->Size = System::Drawing::Size(360, 185);
			this->splitContainer2->SplitterDistance = 214;
			this->splitContainer2->SplitterWidth = 5;
			this->splitContainer2->TabIndex = 0;
			// 
			// polinomTLPanel
			// 
			this->polinomTLPanel->BackColor = System::Drawing::Color::Gainsboro;
			this->polinomTLPanel->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Single;
			this->polinomTLPanel->ColumnCount = 1;
			this->polinomTLPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->polinomTLPanel->Controls->Add(this->polinomLabel, 0, 0);
			this->polinomTLPanel->Controls->Add(this->polinomTBox, 0, 1);
			this->polinomTLPanel->Controls->Add(this->addPolinombutton, 0, 2);
			this->polinomTLPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->polinomTLPanel->Location = System::Drawing::Point(0, 0);
			this->polinomTLPanel->Margin = System::Windows::Forms::Padding(4);
			this->polinomTLPanel->Name = L"polinomTLPanel";
			this->polinomTLPanel->RowCount = 6;
			this->polinomTLPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.33327F)));
			this->polinomTLPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.33327F)));
			this->polinomTLPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.33327F)));
			this->polinomTLPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.33327F)));
			this->polinomTLPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.33327F)));
			this->polinomTLPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 18.33367F)));
			this->polinomTLPanel->Size = System::Drawing::Size(214, 185);
			this->polinomTLPanel->TabIndex = 0;
			// 
			// polinomLabel
			// 
			this->polinomLabel->AutoSize = true;
			this->polinomLabel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->polinomLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold));
			this->polinomLabel->Location = System::Drawing::Point(5, 1);
			this->polinomLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->polinomLabel->Name = L"polinomLabel";
			this->polinomLabel->Size = System::Drawing::Size(204, 29);
			this->polinomLabel->TabIndex = 0;
			this->polinomLabel->Text = L"Polynomial";
			this->polinomLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// polinomTBox
			// 
			this->polinomTBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->polinomTBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->polinomTBox->Font = (gcnew System::Drawing::Font(L"Arial", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->polinomTBox->Location = System::Drawing::Point(5, 35);
			this->polinomTBox->Margin = System::Windows::Forms::Padding(4);
			this->polinomTBox->Multiline = true;
			this->polinomTBox->Name = L"polinomTBox";
			this->polinomTLPanel->SetRowSpan(this->polinomTBox, 4);
			this->polinomTBox->Size = System::Drawing::Size(204, 111);
			this->polinomTBox->TabIndex = 1;
			this->polinomTBox->Text = L"4.5*x^4 + 1.2 * z ^ 2 + 2.1 * y^1";
			// 
			// addPolinombutton
			// 
			this->addPolinombutton->BackColor = System::Drawing::Color::AliceBlue;
			this->addPolinombutton->Dock = System::Windows::Forms::DockStyle::Fill;
			this->addPolinombutton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->addPolinombutton->Location = System::Drawing::Point(5, 155);
			this->addPolinombutton->Margin = System::Windows::Forms::Padding(4);
			this->addPolinombutton->Name = L"addPolinombutton";
			this->addPolinombutton->Size = System::Drawing::Size(204, 25);
			this->addPolinombutton->TabIndex = 2;
			this->addPolinombutton->Text = L"Add";
			this->addPolinombutton->UseVisualStyleBackColor = false;
			this->addPolinombutton->Click += gcnew System::EventHandler(this, &MyForm::addPolinombutton_Click);
			// 
			// calculatorButton
			// 
			this->calculatorButton->BackColor = System::Drawing::Color::AliceBlue;
			this->calculatorButton->Dock = System::Windows::Forms::DockStyle::Fill;
			this->calculatorButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold));
			this->calculatorButton->Location = System::Drawing::Point(0, 0);
			this->calculatorButton->Margin = System::Windows::Forms::Padding(4);
			this->calculatorButton->Name = L"calculatorButton";
			this->calculatorButton->Size = System::Drawing::Size(141, 185);
			this->calculatorButton->TabIndex = 0;
			this->calculatorButton->Text = L"Calculate Polynomial";
			this->calculatorButton->UseVisualStyleBackColor = false;
			this->calculatorButton->Click += gcnew System::EventHandler(this, &MyForm::calculatorButton_Click);
			// 
			// historyGBox
			// 
			this->historyGBox->Controls->Add(this->polinomListBox);
			this->historyGBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->historyGBox->Location = System::Drawing::Point(0, 0);
			this->historyGBox->Margin = System::Windows::Forms::Padding(4);
			this->historyGBox->Name = L"historyGBox";
			this->historyGBox->Padding = System::Windows::Forms::Padding(4);
			this->historyGBox->Size = System::Drawing::Size(539, 595);
			this->historyGBox->TabIndex = 2;
			this->historyGBox->TabStop = false;
			this->historyGBox->Text = L"History";
			// 
			// polinomListBox
			// 
			this->polinomListBox->ContextMenuStrip = this->polinomCMStrip;
			this->polinomListBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->polinomListBox->Font = (gcnew System::Drawing::Font(L"Arial", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->polinomListBox->FormattingEnabled = true;
			this->polinomListBox->ItemHeight = 19;
			this->polinomListBox->Location = System::Drawing::Point(4, 19);
			this->polinomListBox->Margin = System::Windows::Forms::Padding(4);
			this->polinomListBox->Name = L"polinomListBox";
			this->polinomListBox->Size = System::Drawing::Size(531, 572);
			this->polinomListBox->TabIndex = 0;
			this->polinomListBox->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::polinomListBox_MouseDown);
			// 
			// polinomCMStrip
			// 
			this->polinomCMStrip->ImageScalingSize = System::Drawing::Size(20, 20);
			this->polinomCMStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->copyPolyToolStripMenuItem,
					this->deletePolyToolStripMenuItem
			});
			this->polinomCMStrip->Name = L"polyCMStrip";
			this->polinomCMStrip->Size = System::Drawing::Size(156, 52);
			// 
			// copyPolyToolStripMenuItem
			// 
			this->copyPolyToolStripMenuItem->Name = L"copyPolyToolStripMenuItem";
			this->copyPolyToolStripMenuItem->Size = System::Drawing::Size(210, 24);
			this->copyPolyToolStripMenuItem->Text = L"Copy poly";
			this->copyPolyToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::copyPolyToolStripMenuItem_Click);
			// 
			// deletePolyToolStripMenuItem
			// 
			this->deletePolyToolStripMenuItem->Name = L"deletePolyToolStripMenuItem";
			this->deletePolyToolStripMenuItem->Size = System::Drawing::Size(210, 24);
			this->deletePolyToolStripMenuItem->Text = L"Delete poly";
			this->deletePolyToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::deletePolyToolStripMenuItem_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(539, 780);
			this->Controls->Add(this->historyGBox);
			this->Controls->Add(this->splitContainer1);
			this->DoubleBuffered = true;
			this->Margin = System::Windows::Forms::Padding(4);
			this->MinimumSize = System::Drawing::Size(557, 47);
			this->Name = L"MyForm";
			this->Text = L"Polinom Calculator";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->monomTLPanel->ResumeLayout(false);
			this->monomTLPanel->PerformLayout();
			this->splitContainer2->Panel1->ResumeLayout(false);
			this->splitContainer2->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->EndInit();
			this->splitContainer2->ResumeLayout(false);
			this->polinomTLPanel->ResumeLayout(false);
			this->polinomTLPanel->PerformLayout();
			this->historyGBox->ResumeLayout(false);
			this->polinomCMStrip->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void addMonomButton_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void calculatorButton_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	UpdateListBox();
}
private: System::Void addPolinombutton_Click(System::Object^ sender, System::EventArgs^ e);
	

private: System::Void copyPolyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void deletePolyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void polinomListBox_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
};
}
