#include "Calculation2Variables.h"

namespace Statistica{

	void Calculation2Variables::calculate(array<double, 2>^ data){
		if (data->Length == 0){
			valid = false;
			return;
		}

		valid = true;

		array<double>^ x = Util::extractOneDimensionalArray(data, 0);
		array<double>^ y = Util::extractOneDimensionalArray(data, 1);

		// zur Benutzung der StatisticFormula-Klasse
		Series^ series1 = gcnew Series("data1");
		series1->Points->DataBindY(x);
		Series^ series2 = gcnew Series("data2");
		series2->Points->DataBindY(y);

		Chart^ chart = gcnew Chart();
		chart->Series->Add(series1);
		chart->Series->Add(series2);

		sum = 0;
		for (int i=0; i<x->Length; i++)
			sum += x[i] * y[i];

		covariance = chart->DataManipulator->Statistics->Covariance("data1", "data2");

		correlation = chart->DataManipulator->Statistics->Correlation("data1", "data2");
	}

	array<String^>^ Calculation2Variables::getStrings(){
		if (!valid)
			return gcnew array<String^>(0);

		array<String^>^ list = gcnew array<String^>(10);

		list[0] = ResourceUtil::getString("txtSumXY", gcnew array<double^>{sum});
		list[1] = " ";
		list[2] = ResourceUtil::getString("txtSampleCovariance");
		list[3] = "";
		list[4] = ResourceUtil::getString("txtCovariance", gcnew array<double^>{covariance});
		list[5] = " ";
		list[6] = ResourceUtil::getString("txtSampleCorrelationCoefficient");
		list[7] = "";
		list[8] = ResourceUtil::getString("txtCorrelationCoefficient", gcnew array<double^>{correlation});
		list[9] = " ";

		return list;
	}
}
