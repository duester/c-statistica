#pragma once
#include "..\Form\InputForm.h"

namespace Statistica{

	using namespace System;
	using namespace System::Collections::Generic;

	public ref class Sequence abstract{
	protected:
		InputForm^ form;
	public:
		virtual bool validateValues() abstract;
		virtual array<double>^ generate() abstract;
	};
}
