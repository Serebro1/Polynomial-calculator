#include "AddMonom.h"
#include "MyForm.h"

System::Void Visual::AddMonom::btnAttach_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (isAttached)
		Detach();
	else {
		if (MyForm::Instance != nullptr) {
			Attach(MyForm::Instance);
		}
	}
}

void Visual::AddMonom::AddMonom_LocationChanged(Object^ sender, EventArgs^ e)
{
	if (!isAttached && MyForm::Instance != nullptr) {
		CheckForSmartDocking();
	}
}

void Visual::AddMonom::CheckForSmartDocking()
{
	if (MyForm::Instance == nullptr) return;
	System::Drawing::Rectangle parentBounds = MyForm::Instance->Bounds;
	System::Drawing::Rectangle thisBounds = this->Bounds;
	int threshold = 20;

	if (Math::Abs(thisBounds.Right - parentBounds.Left) < threshold) {
		Attach(MyForm::Instance);
	}

}

System::Void Visual::AddMonom::AddMonom_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
{
	return System::Void();
}

System::Void Visual::AddMonom::btnSave_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void Visual::AddMonom::btnCancel_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}
