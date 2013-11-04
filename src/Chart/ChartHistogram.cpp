#include "ChartHistogram.h"

namespace Statistica{

	void ChartHistogram::numberOfIntervals_ValueChanged(Object^  sender, EventArgs^  e){
		drawChart();
		localizeTitles();
	}

	void ChartHistogram::borderColor_Clicked(Object^  sender, EventArgs^  e){
		colorDialog->Color = borderColor->BackColor;
		if (colorDialog->ShowDialog() == DialogResult::OK){
			borderColor->BackColor = colorDialog->Color;
			for (int i=0; i<data->GetLength(1); i++)
				chart->Series["histogram" + i]->BorderColor = colorDialog->Color;
		}
	}

	void ChartHistogram::columnColor_Clicked(Object^  sender, EventArgs^  e){
		colorDialog->Color = columnColor->BackColor;
		if (colorDialog->ShowDialog() == DialogResult::OK){
			columnColor->BackColor = colorDialog->Color;
			for (int i=0; i<data->GetLength(1); i++)
				chart->Series["histogram" + i]->Color = colorDialog->Color;
		}
	}

	double ChartHistogram::roundInterval(double interval){
		// If the interval is zero return error
		if (interval == 0.0) {
			throw(gcnew ArgumentOutOfRangeException("interval", "Interval can not be zero."));
		}

		// If the real interval is > 1.0
		double step = -1;
		double tempValue = interval; 
		while (tempValue > 1.0){
			step++;
			tempValue = tempValue / 10.0;
			if (step > 1000){
				throw(gcnew InvalidOperationException("Auto interval error due to invalid point values or axis minimum/maximum."));
			}
		}

		// If the real interval is < 1.0
		tempValue = interval; 
		if (tempValue < 1.0){
			step = 0;
		}

		while (tempValue < 1.0){
			step --;
			tempValue = tempValue * 10.0;
			if (step < -1000){
				throw(gcnew InvalidOperationException("Auto interval error due to invalid point values or axis minimum/maximum."));
			}
		}

		double tempDiff = interval / Math::Pow(10.0, step);
		if (tempDiff < 3.0){
			tempDiff = 2.0;
		} else if (tempDiff < 7.0){
			tempDiff = 5.0;
		} else{
			tempDiff = 10.0;
		}

		// Make a correction of the real interval
		return tempDiff * Math::Pow(10.0, step);
	}

