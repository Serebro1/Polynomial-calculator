#include "MyForm.h"
#include "AddMonom.h"
#include "PolinomCalculator.h"
#include <msclr/marshal_cppstd.h>
#include <regex>
using namespace System;
using namespace System::Windows::Forms;
using namespace Visual;
[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	MyForm^ form = gcnew MyForm();
	Application::Run(form);
}

void Visual::MyForm::UpdateListBox()
{
	polinomListBox->Items->Clear();
	std::vector<std::string> items = Model::getInstance().getStrPolinoms();

	for (size_t i = 0; i < items.size(); ++i) {
		String^ item = gcnew String(
			(std::to_string(i) + ": " + items[i]).c_str()
		);
		polinomListBox->Items->Add(item);
	}
	if (AddMonom::Instance->Visible) AddMonom::Instance->UpdateTable();
	if (PolinomCalculator::Instance->Visible) PolinomCalculator::Instance->UpdateBuffer();
}

System::Void Visual::MyForm::addMonomButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (PolinomCalculator::Instance->Visible) {
		MessageBox::Show("Close polynomial calculator form.", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
		return;
	}
	try
	{
		if (String::IsNullOrWhiteSpace(coeffTBox->Text))
			coeffTBox->Text = "1";
		if (String::IsNullOrWhiteSpace(xTBox->Text))
			xTBox->Text = "0";
		if (String::IsNullOrWhiteSpace(yTBox->Text))
			yTBox->Text = "0";
		if (String::IsNullOrWhiteSpace(zTBox->Text))
			zTBox->Text = "0";
		String^ input = String::Format("{0}{1}{2}{3}",
			coeffTBox->Text,
			"x^" + xTBox->Text,
			"y^" + yTBox->Text,
			"z^" + zTBox->Text
		);

		std::string monomStr = msclr::interop::marshal_as<std::string>(input);
		model.setMonom(model.parser.parseMonomial(monomStr));

		AddMonom^ child = AddMonom::Instance;
		if (!child->Visible) {
			child->Show(this);
			child->Attach(this);
		}
		child->BringToFront();

	}
	catch (const std::exception& ex)
	{
		String^ errorMsg = gcnew String(ex.what());
		MessageBox::Show(errorMsg, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	
}

System::Void Visual::MyForm::calculatorButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (AddMonom::Instance->Visible) {
		MessageBox::Show("Close add monom form.", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
		return;
	}
	try {
		PolinomCalculator^ child = PolinomCalculator::Instance;
		if (!child->Visible) {
			child->Show(this);
			child->Attach(this);
		}
		child->BringToFront();
	}
	catch(const std::exception & ex)
	{
		String^ errorMsg = gcnew String(ex.what());
		MessageBox::Show(errorMsg, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

System::Void Visual::MyForm::addPolinombutton_Click(System::Object^ sender, System::EventArgs^ e)
{
	try
	{
		String^ text = polinomTBox->Text;
		std::string input = msclr::interop::marshal_as<std::string>(text);

		Polinom poly = Model::getInstance().parsePolinom(input);
		Model::getInstance().addPolinom(poly);
		UpdateListBox();
	}
	catch (const std::exception& ex)
	{
		String^ errorMsg = gcnew String(ex.what());
		MessageBox::Show(errorMsg, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	

}

System::Void Visual::MyForm::copyPolyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (polinomListBox->SelectedIndex != -1) {
		String^ text = polinomListBox->SelectedItem->ToString();
		Clipboard::SetText(text->Split(':')[1]);
	}
}

System::Void Visual::MyForm::deletePolyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (polinomListBox->SelectedIndex != -1) {

		Model::getInstance().removePolinom(polinomListBox->SelectedIndex);
		UpdateListBox();
	}
}

System::Void Visual::MyForm::polinomListBox_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	if (e->Button == System::Windows::Forms::MouseButtons::Right) {

		int index = polinomListBox->IndexFromPoint(e->Location);
		if (index != System::Windows::Forms::ListBox::NoMatches) {
			polinomListBox->SelectedIndex = index;
			polinomCMStrip->Show(polinomListBox, e->Location);
		}
	}
}
