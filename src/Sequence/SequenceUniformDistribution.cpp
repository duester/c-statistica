#include "SequenceUniformDistribution.h"

namespace Statistica{

	SequenceUniformDistribution::SequenceUniformDistribution(){
		minimalValue = "";
		maximalValue = "";
		discrete = false;
	}

	bool SequenceUniformDistribution::validateValues(){
		if (!isDouble(form->getTextBoxValue("txtMinimalValue")))
			return false;
		// minimaler Wert soll kleiner als maximaler Wert sein
		double min = Double::Parse(form->getTextBoxValue("txtMinimalValue"));

		if (!isDouble(form->getTextBoxValue("txtMaximalValue")))
			return false;
		double max = Double::Parse(form->getTextBoxValue("txtMaximalValue"));
		if (min >= max)
			return false;

		return SequenceDistribution::validateValues();
	}

	array<double>^ SequenceUniformDistribution::generate(){
		form = gcnew InputForm(this);
		form->addField("txtMinimalValue", minimalValue);
		form->addField("txtMaximalValue", maximalValue);
		form->addCheckBox("txtDiscrete", discrete);
		form->addField("txtCount", count);
		form->addButtons();
		if (form->ShowDialog() == DialogResult::Cancel)
			return nullptr;

		minimalValue = form->getTextBoxValue("txtMinimalValue");
		maximalValue = form->getTextBoxValue("txtMaximalValue");
		discrete = form->getCheckBoxValue("txtDiscrete");
		count = form->getTextBoxValue("txtCount");
		double min = Double::Parse(minimalValue);
		double max = Double::Parse(maximalValue);
		int cnt = int::Parse(count);
		array<double>^ list = gcnew array<double>(cnt);
		for (int i=0; i<cnt; i++)
			if (discrete)
				list[i] = random->Next(min, max);
			else
				list[i] = random->NextDouble() * (max - min) + min;
		return list;
	}
}