	void ChartHistogram::drawChart(){
		chart->ChartAreas->Clear();
		chart->Series->Clear();

		double absoluteMinimum = Double::MaxValue;
		double absoluteMaximum = Double::MinValue;
		int absoluteMaxNumberInRange = 0;

		for (int i=0; i<data->GetLength(1); i++){
			array<double>^ x = Util::extractOneDimensionalArray(data, i);
			Array::Sort(x);

			double min = x[0];
			double max = x[x->Length - 1];

			if (min == max){
				valid = false;
				chart->Titles->Clear();
				return;
			}

			Series^ series = gcnew Series("histogram" + i);
			chart->Series->Add(series);

			series->ChartType = SeriesChartType::Column;
			series->BorderColor = borderColor->BackColor;
			series->Color = columnColor->BackColor;
			series["PointWidth"] = "1";

			double step = (max - min) / Decimal::ToDouble(numberOfIntervals->Value);
			step = roundInterval(step);
			min = Math::Floor(min / step) * step;
			if (min < absoluteMinimum)
				absoluteMinimum = min;
			max = Math::Ceiling(max / step) * step;
			if (max > absoluteMaximum)
				absoluteMaximum = max;

			double right = min + step;
			if (Math::Abs(Math::Floor(right + 0.5) - right) < 1e-5)
				right = Math::Floor(right + 0.5);
			int numberInRange = 0;
			int maxNumberInRange = 0;
			for (int j=0; j<x->Length; j++){
				while ((j < x->Length - 1 && x[j] >= right) || (j == x->Length - 1 && x[j] > right)){
					DataPoint^ point = gcnew DataPoint(right - step / 2, numberInRange);
					if (numberInRange > 0)
						point->IsValueShownAsLabel = true;
					series->Points->Add(point);
					right += step;
					if (Math::Abs(Math::Floor(right + 0.5) - right) < 1e-5)
						right = Math::Floor(right + 0.5);
					numberInRange = 0;
				}
				numberInRange++;
				if (numberInRange > maxNumberInRange)
					maxNumberInRange = numberInRange;
			}
			if (maxNumberInRange > absoluteMaxNumberInRange)
				absoluteMaxNumberInRange = maxNumberInRange;
			DataPoint^ point = gcnew DataPoint(right - step / 2, numberInRange);
			if (numberInRange > 0)
				point->IsValueShownAsLabel = true;
			series->Points->Add(point);

			ChartArea^ chartArea;
			/*if (i == 0)
				chartArea = chart->ChartAreas["chartArea0"];
			else */
				chartArea = createChartArea("chartArea" + i);
			chartArea->AxisX->Title = columnHeaders[i];

			double axisInterval = step;
			while ((max - min) / axisInterval > 10)
				axisInterval *= 2;
			chartArea->AxisX->Interval = axisInterval;

			chartArea->AxisY->Minimum = 0;

			axisInterval = 1;
			while (maxNumberInRange / axisInterval > 10)
				axisInterval *= 2;
			chartArea->AxisY->Interval = axisInterval;

			//if (i > 0 && !chart->ChartAreas->Contains(chartArea))
				chart->ChartAreas->Add(chartArea);

			series->ChartArea = "chartArea" + i;
		}

		// alle x-Achsen gleich skalieren
		for (int i=0; i<data->GetLength(1); i++){
			chart->ChartAreas["chartArea" + i]->AxisX->Minimum = absoluteMinimum;
			chart->ChartAreas["chartArea" + i]->AxisX->Maximum = absoluteMaximum;
			chart->ChartAreas["chartArea" + i]->AxisY->Maximum = absoluteMaxNumberInRange;
		}
	}

	ChartHistogram::ChartHistogram(System::Windows::Forms::DataVisualization::Charting::Chart^ chart)
		: Chart(chart){
			numberOfIntervals = gcnew NumericUpDown();
			numberOfIntervals->Size = System::Drawing::Size(45, 20);
			numberOfIntervals->Minimum = System::Decimal(1);
			numberOfIntervals->Maximum = System::Decimal(100);
			numberOfIntervals->Value = System::Decimal(10);
			numberOfIntervals->ValueChanged += gcnew EventHandler(this, &ChartHistogram::numberOfIntervals_ValueChanged);

			borderColor = gcnew Button();
			borderColor->BackColor = System::Drawing::Color::Black;
			borderColor->Size = System::Drawing::Size(20, 20);
			borderColor->Click += gcnew EventHandler(this, &ChartHistogram::borderColor_Clicked);

			columnColor = gcnew Button();
			columnColor->BackColor = System::Drawing::Color::Yellow;
			columnColor->Size = System::Drawing::Size(20, 20);
			columnColor->Click += gcnew EventHandler(this, &ChartHistogram::columnColor_Clicked);

			colorDialog = gcnew ColorDialog();
	}

	void ChartHistogram::localizeTitles(){
		if (!valid)
			return;

		setChartTitle("txtHistogram");

		for (int i=0; i<data->GetLength(1); i++)
			chart->ChartAreas["chartArea" + i]->AxisY->Title = ResourceUtil::getString("txtFrequency");
	}

	array<Control^>^ ChartHistogram::getControls(){
		if (!valid)
			return gcnew array<Control^>(0);

		return gcnew array<Control^>(6){createLabel("txtIntervalsNumber"), numberOfIntervals, 
			createLabel("txtBorderColor"), borderColor, 
			createLabel("txtColumnColor"), columnColor};
	}
}
