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

void Visual::AddMonom::UpdateTable()
{
    addMonomTLPanel->Controls->Clear();
    addMonomTLPanel->RowCount = 0;

    for (int i = 0; i < buffer->size(); ++i) {

        Label^ lbl = gcnew Label();
        lbl->Text = (i).ToString();
        lbl->AutoSize = true;

        Button^ btnAdd = gcnew Button();
        btnAdd->Text = "+";
        btnAdd->Tag = i;
        btnAdd->Click += gcnew EventHandler(this, &AddMonom::OnAddClick);
        btnAdd->Dock = System::Windows::Forms::DockStyle::Fill;

        Button^ btnSub = gcnew Button();
        btnSub->Text = "-";
        btnSub->Tag = i;
        btnSub->Click += gcnew EventHandler(this, &AddMonom::OnSubClick);
        btnSub->Dock = System::Windows::Forms::DockStyle::Fill;

        Button^ btnMult = gcnew Button();
        btnMult->Text = "*";
        btnMult->Tag = i;
        btnMult->Click += gcnew EventHandler(this, &AddMonom::OnMultClick);
        btnMult->Dock = System::Windows::Forms::DockStyle::Fill;

        addMonomTLPanel->RowCount++;
        addMonomTLPanel->Controls->Add(lbl, 0, addMonomTLPanel->RowCount - 1);
        addMonomTLPanel->Controls->Add(btnAdd, 1, addMonomTLPanel->RowCount - 1);
        addMonomTLPanel->Controls->Add(btnSub, 2, addMonomTLPanel->RowCount - 1);
        addMonomTLPanel->Controls->Add(btnMult, 3, addMonomTLPanel->RowCount - 1);
    }
}
void Visual::AddMonom::UpdateLBWithBuffer()
{
    auto mainLB = MyForm::Instance->MainListBox;
    for (size_t i = 0; i < buffer->size(); ++i) {
        String^ item = gcnew String(
            (std::to_string(i) + ": " + Model::getInstance().getStrPoly((*buffer)[i])).c_str()
        );
        mainLB->Items->Add(item);
    }
}
System::Void Visual::AddMonom::AddMonom_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
{
    MyForm::Instance->RefreshListBox();
}

System::Void Visual::AddMonom::btnSave_Click(System::Object^ sender, System::EventArgs^ e)
{
    Model::getInstance().setPolinoms(*buffer);
    MyForm::Instance->RefreshListBox();
    this->Close();
}

System::Void Visual::AddMonom::btnCancel_Click(System::Object^ sender, System::EventArgs^ e)
{
    MyForm::Instance->RefreshListBox();
    this->Close();
}

System::Void Visual::AddMonom::OnAddClick(System::Object^ sender, System::EventArgs^ e)
{
    int index = static_cast<int>(static_cast<Button^>(sender)->Tag);
    buffer->at(index) += *currMonom;
    UpdateLBWithBuffer();
}

System::Void Visual::AddMonom::OnSubClick(System::Object^ sender, System::EventArgs^ e)
{
    int index = static_cast<int>(static_cast<Button^>(sender)->Tag);
    buffer->at(index) -= *currMonom;
    UpdateLBWithBuffer();
}

System::Void Visual::AddMonom::OnMultClick(System::Object^ sender, System::EventArgs^ e)
{
    int index = static_cast<int>(static_cast<Button^>(sender)->Tag);
    buffer->at(index) *= *currMonom;
    UpdateLBWithBuffer();
}


