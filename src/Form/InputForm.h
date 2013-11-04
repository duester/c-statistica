#pragma once
#include "..\Util\ResourceUtil.h"

namespace Statistica {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	ref class Sequence;

	public ref class InputForm : public System::Windows::Forms::Form{

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// InputForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->CausesValidation = false;
			this->ClientSize = System::Drawing::Size(83, 31);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"InputForm";
			this->ResumeLayout(false);

		}
#pragma endregion

	private:
		System::ComponentModel::Container ^components;
		Sequence^ sequence;
		Button^ btnOk;
		Button^ btnCancel;
		int xOffset, yOffset;

		void btnOk_Click(Object^  sender, EventArgs^  e);
	protected:
		~InputForm();
	public:
		InputForm(Sequence^ sequence);
		void addField(String^ key, String^ value);
		void addCheckBox(String^ key, bool value);
		void addButtons();
		String^ getTextBoxValue(String^ key);
		bool getCheckBoxValue(String^ key);
	};
}
