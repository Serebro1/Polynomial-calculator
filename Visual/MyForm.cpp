#include "MyForm.h"
#include <msclr/marshal_cppstd.h>
#include "../TasksList/polinom.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Visual::MyForm form;
	Application::Run(% form);
}