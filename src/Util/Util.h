#pragma once

namespace Statistica{

	public ref class Util{
	public:
		static array<double>^ extractOneDimensionalArray(array<double, 2>^ data, int dimension);
	};
}
