#include "PolinomCalculator.h"
#include "MyForm.h"
void Visual::PolinomCalculator::WndProc(Message% m)
{
	if ((m.Msg == MY_WM_ENTERSIZEMOVE || m.Msg == MY_WM_MOVING) && isAttached)
		Detach();
	Form::WndProc(m);
}

void Visual::PolinomCalculator::Attach(Form^ parent)
{
	parentForm = parent;
	this->Owner = parentForm;
	isAttached = true;
	btnAttach->Text = "Detach";
	UpdatePosition();
	this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::SizableToolWindow;
	parentForm->LocationChanged += gcnew EventHandler(this, &PolinomCalculator::parentForm_LocationChanged);
	parentForm->SizeChanged += gcnew EventHandler(this, &PolinomCalculator::parentForm_SizeChanged);
}

void Visual::PolinomCalculator::Detach()
{
	if (parentForm != nullptr) {
		parentForm->LocationChanged -= gcnew EventHandler(this, &PolinomCalculator::parentForm_LocationChanged);
		parentForm->SizeChanged -= gcnew EventHandler(this, &PolinomCalculator::parentForm_SizeChanged);
		parentForm = nullptr;
	}
	this->Owner = nullptr;
	isAttached = false;
	btnAttach->Text = "Attach";
}

void Visual::PolinomCalculator::UpdatePosition()
{
	if (isAttached && parentForm != nullptr) {
		int newX = parentForm->Right + 5;
		int newY = parentForm->Bottom - this->Height;

		if (newX < 0) newX = 0;
		if (newX + this->Width > Screen::PrimaryScreen->WorkingArea.Right)
			newX = Screen::PrimaryScreen->WorkingArea.Right - this->Width;

		if (newY < 0) newY = 0;
		if (newY + this->Height > Screen::PrimaryScreen->WorkingArea.Height)
			newY = Screen::PrimaryScreen->WorkingArea.Height - this->Height;
		

		this->Location = Point(newX, newY);
	}
}

void Visual::PolinomCalculator::PolinomCalculator_MouseDown(Object^ sender, MouseEventArgs^ e)
{
	if (e->Button == System::Windows::Forms::MouseButtons::Left && isAttached) {
		Detach();
		btnAttach->Text = "Attach";
	}
}

System::Void Visual::PolinomCalculator::btnAttach_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (isAttached)
		Detach();
	else {
		if (MyForm::Instance != nullptr) {
			Attach(MyForm::Instance);
		}
	}
}

void Visual::PolinomCalculator::PolinomCalculator_SizeChanged(Object^ sender, EventArgs^ e)
{
	if (isAttached) UpdatePosition();
}

void Visual::PolinomCalculator::PolinomCalculator_LocationChanged(Object^ sender, EventArgs^ e)
{
	if (!isAttached && MyForm::Instance != nullptr) CheckForSmartDocking();
}

void Visual::PolinomCalculator::parentForm_LocationChanged(Object^ sender, EventArgs^ e)
{
	if (isAttached) UpdatePosition();
}

void Visual::PolinomCalculator::parentForm_SizeChanged(Object^ sender, EventArgs^ e)
{
	if (isAttached) UpdatePosition();
}

void Visual::PolinomCalculator::CheckForSmartDocking()
{
    if (MyForm::Instance == nullptr) return;

	System::Drawing::Rectangle parentBounds = MyForm::Instance->Bounds;
	System::Drawing::Rectangle thisBounds = this->Bounds;
    int threshold = 20;

    if (Math::Abs(thisBounds.Left - parentBounds.Right) < threshold &&
		Math::Abs(thisBounds.Bottom - parentBounds.Bottom) < threshold) {
        Attach(MyForm::Instance);
    }
}
void Visual::PolinomCalculator::UpdateBuffer()
{
	buffer = new std::vector<Polinom>(Model::getInstance().getPolinoms());
}
void Visual::PolinomCalculator::UpdateLBWithBuffer()
{
	auto mainLB = MyForm::Instance->MainListBox;
	mainLB->Items->Clear();
	for (size_t i = 0; i < buffer->size(); ++i) {
		String^ item = gcnew String(
			(std::to_string(i) + ": " + Model::getInstance().convertPolyToStr((*buffer)[i])).c_str()
		);
		mainLB->Items->Add(item);
	}
}

System::Void Visual::PolinomCalculator::btnSave_Click(System::Object^ sender, System::EventArgs^ e)
{
	Model::getInstance().setPolinoms(*buffer);
	MyForm::Instance->RefreshListBox();
	this->Close();
}

System::Void Visual::PolinomCalculator::PolinomCalculator_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
{
	MyForm::Instance->RefreshListBox();
}

System::Void Visual::PolinomCalculator::btnCancel_Click(System::Object^ sender, System::EventArgs^ e)
{
	MyForm::Instance->RefreshListBox();
	this->Close();
}

System::Void Visual::PolinomCalculator::btnCalc_Click(System::Object^ sender, System::EventArgs^ e)
{
	Button^ clickedButton = dynamic_cast<Button^>(sender);
	if (clickedButton == nullptr) return;

	calculTBox->Text += clickedButton->Text;
}

System::Void Visual::PolinomCalculator::btnEnter_Click(System::Object^ sender, System::EventArgs^ e)
{
	try {
		CalculatePolinoms();
	}
	catch (const std::exception& ex)
	{
		String^ errorMsg = gcnew String(ex.what());
		MessageBox::Show("Polynomial Calculator: " + errorMsg, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

System::Void Visual::PolinomCalculator::btnBack_Click(System::Object^ sender, System::EventArgs^ e)
{
	HandleBackSpaceKey();
}

System::Void Visual::PolinomCalculator::btnClear_Click(System::Object^ sender, System::EventArgs^ e)
{
	calculTBox->Text = "";
}

void Visual::PolinomCalculator::HandleBackSpaceKey()
{
	String^ currentText = calculTBox->Text;
	if (currentText->Length > 0) {
		calculTBox->Text = currentText->Substring(0, currentText->Length - 1);
	}
}

void Visual::PolinomCalculator::CalculatePolinoms()
{
	std::string input = msclr::interop::marshal_as<std::string>(calculTBox->Text);
	Polinom res = Model::getInstance().calcPolinom(input);
	if (res.isEmpty()) return;
	buffer->push_back(res);
	UpdateLBWithBuffer();
}




