#pragma once
#include <stdlib.h>
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
		static const int MY_WM_ENTERSIZEMOVE = 0x0231;
		static const int MY_WM_MOVING = 0x0216;
		AddMonom(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
	public:
		static property AddMonom^ Instance {
			AddMonom^ get() {
				if (instance == nullptr || instance->IsDisposed)
					instance = gcnew AddMonom();
				return instance;
			}
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
			this->addMonomTLPanel->Location = System::Drawing::Point(4, 45);
			this->addMonomTLPanel->Margin = System::Windows::Forms::Padding(4);
			this->addMonomTLPanel->Name = L"addMonomTLPanel";
			this->addMonomTLPanel->RowCount = 1;
			this->addMonomTLPanel->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->addMonomTLPanel->Size = System::Drawing::Size(189, 116);
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
		Point lastManualLocation;
	protected:
		virtual void WndProc(Message% m) override {
			if (m.Msg == MY_WM_ENTERSIZEMOVE && isAttached) {
				Detach();
			}
			else if (m.Msg == MY_WM_MOVING && isAttached) {
				Detach();
			}
			Form::WndProc(m);
		}
	public:
		void Attach(Form^ parent) {
			parentForm = parent;
			this->Owner = parentForm;
			isAttached = true;
			btnAttach->Text = "Detach";
			UpdatePosition();
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::SizableToolWindow;
			parentForm->LocationChanged += gcnew EventHandler(this, &AddMonom::parentForm_LocationChanged);
		}
		void Detach() {
			if (parentForm != nullptr) {
				parentForm->LocationChanged -= gcnew EventHandler(this, &AddMonom::parentForm_LocationChanged);
				parentForm = nullptr;
			}
			this->Owner = nullptr;
			isAttached = false;
			btnAttach->Text = "Attach";
			lastManualLocation = this->Location;
		}
	private:
		System::Void btnAttach_Click(System::Object^ sender, System::EventArgs^ e);
		
		void parentForm_LocationChanged(Object^ sender, EventArgs^ e) {
			if (isAttached) {
				UpdatePosition();
			}
		}
		void AddMonom_SizeChanged(Object^ sender, EventArgs^ e) {
			if (isAttached) UpdatePosition();
		}
		void UpdatePosition() {
			if (isAttached && parentForm != nullptr) {
				int newX = parentForm->Left - this->Width + 5;
				int newY = parentForm->Bottom - this->Height;

				if (newX < 0) newX = 0;
				if (newY + this->Height > Screen::PrimaryScreen->WorkingArea.Height)
					newY = Screen::PrimaryScreen->WorkingArea.Height - this->Height;

				this->Location = Point(newX, newY);
			}
		}

		void AddMonom_MouseDown(Object^ sender, MouseEventArgs^ e) {
			if (e->Button == System::Windows::Forms::MouseButtons::Left && isAttached) {
				Detach();
				btnAttach->Text = "Attach";
				lastManualLocation = this->Location;
			}
		}
		
		void AddMonom_LocationChanged(Object^ sender, EventArgs^ e);
		void CheckForSmartDocking();
		void CheckForReattach() {
			if (IsNearParent()) {
				Attach(parentForm);
			}
		}

		bool IsNearParent() {
			if (parentForm == nullptr) return false;
			return (abs(this->Right - parentForm->Left) < 20 &&
				abs(this->Top - parentForm->Bottom) < 20);
		}

		
	private: System::Void AddMonom_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
	}
};
}
