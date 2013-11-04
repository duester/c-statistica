#include "SequenceExpression.h"

namespace Statistica{

	SequenceExpression::SequenceExpression(){
		expression = "";
	}

	bool SequenceExpression::validateValues(){
		// TODO
		return true;
	}

	array<double>^ SequenceExpression::generate(){
		/*form = gcnew InputForm(this);
		form->addField("txtExpression", expression);
		form->addButtons();
		if (form->ShowDialog() == DialogResult::Cancel)
			return nullptr;

		expression = form->getTextBoxValue("txtExpression");
		// TODO
		array<double>^ list = nullptr;
		// TODO
		return list;*/

		MessageBox::Show(ResourceUtil::getString("txtFunctionNotImplemented"));
		return nullptr;
	}
}
