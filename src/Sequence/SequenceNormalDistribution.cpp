#include "SequenceNormalDistribution.h"

namespace Statistica{

	SequenceNormalDistribution::SequenceNormalDistribution(){
		expectation = "0";
		standardDeviation ="1";
	}

	bool SequenceNormalDistribution::validateValues(){
		if (!isDouble(form->getTextBoxValue("txtExpectation")))
			return false;

		if (!isDouble(form->getTextBoxValue("txtStandardDeviation")))
			return false;
		// Standardabweichung soll >0 sein
		double stdDev = Double::Parse(form->getTextBoxValue("txtStandardDeviation"));
		if (stdDev <= 0)
			return false;
		
		return SequenceDistribution::validateValues();
	}

	array<double>^ SequenceNormalDistribution::generate(){
		form = gcnew InputForm(this);
		form->addField("txtExpectation", expectation);
		form->addField("txtStandardDeviation", standardDeviation);
		form->addField("txtCount", count);
		form->addButtons();
		if (form->ShowDialog() == DialogResult::Cancel)
			return nullptr;

		expectation = form->getTextBoxValue("txtExpectation");
		standardDeviation = form->getTextBoxValue("txtStandardDeviation");
		count = form->getTextBoxValue("txtCount");
		double exp = Double::Parse(expectation);
		double stdDev = Double::Parse(standardDeviation);
		int cnt = int::Parse(count);
		array<double>^ list = gcnew array<double>(cnt);
		for (int i=0; i<cnt; i++){
			double a, b, r;
			do{
				a = 2 * random->NextDouble() - 1;
				b = 2 * random->NextDouble() - 1;
				r = a * a + b * b;
			} while (r == 0 || r > 1);
			double sq = Math::Sqrt(-2 * Math::Log(r) / r);
			list[i] = exp + stdDev * a * sq;
		}
		return list;
	}
}
