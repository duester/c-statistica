#include "Util.h"

namespace Statistica{

	array<double>^ Util::extractOneDimensionalArray(array<double, 2>^ data, int dimension){
		array<double>^ x = gcnew array<double>(data->GetLength(0));
		for (int i=0; i<x->Length; i++)
			x[i] = data[i, dimension];

		return x;
	}
}
