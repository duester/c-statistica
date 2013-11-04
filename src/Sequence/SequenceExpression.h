#pragma once
#include "Sequence.h"

namespace Statistica{

	public ref class SequenceExpression : public Sequence{
	private:
		String^ expression;
	public:
		SequenceExpression();
		virtual bool validateValues() override;
		virtual array<double>^ generate() override;
	};
}
