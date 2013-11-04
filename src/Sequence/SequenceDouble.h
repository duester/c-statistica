#pragma once
#include "Sequence.h"

namespace Statistica{

	public ref class SequenceDouble abstract : public Sequence{
	protected:
		String^ count;

		static bool isDouble(String^ s);
	public:
		SequenceDouble();
		virtual bool validateValues() override;
	};
}
