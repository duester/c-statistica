#pragma once
#include "Calculation.h"

namespace Statistica{

	public ref class Calculation1Variable : public Calculation{
	private:
		double min, max;
		double mean, median;
		double q25, q75;
		double sum, sum2;
		double variance, varianceN1;
		double standardDeviation, standardDeviationN1;
	public:
		virtual void calculate(array<double, 2>^ data) override;
		virtual array<String^>^ getStrings() override;
	};
}
