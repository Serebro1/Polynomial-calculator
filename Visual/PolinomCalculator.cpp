#include "PolinomCalculator.h"
#include "MyForm.h"
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

void Visual::PolinomCalculator::PolinomCalculator_LocationChanged(Object^ sender, EventArgs^ e)
{
	if (!isAttached && MyForm::Instance != nullptr) {
		CheckForSmartDocking();
	}
}

void Visual::PolinomCalculator::CheckForSmartDocking()
{
    if (MyForm::Instance == nullptr) return;

	System::Drawing::Rectangle parentRect = MyForm::Instance->Bounds;
	System::Drawing::Rectangle thisRect = this->Bounds;
    int threshold = 20;

    if (Math::Abs(thisRect.Left - parentRect.Right) < threshold) {
        Attach(MyForm::Instance);
    }
}
