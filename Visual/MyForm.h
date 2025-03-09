#pragma once

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
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
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







	protected:



	protected:



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
			this->historyGBox = (gcnew System::Windows::Forms::GroupBox());
			this->polinomListBox = (gcnew System::Windows::Forms::ListBox());
			this->polinomTLPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->polinomLabel = (gcnew System::Windows::Forms::Label());
			this->polinomTBox = (gcnew System::Windows::Forms::TextBox());
			this->addPolinombutton = (gcnew System::Windows::Forms::Button());
			this->calculatorButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->monomTLPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->BeginInit();
			this->splitContainer2->Panel1->SuspendLayout();
			this->splitContainer2->Panel2->SuspendLayout();
			this->splitContainer2->SuspendLayout();
			this->historyGBox->SuspendLayout();
			this->polinomTLPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// splitContainer1
			// 
			this->splitContainer1->BackColor = System::Drawing::SystemColors::Control;
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->splitContainer1->Location = System::Drawing::Point(0, 484);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->monomTLPanel);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->splitContainer2);
			this->splitContainer1->Size = System::Drawing::Size(404, 150);
			this->splitContainer1->SplitterDistance = 131;
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
			this->monomTLPanel->Name = L"monomTLPanel";
			this->monomTLPanel->RowCount = 6;
			this->monomTLPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.32653F)));
			this->monomTLPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.32653F)));
			this->monomTLPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.32653F)));
			this->monomTLPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.32653F)));
			this->monomTLPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.32653F)));
			this->monomTLPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 18.36735F)));
			this->monomTLPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->monomTLPanel->Size = System::Drawing::Size(131, 150);
			this->monomTLPanel->TabIndex = 0;
			// 
			// monomLabel
			// 
			this->monomLabel->AutoSize = true;
			this->monomTLPanel->SetColumnSpan(this->monomLabel, 2);
			this->monomLabel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->monomLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->monomLabel->Location = System::Drawing::Point(4, 1);
			this->monomLabel->Name = L"monomLabel";
			this->monomLabel->Size = System::Drawing::Size(123, 23);
			this->monomLabel->TabIndex = 0;
			this->monomLabel->Text = L"Monomial";
			this->monomLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label1->Location = System::Drawing::Point(4, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(58, 23);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Coefficient";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// coeffTBox
			// 
			this->coeffTBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->coeffTBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->coeffTBox->Location = System::Drawing::Point(69, 28);
			this->coeffTBox->Multiline = true;
			this->coeffTBox->Name = L"coeffTBox";
			this->coeffTBox->Size = System::Drawing::Size(58, 17);
			this->coeffTBox->TabIndex = 2;
			// 
			// xTBox
			// 
			this->xTBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->xTBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->xTBox->Location = System::Drawing::Point(69, 52);
			this->xTBox->Multiline = true;
			this->xTBox->Name = L"xTBox";
			this->xTBox->Size = System::Drawing::Size(58, 17);
			this->xTBox->TabIndex = 3;
			// 
			// yTBox
			// 
			this->yTBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->yTBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->yTBox->Location = System::Drawing::Point(69, 76);
			this->yTBox->Multiline = true;
			this->yTBox->Name = L"yTBox";
			this->yTBox->Size = System::Drawing::Size(58, 17);
			this->yTBox->TabIndex = 4;
			// 
			// zTBox
			// 
			this->zTBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->zTBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->zTBox->Location = System::Drawing::Point(69, 100);
			this->zTBox->Multiline = true;
			this->zTBox->Name = L"zTBox";
			this->zTBox->Size = System::Drawing::Size(58, 17);
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
			this->addMonomButton->Location = System::Drawing::Point(4, 124);
			this->addMonomButton->Name = L"addMonomButton";
			this->addMonomButton->Size = System::Drawing::Size(123, 22);
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
			this->label2->Location = System::Drawing::Point(4, 52);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(58, 17);
			this->label2->TabIndex = 7;
			this->label2->Text = L"X";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label3
			// 
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label3->Location = System::Drawing::Point(4, 76);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(58, 17);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Y";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label4->Location = System::Drawing::Point(4, 97);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(58, 23);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Z";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// splitContainer2
			// 
			this->splitContainer2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer2->Location = System::Drawing::Point(0, 0);
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
			this->splitContainer2->Size = System::Drawing::Size(269, 150);
			this->splitContainer2->SplitterDistance = 160;
			this->splitContainer2->TabIndex = 0;
			// 
			// historyGBox
			// 
			this->historyGBox->Controls->Add(this->polinomListBox);
			this->historyGBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->historyGBox->Location = System::Drawing::Point(0, 0);
			this->historyGBox->Name = L"historyGBox";
			this->historyGBox->Size = System::Drawing::Size(404, 484);
			this->historyGBox->TabIndex = 2;
			this->historyGBox->TabStop = false;
			this->historyGBox->Text = L"History";
			// 
			// polinomListBox
			// 
			this->polinomListBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->polinomListBox->FormattingEnabled = true;
			this->polinomListBox->Location = System::Drawing::Point(3, 16);
			this->polinomListBox->Name = L"polinomListBox";
			this->polinomListBox->Size = System::Drawing::Size(398, 465);
			this->polinomListBox->TabIndex = 0;
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
			this->polinomTLPanel->Name = L"polinomTLPanel";
			this->polinomTLPanel->RowCount = 6;
			this->polinomTLPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.33327F)));
			this->polinomTLPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.33327F)));
			this->polinomTLPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.33327F)));
			this->polinomTLPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.33327F)));
			this->polinomTLPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.33327F)));
			this->polinomTLPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 18.33367F)));
			this->polinomTLPanel->Size = System::Drawing::Size(160, 150);
			this->polinomTLPanel->TabIndex = 0;
			// 
			// polinomLabel
			// 
			this->polinomLabel->AutoSize = true;
			this->polinomLabel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->polinomLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold));
			this->polinomLabel->Location = System::Drawing::Point(4, 1);
			this->polinomLabel->Name = L"polinomLabel";
			this->polinomLabel->Size = System::Drawing::Size(152, 23);
			this->polinomLabel->TabIndex = 0;
			this->polinomLabel->Text = L"Polynomial";
			this->polinomLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// polinomTBox
			// 
			this->polinomTBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->polinomTBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->polinomTBox->Location = System::Drawing::Point(4, 28);
			this->polinomTBox->Multiline = true;
			this->polinomTBox->Name = L"polinomTBox";
			this->polinomTLPanel->SetRowSpan(this->polinomTBox, 4);
			this->polinomTBox->Size = System::Drawing::Size(152, 89);
			this->polinomTBox->TabIndex = 1;
			// 
			// addPolinombutton
			// 
			this->addPolinombutton->BackColor = System::Drawing::Color::AliceBlue;
			this->addPolinombutton->Dock = System::Windows::Forms::DockStyle::Fill;
			this->addPolinombutton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->addPolinombutton->Location = System::Drawing::Point(4, 124);
			this->addPolinombutton->Name = L"addPolinombutton";
			this->addPolinombutton->Size = System::Drawing::Size(152, 22);
			this->addPolinombutton->TabIndex = 2;
			this->addPolinombutton->Text = L"Add";
			this->addPolinombutton->UseVisualStyleBackColor = false;
			// 
			// calculatorButton
			// 
			this->calculatorButton->BackColor = System::Drawing::Color::AliceBlue;
			this->calculatorButton->Dock = System::Windows::Forms::DockStyle::Fill;
			this->calculatorButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold));
			this->calculatorButton->Location = System::Drawing::Point(0, 0);
			this->calculatorButton->Name = L"calculatorButton";
			this->calculatorButton->Size = System::Drawing::Size(105, 150);
			this->calculatorButton->TabIndex = 0;
			this->calculatorButton->Text = L"Calculate Polynomial";
			this->calculatorButton->UseVisualStyleBackColor = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(404, 634);
			this->Controls->Add(this->historyGBox);
			this->Controls->Add(this->splitContainer1);
			this->MinimumSize = System::Drawing::Size(420, 39);
			this->Name = L"MyForm";
			this->Text = L"Polinom Calculator";
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
			this->historyGBox->ResumeLayout(false);
			this->polinomTLPanel->ResumeLayout(false);
			this->polinomTLPanel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void addMonomButton_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
