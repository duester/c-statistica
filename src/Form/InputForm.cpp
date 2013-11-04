#include "InputForm.h"
#include "..\Sequence\Sequence.h"

namespace Statistica{

	InputForm::InputForm(Sequence^ sequence){
		InitializeComponent();
		this->sequence = sequence;
		xOffset = 10;
		yOffset = 10;
	}

	InputForm::~InputForm(){
		if (components) {
			delete components;
		}
	}

	void InputForm::btnOk_Click(Object^  sender, EventArgs^  e) {
		if (sequence != nullptr && !sequence->validateValues())
			DialogResult = System::Windows::Forms::DialogResult::None;
	}

	void InputForm::addField(String^ key, String^ value){
		Label^ label = gcnew Label();
		label->Text = ResourceUtil::getString(key);
		label->AutoSize = true;
		label->Location = Point(xOffset, yOffset);
		label->CausesValidation = false;
		Controls->Add(label);
		yOffset += label->Height;

		TextBox^ textBox = gcnew TextBox();
		textBox->Location = Point(xOffset, yOffset);
		textBox->Width = 150;
		textBox->CausesValidation = false;
		textBox->Text = value->ToString();
		textBox->Name = key;
		Controls->Add(textBox);
		yOffset += textBox->Height + 10;
	}

	void InputForm::addCheckBox(String^ key, bool value){
		CheckBox^ checkBox = gcnew CheckBox();
		checkBox->Location = Point(xOffset, yOffset);
		checkBox->CausesValidation = false;
		checkBox->Text = ResourceUtil::getString(key);
		checkBox->Checked = value;
		checkBox->Name = key;
		Controls->Add(checkBox);
		yOffset += checkBox->Height + 10;
	}

	void InputForm::addButtons(){
		btnOk = gcnew Button();
		btnOk->Text = ResourceUtil::getString("btnOk");
		btnOk->DialogResult = System::Windows::Forms::DialogResult::OK;
		AcceptButton = btnOk;
		btnOk->Location = Point(xOffset, yOffset + 10);
		btnOk->CausesValidation = true;
		btnOk->Click += gcnew EventHandler(this, &InputForm::btnOk_Click);
		Controls->Add(btnOk);
		xOffset += btnOk->Width + 10;

		btnCancel = gcnew Button();
		btnCancel->Text = ResourceUtil::getString("btnCancel");
		btnCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
		CancelButton = btnCancel;
		btnCancel->Location = Point(xOffset, yOffset + 10);
		btnCancel->CausesValidation = false;
		Controls->Add(btnCancel);
	}

	String^ InputForm::getTextBoxValue(String^ key){
		return ((TextBox^) Controls->Find(key, false)[0])->Text;
	}

	bool InputForm::getCheckBoxValue(String^ key){
		return ((CheckBox^) Controls->Find(key, false)[0])->Checked;
	}
}
