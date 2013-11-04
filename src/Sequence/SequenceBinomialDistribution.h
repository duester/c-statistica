#pragma once
#include "SequenceDistribution.h"

namespace Statistica{

	public ref class SequenceBinomialDistribution : public SequenceDistribution{
	private:
		String^ experimentsNumber;
		String^ successProbability;
	public:
		SequenceBinomialDistribution();
		virtual bool validateValues() override;
		virtual array<double>^ generate() override;
	};
}
