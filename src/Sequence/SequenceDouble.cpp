#include "SequenceDouble.h"

namespace Statistica{

	SequenceDouble::SequenceDouble(){
		count = "";
	}

	bool SequenceDouble::validateValues(){
		if (!isDouble(form->getTextBoxValue("txtCount")))
			return false;
		// Anzahl muss ganzzahlig und >0 sein
		double cnt = Double::Parse(form->getTextBoxValue("txtCount"));
		if (Math::Ceiling(cnt) != cnt || cnt <= 0)
			return false;
		return true;
	}

	bool SequenceDouble::isDouble(String^ s){
		try{
			double d = Double::Parse(s);
			return true;
		} catch (FormatException^){
			return false;
		}
	}
}
