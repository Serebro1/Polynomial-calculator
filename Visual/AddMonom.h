#pragma once

namespace Visual {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ AddMonom
	/// </summary>
	public ref class AddMonom : public System::Windows::Forms::Form
	{
	public:
		AddMonom(void)
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
		~AddMonom()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnCancel;
	private: System::Windows::Forms::Button^ btnSave;
	private: System::Windows::Forms::TableLayoutPanel^ addMonomTLPanel;
	private: System::Windows::Forms::Button^ btnAttach;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->btnSave = (gcnew System::Windows::Forms::Button());
			this->addMonomTLPanel = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->btnAttach = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->BackColor = System::Drawing::Color::Gainsboro;
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->btnCancel, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->btnSave, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->addMonomTLPanel, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->btnAttach, 1, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 60)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(147, 168);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold));
			this->label1->Location = System::Drawing::Point(3, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(67, 33);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Monom";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// btnCancel
			// 
			this->btnCancel->BackColor = System::Drawing::Color::Pink;
			this->btnCancel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnCancel->Location = System::Drawing::Point(3, 136);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(67, 29);
			this->btnCancel->TabIndex = 1;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = false;
			// 
			// btnSave
			// 
			this->btnSave->BackColor = System::Drawing::Color::PaleGreen;
			this->btnSave->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnSave->Location = System::Drawing::Point(76, 136);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(68, 29);
			this->btnSave->TabIndex = 2;
			this->btnSave->Text = L"Save";
			this->btnSave->UseVisualStyleBackColor = false;
			// 
			// addMonomTLPanel
			// 
			this->addMonomTLPanel->ColumnCount = 4;
			this->tableLayoutPanel1->SetColumnSpan(this->addMonomTLPanel, 2);
			this->addMonomTLPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->addMonomTLPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->addMonomTLPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->addMonomTLPanel->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->addMonomTLPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->addMonomTLPanel->Location = System::Drawing::Point(3, 36);
			this->addMonomTLPanel->Name = L"addMonomTLPanel";
			this->addMonomTLPanel->RowCount = 1;
			this->addMonomTLPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->addMonomTLPanel->Size = System::Drawing::Size(141, 94);
			this->addMonomTLPanel->TabIndex = 3;
			// 
			// btnAttach
			// 
			this->btnAttach->BackColor = System::Drawing::Color::PeachPuff;
			this->btnAttach->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnAttach->Location = System::Drawing::Point(76, 3);
			this->btnAttach->Name = L"btnAttach";
			this->btnAttach->Size = System::Drawing::Size(68, 27);
			this->btnAttach->TabIndex = 4;
			this->btnAttach->Text = L"unpin";
			this->btnAttach->UseVisualStyleBackColor = false;
			this->btnAttach->Click += gcnew System::EventHandler(this, &AddMonom::btnAttach_Click);
			// 
			// AddMonom
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(147, 168);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"AddMonom";
			this->Text = L"AddMonom";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &AddMonom::AddMonom_FormClosed);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnAttach_Click(System::Object^ sender, System::EventArgs^ e) {

	}
private: System::Void AddMonom_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
}
};
}
