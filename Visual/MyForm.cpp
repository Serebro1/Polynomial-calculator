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

void Visual::MyForm::LoadDataToListBox()
{
	polinomListBox->Items->Clear();
	Model& model = Model::getInstance();
	std::vector<std::string> items = model.getStrPolinoms();

	for (size_t i = 0; i < items.size(); ++i) {
		String^ item = gcnew String(
			(std::to_string(i) + ": " + items[i]).c_str()
		);
		polinomListBox->Items->Add(item);
	}
}

System::Void Visual::MyForm::addMonomButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	AddMonom^ child = AddMonom::Instance;
	if (!child->Visible) {
		child->Show(this);
		child->Attach(this);
	}
	child->BringToFront();
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
	String^ text = polinomTBox->Text;
	std::string input = msclr::interop::marshal_as<std::string>(text);
	input = std::regex_replace(input, std::regex("\\s+"), "");
}
