#pragma once
#include "SequenceDistribution.h"

namespace Statistica{

	public ref class SequenceNormalDistribution : public SequenceDistribution{
	private:
		String^ expectation;
		String^ standardDeviation;
	public:
		SequenceNormalDistribution();
		virtual bool validateValues() override;
		virtual array<double>^ generate() override;
	};
}
