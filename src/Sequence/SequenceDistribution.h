#pragma once
#include "SequenceDouble.h"

namespace Statistica{

	public ref class SequenceDistribution abstract : public SequenceDouble{
	protected:
		Random^ random;
	public:
		SequenceDistribution();
	};
}
