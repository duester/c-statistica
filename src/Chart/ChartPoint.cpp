#include "ChartPoint.h"

namespace Statistica{

	void ChartPoint::showRegressionLine_CheckedChanged(Object^  sender, EventArgs^  e){
		chart->Series["regression"]->Enabled = showRegressionLine->Checked;
		regressionLineLegendItem->Enabled = showRegressionLine->Checked;
	}

	void ChartPoint::drawChart(){
		legend->Enabled = true;

		ChartPointLine::drawChart();

		chart->Series["pointLine"]->ChartType = SeriesChartType::Point;

		array<double>^ x = Util::extractOneDimensionalArray(data, 0);
		array<double>^ y = Util::extractOneDimensionalArray(data, 1);

		Series^ seriesX = gcnew Series("x");
		seriesX->Enabled = false;
		seriesX->Points->DataBindY(x);
		chart->Series->Add(seriesX);

		Series^ seriesY = gcnew Series("y");
		seriesY->Enabled = false;
		seriesY->Points->DataBindY(y);
		chart->Series->Add(seriesY);

		double meanX = chart->DataManipulator->Statistics->Mean("x");
		double meanY = chart->DataManipulator->Statistics->Mean("y");
		double varX = chart->DataManipulator->Statistics->Variance("x", false);
		double covXY = chart->DataManipulator->Statistics->Covariance("x", "y");

		double b = covXY / varX;
		double a = meanY - b * meanX;

		Array::Sort(x);
		array<double>^ regX = gcnew array<double>(2){x[0], x[x->Length - 1]};
		array<double>^ regY = gcnew array<double>(regX->Length);
		for (int i=0; i<regX->Length; i++)
			regY[i] = a + b * regX[i];

		Series^ seriesRegression = gcnew Series("regression");
		seriesRegression->ChartType = SeriesChartType::Line;
		seriesRegression->Enabled = showRegressionLine->Checked;
		seriesRegression->Color = regressionLineColor;
		seriesRegression->Points->DataBindXY(regX, regY);
		seriesRegression->IsVisibleInLegend = false;

		chart->Series->Add(seriesRegression);

		regressionLineLegendItem->Name = "y = " + a + " + " + (b < 0 ? "(" + b + ")" : b.ToString()) + " x";
		regressionLineLegendItem->Enabled = showRegressionLine->Checked;
		legend->CustomItems->Add(regressionLineLegendItem);
	}

	ChartPoint::ChartPoint(System::Windows::Forms::DataVisualization::Charting::Chart^ chart)
		: ChartPointLine(chart){
			showRegressionLine = gcnew CheckBox();
			showRegressionLine->Checked = false;
			showRegressionLine->AutoSize = true;
			showRegressionLine->CheckedChanged += gcnew EventHandler(this, &ChartPoint::showRegressionLine_CheckedChanged);

			regressionLineColor = Color::Red;

			regressionLineLegendItem = gcnew LegendItem();
			regressionLineLegendItem->ImageStyle = LegendImageStyle::Line;
			regressionLineLegendItem->Color = regressionLineColor;
	}

	void ChartPoint::localizeTitles(){
		if (!valid)
			return;

		setChartTitle("txtScatterPlot");
	}

	array<Control^>^ ChartPoint::getControls(){
		if (!valid)
			return gcnew array<Control^>(0);

		return gcnew array<Control^>(4){createLabel("txtPointColor"), color,
			createLabel("txtShowRegressionLine"), showRegressionLine};
	}
}
