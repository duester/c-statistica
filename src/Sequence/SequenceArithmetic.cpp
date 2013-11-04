#include "SequenceArithmetic.h"

namespace Statistica{

	SequenceArithmetic::SequenceArithmetic(){
		initialValue = "";
		step = "1";
	}

	bool SequenceArithmetic::validateValues(){
		if (!isDouble(form->getTextBoxValue("txtInitialValue")))
			return false;
		
		if (!isDouble(form->getTextBoxValue("txtStep")))
			return false;
		
		return SequenceDouble::validateValues();
	}
	
	array<double>^ SequenceArithmetic::generate(){
		form = gcnew InputForm(this);
		form->addField("txtInitialValue", initialValue);
		form->addField("txtStep", step);
		form->addField("txtCount", count);
		form->addButtons();
		if (form->ShowDialog() == DialogResult::Cancel)
			return nullptr;
		
		initialValue = form->getTextBoxValue("txtInitialValue");
		step = form->getTextBoxValue("txtStep");
		count = form->getTextBoxValue("txtCount");
		double val = Double::Parse(initialValue);
		double stp = Double::Parse(step);
		int cnt = int::Parse(count);
		array<double>^ list = gcnew array<double>(cnt);
		for (int i=0; i<cnt; i++){
			list[i] = val;
			val += stp;
		}
		return list;
	}
}
