#pragma once
#include "SequenceDistribution.h"

namespace Statistica{

	public ref class SequenceUniformDistribution : public SequenceDistribution{
	private:
		String^ minimalValue;
		String^ maximalValue;
		bool discrete;
	public:
		SequenceUniformDistribution();
		virtual bool validateValues() override;
		virtual array<double>^ generate() override;
	};
}
