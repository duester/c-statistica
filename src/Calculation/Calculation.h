#pragma once
#include "..\Util\ResourceUtil.h"
#include "..\Util\Util.h"

namespace Statistica{

	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Windows::Forms::DataVisualization::Charting;

	public ref class Calculation abstract{
	protected:
		bool valid;
	public:
		virtual void calculate(array<double, 2>^ data) abstract;
		virtual array<String^>^ getStrings() abstract;
	};
}
