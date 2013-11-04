#pragma once
#include "SequenceDouble.h"

namespace Statistica{

	public ref class SequenceArithmetic : public SequenceDouble{
	private:
		String^ initialValue;
		String^ step;
	public:
		SequenceArithmetic();
		virtual bool validateValues() override;
		virtual array<double>^ generate() override;
	};
}
