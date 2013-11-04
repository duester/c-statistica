#include "SequenceBinomialDistribution.h"

namespace Statistica{

	SequenceBinomialDistribution::SequenceBinomialDistribution(){
		experimentsNumber = "";
		successProbability = "";
	}

	bool SequenceBinomialDistribution::validateValues(){
		if (!isDouble(form->getTextBoxValue("txtExperimentsNumber")))
			return false;
		// Zahl der Versuche muss ganzzahlig und >0 sein
		double expNum = Double::Parse(form->getTextBoxValue("txtExperimentsNumber"));
		if (Math::Ceiling(expNum) != expNum || expNum <= 0)
			return false;
		
		if (!isDouble(form->getTextBoxValue("txtSuccessProbability")))
			return false;
		// Erfolgswahrscheinlichkeit soll zwischen 0 und 1 liegen
		double succProb = Double::Parse(form->getTextBoxValue("txtSuccessProbability"));
		if (succProb < 0 || succProb > 1)
			return false;
		
		return SequenceDistribution::validateValues();
	}

	array<double>^ SequenceBinomialDistribution::generate(){
		form = gcnew InputForm(this);
		form->addField("txtExperimentsNumber", experimentsNumber);
		form->addField("txtSuccessProbability", successProbability);
		form->addField("txtCount", count);
		form->addButtons();
		if (form->ShowDialog() == DialogResult::Cancel)
			return nullptr;

		experimentsNumber = form->getTextBoxValue("txtExperimentsNumber");
		successProbability = form->getTextBoxValue("txtSuccessProbability");
		count = form->getTextBoxValue("txtCount");
		int expNum = int::Parse(experimentsNumber);
		double succProb = Double::Parse(successProbability);
		int cnt = int::Parse(count);
		array<double>^ list = gcnew array<double>(cnt);
		for (int i=0; i<cnt; i++){
			list[i] = 0;
			for (int j=0; j<expNum; j++)
				if (random->NextDouble() < succProb)
					list[i]++;
		}
		return list;
	}
}
