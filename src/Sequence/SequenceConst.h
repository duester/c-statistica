#pragma once
#include "SequenceDouble.h"

namespace Statistica{

	public ref class SequenceConst : public SequenceDouble{
	private:
		String^ constant;
	public:
		SequenceConst();
		virtual bool validateValues() override;
		virtual array<double>^ generate() override;
	};
}
