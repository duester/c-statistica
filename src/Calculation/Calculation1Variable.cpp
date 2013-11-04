#include "Calculation1Variable.h"

namespace Statistica{

	void Calculation1Variable::calculate(array<double, 2>^ data){
		if (data->Length == 0){
			valid = false;
			return;
		}

		valid = true;

		// Daten sortieren
		array<double>^ x = Util::extractOneDimensionalArray(data, 0);
		Array::Sort(x);

		// zur Benutzung der StatisticFormula-Klasse
		Series^ series = gcnew Series("data");
		series->Points->DataBindY(x);

		Chart^ chart = gcnew Chart();
		chart->Series->Add(series);

		min = x[0];
		max = x[x->Length - 1];

		sum = 0;
		sum2 = 0;
		for (int i=0; i<x->Length; i++){
			sum += x[i];
			sum2 += x[i] * x[i];
		}

		mean = chart->DataManipulator->Statistics->Mean("data");
		median = chart->DataManipulator->Statistics->Median("data");

		int qIndex;
		switch (x->Length % 4){
		case 0:
			qIndex = x->Length / 4;
			q25 = (x[qIndex - 1] + x[qIndex]) / 2;
			q75 = (x[3 * qIndex - 1] + x[3 * qIndex]) / 2;
			break;
		case 1:
			if (x->Length > 1){
				qIndex = (x->Length - 1) / 4;
				q25 = 0.25 * x[qIndex - 1] + 0.75 * x[qIndex];
				q75 = 0.75 * x[3 * qIndex] + 0.25 * x[3 * qIndex + 1];
			} else {
				q25 = q75 = x[0];
			}
			break;
		case 2:
			qIndex = (x->Length - 2) / 4;
			q25 = x[qIndex];
			q75 = x[3 * qIndex + 1];
			break;
		case 3:
			qIndex = (x->Length - 3) / 4;
			q25 = 0.75 * x[qIndex] + 0.25 * x[qIndex + 1];
			q75 = 0.25 * x[3 * qIndex + 1] + 0.75 * x[3 * qIndex + 2];
			break;
		}

		variance = chart->DataManipulator->Statistics->Variance("data", false);
		varianceN1 = chart->DataManipulator->Statistics->Variance("data", true);

		standardDeviation = Math::Sqrt(variance);
		standardDeviationN1 = Math::Sqrt(varianceN1);
	}

	array<String^>^ Calculation1Variable::getStrings(){
		if (!valid)
			return gcnew array<String^>(0);

		array<String^>^ list = gcnew array<String^>(18);

		list[0] = ResourceUtil::getString("txtMinValue", gcnew array<double^>{min});
		list[1] = ResourceUtil::getString("txtMaxValue", gcnew array<double^>{max});
		list[2] = ResourceUtil::getString("txtMeanValue", gcnew array<double^>{mean});
		list[3] = ResourceUtil::getString("txtMedianValue", gcnew array<double^>{median});
		list[4] = ResourceUtil::getString("txtQuartiles");
		list[5] = "";
		list[6] = ResourceUtil::getString("txtQuartile25", gcnew array<double^>{q25});
		list[7] = ResourceUtil::getString("txtQuartile75", gcnew array<double^>{q75});
		list[8] = ResourceUtil::getString("txtSum", gcnew array<double^>{sum});
		list[9] = ResourceUtil::getString("txtSum2", gcnew array<double^>{sum2});
		list[10] = ResourceUtil::getString("txtSampleVariance");
		list[11] = "";
		list[12] = ResourceUtil::getString("txtVarianceN", gcnew array<double^>{variance});
		list[13] = ResourceUtil::getString("txtVarianceN-1", gcnew array<double^>{varianceN1});
		list[14] = ResourceUtil::getString("txtSampleStandardDeviation");
		list[15] = "";
		list[16] = ResourceUtil::getString("txtStandardDeviationN", gcnew array<double^>{standardDeviation});
		list[17] = ResourceUtil::getString("txtStandardDeviationN-1", gcnew array<double^>{standardDeviationN1});
		
		return list;
	}
}
