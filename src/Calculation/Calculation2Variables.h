#pragma once
#include "Calculation.h"

namespace Statistica{

	public ref class Calculation2Variables : public Calculation{
	private:
		double sum;
		double covariance;
		double correlation;
	public:
		virtual void calculate(array<double, 2>^ data) override;
		virtual array<String^>^ getStrings() override;
	};
}
