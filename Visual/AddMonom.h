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
	/// —водка дл€ AddMonom
	/// </summary>
	public ref class AddMonom sealed : public System::Windows::Forms::Form
	{
	private:
		static AddMonom^ instance = nullptr;
		std::vector<Polinom>* buffer;
		Monom* currMonom;
		
		AddMonom(void)
		{
			InitializeComponent();
			buffer = new std::vector<Polinom>(Model::getInstance().getPolinoms());
			
			UpdateTable();
			//
			//TODO: добавьте код конструктора
			//
		}
	public:
		
		static property AddMonom^ Instance {

			AddMonom^ get() {

				if (instance == nullptr || instance->IsDisposed) {
					instance = gcnew AddMonom();
					
				}
				return instance;
			}
		}
	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~AddMonom()
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
			this->tableLayoutPanel1->Margin = System::Windows::Forms::Padding(4);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 60)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(197, 207);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold));
			this->label1->Location = System::Drawing::Point(4, 0);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(90, 41);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Monom";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// btnCancel
			// 
			this->btnCancel->BackColor = System::Drawing::Color::Pink;
			this->btnCancel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnCancel->Location = System::Drawing::Point(4, 169);
			this->btnCancel->Margin = System::Windows::Forms::Padding(4);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(90, 34);
			this->btnCancel->TabIndex = 1;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = false;
			this->btnCancel->Click += gcnew System::EventHandler(this, &AddMonom::btnCancel_Click);
			// 
			// btnSave
			// 
			this->btnSave->BackColor = System::Drawing::Color::PaleGreen;
			this->btnSave->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnSave->Location = System::Drawing::Point(102, 169);
			this->btnSave->Margin = System::Windows::Forms::Padding(4);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(91, 34);
			this->btnSave->TabIndex = 2;
			this->btnSave->Text = L"Save";
			this->btnSave->UseVisualStyleBackColor = false;
			this->btnSave->Click += gcnew System::EventHandler(this, &AddMonom::btnSave_Click);
			// 
			// addMonomTLPanel
			// 
			this->addMonomTLPanel->AutoSize = true;
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
			this->addMonomTLPanel->Dock = System::Windows::Forms::DockStyle::Top;
			this->addMonomTLPanel->Location = System::Drawing::Point(4, 45);
			this->addMonomTLPanel->Margin = System::Windows::Forms::Padding(4);
			this->addMonomTLPanel->Name = L"addMonomTLPanel";
			this->addMonomTLPanel->RowCount = 1;
			this->addMonomTLPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->addMonomTLPanel->Size = System::Drawing::Size(189, 0);
			this->addMonomTLPanel->TabIndex = 3;
			this->addMonomTLPanel->LocationChanged += gcnew System::EventHandler(this, &AddMonom::AddMonom_LocationChanged);
			this->addMonomTLPanel->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &AddMonom::AddMonom_MouseDown);
			// 
			// btnAttach
			// 
			this->btnAttach->BackColor = System::Drawing::Color::PeachPuff;
			this->btnAttach->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnAttach->Location = System::Drawing::Point(102, 4);
			this->btnAttach->Margin = System::Windows::Forms::Padding(4);
			this->btnAttach->Name = L"btnAttach";
			this->btnAttach->Size = System::Drawing::Size(91, 33);
			this->btnAttach->TabIndex = 4;
			this->btnAttach->Text = L"Detach";
			this->btnAttach->UseVisualStyleBackColor = false;
			this->btnAttach->Click += gcnew System::EventHandler(this, &AddMonom::btnAttach_Click);
			// 
			// AddMonom
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(197, 207);
			this->Controls->Add(this->tableLayoutPanel1);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::SizableToolWindow;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"AddMonom";
			this->Text = L"AddMonom";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &AddMonom::AddMonom_FormClosed);
			this->LocationChanged += gcnew System::EventHandler(this, &AddMonom::AddMonom_LocationChanged);
			this->SizeChanged += gcnew System::EventHandler(this, &AddMonom::AddMonom_SizeChanged);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &AddMonom::AddMonom_MouseDown);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private:
		bool isAttached = false;
		Form^ parentForm = nullptr;

		static const int MY_WM_ENTERSIZEMOVE = 0x0231;
		static const int MY_WM_MOVING = 0x0216;

	protected:
		virtual void WndProc(Message% m) override;
	public:
		void Attach(Form^ parent);
		void Detach();

		void UpdateTable();
	private:
		void UpdateLBWithBuffer();

		void parentForm_LocationChanged(Object^ sender, EventArgs^ e);
		void parentForm_SizeChanged(Object^ sender, EventArgs^ e);
		void AddMonom_SizeChanged(Object^ sender, EventArgs^ e);
		void UpdatePosition();

		void AddMonom_MouseDown(Object^ sender, MouseEventArgs^ e);
		
		void AddMonom_LocationChanged(Object^ sender, EventArgs^ e);
		void CheckForSmartDocking();
		
		System::Void btnAttach_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btnSave_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void AddMonom_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);
		System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void OnAddClick(System::Object^ sender, System::EventArgs^ e);
		System::Void OnSubClick(System::Object^ sender, System::EventArgs^ e);
		System::Void OnMultClick(System::Object^ sender, System::EventArgs^ e);
	
};
}
