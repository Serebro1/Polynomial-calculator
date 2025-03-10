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
}

Polinom Visual::MyForm::parsePolinom(const std::string& input)
{
	Polinom res;
	std::string cleaned = model.parser.cleanInput(input);
	if (cleaned.empty()) {
		throw std::invalid_argument("Entered empty line!");
	}
	if (!model.parser.validateInput(cleaned)) {
		throw std::invalid_argument("Invalid symbols in polynomial!");
	}
	std::vector<std::string> monomsStr = model.parser.splitMonomials(cleaned);
	std::vector<Monom> monoms;
	for (const auto& str : monomsStr) {
		Monom m = model.parser.parseMonomial(str);
		res += m;
	}
	return res;
}

System::Void Visual::MyForm::addMonomButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	try
	{
		if (String::IsNullOrWhiteSpace(coeffTBox->Text) || String::IsNullOrWhiteSpace(xTBox->Text) ||
			String::IsNullOrWhiteSpace(yTBox->Text) || String::IsNullOrWhiteSpace(zTBox->Text))
			throw std::invalid_argument("Too few arguments");

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
	PolinomCalculator^ child = PolinomCalculator::Instance;
	if (!child->Visible) {
		child->Show(this);
		child->Attach(this);
	}
	child->BringToFront();
}

System::Void Visual::MyForm::addPolinombutton_Click(System::Object^ sender, System::EventArgs^ e)
{
	try
	{
		String^ text = polinomTBox->Text;
		std::string input = msclr::interop::marshal_as<std::string>(text);

		Polinom poly = parsePolinom(input);
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
