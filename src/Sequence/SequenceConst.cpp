#include "SequenceConst.h"

namespace Statistica{

	SequenceConst::SequenceConst(){
		constant = "";
	}
	
	bool SequenceConst::validateValues(){
		if (!isDouble(form->getTextBoxValue("txtConstant")))
			return false;
		
		return SequenceDouble::validateValues();
	}

	array<double>^ SequenceConst::generate(){
		form = gcnew InputForm(this);
		form->addField("txtConstant", constant);
		form->addField("txtCount", count);
		form->addButtons();
		if (form->ShowDialog() == DialogResult::Cancel)
			return nullptr;
		
		constant = form->getTextBoxValue("txtConstant");
		count = form->getTextBoxValue("txtCount");
		double cnst = Double::Parse(constant);
		int cnt = int::Parse(count);
		array<double>^ list = gcnew array<double>(cnt);
		for (int i=0; i<cnt; i++)
			list[i] = cnst;
		return list;
	}
}
