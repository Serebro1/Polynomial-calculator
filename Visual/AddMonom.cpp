#include "AddMonom.h"
#include "MyForm.h"

void Visual::AddMonom::WndProc(Message% m)
{
    if ((m.Msg == MY_WM_ENTERSIZEMOVE || m.Msg == MY_WM_MOVING) && isAttached)
        Detach();
    Form::WndProc(m);
}

void Visual::AddMonom::Attach(Form^ parent)
{
    parentForm = parent;
    this->Owner = parentForm;
    isAttached = true;
    btnAttach->Text = "Detach";
    UpdatePosition();
    this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::SizableToolWindow;
    parentForm->LocationChanged += gcnew EventHandler(this, &AddMonom::parentForm_LocationChanged);
    parentForm->SizeChanged += gcnew EventHandler(this, &AddMonom::parentForm_SizeChanged);
}

void Visual::AddMonom::Detach()
{
    if (parentForm != nullptr) {
        parentForm->LocationChanged -= gcnew EventHandler(this, &AddMonom::parentForm_LocationChanged);
        parentForm->SizeChanged -= gcnew EventHandler(this, &AddMonom::parentForm_SizeChanged);
        parentForm = nullptr;
    }
    this->Owner = nullptr;
    isAttached = false;
    btnAttach->Text = "Attach";
}

void Visual::AddMonom::parentForm_LocationChanged(Object^ sender, EventArgs^ e)
{
    if (isAttached) UpdatePosition();
}
void Visual::AddMonom::parentForm_SizeChanged(Object^ sender, EventArgs^ e)
{
    if (isAttached) UpdatePosition();
}
void Visual::AddMonom::AddMonom_SizeChanged(Object^ sender, EventArgs^ e)
{
    if (isAttached) UpdatePosition();
}

void Visual::AddMonom::UpdatePosition()
{
    if (isAttached && parentForm != nullptr) {
        int newX = parentForm->Left - this->Width + 5;
        int newY = parentForm->Bottom - this->Height;

        if (newX < 0) newX = 0;
        if (newY + this->Height > Screen::PrimaryScreen->WorkingArea.Height)
            newY = Screen::PrimaryScreen->WorkingArea.Height - this->Height;

        this->Location = Point(newX, newY);
    }
}

void Visual::AddMonom::AddMonom_MouseDown(Object^ sender, MouseEventArgs^ e)
{
    if (e->Button == System::Windows::Forms::MouseButtons::Left && isAttached) {
        Detach();
        btnAttach->Text = "Attach";
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

	if (Math::Abs(thisBounds.Right - parentBounds.Left) < threshold &&
        Math::Abs(thisBounds.Bottom - parentBounds.Bottom) < threshold) {
		Attach(MyForm::Instance);
	}

}

void Visual::AddMonom::UpdateTable()
{
    addMonomTLPanel->Controls->Clear();
    addMonomTLPanel->RowCount = 0;
    
    buffer = new std::vector<Polinom>(Model::getInstance().getPolinoms());

    Height = 100 + 50 * buffer->size();
    addMonomTLPanel->Height = 50 * buffer->size();
    for (int i = 0; i < buffer->size(); ++i) {

        Label^ lbl = gcnew Label();
        lbl->Text = (i).ToString();
        lbl->AutoSize = true;

        Button^ btnAdd = gcnew Button();
        btnAdd->Text = "+";
        btnAdd->Tag = i;
        btnAdd->Click += gcnew EventHandler(this, &AddMonom::OnAddClick);

        Button^ btnSub = gcnew Button();
        btnSub->Text = "-";
        btnSub->Tag = i;
        btnSub->Click += gcnew EventHandler(this, &AddMonom::OnSubClick);

        Button^ btnMult = gcnew Button();
        btnMult->Text = "*";
        btnMult->Tag = i;
        btnMult->Click += gcnew EventHandler(this, &AddMonom::OnMultClick);

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
    mainLB->Items->Clear();
    for (size_t i = 0; i < buffer->size(); ++i) {
        String^ item = gcnew String(
            (std::to_string(i) + ": " + Model::getInstance().convertPolyToStr((*buffer)[i])).c_str()
        );
        mainLB->Items->Add(item);
    }
}

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

System::Void Visual::AddMonom::btnSave_Click(System::Object^ sender, System::EventArgs^ e)
{
    Model::getInstance().setPolinoms(*buffer);
    MyForm::Instance->RefreshListBox();
    this->Close();
}

System::Void Visual::AddMonom::AddMonom_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
{
    MyForm::Instance->RefreshListBox();
}

System::Void Visual::AddMonom::btnCancel_Click(System::Object^ sender, System::EventArgs^ e)
{
    MyForm::Instance->RefreshListBox();
    this->Close();
}

System::Void Visual::AddMonom::OnAddClick(System::Object^ sender, System::EventArgs^ e)
{
    currMonom = new Monom(Model::getInstance().getMonom());
    int index = static_cast<int>(static_cast<Button^>(sender)->Tag);
    buffer->at(index) += *currMonom;
    UpdateLBWithBuffer();
}

System::Void Visual::AddMonom::OnSubClick(System::Object^ sender, System::EventArgs^ e)
{
    currMonom = new Monom(Model::getInstance().getMonom());
    int index = static_cast<int>(static_cast<Button^>(sender)->Tag);
    buffer->at(index) -= *currMonom;
    UpdateLBWithBuffer();
}

System::Void Visual::AddMonom::OnMultClick(System::Object^ sender, System::EventArgs^ e)
{
    currMonom = new Monom(Model::getInstance().getMonom());
    int index = static_cast<int>(static_cast<Button^>(sender)->Tag);
    buffer->at(index) *= *currMonom;
    UpdateLBWithBuffer();
}


